/*
 * rrhandle.h
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
 */
#ifndef _SMT_DNS_RA_RRHANDLE_H_
#define _SMT_DNS_RA_RRHANDLE_H_
#include "smt_dns_ra_support.h"

#ifdef __cplusplus
extern "C" {
#endif

int disableRR(const char *name,const char *file);
int enableRR(const char *name,const char *file);
int deleteRR(const char *name, const char *file);
int removeRR(const char *filename);

DNSRECORD* addRecord(DNSZONE*,DNSRECORD*);
DNSRECORD* findRecord(DNSZONE*,DNSRECORD *);
int deleteRecord(const char *, DNSRECORD *) ;

int        modifyRecord(const char *, const char *, const char, const char *);
int        modifyRecordType(const char *, const char *, const char *);
int        modifyRecordValue(const char *, const char *, const char *);
int        modifyRecordTTL(const char *, DNSRECORD *, SL64);
int        modifyRecordClass(const char *, DNSRECORD *, const char *);

#ifdef __cplusplus
}
#endif

#endif

