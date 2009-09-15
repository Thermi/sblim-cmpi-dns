#!/bin/bash

#
# disablerr.sh
#
# (C) Copyright IBM Corp. 2005
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Eclipse Public License from
# http://www.opensource.org/licenses/eclipse-1.0.php
#
# Author:  Glauber de Oliveira Costa <gocosta@br.ibm.com>
#
# Contributors:
#
#

if [ $# -lt 2 ]; 
	then 
		exit 1;
fi

zname=$1
filename=$2
sed -i "s/\(.*$zname.*\)/;\1/g" $filename
