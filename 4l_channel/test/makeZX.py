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
from utils import TFileContext, FinalState, Channel, write_resultmap
from cConstants import get_FSLFO, get_fs_ROS_SS

CUTS = {
    'fid_region': 'ZZ_mass > 180 &&\
DiJet_mass > 100 && nCleanedJetsPt30 > 1 && \
ZZ_Z1mass < 120 && ZZ_Z1mass > 60 && \
ZZ_Z2mass < 120 && ZZ_Z2mass > 60',
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

    if(args.multithread): ROOT.EnableImplicitMT()

    # Get the Events tree
    df = ROOT.RDataFrame('Events', args.fname_in)

    if(args.list_columns):
        print(df.Describe())
        return 0

    # Load external C/C++ functions
    err = ROOT.gInterpreter.Load('../data_driven_MC/ext/FakeRates_cpp.so')
    if(err!=0):
        logging.critical('Failure loading FakeRates_cpp.so')
        return 2
    logging.debug('Loaded FakeRates_cpp.so')
    ok  = ROOT.gInterpreter.Declare('#include "../data_driven_MC/include/FakeRates.h"')
    if(not ok): return 2
    logging.debug('Included FakeRates.h')

    err = ROOT.gInterpreter.Load('../data_driven_MC/ext/pyhelpers_cc.so')
    if(err!=0):
        logging.critical('Failure loading pyhelpers_cc.so')
        return 2
    logging.debug('Loaded pyhelpers_cc.so')
    ok  = ROOT.gInterpreter.Declare('#include "../data_driven_MC/include/pyhelpers.h"')
    if(not ok): return 2
    logging.debug('Included pyhelpers.h')

    # Initialize helper objects (lepton fake rates)
    lepFR_file = _paths["FR"][args.year]
    logging.info('lep FR file: %s', lepFR_file)
    ROOT.gInterpreter.Declare('FakeRates frHelper("%s");' %(lepFR_file))
    ROOT.gInterpreter.Calc(r'printf("DEBUG: frHelper = %p\n", &frHelper);')

    spline_file = _paths["KDconstants"]["13TeV"]
    logging.info('spline file: %s', spline_file)
    ROOT.gInterpreter.Declare('auto splineKD = dynamic_cast<TSpline*>( get_from_TFile("%s", "%s") );'%(spline_file, 'sp_gr_varReco_Constant_Smooth'))
    ROOT.gInterpreter.Calc(r'printf("DEBUG: splineKD = %p\n", splineKD);')

    # Run the analysis
    status = produce(df, args)

    logging.info('wrote tree to to "%s"', args.fname_out)

    # Cleanup
    ROOT.gInterpreter.Calc(r'delete splineKD;')

    return status


def parse_args():
    parser = ArgumentParser('Produce the ZX background estimation from data NanoAOD from ZZ (Run 3)',
                            epilog='outputs a ROOT file with a TTree akin to the result '
                            'of the legacy run_makeZX.cpp')
    parser.add_argument('fname_in', metavar='FILE', help='Input: (post-processed) NanoAOD file')
    parser.add_argument('-o', '--output', default='ZX.root', dest='fname_out', metavar='FILE', help='Default: %(default)s')
    parser.add_argument('-y', '--year', default='2018', help='Year and possibly era (e.g. "2018", "2022preEE", ...). Default: %(default)s')
    parser.add_argument(      '--list', dest='list_columns', action='store_true', help='List the columns present in the input file and exit')
    parser.add_argument(      '--mt', dest='multithread', action='store_true', help='Enable ROOT implicit multithread (output entries will not be ordered)')
    parser.add_argument('--log', dest='loglevel', metavar='LEVEL', default='WARNING', help='Level for the python logging module. Can be either a mnemonic string like DEBUG, INFO or WARNING or an integer (lower means more verbose).')

    args = parser.parse_args()
    return args


def produce(df, args):
    # Preliminary cuts: are we in the CR?
    logging.info('Total events: %d', df.Count().GetValue())
    df = df.Filter('ZLLbestSSIdx >= 0', 'has_ZLL_SS')
    lepZZ = ['Z%dl%d' %(Z,l) for Z in (1,2) for l in (1,2)] # names of the leptons in the ZZ

    # Aliases
    df = df.Define('ZZ_mass'  , 'ZLLCand_mass[ZLLbestSSIdx]')
    df = df.Define('ZZ_Z1mass', 'ZLLCand_Z1mass[ZLLbestSSIdx]')
    df = df.Define('ZZ_Z2mass', 'ZLLCand_Z2mass[ZLLbestSSIdx]')
    df = df.Define('ZZ_Z1flav', 'ZLLCand_Z1flav[ZLLbestSSIdx]')
    df = df.Define('ZZ_Z2flav', 'ZLLCand_Z2flav[ZLLbestSSIdx]')

    for l in lepZZ:
        df = df.Define('%s_Idx' %(l), 'ZLLCand_%sIdx[ZLLbestSSIdx]' %(l))

    # Intermediates
    df = df.Define('FSLFO', 'get_FSLFO(ZZ_Z1flav, ZZ_Z2flav)')
    df = df.Define('fs_ROS_SS', 'get_fs_ROS_SS(FSLFO)')

    # TODO split by lepton flavour
    # TODO heavy lifting in C/C++
    lepFR_w_names = []
    for l in lepZZ:
        name  = 'weight_FR_%s'    %(l)
        vname = 'weight_FRval_%s' %(l)
        ename = 'weight_FRunc_%s' %(l)
        FRargs = 'Lepton_pt[{0}], Lepton_eta[{0}], Lepton_pdgId[{0}]'.format(l+'_Idx')
        df = df.Define(name , 'frHelper.getFR(%s)'%(FRargs))
        df = df.Define(vname, '%s.first'  %(name))
        df = df.Define(ename, '%s.second' %(name))
        df = df.Vary(vname, 'ROOT::RVecF{{ {0}-{1}, {0}+{1} }}'.format(vname, ename), ['Down', 'Up'], 'fake_l')
        lepFR_w_names.append(vname)

    df = df.Define('weight_FRval_Z1', 'weight_FRval_Z1l1*weight_FRval_Z1l2')
    df = df.Define('weight_FRval_Z2', 'weight_FRval_Z2l1*weight_FRval_Z2l2')

    wFR_def = '*'.join(lepFR_w_names)
    logging.debug(wFR_def)
    df = df.Define('weight_FR', wFR_def)
    df = df.Define('weight', 'overallEventWeight * fs_ROS_SS * weight_FR')

    # TEMP
    df = df.Define('DiJet_mass', '101')
    logging.warning('DiJet_mass is hardcoded. TODO compute it')
    df = df\
        .Redefine('nCleanedJetsPt30_jesDn', '(Char_t)(nCleanedJetsPt30-(Char_t)1)')\
        .Redefine('nCleanedJetsPt30_jesUp', '(Char_t)(nCleanedJetsPt30+(Char_t)1)')

    # SYSTEMATICS
    systs = []
    df = df.Vary('nCleanedJetsPt30', 'ROOT::RVecC{nCleanedJetsPt30_jesDn, nCleanedJetsPt30_jesUp}', ['Down', 'Up'], 'jes')
    systs.append(VariationsFor(df.Histo1D("nCleanedJetsPt30")))
    systs.append(VariationsFor(df.Histo1D("weight_FR")))

    for Z in (1,2):
        systs.append(VariationsFor(df.Histo1D('weight_FRval_Z%d'%(Z))))
    for l in lepZZ:
        systs.append(VariationsFor(df.Histo1D('weight_FRval_%s'%(l))))

    systs.append(VariationsFor(df.Histo1D("weight")))
    h_logw = df.Define("log_weight", "log(weight)").Histo1D("log_weight")
    systs.append(VariationsFor(h_logw))

    # CUT 1 fiducial region
    df = df.Filter(CUTS['fid_region'], 'fid_region')

    # Define variables to be written out
    columns_out = []
    df = df.Define('ZZ_mass_diff', 'ZZCand_mass - GenZZ_mass')
    columns_out.append('ZZ_mass_diff')

    df = df.Define('c_Mela2j', 'getDVBF2jetsConstant(ZZ_mass)')
    df = df.Define('WP_VBF2j', 'getDVBF2jetsWP(ZZ_mass, 0)')
    columns_out.extend(['c_Mela2j', 'WP_VBF2j'])

    df = df.Define('c_mzz', '{c_constant}*splineKD->Eval(ZZ_mass)'.format(c_constant=_c_constant))
    systs.append(VariationsFor(df.Histo1D("c_mzz")))
    # TODO work here

    logging.info("Finished setting up the analysis")

    # End
    df.Report().GetValue().Print()

    df.Snapshot('candTree', args.fname_out, columns_out)
    logging.info('Wrote output tree to "%s" (%d entries)', args.fname_out, df.Count().GetValue())

    # Write debug histograms
    tf = ROOT.TFile("ZX_debug.root", "RECREATE")
    tf.cd()
    for hdict in systs:
        write_resultmap(hdict)
    tf.Close()

    return 0


if __name__ == '__main__':
    args = parse_args()
    loglevel = args.loglevel.upper() if not args.loglevel.isdigit() else int(args.loglevel)
    logging.basicConfig(format='%(levelname)s:%(module)s:%(funcName)s: %(message)s', level=loglevel)

    exit(main(args))
