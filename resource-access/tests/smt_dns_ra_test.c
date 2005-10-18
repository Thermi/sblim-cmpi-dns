/*
 * dnstest.c
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
#include "smt_dns_ra_support.h"
#include "smt_dns_ra_rrhandle.h"
int listzones (void)
{
  DNSZONE *z;
  for (z = getZones (); z != NULL && z->zoneName != NULL; ++z)   {
      printf ("%s (%s) - soa(%s,%s,%lld,%lld, %lld, %lld) - file: %s\n", 
	      z->zoneName, z->zoneType,
	      z->soaContact, z->soaServer, z->soaSerialNumber,
	      z->soaRefresh, z->soaRetry, z->soaExpire, z->zoneFileName);
      DNSRECORD *r;
      for (r = z->records; r != NULL && r->recordName != NULL; ++r)
      {
	  printf ("\t%s (%s) = %s in %s\n",
		  r->recordName, r->recordType,
		  r->recordValue, r->recordZoneName);
      }
    }
  freeZones (z);
  return 0;
}


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

void inczone()
{
	DNSZONE dnszone = {"dark.com","slave","master/bluesky.com","web","@",2005031000,60*60,3*60*60,2*60*60,0,NULL};
	DNSRECORD dnsrec[4] = {
  {"pc1","dark.com","A","10.0.0.4"},
  {"tp2","dark.com","A","10.0.0.5"},
  {"phobos","dark.com","A","192.168.0.7"},
  {"deimos","dark.com","A","192.168.0.8"}
	 };
	addZone(&dnszone,&dnsrec);
}
void modifyrr(){
	modifyRecord("0.0.10.in-addr.arpa","1",'T',"pqp");
}
	
void addmaster(){
	DNSZONE *dz = getZones();
	addMasters(dz,"dark.com","{9.23.87.98; }");

}
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

int addoptions(void){
	
	BINDOPTS bopt;
	bopt.key = "recursion";
	bopt.value = "yes";

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

	while (acl && acl->key && acl->value){
		printf("acl: %s, value: %s\n",acl->key,acl->value);
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
int setacl(void){
	ACL *acl = ReadACL();

	return setACL(acl,"internal","{10.1.1.1.8}");
}

void disablezone(void){
	printf("disablezone ret: %d\n",disableZone("bluesky.com"));	
}
void enablezone(void){
	printf("enablezone ret: %d\n",enableZone("mydomain"));
}

void allow_update()
{
	DNSZONE *zones = getZones();
        DNSZONE *zone;
	zone = findZone(zones, "glommerdomain" );
	if (! zone)
	{
		fprintf(stderr,"ERROR: allow_update");
		return;
	}
	addOptsToZone(zone, "allow-update",  "{ 2.2.2.2; 3.3.3.3; }");
	int up = updateZones( zones );
	printf("%x",up);
}

int main(void)
{
	//	test_status();
	//stop_service();
	//test_status();
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
	int i=0;
	for (; i < 10 ; i++){ 
  	listzones();
		updatezones();
	}
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
