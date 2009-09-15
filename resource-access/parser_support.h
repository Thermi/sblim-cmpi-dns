/*
 * parser_support.h
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

#ifndef __PARSER_SUPPORT_H
#define __PARSER_SUPPORT_H

#define UL64 unsigned long long
#define SL64 signed long long

typedef struct {
  char *recordName;
  char *recordZoneName;
  char *recordType;
  char *recordValue;
  char *recordClass;
  SL64 recordTTL;
} RRECORD;

typedef struct {
  char *key;
  char *value;
} OPTS;

typedef struct {
  char *key;
  char *value;
  SL64 port;
} MASTER;

typedef struct {
  char *zoneName;
  char *zoneType;
  char *zoneFileName;
  char *soaContact;
  char *soaServer;
  UL64 soaSerialNumber;
  UL64 soaRefresh;
  UL64 soaRetry;
  UL64 soaExpire;
  UL64 soaNegativeCachingTTL;
  SL64 zoneTTL;
  RRECORD *records;
  OPTS *zopts;
} DNSZONE;

typedef struct {
  OPTS *opts;
  OPTS *acls;
  DNSZONE *zones;
  MASTER *masters;
} CONF;

#define DEFAULT_SET_SIZE 4
#define SIZE_INCREMENT 4

typedef struct {
  int count;
  int size;
  int datasize;
  void *data;
  int (*add) (void *, int, void *, void *);
} DATASET;

DATASET *initset(int datasize, int (*add)(void *, int, void *, void *));
void adddata(DATASET *set, void *data1, void *data2);
DATASET *stripset(DATASET *set);

int addoption(OPTS *opts, int index, char *key, char *value);
int addzone(DNSZONE *zones, int index, char *zonename, OPTS *zopts);
int addrecord(RRECORD *records, int index, RRECORD *record, void *ignr);
int addmaster(MASTER *masters, int index, OPTS *opts, UL64 *port);

#endif
