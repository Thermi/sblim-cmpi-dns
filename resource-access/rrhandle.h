/*
 * rrhandle.h
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
#ifndef _RRHANDLE_H_
#define _RRHANDLE_H_
#include "dnssupport.h"

#ifdef __cplusplus
extern "C" {
#endif

int disableRR(const char *name,const char *file);
int enableRR(const char *name,const char *file);
int deleteRR(const char *name, const char *file);

DNSRECORD* addRecord(DNSZONE*,DNSRECORD*);
DNSRECORD* findRecord(DNSZONE*,const char*);

#ifdef __cplusplus
}
#endif

#endif 
