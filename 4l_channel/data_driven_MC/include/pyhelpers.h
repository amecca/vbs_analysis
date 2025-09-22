#ifndef PYHELPERS
#define PYHELPERS

#include "TObject.h"

TObject* get_from_TFile(const char* fname, const char* objname);

#endif
