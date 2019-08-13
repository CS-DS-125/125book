#!/bin/sh
set -e
set -x

for file in source/*/notebooks/*.ipynb ; do
    tools/nb2rst.sh $file
done
