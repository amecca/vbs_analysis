# HZZ4l-plotter

Developed originally in CMSSW_8_0_21 as a [standalone package](https://github.com/mkovac/HZZ4l-plotter) by Marko Kovac,
then in CMSSW_8_0_24_patch1 by Meng Xiao [here](https://github.com/meng-xiao/HZZ4l-plotter),
integrated (with CMSSW_8_0_26_patch1) in [vbs_analysis](https://github.com/cthorbur/vbs_analysis) by cthorbur
and maintained by Roberto Covarelli [here](https://github.com/covarell/vbs_analysis/tree/master).
Ported to CMSSW_13_3_3 by Alberto Mecca.

## Compilation:
```
source set_library.sh
make
```
Note that every time you add something in the code you need to recompile the code with make again.

## Running:
The discriminant is defined in `src/run_makeZX.cpp` and all changes must be done in this file.
```
./run_makeZX <year> <enrichment>
```

The enrichment variable refers to the selection:
* 0 = baseline,
* 1 = VBS-enriched (loose),
* 2 = VBS-enriched (tight with DeltaEta),
* 3 = background enriched,
* 4 = tighter pTjet cut (50 GeV),
* 5 = VBS-enriched (tight with mjj).

The necessary variables (ZZMass, dbkg_kin, weight etc.) will be stored in the file `ZX<year>.root`.
