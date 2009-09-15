/*
 * smt_dns_ra_cache.h
 *
 * (C) Copyright IBM Corp. 2006
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Eclipse Public License from
 * http://www.opensource.org/licenses/eclipse-1.0.php
 *
 * Author: Tyrel Datwyler <tyreld@us.ibm.com>
 *
 * Contributors:
 *
 */

#ifndef __SMT_DNS_RA_CACHE
#define __SMT_DNS_RA_CACHE

#ifdef __cplusplus
extern "C" {
#endif

#include "smt_dns_ra_support.h"

#define _MAX_FILENAME_LENGTH 1024

typedef struct _DNSCONF {
  BINDOPTS *bopts;
  ACL *acls;
  DNSZONE *zones;
  MASTERS *masters;
} DNSCONF;

DNSCONF *global_dns_conf = NULL;

static inline DNSCONF *allocDnsConf()
{
  DNSCONF *conf = (DNSCONF *)malloc(sizeof(DNSCONF));
  if (conf) {
    conf->bopts = NULL;
    conf->acls = NULL;
    conf->zones = NULL;
    conf->masters = NULL;

    return conf;
  }

  return NULL;
}

#define vsize(vector, size) for (size = 0; vector + size && vector[size].key; size++)

#define copy_vector(vector, newvec) do { int _vsize, _viter; \
    vsize(vector, _vsize); \
    newvec = calloc(_vsize + 1, sizeof(*vector)); \
    memcpy(newvec, vector, (_vsize + 1) * sizeof(*vector)); \
    for (_viter = 0; _viter < _vsize; _viter++) { \
      newvec[_viter].key = strdup(vector[_viter].key); \
      newvec[_viter].value = strdup(vector[_viter].value); \
    } \
  } while(0)

#define copy_to_global(vector) copy_vector(vector, global_dns_conf->vector)
#define copy_from_global(vector) copy_vector(global_dns_conf->vector, vector)

static inline DNSRECORD *copy_records(DNSRECORD *record)
{
  DNSRECORD *r;
  int i;

  for (i = 0; record+i && record[i].recordName; i++);
  
  r = calloc(i+1,sizeof(DNSRECORD));
  
  for (i = 0; record+i && record[i].recordName; i++) {
    r[i].recordName = strdup(record[i].recordName);
    if (record[i].recordZoneName)
      r[i].recordZoneName = strdup(record[i].recordZoneName);
    if (record[i].recordType)
      r[i].recordType = strdup(record[i].recordType);
    if (record[i].recordValue)
      r[i].recordValue = strdup(record[i].recordValue);
    if (record[i].recordClass)
      r[i].recordClass = strdup(record[i].recordClass);
    r[i].recordTTL = record[i].recordTTL;
  }
  return r;
}

static inline DNSZONE *copy_zones(DNSZONE *zones)
{
  DNSZONE *z;
  int i;

  if (!zones)
    return NULL;
  
  for (i= 0; zones+i && zones[i].zoneName; i++);
  
  z = calloc(i+1,sizeof(DNSZONE));
  
  for (i= 0; zones+i && zones[i].zoneName; i++){
    z[i].zoneName = strdup(zones[i].zoneName);
    if (zones[i].zoneType)
      z[i].zoneType = strdup(zones[i].zoneType);
    if (zones[i].zoneFileName)
      z[i].zoneFileName = strdup(zones[i].zoneFileName);
    if (zones[i].soaContact)
      z[i].soaContact = strdup(zones[i].soaContact);
    if (zones[i].soaServer)
      z[i].soaServer = strdup(zones[i].soaServer);
    z[i].soaSerialNumber = zones[i].soaSerialNumber;
    z[i].soaRefresh = zones[i].soaRefresh;
    z[i].soaRetry = zones[i].soaRetry;
    z[i].soaExpire = zones[i].soaExpire;
    z[i].soaNegativeCachingTTL = zones[i].soaNegativeCachingTTL;
    z[i].zoneTTL = zones[i].zoneTTL;
    if (zones[i].records)
      z[i].records = copy_records(zones[i].records);
    if (zones[i].zoneOpts)
      copy_vector(zones[i].zoneOpts,z[i].zoneOpts);
  }
  return z;				
}

static inline void zone_to_global(DNSZONE *zones)
{  
  global_dns_conf->zones = copy_zones(zones);
}																			

static inline DNSZONE *zone_from_global(void)
{  
  return copy_zones(global_dns_conf->zones); 
}

#ifdef __cplusplus
}
#endif

#endif
