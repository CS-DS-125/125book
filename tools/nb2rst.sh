#!/bin/sh
#
# Convert a notebook file to a restructuredtext .inc file,
# placing it and its images/files directory in the parent directory.
#
# Use this in a folder structure with chapter sources in "ch0[x]/"
# and notebooks for that chapter in "ch0[x]/notebooks".
#
# Usage: nb2rst.sh FILE.ipynb
#
# It will cd to the directory containing the ipynb to do the conversion and
# file moving.
set -x # echo on
set -e # exit immediately on failure

NBFILE=$1
NBDIR=`dirname $NBFILE`
NBNAME=`basename $NBFILE .ipynb`

cd $NBDIR

# Execute the notebook, but fall back to not executing it if that fails
#jupyter-nbconvert --to rst --execute ${NBNAME}.ipynb || jupyter-nbconvert --to rst ${NBNAME}.ipynb

jupyter-nbconvert --to rst ${NBNAME}.ipynb

sed -i -e "s/code:: ipython3/code:: python3/g" ${NBNAME}.rst
sed -i -e "s/parsed-literal::/nboutput::/g" ${NBNAME}.rst
sed -i -e "s/^\.\. image:: \(.*\)$/.. figure:: \1\n   :width: 100%/g" ${NBNAME}.rst
mv ${NBNAME}.rst ../${NBNAME}.inc
rm -rf ../${NBNAME}_files/
if [ -d ${NBNAME}_files ] ; then
    mv ${NBNAME}_files/ ../
fi
