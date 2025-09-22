#include "../include/pyhelpers.h"
#include "TFile.h"

TObject* get_from_TFile(const char* fname, const char* objname){
  TFile tf(fname);
  if(!tf.IsOpen()) return nullptr;
  auto obj = tf.Get(objname);
  return obj;
}
