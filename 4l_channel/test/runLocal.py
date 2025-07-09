#!/usr/bin/env python3
###
# Example for running the analysis locally, after customizing variables.
# Run with:
# python runLocal.py
###
from argparse import ArgumentParser
import logging
import json

from ZZAnalysis.NanoAnalysis.tools import setConf, getConf, insertAfter

# Check that the checkout recipe has been properly updated
from ZZAnalysis.AnalysisStep.validateCheckout import validateCheckout
if(not validateCheckout()):
    exit(1)


def main(args):
    configstatus = configure(args)
    logging.debug("configuration status = %d", configstatus)
    if(configstatus != 0): return configstatus

    #####################################################################
    ### This import should be done AFTER all customizations (setConf calls)c
    from ZZAnalysis.NanoAnalysis.nanoZZ4lAnalysis import p
    ######################################################################

    ### Tweak postprocessor parameters as necessary
    p.prefetch=True # Prefetch remote files
    p.longTermCache=True # keep prefetched files (useful for rerunning tests several times)
    if len(p.inputFiles) == 1 :
        p.haddFileName = None # Skip final hadd
    p.maxEntries = args.maxevents

    ### Select specific events to debug
    # p.cut = "run==316239  && luminosityBlock==226 && event==284613817"

    ### Print out detailed candidate information for debug purposes
    # from ZZAnalysis.NanoAnalysis.dumpEvents import dumpEvents
    # p.cut = None # Remove preselction
    # insertAfter(p.modules,"lepFiller",dumpEvents(level=-1),getConf("NANOVERSION", 11))

    # p.branchsel=None #Read all branches
    # p.outputbranchsel=None #Output all branches

    ### Replace JSON
    # p.json =

    ### Early stop for --dry-run
    if(args.dry_run): return 0

    ### Run the postprocessor
    p.run()


def configure(args):
    '''Use setConf() depending on the chosen sample and other settings in args'''
    ### Customize processing variables.
    #setConf("runMELA", False)
    #setConf("bestCandByMELA", False)
    #setConf("APPLYMUCORR", False)
    #setConf("APPLYELECORR", False)

    ## Force filling K factors and weights (default: all off)
    #setConf("APPLY_K_NNLOQCD_ZZGG", 1) # 0:None; 1: NNLO/LO; 2: NNLO/NLO; 3: NLO/LO
    #setConf("APPLY_K_NNLOQCD_ZZQQB", True)
    #setConf("APPLY_K_NNLOEW_ZZQQB", True)
    #setConf("APPLY_QCD_GGF_UNCERT", True)

    setConf("PROCESS_CR", True)
    setConf("PROCESS_ZL", True)
    setConf("DEBUG", False)
    setConf("SYNCMODE", True) # Force muon resolution correction with fixed +1 sigma smearing
    #setConf("ADD_ALLEVENTS", True) # Add extra tree of gen info for all events
    #setConf("FILTER_EVENTS", 'Z') # Store all events which contain a good Z candidate
    #setConf("FILTER_EVENTS", '3L_20_10') # for trigger studies
    #setConf("FILTER_EVENTS", 'NoFilter') # don't skip events with no candidates
    #setConf("TRIGPASSTHROUGH", True) #don't skip events failing triggers
    #setConf("APPLYJETCORR", False)
    #setConf("CANDSTOSTORE",'AllWithRelaxedMuId')

    setConf("store","root://cms-xrd-global.cern.ch/")

    if(args.sample.startswith("Data")):
        # 2022 data sample from /MuonEG/Run2022D-PromptNanoAODv10_v1-v1/NANOAOD
        setConf("IsMC", False)
        setConf("PD", "any")
        if(args.sample == "Data2022"):
            setConf("SAMPLENAME", "test")
            setConf("TRIGPASSTHROUGH", True)
            setConf("LEPTON_SETUP", 2022)
            setConf("fileNames", [
                "/store/data/Run2022D/MuonEG/NANOAOD/PromptNanoAODv10_v2-v1/50000/68f42f42-3274-46ec-b23d-bfadc13012c2.root",
            ])
        else:
            return 1

    elif(args.sample.startswith("MC")):
        setConf("IsMC", True)
        setConf("XSEC", 0.001142)
        if(args.sample == "MC2022preEE"):
            setConf("SAMPLENAME", "ZZto4Ljj_EW")
            setConf("LEPTON_SETUP", 2022)
            setConf("DATA_TAG", "pre_EE")
            setConf("fileNames", [
                "/store/mc/Run3Summer22EENanoAODv12/ZZto4L-2Jets_EW_TuneCP5_13p6TeV_madgraph-pythia8/NANOAODSIM/130X_mcRun3_2022_realistic_postEE_v6-v2/2530000/4f6ffdfe-1ffe-44cb-9632-42d185e1f9a8.root",
            ])
        else:
            return 1

    if(logging.getLogger().isEnabledFor(logging.DEBUG)):
        try:
            from ZZAnalysis.NanoAnalysis.tools import _myConf
        except ImportError as e:
            logging.warning(e)
        else:
            print(json.dumps(_myConf, indent=2))

    return 0


def parse_args():
    parser = ArgumentParser('Run locally the analysis before submitting batch jobs')
    parser.add_argument('sample', choices=["Data2022", "MC2022preEE"], help='Sample to run on')
    parser.add_argument('-d', '--dry-run', action='store_true', help='Configure everything but do not run (for debugging, set --log to INFO or DEBUG)')
    parser.add_argument('-n', '--maxevents', type=int, default=100, help='Max number of events to process. Default: %(default)d.')
    parser.add_argument('--log', dest='loglevel', metavar='LEVEL', default='WARNING', help='Level for the python logging module. Can be either a mnemonic string like DEBUG, INFO or WARNING or an integer (lower means more verbose).')
    args = parser.parse_args()
    return args


if __name__ == '__main__':
    args = parse_args()
    logging.basicConfig(format='%(levelname)s:%(module)s:%(funcName)s: %(message)s',
                        level=args.loglevel.upper() if not args.loglevel.isdigit() else int(args.loglevel))

    exit(main(args))
