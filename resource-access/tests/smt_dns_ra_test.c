/*
 * smt_dns_ra_test.c
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
 * Contributors: Tyrel Datwyler <tyreld@us.ibm.com>
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "smt_dns_ra_support.h"
#include "smt_dns_ra_rrhandle.h"


int listzones (void)
{
  DNSZONE *z;
  
  printf("--- ZONES ---\n\n");

  for (z = getZones (); z != NULL && z->zoneName != NULL; ++z)   {
    DNSRECORD *r;
    ZONEOPTS *o;

      printf ("%s (%s) (TTL %lld) - soa(%s, %s, %lld, %lld, %lld, %lld) - file: %s\n", 
	      z->zoneName, z->zoneType, z->zoneTTL,
	      z->soaContact, z->soaServer, z->soaSerialNumber,
	      z->soaRefresh, z->soaRetry, z->soaExpire, z->zoneFileName);

      for (r = z->records; r != NULL && r->recordName != NULL; ++r)
      {
	  printf ("\t%s (TTL %lld) (class %s) (%s) = %s in %s\n",
		  r->recordName, r->recordTTL, r->recordClass, r->recordType,
		  r->recordValue, r->recordZoneName);
      }

      for (o = z->zoneOpts; o && o->key && o->value; o++)
	printf("\t%s %s\n", o->key, o->value);
    }
  freeZones (z);
  return 0;
}

/*
  int updatezones_static()
  {
  DNSRECORD dr[3] = {{"hugo","bluesky.com","A","10.0.0.2"},
  {"joe","bluesky.com","A","10.0.0.3"},
  {NULL,NULL,NULL,NULL}};
  DNSRECORD drp[3] = {{"ivan","redplanet.de","A","192.168.0.7"},
  {"viktor","redplanet.de","A","192.168.0.8"},
  {NULL,NULL,NULL,NULL}};
  DNSZONE dz[3] = {{"bluesky.com","master","master/bluesky.com","webmogul","@",2005031000,60*60,3*60*60,2*60*60,0,dr},
  {"redplanet.de","master","master/bluesky.com","root","@",2005031000,60*60,3*60*60,2*60*60,0,drp},
  {NULL,NULL,NULL,NULL,NULL,0,0,0,0,0,NULL}};
  updateZones(dz);
  return 0;
  }
*/

/*
  int updatezones()
  {
  DNSZONE * zones=NULL;
  DNSZONE * newzone;
  DNSZONE dnszones[2] = {
  {"bluesky.com","slave","slave/bluesky.com","webmogul","@",2005031000,60*60,3*60*60,2*60*60,0,NULL},
  {"redplanet.de","slave","slave/redplanet.de","root","@",2005031000,60*60,3*60*60,2*60*60,0,NULL}
  };
  DNSRECORD dnsrecs[4] = {
  {"pc1","bluesky.com","A","10.0.0.4"},
  {"tp2","bluesky.com","A","10.0.0.5"},	
  {"phobos","redplanet.de","A","192.168.0.7"},
  {"deimos","redplanet.de","A","192.168.0.8"}
  };
  
  newzone = __addZone(&zones,&dnszones[0]);
  if (zones) {
  addRecord(newzone,&dnsrecs[0]);
  addRecord(newzone,&dnsrecs[1]);
  newzone = __addZone(&zones,&dnszones[1]);
  addRecord(newzone,&dnsrecs[2]);
  addRecord(newzone,&dnsrecs[3]);
  
  updateZones(zones);
  freeZones( zones );
  return 0;
  } else {
  printf ("misery...\n");
  return 1;
  }
  }
*/

