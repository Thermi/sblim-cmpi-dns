/*
 * util.c
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
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "dnssupport.h"
#include "util.h"


CONF *conf = NULL;
/*
void free_conf(){

	CONF *cf = conf;
		
	while (cf && cf->key && cf->value){
		free(cf->key);
		free(cf->value);
		cf++;
	}
}
void read_conf(const char *file){
	FILE *f = NULL;
	int count = 0;
	char *line;
	char *ptr;

	if (file)
		f = fopen(file,"r");
	else if ((!file) || (!f)) 
		f = fopen(CONFFILE,"r");
		
	if (!conf)
		conf = malloc(2*sizeof(CONF));
	else{ 
		free_conf();
		conf = realloc(conf,2*sizeof(CONF));
	}
	count = 0;
	line = (char *)malloc(LINE);

	while (!feof(f)){
		fgets(line,LINE,f);
		if ((!line) || (*line == '\n'))
			continue;
		conf = realloc(conf,(count+1)*sizeof(CONF)); 
		conf[count].key = strsep(&line,"=");
		ptr = strchr(conf[count].key,'\n');
		if (ptr)
			*ptr = '\0';
		if (line){
			conf[count].value = strdup(line);
			ptr = strchr(conf[count].value,'\n');
			if (ptr)
				*ptr = '\0';
			count++;		
		}
	}	 
	conf[count].key = NULL;
	conf[count].value = NULL;

	fclose(f);
}

char *get_conf(const char *key){
	
	CONF *c = conf;
	char *ret;

	if (!conf)
		return NULL;
	
	while (c && c->key && c->value){
		if (!strcmp(c->key,key)){
			ret = strdup(c->value);
			return ret;
		}
		c++;
	} 	
	return NULL;
}
*/
char *script_path(const char *name){
	char *scriptdir;
	char *script;
	char *ptr;

	read_conf(CONFFILE); 
	scriptdir = get_conf("scriptdir");
	if (!scriptdir)
		scriptdir = strdup("./scripts/");

	script = (char *)malloc(strlen(scriptdir)+strlen(name)+2);
	strncpy(script,scriptdir,strlen(scriptdir)+1);

	ptr = strchr(script,'\n');	
	if (ptr)
		*ptr = '/';
	else
		strcat(script,"/");
	strcat(script,name);

	return script;
}
/*
int execScript(const char *script, const char *name, const char *conffile){
	char *filename; 
	int status;
	pid_t pid;

	if ((!name) || (!script))
		return -EINVAL;

	if (!conffile){
		filename = strdup(BINDCONF);
	}
	else{
		filename = strdup(conffile);
	}


	pid = fork();
	if (pid){
		waitpid(pid,&status,0);
		free(filename);
		return WEXITSTATUS(status);
	}
	else{
		execlp(script,script,name,filename,NULL);
	}
	return 0;
}
*/

