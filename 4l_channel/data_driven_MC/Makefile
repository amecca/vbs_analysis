#makefile

CXXFLAGS = -g -I. -m64 $(shell root-config --cflags) -I include
LDFLAGS = $(shell root-config --libs) -lm -lGenVector
CXX = g++

EXTLIBS = ./ext/cConstants_cc.so ./ext/FinalStates_cc.so ./ext/bitops_cc.so ./ext/Discriminants_cc.so

VPATH = ./src/ ./include/

SRCPP_PLOTTER = run_plotter.cpp\
                Plotter.cpp\
                Histograms.cpp\
                Variables.cpp\
                Tree.cpp\
                Settings.cpp\
                M4lZX.cpp\
                FakeRates.cpp\
                Category.cpp\
                ZXVariables.cpp\
                CMS_lumi.cpp\
                Cosmetics.cpp

SRCPP_YIELDS = run_yields.cpp\
					Yields.cpp\
					Histograms.cpp\
					Variables.cpp\
					Tree.cpp\
					Settings.cpp\
					M4lZX.cpp\
					FakeRates.cpp\
					Category.cpp\
					ZXVariables.cpp\
					CMS_lumi.cpp
SRCPP_MAKEZX = run_makeZX.cpp\
					Settings.cpp\
					FakeRates.cpp\
					Category.cpp\
					candTree.cpp

INCLUDES = Plotter.h\
			  Yields.h\
			  Histograms.h\
			  Variables.h\
			  Tree.h\
			  candTree.h\
			  Settings.h\
			  M4lZX.h\
			  FakeRates.h\
			  Category.h\
			  ZXVariables.h\
			  CMS_lumi.h


OBJCPP_PLOTTER = $(patsubst %.cpp,obj/%.o,$(SRCPP_PLOTTER))
OBJCPP_YIELDS = $(patsubst %.cpp,obj/%.o,$(SRCPP_YIELDS))
OBJCPP_MAKEZX = $(patsubst %.cpp,obj/%.o,$(SRCPP_MAKEZX))


# Default target
all: run_makeZX run_yields run_plotter
.PHONY: all

# Do not search for rule for source files
Makefile: ;
%.cpp: ;

# Rules
obj:
	mkdir -p $@

obj/%.o: %.cpp $(INCLUDES) | obj
	@echo ">> compiling $*"
	$(CXX) -c $< ${CXXFLAGS} -o $@

run_plotter: $(OBJCPP_PLOTTER) $(EXTLIBS)
	@echo ">> linking..."
	$(CXX) $^ ${LDFLAGS} ${CXXFLAGS} -o $@

run_yields: $(OBJCPP_YIELDS) $(EXTLIBS)
	@echo ">> linking..."
	$(CXX) $^ ${LDFLAGS} ${CXXFLAGS} -o $@

run_makeZX: $(OBJCPP_MAKEZX) $(EXTLIBS)
	@echo ">> linking..."
	$(CXX) $^ ${LDFLAGS} ${CXXFLAGS} -o $@

# The ext libraries always depend on the phony target ext (always outdated),
# which just runs `make` in that subdirectory.
# "&:" -> gruped targets, i.e. this rule makes all of them at once
$(EXTLIBS) &: ext
	@: # does nothing

ext:
	$(MAKE) -C ext
.PHONY: ext

clean:
	@echo ">> cleaning objects and executable"
	rm -f obj/*.o
	rm -f run_yields
	rm -f run_makeZX
.PHONY: clean

uninstall:
	@echo ">> Uninstalling plotter"
	rm -f obj/*.o
	$(MAKE) -C ext clean
.PHONY: uninstall
