################################################################
# Wrapper around the C library cConstants                      #
#                                                              #
# Author: Alberto Mecca (alberto.mecca@cern.ch)                #
# Initial revision: 2025-07-09                                 #
################################################################

import os
from ctypes import CDLL, c_int, c_float

def _find_lib():
    librelpath = '4l_channel/data_driven_MC/ext/cConstants_cc.so'
    if('CMSSW_BASE' in os.environ):
        p = os.path.join(os.path.expandvars('$CMSSW_BASE'), 'src', 'vbs_analysis', librelpath)
        if(os.path.exists(p)):
            return p

    pwd_split = os.getcwd().split(os.sep)
    idx = pwd_split.index('vbs_analysis')
    p = '/'+os.path.join(*pwd_split[:idx+1], librelpath)
    if(os.path.exists(p)):
        return p

    raise RuntimeError('Unable to locate "cConstants_cc.so"')

cConstants = CDLL(_find_lib())
getDVBF2jetsConstant = cConstants.getDVBF2jetsConstant
getDVBF2jetsConstant.argtype = (c_float,)
getDVBF2jetsConstant.restype = c_float

getDVBF2jetsWP = cConstants.getDVBF2jetsWP
getDVBF2jetsWP.argtype = (c_float, c_float)
getDVBF2jetsWP.restype = c_float

get_FSLFO = cConstants.get_FSLFO
get_FSLFO.argtype = (c_int, c_int)
get_FSLFO.restype = c_int # actually an enum

get_fs_ROS_SS = cConstants.get_fs_ROS_SS
get_fs_ROS_SS.argtype = (c_int, ) # actually an enum
get_fs_ROS_SS.restype = c_float
