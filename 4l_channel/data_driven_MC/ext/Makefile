SRCS::=Discriminants.cc FinalStates.cc bitops.cc cConstants.cc setTDRStyle.cpp FakeRates.cpp pyhelpers.cc
OBJS::=$(patsubst %.cpp,%_cpp.so,$(patsubst %.cc,%_cc.so,$(SRCS)))
INCLDIR::=../include

# Default target: compile everything
all: $(OBJS)
.PHONY: all

# Do not search for rules for source files
Makefile: ;
%.h: ;
%.cc: ;
%.cpp: ;

%_cc.so: %.cc $(INCLDIR)/%.h
	root -l -e ".L $<+" -q

%_cpp.so: %.cpp $(INCLDIR)/%.h
	root -l -e ".L $<+" -q

clean:
	-rm $(OBJS) *.pcm *.d
.PHONY: clean

debug:
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"
.PHONY: debug
