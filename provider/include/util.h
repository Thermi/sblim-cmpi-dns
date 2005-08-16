 /**
 * util.h
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:	Glauber de Oliveira Costa <gocosta@br.ibm.com>
 * 
 * Contributors:
 *
 */
#ifndef _UTIL_H_
#define _UTIL_H_

#ifndef CONFFILE
	#define CONFFILE "/etc/dnssupport.conf"
#endif 
#ifndef BINDCONF
	#define BINDCONF "/etc/named.conf"
#endif

#define LINE 1024


void read_conf(const char *);

char *get_conf(const char *);

char *script_path(const char *);

int execScript(const char *, const char *, const char *);


#endif
