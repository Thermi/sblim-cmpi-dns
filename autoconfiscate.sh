#!/bin/sh
#
# Script to setup autoconf/automake build environment.
# Run this first to create the configure script
aclocal --force -I m4 &&
autoheader --force &&
libtoolize --force && 
automake --add-missing --force-missing &&
autoconf --force &&
echo
echo "You may now run ./configure"
echo
