#ifndef FAKERATES_H
#define FAKERATES_H

// C++
#include <iostream>
#include <fstream>

// ROOT
#include "TFile.h"
#include "TString.h"
#include "TH1F.h"

using namespace std;

class FakeRates
{

public:
	
	FakeRates( TString );
	~FakeRates();
  float getFRval(float pt, float eta, int id) const;
  float getFRerr(float pt, float eta, int id) const;
  std::pair<float, float> getFR(float pt, float eta, int id) const;
  float GetFakeRate(float pt, float eta, int id) const{
    return getFRval(pt, eta, id);
  }

protected:
  const TH1F* get_hist(float, int) const;

private:
   std::unique_ptr<TH1F> h_m_EB, h_m_EE, h_e_EB, h_e_EE;
};

#endif
