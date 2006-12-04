#!/bin/bash

#
# cleanuprr.sh
#
# (C) Copyright IBM Corp. 2006
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Common Public License from
# http://www.opensource.org/licenses/cpl1.0.php
#
# Author:  Tyrel Datwyler <tyreld@us.ibm.com>
#
# Contributors:
#
#

if [ $# -lt 1 ]; 
	then 
		exit 1;
fi

rm $1