#!/bin/bash

#
# enable.sh
#
# (C) Copyright IBM Corp. 2005
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Common Public License from
# http://www.opensource.org/licenses/cpl1.0.php
#
# Author:  Glauber de Oliveira Costa <gocosta@br.ibm.com>
#
# Contributors:
#
#

#Enable zone
#error codes: 1: wrong parameters
#							2: zone not found 

dir=`dirname $0`
if [ $# -lt 2 ];
	then
		exit 1
fi 

zname=$1
filename=$2
file=`echo $filename | sed s:\/:\\\\\\\/:g`

awkr=`awk -v zname=$zname -f $dir/lines.awk $filename` 

if [ "x$awkr" == "x" ]; 
	then 
		exit 2
fi

echo $awkr | sed "s/ //g;s/^/'/g;s/$/s:^#*::' $file/g" | xargs  sed -i
