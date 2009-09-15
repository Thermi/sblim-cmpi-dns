 /**
 * smt_dns_valuemap.h
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
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
/* Zone Types (Unknown, Master, Slave| Stub, Forward, Hint)*/
#ifndef _SMT_DNS_VALUEMAP_H
#define _SMT_DNS_VALUEMAP_H

#define DNS_ZONETYPE_UNKNOWN	0
#define DNS_ZONETYPE_MASTER	1
#define DNS_ZONETYPE_SLAVE	2
#define DNS_ZONETYPE_STUB	3
#define DNS_ZONETYPE_FORWARD    4
#define DNS_ZONETYPE_HINT       5

/* Allow-Updates*/
#define DNS_UPDATES_UNKNOWN	0
#define DNS_UPDATES_STATIC	1
#define DNS_UPDATES_DYNAMIC	2

/* XferFormat attribute (Unknown, Incremental, Complete)*/
#define DNS_XFER_UNKNOWN       	0
#define DNS_XFER_INCREMENTAL   	1
#define DNS_XFER_COMPLETE      	2

/* ResourceRecords Family (Unknown, Internet, hesiod, chaos)*/
#define DNS_RRFAMILY_UNKNOWN   	0
#define DNS_RRFAMILY_INTERNET  	1
#define DNS_RRFAMILY_HESIOD	2
#define DNS_RRFAMILY_CHAOS   	3


/* ResourceRecords Types */
#define DNS_RRTYPE_UNKNOWN   	0
#define DNS_RRTYPE_CNAME	1
#define DNS_RRTYPE_PTR		2
#define DNS_RRTYPE_NS   	3
#define DNS_RRTYPE_MX   	4
#define DNS_RRTYPE_HINFO   	5
#define DNS_RRTYPE_A	   	6
#define DNS_RRTYPE_AAAA   	7
#define DNS_RRTYPE_WKS   	8
#define DNS_RRTYPE_RP   	9
#define DNS_RRTYPE_AFSBD   	10
#define DNS_RRTYPE_SRV		11
#define DNS_RRTYPE_TXT		12
#define DNS_RRTYPE_LOC		13
#define DNS_RRTYPE_NXT		14
#define DNS_RRTYPE_SIG		15
#define DNS_RRTYPE_A6		16
#define DNS_RRTYPE_DNAME	17

#define DNS_AMLTYPE_UNKNOWN	0
#define DNS_AMLTYPE_PREDEFINED	1
#define DNS_AMLTYPE_IPV4	2
#define DNS_AMLTYPE_IPV6	3
#define DNS_AMLTYPE_IPPREFIX	4
#define DNS_AMLTYPE_KEY		5
#define DNS_AMLTYPE_AML		6
#define DNS_AMLTYPE_NESTEDAML	7

#define DNS_FORWARD_UNKNOWN	0
#define DNS_FORWARD_ONLY     	1
#define DNS_FORWARD_FIRST	2

/* Defualt values */
#define DNS_ZONETYPE_DEFAULT	DNS_ZONETYPE_MASTER
#define DNS_RRTYPE_DEFAULT	DNS_RRTYPE_A

#endif

