# Utiltiies, constants and enums
from enum import Enum
import ROOT


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


class FinalState(Enum):
    fs4e = 0
    fs4mu = 1
    fs2e2mu = 2
    fs2mu2e = 3
    fs4l = 4


class Channel(Enum):
    NONE = 0
    ch4mu = 1
    ch4e = 2
    ch2e2mu = 3

    @classmethod
    def from_fs(cls, fs):
        if  (fs == FinalState.fs4mu): return cls(Channel.ch4mu)
        elif(fs == FinalState.fs4e ): return cls(Channel.ch4e )
        elif(fs==FinalState.fs2e2mu or fs==FinalState.fs2mu2e): return cls(Channel.ch2e2mu)
        else: return cls(Channel.NONE)