/*
  void inczone()
  {
  DNSZONE dnszone = {"dark.com","slave","master/bluesky.com","web","@",2005031000,60*60,3*60*60,2*60*60,0,NULL};
  DNSRECORD dnsrec[4] = {
  {"pc1","dark.com","A","10.0.0.4",NULL,0},
  {"tp2","dark.com","A","10.0.0.5",NULL,0},
  {"phobos","dark.com","A","192.168.0.7",NULL,0},
  {"deimos","dark.com","A","192.168.0.8",NULL,0}
  };
  addZone(&dnszone,dnsrec);
  }
*/

void add_zone()
{
  DNSZONE *zone = malloc(sizeof(DNSZONE));
  DNSRECORD *records = malloc(sizeof(DNSRECORD) * 3);
  ZONEOPTS *opts = malloc(sizeof(ZONEOPTS) * 3);

  zone->zoneName = strdup("dark.com");
  zone->zoneType = strdup("slave");
  zone->zoneFileName = strdup("master/dark.com");
  zone->soaContact = strdup("web");
  zone->soaServer = strdup("@");
  zone->soaSerialNumber = 2005031000;
  zone->soaRefresh = 60*60;
  zone->soaRetry = 3*60*60;
  zone->soaExpire = 2*60*60;
  zone->soaNegativeCachingTTL = 0;
  zone->zoneTTL = -1;
  zone->records = NULL;
  zone->zoneOpts = NULL;

  records[0].recordName = strdup("pc1");
  records[0].recordZoneName = strdup("dark.com");
  records[0].recordType = strdup("A");
  records[0].recordValue = strdup("10.0.0.4");
  records[0].recordClass = strdup("IN");
  records[0].recordTTL = -1;

  records[1].recordName = strdup("tp2");
  records[1].recordZoneName = strdup("dark.com");
  records[1].recordType = strdup("A");
  records[1].recordValue = strdup("10.0.0.5");
  records[1].recordClass = strdup("IN");
  records[1].recordTTL = -1;

  records[2].recordName = NULL;
  records[2].recordZoneName = NULL;
  records[2].recordType = NULL;
  records[2].recordValue = NULL;
  records[2].recordClass = NULL;
  records[2].recordTTL = -1;

  opts[0].key = strdup("type");
  opts[0].value = strdup("slave");
  
  opts[1].key = strdup("file");
  opts[1].value = strdup("master/dark.com");

  opts[2].key = NULL;
  opts[2].value = NULL;

  addZone(zone, records);
  addOptsToZone(zone, "type", "slave");
  addOptsToZone(zone, "file", "\"master/dark.com\"");
}

void modifyrr(){
	modifyRecord("0.0.10.in-addr.arpa","1",'T',"pqp");
}
	
//void addmaster(){
//	DNSZONE *dz = getZones();
//	addMasters(dz,"dark.com","{ 9.23.87.98; }");
//	addMasters(dz,"dark.com","{ 9.23.87.98; 9.23.87.99; }");
//}
void test_status(void){

	if (status_service())
		printf("Dns Server is running.\n");
	else
		printf("Dns Server not running.\n");
}

void test_free(void){
	DNSZONE *dz = getZones();
	freeZones(dz);
}

void readoptions(void){
	BINDOPTS *bopts = ReadOptions();
	
	printf("--- OPTIONS ---\n\n");

	while (bopts && bopts->key && bopts->value){
		printf("Key: %s\nValue: %s\n\n",bopts->key,bopts->value);
		bopts++;
	}
	
}

int writeoptions(void){
	BINDOPTS *bopts = malloc(3*sizeof(BINDOPTS));

	bopts[0].key = "allow-query";
	bopts[0].value = "{ 10.0.0.1; }";


	bopts[1].key = NULL;
	bopts[1].value = NULL;

	return WriteOptions(bopts);
}

int addoptions(char *key, char *value){
	
	BINDOPTS bopt;
	bopt.key = strdup(key);
	bopt.value = strdup(value);

	return addOption(&bopt);

}
int getopt(void){
	BINDOPTS *bopt = ReadOptions();

	printf("allow-query value: %s\n",getOption(bopt,"allow-query"));

	return 0;
}

