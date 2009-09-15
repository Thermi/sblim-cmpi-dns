/*
 * service.h
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
#ifndef _SMT_DNS_RA_SERVICE_H_
#define _SMT_DNS_RA_SERVICE_H_

#include <smt_libra_execscripts.h>

#ifdef __cplusplus
extern "C" {
#endif

int start_service();
int stop_service();
int status_service();

#ifdef __cplusplus
}
#endif

#endif 

