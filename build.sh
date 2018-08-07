#!/bin/sh

libtoolize && aclocal && autoheader && autoconf && automake --add-missing

sh configure

rm -rf build
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=relwithdebinfo ..
make
cd ..
