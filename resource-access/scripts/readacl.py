#!/usr/bin/python

#
# readacl.py
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

import re
from os import open,write,close,O_WRONLY
from sys import argv
from errors import *

acl = re.compile("^\s*acl\s+[\"\']?(\w+)[\"\']?\s+({.*})")
EINVAL=22
try: 
	filename="/etc/named.conf"
except AttributeError:
	exit(EINVAL)
try:
	pipeid = int(argv[2]) 
except AttributeError:
	exit(EINVAL)

try:
	f = file(filename)
except IOError:
	exit(ENOFILE)

acls = []
for line in f:
	try:
		acls.append(acl.search(line).groups())
	except AttributeError:
		continue

if (len(acls) > 0):
	write(pipeid,"#:" + str(len(acls)) + "\n")
	for a in acls:
		write(pipeid,"K:%s\n"%a[0])
		write(pipeid,"V:%s\n"%a[1])
	write(pipeid,"ENDACL\n")
	close(pipeid)	
