#!/bin/sh
#
# Usage: ../../tools/make_rst.sh 06-Pandas   [or whatever the current chapter dirname is]
#

DIR=$1

for nb in notebooks/* ; do
    nbname=`basename $nb .ipynb`
    sed -e "s/__DIR__/$DIR/g;s/__FILE__/$nbname.ipynb/g;s/__INC__/$nbname.inc/g" ../template.rst > $nbname.rst
done

