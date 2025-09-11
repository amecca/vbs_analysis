#ifndef CCONSTANTS_H
#define CCONSTANTS_H

extern "C" float getDVBF2jetsConstant(float ZZMass);
extern "C" float getDVBF1jetConstant(float ZZMass);
extern "C" float getDWHhConstant(float ZZMass);
extern "C" float getDZHhConstant(float ZZMass);

extern "C" float getDVBF2jetsWP(float ZZMass, bool useQGTagging);
extern "C" float getDVBF1jetWP(float ZZMass, bool useQGTagging);
extern "C" float getDWHhWP(float ZZMass, bool useQGTagging);
extern "C" float getDZHhWP(float ZZMass, bool useQGTagging);

extern "C" float getDVBF2jetsConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP);
extern "C" float getDVBF1jetConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP);
extern "C" float getDWHhConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP);
extern "C" float getDZHhConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP);

extern "C" float getDbkgkinConstant(int ZZflav, float ZZMass);
extern "C" float getDbkgConstant(int ZZflav, float ZZMass);

extern "C" enum FSLFO {
    /* Lepton flavour with order (i.e. 2e2m != 2m2e) in the final state */
    FSLFO_INVALID = -1,
    FSLFO_4e    = 0,
    FSLFO_4mu   = 1,
    FSLFO_2e2mu = 2,
    FSLFO_2mu2e = 3,
    FSLFO_4l    = 4,
    FSLFO_MAX
  };
  /* Get the Final State in terms of Lepton Flavour (with order, i.e. 2e2mu != 2mu2m)*/
extern "C" enum FSLFO get_FSLFO(int Z1Flav, int Z2Flav);
extern "C" float get_fs_ROS_SS(enum FSLFO f);

#endif
