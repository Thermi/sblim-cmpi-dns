/*
 * dnssupport.h
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
#ifndef _DNSSUPPORT_H_
#define _DNSSUPPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "scripts.h"

#define BUFSIZE 1024
#ifndef CONFFILE
	#define CONFFILE "/etc/dnssupport.conf"
#endif 

#ifndef BINDDIR
	#define BINDDIR "/var/lib/named"
#endif
#ifndef BINDCONF
	#define BINDCONF "/etc/named.conf"
#endif

/* scripts */

#ifndef GETZONES 
	#define GETZONES "getzones.pl"
#endif

#define vsize(vector,size) for (size = 0; vector+size && vector[size].key; size++)

#define copy_vector(vector,newvec) do { int SIZE,ITER; \
	vsize(vector,SIZE);\
	newvec = calloc(SIZE+1,sizeof(*vector));\
	memcpy(newvec,vector,(SIZE+1)*sizeof(*vector));\
	for (ITER = 0; ITER < SIZE; ITER++){\
		newvec[ITER].key = strdup(vector[ITER].key);\
		newvec[ITER].value = strdup(vector[ITER].value);\
	}\
	} while(0)

#ifdef USE_CACHE
/* If you're a user of this macro, PLEASE, check if the global vector already
	exists, and in case it does, FREE IT FIRSTi, with the proper free functions */

#define copy_to_global(vector) copy_vector(vector,g##vector)
#define copy_from_global(vector) copy_vector(g##vector,vector)
//static inline DNSZONE *zones_from_global();
//static inline void zones_to_global(DNSZONE *);

#endif

#define UL64 unsigned long long
#include "service.h"

  typedef struct _DNSRECORD {
    char * recordName;
    char * recordZoneName;
    char * recordType;    
    char * recordValue;
  } DNSRECORD;

	typedef struct _ZONEOPTS {
		char *key;
		char *value;
	} ZONEOPTS;

	typedef struct _ZONEOPTS ACL;

  typedef struct _DNSZONE {
    char * zoneName;
    char * zoneType;
    char * zoneFileName;
    char * soaContact;
    char * soaServer;
    UL64   soaSerialNumber;
    UL64   soaRefresh;
    UL64   soaRetry;
    UL64   soaExpire;
    UL64   soaNegativCachingTTL;
    DNSRECORD * records;
		ZONEOPTS * zoneOpts;
  } DNSZONE;

	typedef struct _ZONEOPTS BINDOPTS;
	
	char *my_script_path(char *);

  	DNSZONE* getZones();
	/*DNSZONE* getSlaveZones();
	DNSZONE* getZonesByType(char *type);*/
  
  	DNSZONE* addZone(DNSZONE*,DNSRECORD*);
  	DNSZONE* __addZone(DNSZONE**,DNSZONE*);
  	DNSZONE* findZone(DNSZONE*,const char*);
  	DNSZONE* addOptsToZone(DNSZONE* zone, const char *key, const char *value);
  	ZONEOPTS* findOptsInZone(DNSZONE* zone,const char *key);
  	DNSZONE* addMasters(DNSZONE*, const char *, const char *);
  	int updateZones(DNSZONE*);
 	int modifyRecord(const char *, const char*, const char, const char *);
  	void freeZones(DNSZONE*);

	int status_service();
	int start_service();
	int stop_service();

	void freeOptions(BINDOPTS *bopts);
	int WriteOptions(BINDOPTS *); 
 	BINDOPTS *ReadOptions(void);
	int addOption(BINDOPTS *);
	int setOption(BINDOPTS *,const char *, const char *);
	char *getOption(BINDOPTS *, const char *);
	
	ACL *ReadACL(void);
	char *getACL(ACL *,const char *);
	int addACL(ACL *acl);
	void freeACL(ACL *acl);
	int WriteACL(ACL *);
	int setACL(BINDOPTS *, const char *, const char*);
	int deleteACL(const char *);

	int disableZone(const char *);
	int enableZone(const char *);
	int deleteZone(const char *);


#ifdef __cplusplus
}
#endif


#endif
