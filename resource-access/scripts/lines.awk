#
# lines.awk
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

BEGIN { FS = " "; zone=0; brackets=0; begin=0;}
/^#*zone[[:space:]]+\"([[:graph:]]+)\"/  {if ($2 == "\"" zname "\"") {zone = 1; begin=NR;} }
/\{/	{ if (zone == 1) brackets++; }
/\}/	{ if (zone == 1 && (brackets == 1) ) { zone=0; brackets--; print begin,",",NR; }  else if (zone == 1) brackets--; }
END { }
