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

NBFILE=$1
NBDIR=`dirname $NBFILE`
NBNAME=`basename $NBFILE .ipynb`

cd $NBDIR

jupyter-nbconvert --to rst ${NBNAME}.ipynb
sed -i -e "s/ipython3/python3/g" ${NBNAME}.rst
sed -i -e "s/^\.\. image:: \(.*\)$/.. figure:: \1\n   :width: 100%/g" ${NBNAME}.rst
mv ${NBNAME}.rst ../${NBNAME}.inc
rm -r ../${NBNAME}_files/
mv ${NBNAME}_files/ ../