int setopt(void){
	BINDOPTS *bopt = ReadOptions();

	return setOption(bopt,"allow-query","{ 10.1.1.8; }");
}

void readacl(void){
	ACL *acl = ReadACL();

	printf("--- ACL's ---\n\n");

	while (acl && acl->key && acl->value){
		printf("acl: %s, value: %s\n\n",acl->key,acl->value);
		acl++;
	}

}

int writeacl(void){
	
	ACL *acl = malloc(3*sizeof(ACL));

	acl[0].key = strdup("internal");
	acl[0].value = strdup("{ 10.0.0.1; }");
	acl[1].key = strdup("joao");
	acl[1].value = strdup("{ 10.1.1.2; }");
	acl[2].key = NULL;
	acl[2].value = NULL;

	return WriteACL(acl);

}
int getacl(void){
	ACL *acl = ReadACL();

	printf("internal value: %s\n",getACL(acl,"internal"));

	return 0;
}
//int setacl(char *key, char *value) {
//	ACL *acl = ReadACL();
//
//	return setACL(acl, key, value);
//}

void disablezone(void){
	printf("disablezone ret: %d\n",disableZone("bluesky.com"));	
}
void enablezone(void){
  printf("enablezone ret: %d\n",enableZone("mydomain"));
}

void removezone(void) {
  char *filename;
  char *zone_dir;
  char *dir;
  int length;
  DNSZONE *zones = getZones();
  DNSZONE *zone = findZone(zones, "dark.com");
  BINDOPTS *opts = ReadOptions();

  zone_dir = getOption(opts, "directory");
  dir = stripQuotes(zone_dir);

  length = strlen(zone->zoneFileName) + strlen(zone_dir);
  filename = (char *)malloc(sizeof(char) * (length + 2));
  
  *filename = '\0';
  filename = strcat(filename, dir);
  
  filename = strcat(filename, "/");
  filename = strcat(filename, stripQuotes(zone->zoneFileName));

  printf("removezone ret: %d\n", removeRR(filename));
}

void allow_update()
{
	DNSZONE *zones = getZones();
        DNSZONE *zone;
	int up;

	zone = findZone(zones, "glommerdomain" );
	if (! zone)
	{
		fprintf(stderr,"ERROR: allow_update");
		return;
	}
	addOptsToZone(zone, "allow-update",  "{ 2.2.2.2; 3.3.3.3; }");
	up = updateZones( zones );
	printf("%x",up);
}

int main(void)
{
  start_service();
  test_status();
  stop_service();
  test_status();

  //  readoptions();

  //  readacl();

  listzones();
  listzones();

  add_zone();

  //  inczone();
  //  addmaster();

  listzones();

  //  removezone();

  deleteZone("dark.com");

  listzones();

  addoptions("recursion", "yes");
  addoptions("forward", "first");

  readoptions();

//  setacl("internal", "{ 10.1.1.8; }");

  readacl();
  getacl();
  writeacl();
  readacl();

  setopt();
  getopt();
  readoptions();

  //  printf("%d\n", set_bindconf("/home/tyreld/named.conf"));
  //printf("%d\n", set_bindconf("/usr/local/etc/named.conf"));


	//disablezone();
	//enablezone();
	//readoptions();
	//addoptions();
//	writeoptions();
//	readoptions();
//	getopt();
//	setopt();
//	getopt();
//	test_free();
//	test_status();	
//  listzones();
//  allow_update();
//  listzones();
//	modifyrr();
//  listzones();
//	modifyrr();
//	int i=0;
//	for (; i < 10 ; i++){ 
//  	listzones();
//		updatezones();
//	}
//	inczone();
//	updatezones();
//	test_free();
//	test_status();
//	writeacl();
//	readacl();
//	getacl();
//	setacl();
//	getacl();
//	stop_service();
//	test_status();

  return 0;
}
