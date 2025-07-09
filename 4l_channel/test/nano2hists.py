#!/usr/bin/env python3

################################################################
# Run the VBS ZZ analysis on NanoAOD files                     #
#                                                              #
# Author: Alberto Mecca (alberto.mecca@cern.ch)                #
# Initial revision: 2025-07-09                                 #
################################################################

from argparse import ArgumentParser
import logging

import ROOT
from ROOT.RDF import TH1DModel


class TFileContext(object):
    '''Allows using a TFile in a with satatement'''
    def __init__(self, *args):
        self.tfile = ROOT.TFile(*args)
        if(not (self.tfile and self.tfile.IsOpen())):
            raise FileNotFoundError(args[0] if len(args) > 0 else '')

    def __enter__(self):
        return self.tfile

    def __exit__(self, exc_type, exc_value, traceback):
        self.tfile.Close()


def main(args):
    logging.debug('args: %s', args)

    ROOT.EnableImplicitMT()

    # Get the Events tree
    df = ROOT.RDataFrame('Events', args.fname_in)

    if(args.list_columns):
        print(df.Describe())
        return 0

    # Run the analysis
    histograms = analyze(df, args)

    # Write histograms
    with TFileContext(args.fname_out, 'RECREATE') as tf_out:
        for hist in histograms:
            hname = hist.GetName()
            if('/' in hname):
                raise NotImplementedError('Automatic creation of TDirectories')
            hist.Write()
    logging.info('wrote histograms to "%s"', args.fname_out)

    return 0


def parse_args():
    parser = ArgumentParser('Run the VBS ZZjj analysis on a NanoAOD file from ZZ (Run 3)',
                            epilog='outputs ROOT files with histograms. For efficiency, '
                            'the fancy plot formatting is in a separate step')
    parser.add_argument('fname_in', metavar='FILE', help='Input: (post-processed) NanoAOD file')
    parser.add_argument('-o', '--output', dest='fname_out')
    parser.add_argument(      '--list', dest='list_columns', action='store_true', help='List the columns present in the input file and exit')
    parser.add_argument('--log', dest='loglevel', metavar='LEVEL', default='WARNING', help='Level for the python logging module. Can be either a mnemonic string like DEBUG, INFO or WARNING or an integer (lower means more verbose).')

    return parser.parse_args()


def analyze(df, args):
    futures = [] # <ROOT.RDF.RResultPtr>
    histograms = [] # <ROOT.TH1F>

    def mkhist(*model_args, v=None, w='overallEventWeight'):
        logging.debug('model_args: %s', model_args)
        model = TH1DModel(*model_args)
        return df.Histo1D(model, model.fName if v is None else v, w)

    # GenZZ_mass
    # futures.append(df.Histo1D(TH1DModel('GenZZ_mass', '', 60,100,700), 'GenZZ_mass'))
    futures.append(mkhist('GenZZ_mass', '', 60,100,700))
    futures.append(mkhist('ZZCand_mass', '', 60,100,700))

    df = df.Define('ZZ_mass_diff', 'ZZCand_mass - GenZZ_mass')
    futures.append(mkhist('ZZ_mass_diff', '', 60,-60,60))

    # futures.append(df.Histo1D(TH1DModel('ZZ_mass_diff', '', 60,100,700), 'ZZcand_mass - GenZZ_mass'))
    logging.info("Finished setting up the analysis")

    histograms = [f.GetValue() for f in futures]
    df.Report().GetValue().Print()

    return histograms


if __name__ == '__main__':
    args = parse_args()
    loglevel = args.loglevel.upper() if not args.loglevel.isdigit() else int(args.loglevel)
    logging.basicConfig(format='%(levelname)s:%(module)s:%(funcName)s: %(message)s', level=loglevel)

    exit(main(args))
