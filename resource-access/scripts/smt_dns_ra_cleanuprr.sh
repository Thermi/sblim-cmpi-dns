#!/bin/bash

#
# cleanuprr.sh
#
# (C) Copyright IBM Corp. 2006
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Eclipse Public License from
# http://www.opensource.org/licenses/eclipse-1.0.php
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