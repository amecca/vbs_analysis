######################################################################
# Python equivalent of 4l_channel/data_driven_MC/include/FakeRates.h #
#                                                                    #
# Author: Alberto Mecca (alberto.mecca@cern.ch)                      #
# Initial revision: 2025-08-06                                       #
######################################################################
import logging
from array import array
import ROOT

from utils import TFileContext


class FRhelper:
    '''
    `TH1`s are much handier (e.g. FindFix()) for retrieving binned values
    '''
    def __init__(self, fname: str):
        logging.debug('opening "%s"', fname)
        with TFileContext(fname) as tf:
            self.h_m_EB = FRhelper._h_from_tge(tf.Get("FR_SS_muon_EB")    )
            self.h_m_EE = FRhelper._h_from_tge(tf.Get("FR_SS_muon_EE")    )
            self.h_e_EB = FRhelper._h_from_tge(tf.Get("FR_SS_electron_EB"))
            self.h_e_EE = FRhelper._h_from_tge(tf.Get("FR_SS_electron_EE"))

    @staticmethod
    def _h_from_tge(g):
        n = g.GetN()
        edges = []
        values = []
        errors = []
        logging.debug('converting "%s"', g.GetName())
        for i in range(n):
            last = edges[-1] if len(edges) > 0 else None
            px = g.GetPointX(i)
            py = g.GetPointY(i)
            ex = g.GetErrorX(i)
            ey = g.GetErrorY(i)
            # logging.debug("%d - x = %.3g +- %.3g  y = %.3g +- %.3g", i, px, ex, py, ey)
            px_ex = px - ex
            if(last is not None):
                if(px_ex - last > 1e-7):
                    logging.warning("edge discrepancy: last=%.3g, x-ex=%.3g (diff=%.3g)", last, px_ex, px_ex-last)
            else:
                edges.append(px_ex)
            edges.append(px + ex)
            values.append(py)
            errors.append(ey)

        h = ROOT.TH1F(g.GetName(), g.GetTitle(), n, array('d', edges))
        h.SetDirectory(0) # ROOT deletes TH1 objects created while a TFile is open, when closing it
        for i, (v, e) in enumerate(zip(values, errors)):
            # logging.debug("%d - y = %.3g +- %.3g", i+1, v, e)
            h.SetBinContent(i+1, v)
            h.SetBinError(i+1, e)
        # Set the under/overflow value and error equal to the first/last bin - simplifies getFR
        h.SetBinContent(0, values[0])
        h.SetBinError  (0, errors[0])
        h.SetBinContent(n+1, values[-1])
        h.SetBinError  (n+1, errors[-1])
        return h

    def getFRval(self, pt: float, eta: float, id: int):
        h = self._get_hist(eta, id)
        b = h.FindFixBin(pt)
        return h.GetBinContent(b)

    def getFRunc(self, pt: float, eta: float, id: int):
        h = self._get_hist(eta, id)
        b = h.FindFixBin(pt)
        return h.GetBinError(b)

    def getFR(self, pt: float, eta: float, id: int):
        h = self._get_hist(eta, id)
        b = h.FindFixBin(pt)
        v = h.GetBinContent(b)
        e = h.GetBinError(b)
        # logging.debug('pt: %.3g, eta: %.3g, id: %d -> b: %d, %.3g +- %.3g', pt, eta, id, b, v, e)
        return v, e

    def _get_hist(self, eta, id):
        aid = abs(id)
        barrel = abs(eta) < 1.479
        if  (aid == 11):
            return self.h_e_EB if barrel else self.h_e_EE
        elif(aid == 13):
            return self.h_m_EB if barrel else self.h_m_EE
        else:
            raise KeyError("Unknow ID for lepton: %d" %(id))
