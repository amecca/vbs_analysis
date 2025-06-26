//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Feb 21 21:47:00 2017 by ROOT version 6.06/00
// from TTree candTree/Event Summary
// found on file: root://lxcms03//data3/Higgs/170203/AllData/ZZ4lAnalysis.root
//////////////////////////////////////////////////////////

#ifndef candTree_h
#define candTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

using namespace std;
class candTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           RunNumber;
   Long64_t        EventNumber;
   Int_t           LumiNumber;
   Short_t         NRecoMu;
   Short_t         NRecoEle;
   Short_t         Nvtx;
   Short_t         NObsInt;
   Float_t         NTrueInt;
   Float_t         PFMET;
   Float_t         PFMETPhi;
   Float_t         PFMETNoHF;
   Float_t         PFMETNoHFPhi;
   Short_t         nCleanedJets;
   Short_t         nCleanedJetsPt30;
   Short_t         nCleanedJetsPt30_jecUp;
   Short_t         nCleanedJetsPt30_jecDn;
   Short_t         nCleanedJetsPt30BTagged;
   Short_t         nCleanedJetsPt30BTagged_bTagSF;
   Short_t         nCleanedJetsPt30BTagged_bTagSFUp;
   Short_t         nCleanedJetsPt30BTagged_bTagSFDn;
   Short_t         trigWord;
   Float_t         ZZMass;
   Float_t         ZZMassErr;
   Float_t         ZZMassErrCorr;
   Float_t         ZZMassPreFSR;
   Short_t         ZZsel;
   Float_t         ZZPt;
   Float_t         ZZEta;
   Float_t         ZZPhi;
   Int_t           CRflag;
   Float_t         Z1Mass;
   Float_t         Z1Pt;
   Short_t         Z1Flav;
   Float_t         ZZMassRefit;
   Float_t         ZZMassRefitErr;
   Float_t         ZZMassUnrefitErr;
   Float_t         Z2Mass;
   Float_t         Z2Pt;
   Short_t         Z2Flav;
   Float_t         costhetastar;
   Float_t         helphi;
   Float_t         helcosthetaZ1;
   Float_t         helcosthetaZ2;
   Float_t         phistarZ1;
   Float_t         phistarZ2;
   Float_t         xi;
   Float_t         xistar;
   vector<float>   *LepPt;
   vector<float>   *LepEta;
   vector<float>   *LepPhi;
   vector<short>   *LepLepId;
   vector<float>   *LepSIP;
   vector<float>   *LepTime;
   vector<bool>    *LepisID;
   vector<short>   *LepisLoose;
   vector<float>   *LepBDT;
   vector<char>    *LepMissingHit;
   vector<float>   *LepCombRelIsoPF;
   vector<float>   *fsrPt;
   vector<float>   *fsrEta;
   vector<float>   *fsrPhi;
   vector<short>   *fsrLept;
   Bool_t          passIsoPreFSR;
   vector<float>   *JetPt;
   vector<float>   *JetEta;
   vector<float>   *JetPhi;
   vector<float>   *JetMass;
   vector<float>   *JetBTagger;
   vector<float>   *JetIsBtagged;
   vector<float>   *JetIsBtaggedWithSF;
   vector<float>   *JetIsBtaggedWithSFUp;
   vector<float>   *JetIsBtaggedWithSFDn;
   vector<float>   *JetQGLikelihood;
   vector<float>   *JetAxis2;
   vector<float>   *JetMult;
   vector<float>   *JetPtD;
   vector<float>   *JetSigma;
   vector<short>   *JetHadronFlavour;
   vector<short>   *JetPartonFlavour;
   vector<float>   *JetJERUp;
   vector<float>   *JetJERDown;
   vector<short>   *JetPUID;
   vector<float>   *JetPUValue;
   Float_t         DiJetMass;
   Float_t         DiJetDEta;
   Float_t         DiJetFisher;
   Short_t         nExtraLep;
   Short_t         nExtraZ;
   vector<float>   *ExtraLepPt;
   vector<float>   *ExtraLepEta;
   vector<float>   *ExtraLepPhi;
   vector<short>   *ExtraLepLepId;
   Float_t         ZXFakeweight;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghza2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghza4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_gha2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_gha4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen;
   Float_t         p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen;
   Float_t         pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal;
   Float_t         p_JVBF_SIG_ghv1_1_JHUGen_JECNominal;
   Float_t         p_JQCD_SIG_ghg2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_gha2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_gha4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal;
   Float_t         p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal;
   Float_t         p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal;
   Float_t         p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghza2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghza4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_gha2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_gha4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal;
   Float_t         p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw2_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw4_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal;
   Float_t         p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal;
   Float_t         p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal;
   Float_t         p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal;
   Float_t         p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal;
   Float_t         p_bbH_SIG_kappa_1_JHUGen_JECNominal;
   Float_t         pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp;
   Float_t         p_JVBF_SIG_ghv1_1_JHUGen_JECUp;
   Float_t         p_JQCD_SIG_ghg2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghza2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghza4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_gha2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_gha4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp;
   Float_t         p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECUp;
   Float_t         p_JJQCD_SIG_ghg4_1_JHUGen_JECUp;
   Float_t         p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghza2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghza4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_gha2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_gha4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp;
   Float_t         p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw2_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw4_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp;
   Float_t         p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp;
   Float_t         p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp;
   Float_t         p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp;
   Float_t         p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp;
   Float_t         p_bbH_SIG_kappa_1_JHUGen_JECUp;
   Float_t         pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn;
   Float_t         p_JVBF_SIG_ghv1_1_JHUGen_JECDn;
   Float_t         p_JQCD_SIG_ghg2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghza2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghza4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_gha2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_gha4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn;
   Float_t         p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECDn;
   Float_t         p_JJQCD_SIG_ghg4_1_JHUGen_JECDn;
   Float_t         p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghza2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghza4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_gha2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_gha4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn;
   Float_t         p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw2_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw4_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn;
   Float_t         p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn;
   Float_t         p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn;
   Float_t         p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn;
   Float_t         p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn;
   Float_t         p_bbH_SIG_kappa_1_JHUGen_JECDn;
   Float_t         p_LepZH_SIG_ghz1_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1prime2_1E4_JHUGen;
   Float_t         p_LepZH_SIG_ghz2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz4_1_JHUGen;
   Float_t         p_LepZH_SIG_ghza1prime2_1E4_JHUGen;
   Float_t         p_LepZH_SIG_ghza2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghza4_1_JHUGen;
   Float_t         p_LepZH_SIG_gha2_1_JHUGen;
   Float_t         p_LepZH_SIG_gha4_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_gha2_1_JHUGen;
   Float_t         p_LepZH_SIG_ghz1_1_gha4_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw1_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw1prime2_1E4_JHUGen;
   Float_t         p_LepWH_SIG_ghw2_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw4_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen;
   Float_t         p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen;
   Float_t         p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen;
   Float_t         p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen;
   Float_t         p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gZPz1_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gZPz2_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz1_1_JHUGen;
   Float_t         p_GG_SIG_gXg2_1_gXz2_1_JHUGen;
   Float_t         p_GG_SIG_gXg3_1_gXz3_1_JHUGen;
   Float_t         p_GG_SIG_gXg4_1_gXz4_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz5_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz6_1_JHUGen;
   Float_t         p_GG_SIG_gXg1_1_gXz7_1_JHUGen;
   Float_t         p_GG_SIG_gXg5_1_gXz8_1_JHUGen;
   Float_t         p_GG_SIG_gXg5_1_gXz9_1_JHUGen;
   Float_t         p_GG_SIG_gXg5_1_gXz10_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen;
   Float_t         p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz1_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz2_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz3_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz4_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz5_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz6_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz7_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz8_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz9_1_JHUGen;
   Float_t         p_INDEPENDENT_SIG_gXz10_1_JHUGen;
   Float_t         pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;
   Float_t         p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;
   Float_t         p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM;
   Float_t         p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM;
   Float_t         pConst_GG_BKG_MCFM;
   Float_t         p_GG_BKG_MCFM;
   Float_t         pConst_QQB_BKG_MCFM;
   Float_t         p_QQB_BKG_MCFM;
   Float_t         p_ZJJ_BKG_MCFM;
   Float_t         p_JJEW_SIG_ghv1_1_MCFM_JECNominal;
   Float_t         p_JJEW_BSI_ghv1_1_MCFM_JECNominal;
   Float_t         p_JJEW_BSI_ghv1_i_MCFM_JECNominal;
   Float_t         p_JJEW_BKG_MCFM_JECNominal;
   Float_t         p_JJVBF_BKG_MCFM_JECNominal;
   Float_t         p_JJQCD_BKG_MCFM_JECNominal;
   Float_t         p_JJEW_SIG_ghv1_1_MCFM_JECUp;
   Float_t         p_JJEW_BSI_ghv1_1_MCFM_JECUp;
   Float_t         p_JJEW_BSI_ghv1_i_MCFM_JECUp;
   Float_t         p_JJEW_BKG_MCFM_JECUp;
   Float_t         p_JJVBF_BKG_MCFM_JECUp;
   Float_t         p_JJQCD_BKG_MCFM_JECUp;
   Float_t         p_JJEW_SIG_ghv1_1_MCFM_JECDn;
   Float_t         p_JJEW_BSI_ghv1_1_MCFM_JECDn;
   Float_t         p_JJEW_BSI_ghv1_i_MCFM_JECDn;
   Float_t         p_JJEW_BKG_MCFM_JECDn;
   Float_t         p_JJVBF_BKG_MCFM_JECDn;
   Float_t         p_JJQCD_BKG_MCFM_JECDn;
   Float_t         p_m4l_SIG;
   Float_t         p_m4l_BKG;
   Float_t         p_m4l_SIG_ScaleDown;
   Float_t         p_m4l_BKG_ScaleDown;
   Float_t         p_m4l_SIG_ResDown;
   Float_t         p_m4l_BKG_ResDown;
   Float_t         p_m4l_SIG_ScaleUp;
   Float_t         p_m4l_BKG_ScaleUp;
   Float_t         p_m4l_SIG_ResUp;
   Float_t         p_m4l_BKG_ResUp;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ;
   Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ;
   Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_LumiNumber;   //!
   TBranch        *b_NRecoMu;   //!
   TBranch        *b_NRecoEle;   //!
   TBranch        *b_Nvtx;   //!
   TBranch        *b_NObsInt;   //!
   TBranch        *b_NTrueInt;   //!
   TBranch        *b_PFMET;   //!
   TBranch        *b_PFMETPhi;   //!
   TBranch        *b_PFMETNoHF;   //!
   TBranch        *b_PFMETNoHFPhi;   //!
   TBranch        *b_nCleanedJets;   //!
   TBranch        *b_nCleanedJetsPt30;   //!
   TBranch        *b_nCleanedJetsPt30_jecUp;   //!
   TBranch        *b_nCleanedJetsPt30_jecDn;   //!
   TBranch        *b_nCleanedJetsPt30BTagged;   //!
   TBranch        *b_nCleanedJetsPt30BTagged_bTagSF;   //!
   TBranch        *b_nCleanedJetsPt30BTagged_bTagSFUp;   //!
   TBranch        *b_nCleanedJetsPt30BTagged_bTagSFDn;   //!
   TBranch        *b_trigWord;   //!
   TBranch        *b_ZZMass;   //!
   TBranch        *b_ZZMassErr;   //!
   TBranch        *b_ZZMassErrCorr;   //!
   TBranch        *b_ZZMassPreFSR;   //!
   TBranch        *b_ZZsel;   //!
   TBranch        *b_ZZPt;   //!
   TBranch        *b_ZZEta;   //!
   TBranch        *b_ZZPhi;   //!
   TBranch        *b_CRflag;   //!
   TBranch        *b_Z1Mass;   //!
   TBranch        *b_Z1Pt;   //!
   TBranch        *b_Z1Flav;   //!
   TBranch        *b_ZZMassRefit;   //!
   TBranch        *b_ZZMassRefitErr;   //!
   TBranch        *b_ZZMassUnrefitErr;   //!
   TBranch        *b_Z2Mass;   //!
   TBranch        *b_Z2Pt;   //!
   TBranch        *b_Z2Flav;   //!
   TBranch        *b_costhetastar;   //!
   TBranch        *b_helphi;   //!
   TBranch        *b_helcosthetaZ1;   //!
   TBranch        *b_helcosthetaZ2;   //!
   TBranch        *b_phistarZ1;   //!
   TBranch        *b_phistarZ2;   //!
   TBranch        *b_xi;   //!
   TBranch        *b_xistar;   //!
   TBranch        *b_LepPt;   //!
   TBranch        *b_LepEta;   //!
   TBranch        *b_LepPhi;   //!
   TBranch        *b_LepLepId;   //!
   TBranch        *b_LepSIP;   //!
   TBranch        *b_LepTime;   //!
   TBranch        *b_LepisID;   //!
   TBranch        *b_LepisLoose;   //!
   TBranch        *b_LepBDT;   //!
   TBranch        *b_LepMissingHit;   //!
   TBranch        *b_LepCombRelIsoPF;   //!
   TBranch        *b_fsrPt;   //!
   TBranch        *b_fsrEta;   //!
   TBranch        *b_fsrPhi;   //!
   TBranch        *b_fsrLept;   //!
   TBranch        *b_passIsoPreFSR;   //!
   TBranch        *b_JetPt;   //!
   TBranch        *b_JetEta;   //!
   TBranch        *b_JetPhi;   //!
   TBranch        *b_JetMass;   //!
   TBranch        *b_JetBTagger;   //!
   TBranch        *b_JetIsBtagged;   //!
   TBranch        *b_JetIsBtaggedWithSF;   //!
   TBranch        *b_JetIsBtaggedWithSFUp;   //!
   TBranch        *b_JetIsBtaggedWithSFDn;   //!
   TBranch        *b_JetQGLikelihood;   //!
   TBranch        *b_JetAxis2;   //!
   TBranch        *b_JetMult;   //!
   TBranch        *b_JetPtD;   //!
   TBranch        *b_JetSigma;   //!
   TBranch        *b_JetHadronFlavour;   //!
   TBranch        *b_JetPartonFlavour;   //!
   TBranch        *b_JetJERUp;   //!
   TBranch        *b_JetJERDown;   //!
   TBranch        *b_JetPUID;   //!
   TBranch        *b_JetPUValue;   //!
   TBranch        *b_DiJetMass;   //!
   TBranch        *b_DiJetDEta;   //!
   TBranch        *b_DiJetFisher;   //!
   TBranch        *b_nExtraLep;   //!
   TBranch        *b_nExtraZ;   //!
   TBranch        *b_ExtraLepPt;   //!
   TBranch        *b_ExtraLepEta;   //!
   TBranch        *b_ExtraLepPhi;   //!
   TBranch        *b_ExtraLepLepId;   //!
   TBranch        *b_ZXFakeweight;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghza2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghza4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_gha2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_gha4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen;   //!
   TBranch        *b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JVBF_SIG_ghv1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JQCD_SIG_ghg2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_gha2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_gha4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghza2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghza4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_gha2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_gha4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal;   //!
   TBranch        *b_p_bbH_SIG_kappa_1_JHUGen_JECNominal;   //!
   TBranch        *b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JVBF_SIG_ghv1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JQCD_SIG_ghg2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghza2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghza4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_gha2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_gha4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJQCD_SIG_ghg4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghza2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghza4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_gha2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_gha4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp;   //!
   TBranch        *b_p_bbH_SIG_kappa_1_JHUGen_JECUp;   //!
   TBranch        *b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JVBF_SIG_ghv1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JQCD_SIG_ghg2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghza2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghza4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_gha2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_gha4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJQCD_SIG_ghg4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghza2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghza4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_gha2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_gha4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn;   //!
   TBranch        *b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn;   //!
   TBranch        *b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn;   //!
   TBranch        *b_p_bbH_SIG_kappa_1_JHUGen_JECDn;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghza1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghza2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghza4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_gha2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_gha4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_gha2_1_JHUGen;   //!
   TBranch        *b_p_LepZH_SIG_ghz1_1_gha4_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw2_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw4_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen;   //!
   TBranch        *b_p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gZPz1_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gZPz2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz1_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg2_1_gXz2_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg3_1_gXz3_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg4_1_gXz4_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz6_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg1_1_gXz7_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg5_1_gXz8_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg5_1_gXz9_1_JHUGen;   //!
   TBranch        *b_p_GG_SIG_gXg5_1_gXz10_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen;   //!
   TBranch        *b_p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz1_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz2_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz3_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz4_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz5_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz6_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz7_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz8_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz9_1_JHUGen;   //!
   TBranch        *b_p_INDEPENDENT_SIG_gXz10_1_JHUGen;   //!
   TBranch        *b_pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;   //!
   TBranch        *b_p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;   //!
   TBranch        *b_p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM;   //!
   TBranch        *b_p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM;   //!
   TBranch        *b_pConst_GG_BKG_MCFM;   //!
   TBranch        *b_p_GG_BKG_MCFM;   //!
   TBranch        *b_pConst_QQB_BKG_MCFM;   //!
   TBranch        *b_p_QQB_BKG_MCFM;   //!
   TBranch        *b_p_ZJJ_BKG_MCFM;   //!
   TBranch        *b_p_JJEW_SIG_ghv1_1_MCFM_JECNominal;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_1_MCFM_JECNominal;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_i_MCFM_JECNominal;   //!
   TBranch        *b_p_JJEW_BKG_MCFM_JECNominal;   //!
   TBranch        *b_p_JJVBF_BKG_MCFM_JECNominal;   //!
   TBranch        *b_p_JJQCD_BKG_MCFM_JECNominal;   //!
   TBranch        *b_p_JJEW_SIG_ghv1_1_MCFM_JECUp;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_1_MCFM_JECUp;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_i_MCFM_JECUp;   //!
   TBranch        *b_p_JJEW_BKG_MCFM_JECUp;   //!
   TBranch        *b_p_JJVBF_BKG_MCFM_JECUp;   //!
   TBranch        *b_p_JJQCD_BKG_MCFM_JECUp;   //!
   TBranch        *b_p_JJEW_SIG_ghv1_1_MCFM_JECDn;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_1_MCFM_JECDn;   //!
   TBranch        *b_p_JJEW_BSI_ghv1_i_MCFM_JECDn;   //!
   TBranch        *b_p_JJEW_BKG_MCFM_JECDn;   //!
   TBranch        *b_p_JJVBF_BKG_MCFM_JECDn;   //!
   TBranch        *b_p_JJQCD_BKG_MCFM_JECDn;   //!
   TBranch        *b_p_m4l_SIG;   //!
   TBranch        *b_p_m4l_BKG;   //!
   TBranch        *b_p_m4l_SIG_ScaleDown;   //!
   TBranch        *b_p_m4l_BKG_ScaleDown;   //!
   TBranch        *b_p_m4l_SIG_ResDown;   //!
   TBranch        *b_p_m4l_BKG_ResDown;   //!
   TBranch        *b_p_m4l_SIG_ScaleUp;   //!
   TBranch        *b_p_m4l_BKG_ScaleUp;   //!
   TBranch        *b_p_m4l_SIG_ResUp;   //!
   TBranch        *b_p_m4l_BKG_ResUp;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ;   //!
   TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ;   //!
   TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ;   //!

   candTree(TTree *tree=0);
   virtual ~candTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif
