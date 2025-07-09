#!/usr/bin/env python3
###
# Example for running the analysis locally, after customizing variables.
# Run with:
# python runLocal.py
###
from argparse import ArgumentParser
import logging
import json
import re
import os
from subprocess import check_output

from ZZAnalysis.AnalysisStep.readSampleInfo import readSampleDB
from ZZAnalysis.NanoAnalysis.tools import setConf, getConf, insertAfter

# Check that the checkout recipe has been properly updated
from ZZAnalysis.AnalysisStep.validateCheckout import validateCheckout
if(not validateCheckout()):
    exit(1)


def main(args):
    args.isMC = True # TODO deduce from file name
    configure_manual()
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

    ### TEMP - Dump config
    if(logging.getLogger().isEnabledFor(logging.DEBUG)):
        try:
            from ZZAnalysis.NanoAnalysis.tools import _myConf
        except ImportError as e:
            logging.warning(e)
        else:
            print(json.dumps(_myConf, indent=2))

    ### Early stop for --dry-run
    if(args.dry_run): return 0

    ### Run the postprocessor
    p.run()


def configure(args):
    '''Use setConf() for using variables retrieved from the CSV'''

    csv_files = get_csvs(args)
    logging.debug('CSVs: %s', csv_files)
    if(len(csv_files) == 0):
        logging.critical('0 valid CSV files found')
        return 1

    for csvfile in csv_files:
        samplesDB = readSampleDB(csvfile)
        sampleInfo = samplesDB.get(args.sample, None)
        if(sampleInfo is not None):
            logging.debug('found sample %s in %s', args.sample, csvfile)
            break
    else:
        logging.critical('sample "%s" not found in any CSV (tried: %s)', args.sample, csv_files)
        return 2
    logging.debug('sampleInfo: %s', sampleInfo)

    setConf('IsMC', args.isMC)
    setConf('XSEC', float(sampleInfo['crossSection']))
    setConf('SAMPLENAME', args.sample)
    for k,v in sampleInfo['::variables'].items():
        setConf(k, v)

    # Get files from the dataset name
    das_cmd = ['dasgoclient', '-query', 'file dataset=%s'%(sampleInfo['dataset'])]
    logging.debug('DAS query: %s', ' '.join(das_cmd))
    das_out = check_output(das_cmd, encoding='utf-8').strip('\n').split('\n')
    logging.debug('DAS result (%d): %s', len(das_out), das_out)

    setConf("fileNames", das_out[0:1]) # just the 1st file is sufficient for a test

    return 0


def configure_manual():
    '''Use setConf() for overrides that we always want (or that we just
    hardcode for simplicity)'''
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


def get_csvs(args):
    base_dir_ZZ = '$CMSSW_BASE/src/ZZAnalysis/NanoAnalysis/test/prod/'
    base_dir_VBS= '$CMSSW_BASE/src/vbs_analysis/4l_channel/test/prod/'
    filepattern = 'samplesNano_{year}_{DataMC}.csv'

    match = re.search(r'(\d+)([^\d].*)?', args.year)
    year_int, year_era = match.groups()
    year_int = int(year_int)
    if(year_era is None): year_era = ''
    year_era_ZZ = year_era

    # In some cases, in the official samples the year without sub-era refers to "before something happended"
    # We chose to be clear: "2022" means the whole year, which is the sum "2022preEE + 2022postEE"
    if(args.isMC):
        if(year_int==2022):
           if  (year_era=='preEE' ): year_era_ZZ = ''
           elif(year_era=='postEE'): year_era_ZZ = 'EE'

    year_ZZ = '%d%s' %(year_int, year_era_ZZ)
    logging.debug('year (args): %s -> year: %d, era: "%s" -> year_ZZ: "%s"', args.year, year_int, year_era, year_ZZ)

    filename_ZZ = filepattern.format(year=year_ZZ  , DataMC='MC' if args.isMC else 'Data')
    filename_VBS= filepattern.format(year=args.year, DataMC='MC' if args.isMC else 'Data')

    paths = []
    for base_dir, filename in [[base_dir_ZZ, filename_ZZ], [base_dir_VBS, filename_VBS]]:
        filepath = os.path.join(os.path.expandvars(base_dir), filename)
        if(os.path.exists(filepath)):
            paths.append(filepath)
        else:
            logging.debug('"%s" does not exist', filepath)

    return paths


def parse_args():
    parser = ArgumentParser('Run locally the analysis before submitting batch jobs')
    parser.add_argument('sample', help='Sample to run on')
    parser.add_argument('-d', '--dry-run', action='store_true', help='Configure everything but do not run (for debugging, set --log to INFO or DEBUG)')
    parser.add_argument('-n', '--maxevents', type=int, default=100, help='Max number of events to process. Default: %(default)d.')
    parser.add_argument('-y', '--year', help='Year, optionally followed by era or specifier (e.g. 2018UL, 2022preEE, etc.)')
    parser.add_argument('--log', dest='loglevel', metavar='LEVEL', default='WARNING', help='Level for the python logging module. Can be either a mnemonic string like DEBUG, INFO or WARNING or an integer (lower means more verbose).')
    args = parser.parse_args()

    return args


if __name__ == '__main__':
    args = parse_args()
    logging.basicConfig(format='%(levelname)s:%(module)s:%(funcName)s: %(message)s',
                        level=args.loglevel.upper() if not args.loglevel.isdigit() else int(args.loglevel))

    exit(main(args))
