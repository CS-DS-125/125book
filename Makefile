# You can set these variables from the command line.
# e.g.  "make SPHINXOPTS=-a"
SPHINXOPTS    =
SPHINXBUILD   = sphinx-build
SOURCEDIR     = source
BUILDDIR      = build

# For auto-converting notebooks
VPATH := $(wildcard $(SOURCEDIR)/??-*/)   # so make will match the %.inc rule below *in* its directory, so % won't expand with the full path
NB_SOURCES := $(wildcard $(SOURCEDIR)/*/notebooks/*.ipynb)
NB_INCS := $(patsubst %.ipynb, %.inc, $(subst /notebooks/,/,$(NB_SOURCES)))

all: Makefile $(NB_INCS)
	@$(SPHINXBUILD) "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS)

%.inc: notebooks/%.ipynb
	tools/nb2rst.sh $^

help:
	@$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.PHONY: all help
