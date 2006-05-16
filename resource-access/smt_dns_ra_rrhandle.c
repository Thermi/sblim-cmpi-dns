/*
 * rrhandle.c
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
 * Description: Functions to handle the resource records of a zone
 *
 */ 
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "smt_dns_ra_support.h"
#include <smt_libra_conf.h>

DNSRECORD* addRecord(DNSZONE* zone, DNSRECORD* newrec)
{
    off_t num;
    if (zone && newrec) {
	if (zone->records == NULL) {
	    zone->records = calloc(sizeof(DNSRECORD),2);
	    num=1;
	} else {
	    num=0;
	    while(zone->records[num++].recordName);
	    zone->records = realloc(zone->records, sizeof(DNSRECORD)*(num+1));
	}	
	zone->records[num] = zone->records[num-1]; 
	zone->records[num-1] = *newrec; 
	return &zone->records[num-1];
    } 
    return NULL;
}

DNSRECORD* findRecord(DNSZONE* zone, const char * recname)
{
    while(zone && zone->records && zone->records->recordName) {
	if (strcmp(zone->records->recordName,recname)==0) {
	    return zone->records;
	}
	zone->records ++;
    }
    return NULL;
}

int modifyRecord(const char *zname,const char *recname, const char field, const char *value){

	DNSZONE *zones = getZones();
	DNSRECORD *rec = findRecord(findZone(zones,zname),recname);
	
	switch (field){

		case 'T':
			free(rec->recordType);
			rec->recordType = strdup(value);
			break;
		case 'V':
			free(rec->recordValue);
			rec->recordValue = strdup(value);
			break;
		default:
			break;
	}
	return updateZones(zones);
}

int disableRR(const char *name,const char *file){
	char *script= my_script_path(DISABLERR);
	int ret = 0;
	if (!file)
		return -EINVAL;


	ret = execScript2(script,name,file);
	free(script);

	return ret;
}

int enableRR(const char *name,const char *file){
	char *script= my_script_path(ENABLERR);
	int ret = 0;

	if (!file)
		return -EINVAL;

	ret = execScript2(script,name,file);
	free(script);

	return ret;
}

int deleteRR(const char *name, const char *file){
	char *script= my_script_path(DELETERR);
	char *absolute_path;
	int ret = 0;

	if (!file)
		return -EINVAL;
	
	absolute_path = (char *) malloc( (strlen(BINDDIR)+strlen(file)+2)*sizeof(char) );
	strcpy(absolute_path, BINDDIR);
	strcat(absolute_path, "/" );
	strcat(absolute_path, file);

	ret = execScript2(script,name,absolute_path);
	free( absolute_path );
	return ret;

}

