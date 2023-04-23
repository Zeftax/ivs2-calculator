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
BUILDDIR   = _build
BINDIR     = _bin
INSTALLDIR = /usr/bin
PACKNAME   = xborov08_xkrejc84_xlozrt00_xmitre07
PACKDIR   := $(shell mktemp -d -t ivstmp-XXX)

EXEC       = ratulator


# == REQUIRED TARGETS ==
.PHONY: all pack clean test doc run profile

# compiles the project including the profiler
all: mathlib profile calc

# makes the project ready to be submitted
pack: clean
	# create temporary dir
	mkdir -p $(PACKDIR)/doc
	mkdir -p $(PACKDIR)/install
	mkdir -p $(PACKDIR)/repo
	# copy clean repo
	cp -r -T $(ROOTDIR) $(PACKDIR)/repo
	# create install packages
	make deb-calc
	make deb-prof
	# generate docs
	make doc
	# copy docs, packages and repo into temp dir
	cp $(DOCSDIR)/program_documentation.pdf $(PACKDIR)/doc
	cp $(CALCDIR)/_packages/* $(PACKDIR)/install
	# name temp dir correctly
	mv $(PACKDIR) $(ROOTDIR)/$(PACKNAME)
	# zip temporary dir
	zip -r $(ROOTDIR)/$(PACKNAME).zip $(ROOTDIR)/$(PACKNAME)
	# remove temp directory
	rm -R -f $(ROOTDIR)/$(PACKNAME)

# removes all files that should not be submitted
clean: calc-clean mathlib-clean profile-clean
	rm -R -f $(CALCDIR)/$(BINDIR)
	rm -R -f $(CALCDIR)/.cache
	rm -R -f $(CALCDIR)/_packages
	rm -R -f $(CALCDIR)/$(DOCSDIR)
	rm -f $(CALCDIR)/doxygen_warning.txt
	rm -f $(CALCDIR)/compile_commands.json

# runs math library tests
test: mathlib
	cd $(MATHDIR) && make test

# generates documentation in PDF (latex) and HTML
doc:
	# TODO:
	# doxygen generation for calc, mathlib and profiler
	mkdir -p $(DOCSDIR)/calculator
	doxygen
	cd $(DOCSDIR)/calculator/latex && make
	cp $(DOCSDIR)/calculator/latex/refman.pdf $(CALCDIR)/$(DOCSDIR)/program_documentation.pdf

# runs the program
run: 
	@if [ -f $(CALCDIR)/$(BINDIR)/$(EXEC) ]; then\
		$(CALCDIR)/$(BINDIR)/$(EXEC);\
	else\
		echo "You must run 'make' or 'make calc' first";\
	fi\

# installs the profiler
profile: bin mathlib
	cd $(PROFILEDIR) && make
	cp $(PROFILEDIR)/install/bin/* $(CALCDIR)/$(BINDIR)


# == INSTALLATION TARGETS ==
.PHONY: calc calc-install mathlib bin

# compiles ivs2-calculator
calc: bin
	mkdir -p $(CALCDIR)/$(BUILDDIR) && cd $(CALCDIR)/$(BUILDDIR) &&\
		cmake .. && make
	cp $(CALCDIR)/$(BUILDDIR)/$(EXEC) $(CALCDIR)/$(BINDIR)

# compiles ivs2-calculator and installs it on the current system
calc-install: calc
	cd $(CALCDIR)/$(BUILDDIR) &&\
		cmake -DCMAKE_INSTALL_PREFIX:PATH=$(INSTALLDIR) . &&\
		make install

# installs ivs2-mathlib
mathlib: bin
	cd $(MATHDIR) && make

bin:
	mkdir -p $(CALCDIR)/$(BINDIR)

# == CLEAN TARGETS == 
.PHONY: calc-clean calc-uninstall mathlib-clean profile-clean

# removes compiled calculator files
calc-clean:
	rm -R -f $(CALCDIR)/$(BUILDDIR)

# removes installed ivs2-calculator files from the system
calc-uninstall: 
	rm -f $(INSTALLDIR)/$(EXEC)
	rm -f /usr/share/applications/ratulator.desktop
	rm -f /usr/share/icons/hicolor/512x512/apps/ratulator.png

# removes compiled ivs2-mathlib files
mathlib-clean:
	cd $(MATHDIR) && make clean

# removes compiled ivs2-profiler files
profile-clean:
	cd $(PROFILEDIR) && make clean


# == OTHER TARGETS ==
.PHONY: ccmds deb-calc deb-prof

# generates compile_commands.json for autocomplete in neovim
ccmds:
	mkdir -p $(CALCDIR)/$(BUILDDIR) && cd $(CALCDIR)/$(BUILDDIR) &&\
		cmake .. && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
	cp $(CALCDIR)/$(BUILDDIR)/compile_commands.json $(CALCDIR)/

# generates .deb package
deb-calc: calc
	cd $(CALCDIR)/$(BUILDDIR) && cpack -G DEB\
		|| echo "Something went wrong. Try running 'make clean' first"

deb-prof: profile
	cd $(PROFILEDIR)/$(BUILDDIR) \
		&& cpack -D CPACK_OUTPUT_FILE_PREFIX="../../../_packages" -G DEB \
		|| echo "Something went wrong. Try running 'make clean' first"
