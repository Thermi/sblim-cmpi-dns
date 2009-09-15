#! /bin/sh

#
# status.sh
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
# Author:     Mukunda Chowdaiah          <cmukunda@in.ibm.com>
#             Ashoka S Rao               <ashoka.rao@in.ibm.com>
#
# Contributors:
#
#
named='named'
prog=$named
if [ "`pidof -o %PPID $named`" ]; then
	echo -n $"$named: already running"
	echo
	exit 2
else
	echo -n $"$named: is not  running"
	echo
	exit 0   
fi
