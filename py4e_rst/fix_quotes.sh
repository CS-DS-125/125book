#!/bin/sh

# Usage:  fix_quotes.sh file1.rst file2.rst ...
# or:     fix_quotes.sh *.rst

for f in $@ ; do
    sed --in-place=.bak -e 's/[“”]/"/g' $f
done
