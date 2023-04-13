###################################################
# Application name: ratulator
# Project: ivs2-calculator
#
# Date:         2023-04-10
# File:         Makefile
#
# Author: Zdeněk Borovec <xborov08@vutbr.cz>
# Author: Tomáš Krejčí   <xkrejc84@vutbr.cz>
# Author: Jan Lozrt      <xlozrt00@vutbr.cz>
# Author: Jakub Mitrenga <xmitre07@vutbr.cz>
#
# Description: Simple calculator app
# 
###################################################

MATHDIR    = extern/ivs2-mathlib
PROFILEDIR = extern/ivs2-profiler
CALCDIR    = .
DOCSDIR    = docs
ROOTDIR    = ..

EXEC       = bin/ratulator


# == REQUIRED TARGETS ==
.PHONY: all pack clean test doc run profile

# compiles the project including the profiler
all: mathlib profile calc

# makes the project ready to be submitted
pack: clean
	# TODO: 
	# create temporary dir
	# create install packages
	# generate docs
	# copy docs, packages and repo into temp dir
	# zip temporary dir

# removes all files that should not be submitted
clean: calc-clean mathlib-clean profile-clean
	rm -R -f $(CALCDIR)/bin
	rm -R -f $(CALCDIR)/.cache
	rm -R -f $(DOCSDIR)
	rm -f $(CALCDIR)/doxygen_warning.txt
	rm -f $(CALCDIR)/compile_commands.json

# runs math library tests
test:
	@if [ -f $(MATHDIR)/build/tests ]; then\
		$(MATHDIR)/build/tests;\
	else\
		echo "You must run 'make' or 'make mathlib' first";\
	fi\

# generates documentation in PDF (latex) and HTML
doc:
	# TODO:
	# doxygen generation for calc, mathlib and profiler
	mkdir -p $(DOCSDIR)/calculator
	doxygen
	cd $(DOCSDIR)/calculator/latex && make
	cp $(DOCSDIR)/calculator/latex/refman.pdf $(ROOTDIR)/documentation.pdf

# runs the program
run: 
	@if [ -f $(EXEC) ]; then\
		$(EXEC);\
	else\
		echo "You must run 'make' or 'make calc' first";\
	fi\

# installs the profiler
profile: bin mathlib
	mkdir -p $(PROFILEDIR)/build && cd $(PROFILEDIR)/build &&\
		cmake .. && cmake --build . --target install
	cp $(PROFILEDIR)/install/bin/* $(CALCDIR)/bin


# == INSTALLATION TARGETS ==
.PHONY: calculator mathlib bin

# installs ivs2-calculator
calc: bin
	mkdir -p $(CALCDIR)/build && cd $(CALCDIR)/build &&\
		cmake .. && cmake --build . --target install
	cp $(CALCDIR)/install/bin/* $(CALCDIR)/bin

# installs ivs2-mathlib
mathlib: bin
	mkdir -p $(MATHDIR)/build && cd $(MATHDIR)/build &&\
		cmake .. && cmake --build . --target install

bin:
	mkdir -p $(CALCDIR)/bin

# == CLEAN TARGETS == 
.PHONY: calc-clean mathlib-clean profile-clean

# removes compiled calculator files
calc-clean:
	rm -R -f $(CALCDIR)/build
	rm -R -f $(CALCDIR)/install

# removes compiled ivs2-mathlib files
mathlib-clean:
	rm -R -f $(MATHDIR)/build
	rm -R -f $(MATHDIR)/install

# removes compiled ivs2-profiler files
profile-clean:
	rm -R -f $(PROFILEDIR)/build
	rm -R -f $(PROFILEDIR)/install


# == OTHER TARGETS ==

# generates compile_commands.json for autocomplete in neovim
ccmds:
	mkdir -p $(CALCDIR)/build && cd $(CALCDIR)/build &&\
		cmake .. && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
	cp $(CALCDIR)/build/compile_commands.json $(CALCDIR)/
