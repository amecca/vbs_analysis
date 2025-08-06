#!/usr/bin/env python3

################################################################
# Produce ntuples describing the ZX background from the ZZ-    #
# processed NanoAOD files. Apparently we use the SS method     #
#                                                              #
# Author: Alberto Mecca (alberto.mecca@cern.ch)                #
# Initial revision: 2025-07-09                                 #
################################################################

import os
import sys
from argparse import ArgumentParser
import logging

import ROOT
from ROOT.RDF import TH1DModel
VariationsFor = ROOT.RDF.Experimental.VariationsFor

sys.path.append(os.path.realpath('../python')) # See nano2hist.py for an explaination
from utils import TFileContext, FinalState, Channel
from FRhelper import FRhelper

CUTS = {
    'fid_region': 'ZZ_mass > 180 &&\
DiJet_mass > 100 && nCleanedJetsPt30 > 1 && \
ZZ_Z1mass < 120 && ZZ_Z1mass > 60 && \
ZZ_Z2mass < 120 && ZZ_Z2mass > 60',
}


# Constants specific for this script
_fs_ROS_SS = {
    FinalState.fs4mu  : 1.04,
    FinalState.fs4e   : 1.01,
    FinalState.fs2e2mu: 1.04,
    FinalState.fs2mu2e: 1.00
}

_c_constant = 14.0

_paths = {
    "FR": {
        "2016": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIILegacy/200205_CutBased/FRfiles/FakeRates_SS_2016.root",
        "2017": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIILegacy/200205_CutBased/FRfiles/FakeRates_SS_2017.root",
        "2018": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIILegacy/200205_CutBased/FRfiles/FakeRates_SS_2018.root",
        "2022preEE": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIII_byZ1Z2/FRfiles/FakeRates_SS_2022.root",
        "2022postEE": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIII_byZ1Z2/FRfiles/FakeRates_SS_2022EE.root",
        "2023preBPix": None,
        "2023postBPix": None,
        "2024": None,
    },
    "data": {
        "2016": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIILegacy/200205_CutBased/Data_2016/AllData/ZZ4lAnalysis.root",
        "2017": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIILegacy/200205_CutBased/Data_2017/AllData/ZZ4lAnalysis.root",
        "2018": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIILegacy/200205_CutBased/Data_2018/AllData/ZZ4lAnalysis.root",
        "2022preEE": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIII_byZ1Z2/240820/2022/Data/ZZ4lAnalysis.root",
        "2022postEE": "/eos/cms/store/group/phys_higgs/cmshzz4l/cjlst/RunIII_byZ1Z2/240820/2022EE/Data/AllData_2022EE.root",
        "2023preBPix": None,
        "2023postBPix": None,
        "2024": None,
    },
    "KDconstants": {
        "13TeV": "$CMSSW_BASE/src/ZZAnalysis/AnalysisStep/data/cconstants/SmoothKDConstant_m4l_DjjVBF13TeV.root",
        "13p6TeV": None
    }
}


def main(args):
    logging.debug('args: %s', args)

    ROOT.EnableImplicitMT()

    # Get the lepton fake rates
    frHelper = FRhelper(_paths["FR"][args.year])

    # Get the Events tree
    df = ROOT.RDataFrame('Events', args.fname_in)

    if(args.list_columns):
        print(df.Describe())
        return 0

    # Load external C/C++ functions
    ROOT.gInterpreter.Load('../data_driven_MC/ext/cConstants_cc.so')

    # Run the analysis
    status = produce(df, args)

    logging.info('wrote tree to to "%s"', args.fname_out)

    return status


def parse_args():
    parser = ArgumentParser('Produce the ZX background estimation from data NanoAOD from ZZ (Run 3)',
                            epilog='outputs a ROOT file with a TTree akin to the result '
                            'of the legacy run_makeZX.cpp')
    parser.add_argument('fname_in', metavar='FILE', help='Input: (post-processed) NanoAOD file')
    parser.add_argument('-o', '--output', default='ZX.root', dest='fname_out', metavar='FILE', help='Default: %(default)s')
    parser.add_argument('-y', '--year', default='2018', help='Year and possibly era (e.g. "2018", "2022preEE", ...). Default: %(default)s')
    parser.add_argument(      '--list', dest='list_columns', action='store_true', help='List the columns present in the input file and exit')
    parser.add_argument('--log', dest='loglevel', metavar='LEVEL', default='WARNING', help='Level for the python logging module. Can be either a mnemonic string like DEBUG, INFO or WARNING or an integer (lower means more verbose).')

    args = parser.parse_args()
    return args


def produce(df, args):
    # Preliminary cuts: are we in the CR?
    logging.info('Total events: %d', df.Count().GetValue())
    df = df.Filter('ZLLbestSSIdx >= 0', 'has_ZLL_SS')

    # Aliases
    df = df.Define('ZZ_mass'  , 'ZLLCand_mass[ZLLbestSSIdx]')
    df = df.Define('ZZ_Z1mass', 'ZLLCand_Z1mass[ZLLbestSSIdx]')
    df = df.Define('ZZ_Z2mass', 'ZLLCand_Z2mass[ZLLbestSSIdx]')

    # TEMP
    df = df.Define('DiJet_mass', '101')
    logging.warning('DiJet_mass is hardcoded. TODO compute it')
    df = df\
        .Redefine('nCleanedJetsPt30_jesDn', '(Char_t)(nCleanedJetsPt30-(Char_t)1)')\
        .Redefine('nCleanedJetsPt30_jesUp', '(Char_t)(nCleanedJetsPt30+(Char_t)1)')

    # SYSTEMATICS
    df = df.Vary('nCleanedJetsPt30', 'ROOT::RVecC{nCleanedJetsPt30_jesDn, nCleanedJetsPt30_jesUp}', ['dn', 'up'], 'jes')
    h_njets_centr = df.Histo1D("nCleanedJetsPt30")
    h_njets_systs = VariationsFor(h_njets_centr)

    # CUT 1 fiducial region
    df = df.Filter(CUTS['fid_region'], 'fid_region')

    # Define variables to be written out
    columns_out = []
    df = df.Define('ZZ_mass_diff', 'ZZCand_mass - GenZZ_mass')
    columns_out.append('ZZ_mass_diff')

    df = df.Define('c_Mela2j', 'getDVBF2jetsConstant(ZZ_mass)')
    df = df.Define('WP_VBF2j', 'getDVBF2jetsWP(ZZ_mass, 0)')
    columns_out.extend(['c_Mela2j', 'WP_VBF2j'])
    # TODO work here

    logging.info("Finished setting up the analysis")

    # End
    df.Report().GetValue().Print()

    df.Snapshot('candTree', args.fname_out, columns_out)
    logging.info('Wrote output tree to "%s" (%d entries)', args.fname_out, df.Count().GetValue())

    # Write debug histograms
    tf = ROOT.TFile("ZX_debug.root", "RECREATE")
    tf.cd()
    h_njets_systs['nominal'].Write()
    h_njets_systs['jes:up' ].Write('nCleanedJetsPt30_jes_up'  )
    h_njets_systs['jes:dn' ].Write('nCleanedJetsPt30_jes_down')
    tf.Close()

    return 0


if __name__ == '__main__':
    args = parse_args()
    loglevel = args.loglevel.upper() if not args.loglevel.isdigit() else int(args.loglevel)
    logging.basicConfig(format='%(levelname)s:%(module)s:%(funcName)s: %(message)s', level=loglevel)

    exit(main(args))
