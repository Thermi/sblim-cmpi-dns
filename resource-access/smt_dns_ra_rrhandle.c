/*
 * rrhandle.c
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Eclipse Public License from
 * http://www.opensource.org/licenses/eclipse-1.0.php
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
#include <smt_libra_execscripts.h>

DNSRECORD* addRecord(DNSZONE* zone, DNSRECORD* newrec)
{
    off_t num;
    if (zone && newrec) {
	if (zone->records == NULL) {
	    zone->records = calloc(2,sizeof(DNSRECORD));
	    num=1;
	} else {
	    num=0;
	    while(zone->records[num++].recordName);
	    zone->records = realloc(zone->records, sizeof(DNSRECORD)*(num+1));
	}	
	zone->records[num] = zone->records[num-1]; 
        zone->records[num-1].recordName = strdup(newrec->recordName); 
        zone->records[num-1].recordZoneName = strdup(newrec->recordZoneName); 
        zone->records[num-1].recordType = strdup(newrec->recordType); 
        zone->records[num-1].recordValue = strdup(newrec->recordValue); 
        zone->records[num-1].recordClass = strdup(newrec->recordClass); 
        zone->records[num-1].recordTTL = newrec->recordTTL; 
	//zone->records[num-1] = *newrec; 
	return &zone->records[num-1];
    } 
    return NULL;
}

int deleteRecord(const char *zoneName, DNSRECORD  *dnsRecord) {

        DNSZONE *zones = NULL, *myZone = NULL;
        DNSRECORD *records;
        int size = 0, off = 0, ret = 0;


        zones = getZones();

        if (zones) {
          myZone = findZone(zones, zoneName);
          if (myZone) {
            if (myZone->records) {
              records = myZone->records;
              for (size = 0, off=0; records+size && records[size].recordName; size++) {
                 if ((strcmp(dnsRecord->recordName,records[size].recordName)==0) && 
                     (strcmp(dnsRecord->recordZoneName,records[size].recordZoneName)==0) && 
                     (strcmp(dnsRecord->recordType,records[size].recordType)==0) && 
                     (strcmp(dnsRecord->recordValue,records[size].recordValue)==0)) {
                   off = size;
                 }
              }

//              printf("off = %d; size = %d\n",off, size);
//              if ( (off==0) && (size!=0)) {
//                free(zones);
//                return 1;
//              }

              memmove(records+off, records+off+1, (size-off)*sizeof(DNSRECORD));

              ret = updateZones(zones);
              freeZones(zones);
              return ret;
            }
          }
          freeZones(zones);
        }
        return 1;
}

DNSRECORD* findRecord(DNSZONE* zone, DNSRECORD  * dnsRecord)
{
    DNSRECORD * records = NULL;

    if (!zone)
      return NULL;

    if (!zone->records)
      return NULL;

    records = zone->records;

    while(records && records->recordName) {
        if ((strcmp(records->recordName,dnsRecord->recordName)==0) && 
            (strcmp(records->recordZoneName,dnsRecord->recordZoneName)==0) && 
            (strcmp(records->recordType,dnsRecord->recordType)==0) && 
            (strcmp(records->recordValue,dnsRecord->recordValue)==0)) { 
            return records;
        }
        records ++;
    }
    return NULL;
}

int modifyRecordTTL(const char *zname, DNSRECORD *dnsRecord, SL64 TTL) {

  DNSZONE *zones = NULL, *myZone = NULL;
  int ret = 0;

  zones = getZones();
  if (!zones)
    return 1;

  myZone = findZone(zones,zname);
  if (! myZone)
    return 1;

  DNSRECORD *rec = findRecord(myZone,dnsRecord);

  if (! rec)
    return 1;

  rec->recordTTL = TTL;

  ret = updateZones(zones);
  free(zones);
  return ret;

}

int modifyRecordClass(const char *zname, DNSRECORD *dnsRecord , const char *class) {

  DNSZONE *zones = NULL, *myZone = NULL;
  int ret = 0;

  zones = getZones();
  if (!zones)
    return 1;

  myZone = findZone(zones,zname);
  if (! myZone)
    return 1;

  DNSRECORD *rec = findRecord(myZone,dnsRecord);

  if (! rec)
    return 1;

  free(rec->recordClass);
  if (class) 
    rec->recordClass = strdup(class);
  else 
    rec->recordClass = NULL;

  ret = updateZones(zones);
  free(zones);
  return ret;

}
/*
int modifyRecordType(const char *zname, const char *recname, const char *type) {
  DNSZONE *zones = getZones();
  DNSRECORD *rec = findRecord(findZone(zones,zname),recname);

  free(rec->recordType);
  if (type)
    rec->recordType = strdup(type);
  else
    rec->recordType = NULL;

  return updateZones(zones);
}

int modifyRecordValue(const char *zname, const char *recname, const char *value) {
  DNSZONE *zones = getZones();
  DNSRECORD *rec = findRecord(findZone(zones,zname),recname);

  free(rec->recordValue);
  rec->recordValue = strdup(value);

  return updateZones(zones);
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
}*/

int disableRR(const char *name,const char *file){
        char *tmp = stripQuotes(file);
	char *script= my_script_path(DISABLERR);
	int ret = 0;
	if (!tmp)
		return -EINVAL;


	ret = execScript2(script,name,tmp);
	free(script);

	return ret;
}

int enableRR(const char *name,const char *file){
        char *tmp = stripQuotes(file);
	char *script= my_script_path(ENABLERR);
	int ret = 0;

	if (!tmp)
		return -EINVAL;

	ret = execScript2(script,name,tmp);
	free(script);

	return ret;
}

int deleteRR(const char *name, const char *file){
        char *tmp = stripQuotes(file);
	char *script= my_script_path(DELETERR);
	char *absolute_path;
	int ret = 0;

	if (!tmp)
		return -EINVAL;
	
	absolute_path = (char *) malloc( (strlen(BINDDIR)+strlen(file)+2)*sizeof(char) );
	strcpy(absolute_path, BINDDIR);
	strcat(absolute_path, "/" );
	strcat(absolute_path, tmp);

	ret = execScript2(script,name,absolute_path);
	free( absolute_path );
	return ret;

}

int removeRR(const char *file) {
  char *tmp = stripQuotes(file);
  char *script = my_script_path(REMOVERR);
  int ret = 0;

  if (!tmp)
    return -EINVAL;

  ret = execScript1(script, tmp);
  free(script);

  return ret;
}

