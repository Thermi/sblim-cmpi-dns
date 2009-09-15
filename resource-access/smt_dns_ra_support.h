/*
 * smt_dns_ra_support.h
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

#ifndef _SMT_DNS_RA_SUPPORT_H_
#define _SMT_DNS_RA_SUPPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "smt_dns_ra_scripts.h"

#define BUFSIZE 1024

#ifndef BINDDIR
	#define BINDDIR "/var/lib/named"
#endif
#ifndef BINDCONF
	#define BINDCONF "/etc/named.conf"
#endif

#define UL64 unsigned long long
#define SL64 signed long long

  static inline char *stripQuotes(const char *p_value)
  {
    char *tmp_value, *strip_value;
    char *ptr;

    if (!p_value) return NULL;

    tmp_value = strdup(p_value);

    if ((ptr = index(tmp_value,'\r')) != NULL)
      *ptr = '\0';

    if ((ptr = index(tmp_value,'\n')) != NULL)
      *ptr = '\0';

    ptr = index(tmp_value,'\0');
    while (*(--ptr) && ((*ptr == '"')))
      *ptr = '\0';

    ptr = tmp_value;
    while (*ptr && ((*ptr == '"'))) {
      char *tmp = strdup(ptr);
      strcpy(ptr,tmp+1);
    }

    strip_value = strdup(tmp_value);
    if(tmp_value) free(tmp_value);

    return strip_value;
  }

  static inline void addQuotes(char **str) { 
    char * buffer = NULL;  
    int length = 0; 

    length = (strlen(*str) + 3); 
    buffer = (char *)calloc(length, sizeof(char)); 
   
    strcat(buffer,"\"");
    strcat(buffer,*str); 
    strcat(buffer,"\"");
    free(*str); 
    *str=buffer; 
    return; 
  } 

  typedef struct _DNSRECORD {
    char * recordName;
    char * recordZoneName;
    char * recordType;    
    char * recordValue;
    char * recordClass;
    SL64   recordTTL;
  } DNSRECORD;

  typedef struct _ZONEOPTS {
    char *key;
    char *value;
  } ZONEOPTS;

  typedef struct _ACL {
    char* key;
    char* value;
  } ACL;

  typedef struct _MASTERS {
    char* key;
    char* value;
    SL64 port;
  } MASTERS;

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
    UL64   soaNegativeCachingTTL;
    SL64   zoneTTL;
    DNSRECORD * records;
    ZONEOPTS * zoneOpts;
  } DNSZONE;

  typedef struct _BINDOPTS { 
    char* key;
    char* value;
  }BINDOPTS;
	
  char *my_script_path(char *);
  
  DNSZONE* getZones();

  /*DNSZONE* getSlaveZones();
    DNSZONE* getZonesByType(char *type);*/
  
  DNSZONE*  __addZone(DNSZONE**,DNSZONE*);
  DNSZONE*  addZone(DNSZONE*,DNSRECORD*);
  int       deleteZone(const char *);
  DNSZONE*  findZone(DNSZONE*,const char*);
  void      freeZones(DNSZONE*);
  int       updateZones(DNSZONE*);
  int       disableZone(const char *);
  int       enableZone(const char *);
  int       deleteZone(const char *);

  DNSZONE*  addOptsToZone(DNSZONE* zone, const char *key, const char *value);
  int       delOptsFromZone(DNSZONE* zone, const char *key);
  ZONEOPTS* findOptsInZone(DNSZONE* zone,const char *key);

  BINDOPTS* ReadOptions(void);
  int       WriteOptions(BINDOPTS *); 
  void      freeOptions(BINDOPTS *bopts);
  char*     getOption(BINDOPTS *, const char *);
  int       addOption(BINDOPTS *);
  int       setOption(BINDOPTS *,const char *, const char *);
  int       deleteOption(const char *);
	
  ACL*      ReadACL(void);
  int       WriteACL(ACL *);
  void      freeACL(ACL *acl);
  char*     getACL(ACL *,const char *);
  int       addACL(ACL *acl);
  int       deleteACL(const char *);
  ACL*      addBuiltinACL(ACL *acl);

  MASTERS*  ReadMasters(void);
  int       WriteMasters(MASTERS *masters);
  void      freeMasters(MASTERS *masters);
  int       deleteMasters(const char *key);
  int       addMasters(MASTERS* masters);

  int       getACLType(const char *aclValue);
  int       getMastersType(const char *mastersValue);
  int       getForwardersType(const char *forwardersValue);

  char*     get_bindconf();
  int       set_bindconf(const char *);

#ifdef __cplusplus
}
#endif


#endif

