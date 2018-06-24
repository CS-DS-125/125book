#!/bin/sh

# Usage:  fix_index_stmnts.sh file1.rst file2.rst ...
# or:     fix_index_stmnts.sh *.rst

for f in $@ ; do
    sed --in-place=.bak -e 's/ *:raw-latex:`\\index{\([^}]*\)}`/\n.. index:: \1/ ; s/ :raw-latex:`\\index{\([^}]*\)}`/, \1/g' $f
done
