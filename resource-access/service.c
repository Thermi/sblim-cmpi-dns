/*
 * service.c 
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
 * Author:  Glauber de Oliveira Costa <gocosta@br.ibm.com>
 *
 * Contributors:
 *
 * Description: Start/Stop/Status functionality
 *
 */ 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <conf.h>

#include "service.h"

#define INITSCRIPT "/etc/init.d/named"
#define INITSCRIPT2 "/etc/init.d/bind"
#define NAMEDPATH "/usr/sbin/named"


extern struct conf *dns_conf;

static char *init_script(){
	struct stat buf;
	char *script = get_conf(dns_conf,"initscript");

	if ((script) || !stat(script,&buf)) 
		goto out;
	else 
		 script = strdup(INITSCRIPT);
	if (!stat(script,&buf))
		goto out;
	else
		script = strdup(INITSCRIPT2);		
	if (stat(script,&buf) < 0)
		return NULL;

out:
	return script;

}
int start_service(){
	char *script = init_script();
	int ret = 0;
	if (!script)
		return -ENOENT;

	ret = execScript1(script,"start");
	free(script);
	return ret;
}

int stop_service(){
	char *script = init_script();
	int ret = 0;
	if (!script)
		return -ENOENT;

	ret = execScript1(script,"stop");
	free(script);
	return ret;
}

int status_service(){
	/* we cannot rely on the distribution's status function of the init script
		and the reasons are:
		1) Some of them (i.e. Debian) does not provide status funcionality
		2) The return value may not be always the same for them */
	char *named_path = get_conf(dns_conf,"named_path");
	char *script = my_script_path("status");

	int ret = 0;
	if (!named_path)
		named_path = strdup(NAMEDPATH);

	ret = execScript1(script,named_path);
	free(named_path);
	free(script);
	return ret;

}

