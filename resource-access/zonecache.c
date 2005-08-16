/*
 * zonecache.c
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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <fam.h>
#include <signal.h>
#include <string.h>
#include "zonecache.h"

FAMConnection fc;
FAMRequest fr;
FAMEvent fe;
char *data;


struct entry *entries;
int nentries = 0;
int maxentries = ENTRIES;

void init_entries(){
	entries =  (struct entry *)calloc(maxentries + 1,sizeof(struct entry));
}
void destroy_entries(){
	int i;
	for (i = 0; i < nentries; i++)
		free(entries[i].filename);
	free(entries);
}
		
struct entry *add_entry(char *filename){
	
	if (nentries >= maxentries){
		maxentries += 10;
		entries = (struct entry *)realloc(entries,(maxentries +1)*sizeof(struct entry));
	}
	entries[nentries].filename  =  strdup(filename);
	return entries+(nentries++);

}	
struct entry *find_entry(char *filename){
	struct entry *e = entries;

	for (; e && e->filename; e++)
		if (!strcmp(e->filename,filename))
			return e;

	return NULL;
}

static void del_entry_by_filename(char *filename){
	int i;

	for (i = 0; i < nentries; i++)
		if (!strcmp(entries[i].filename,filename))
			break;
	if (i < nentries--)
		memmove(entries+i,entries+i+1,sizeof(struct entry));
}

void del_entry(struct entry *e){
	memmove(e,e+1,sizeof(struct entry));
	nentries++;
}


static void check_events(int signum){
	struct timeval tv;
	fd_set fset;
	int ret = 0;
	
	tv.tv_sec = 0;
	tv.tv_usec = 50;
	FD_ZERO(&fset);
	FD_SET(FAMCONNECTION_GETFD(&fc),&fset);
	ret = select(FAMCONNECTION_GETFD(&fc)+1,&fset,NULL,NULL,&tv);
	if (ret < 0){
		perror("Select Failed");
		goto out;
	}
	if (FAMPending(&fc)){
		ret = FAMNextEvent(&fc,&fe);
		if (ret < 0){
			printf("Could not get event\n");
			goto out;
		}
		if (fe.code == (FAMChanged || FAMDeleted )){
			printf("Event on file %s\n",fe.filename);
			getZones();
		}
	}
out:
	alarm(ALARM_INTERVAL);
	return;
}

int init_monitor(){ 

	int ret = 0;
	
	data = (char *)malloc(1024);
	if (!data){
		ret = -1;
		goto out;
	}
	ret = FAMOpen(&fc);

	if (ret < 0){
		goto out;
	}

	signal(SIGALRM,check_events);
	ret = alarm(ALARM_INTERVAL);
out:
	return ret;
}
int monitor_file(char *file){
	struct entry *e = find_entry(file);

	if (!e){
		e = add_entry(file);
		return  FAMMonitorFile(&fc,file,&(e->fr),data);
	}
	else
		return 0;
}
int unmonitor_file(char *file){
	struct entry *e = find_entry(file);
	int ret = 0;
	if (e){
		ret = FAMCancelMonitor(&fc,&(e->fr));
		del_entry(e);
	}
	return ret;
}

/*int main(int argc, char *argv[]){
	int ret = 0;	

	init_entries();
	ret = init_monitor();
	if (ret < 0)
		return ret;
	//monitor_file("/home/glauber/sources/teste.c");

	if (!ret)
		for(;;);
	return ret;
}*/
//PROTOTYPES

/*DNSZONE *zones = NULL;

DNSZONE *getZones(){

	char *conffile;
	int i;
	if (!zones){
		init_entries();
		init_monitor();
		conffile = get_conf("bindconf");
		if (!conffile)
			conffile = strdup(BINDCONF);
			zones = getZones();
			monitor_file(conffile);
		}
		for (i = 0; (zones+i) && zones[i].zoneName; i++){
			if (zones[i].zoneFile)
				monitor_file(zones[i].zoneFile);
		}
	}
		return zones;
}*/
