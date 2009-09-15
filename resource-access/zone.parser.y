%{

/*
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
 * Contributors: René Neumann <r.neumann@de.ibm.com>
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parser_support.h"

extern FILE *zoneout;

extern void zonerestart(FILE *input_file);
extern void zoneerror(char* errmsg);
extern int zonelex(void);

#ifdef DEBUG_YACC
#define debugf(s) printf(s)
#define debugfv(s1, s2) printf((s1), (s2))
#define debugfvs(s1, s2, s3) printf((s1), (s2), (s3))
#else
#define debugf(s) printf(s)
#define debugfv(s1, s2) printf((s1), (s2))
#define debugfvs(s1, s2, s3) printf((s1), (s2), (s3))
#endif

static RRECORD *record;
static DNSZONE *zone;

static inline void setqname(const char *recordName)
{
	record->recordName = strdup(recordName);
}

static inline void setrdata(const char *recordType, const char *recordValue)
{
	record->recordType = strdup(recordType);
	record->recordValue = strdup(recordValue);
}

static inline void setcdata(const char *class)
{
  record->recordClass = strdup(class);
}

static inline void settdata(signed long long ttl)
{
  record->recordTTL = ttl;
}

static inline void sethdata(const char * class, signed long long ttl)
{
  record->recordClass = strdup(class);
  record->recordTTL = ttl;
}

//static RECORDSET *records;

static DATASET *records;

%}

%defines
%name-prefix="zone"

%union {
	char *string;
	unsigned long long num;
}

%token <num> NUMBER TIME
%token <string> IPADDR CLASS TYPE DOMAIN LITERAL GENERIC
%token TTL ORIGIN EOLN
%token A NS CNAME SOA PTR HINFO MX FILENAME

%type <num> time

%start statements

%%

statements :		/* empty */
	   |		statements statement
	   ;

statement :		EOLN
	  |		directive EOLN
				{
					debugf("directive\n");
				}
	  |		rrecord EOLN
				{
					debugf("rrecord\n");
					if (record->recordType && record->recordValue) {
						adddata(records, (void *)record, NULL);
					}
					record->recordName = NULL;
					record->recordValue = NULL;
					record->recordType = NULL;
					record->recordClass = NULL;
					record->recordTTL = -1;					
				}
          |             error EOLN
                                {
                                        printf("Parser error... ignoring entry in zoneFile of zone %s!\n", zone->zoneName);
                                        if(record->recordName) {
                                            printf("\tName = %s\n",record->recordName);
                                            free(record->recordName);
                                        }
                                        if(record->recordValue) {
                                            printf("\tValue = %s\n",record->recordValue);
                                            free(record->recordValue);
                                        }
                                        if(record->recordType) {
                                            printf("\tType = %s\n",record->recordType);
                                            free(record->recordType);
                                        }
                                        if(record->recordClass) {
                                            printf("\tClass = %s\n",record->recordClass);
                                            free(record->recordClass);
                                        }
                                        record->recordName = NULL;
                                        record->recordValue = NULL;
                                        record->recordType = NULL;
                                        record->recordClass = NULL;
                                        record->recordTTL = -1;
                                }
	  ;

directive :		TTL time
				{
					debugfv("$TSIG = %llu\n", $2);
					zone->zoneTTL = $2;
				}
	  |		ORIGIN DOMAIN
			        {
					debugfv("$ORIGIN = %s\n", $2);
				}
	  ;

rrecord :	IPADDR rr
			{
				debugf("IP + record\n");
				setqname($1);
				free($1);
			}
        |   DOMAIN rr
            {
				debugf("domain + record\n");
				setqname($1);
				free($1);
            }
		|	rr
			{
				debugf("record only\n");
				setqname("@");
			}
		;

rr :			header type_rdata
   ;

header :		/* empty */	{ debugf("empty header\n"); }
       |		time
				{
					debugf("time header\n");
					settdata($1);
				}
       |		CLASS
				{
				        debugfv("class header (CLASS = %s)\n", $1);
					setcdata($1);
					free($1);
				}
       |		time CLASS
			        {
					debugf("time + class header\n");
					sethdata($2, $1);
					free($2);
				}
       |		CLASS time
			        {
					debugf("class + time header\n");
					sethdata($1, $2);
					free($1);
				}
       ;

time :			NUMBER
				{
					debugfv("Time = %llu\n", $1);
					$$ = $1;
				}
     |			TIME
				{
					debugfv("Time = %llu\n", $1);
					$$ = $1;
				}
     ;

type_rdata :	SOA DOMAIN DOMAIN NUMBER time time time time
				{
					debugfvs("SOA %s %s\n", $2, $3);
					debugfv("Serial = %llu\n", $4);
					debugfv("Refresh = %llu\n", $5);
					debugfv("Retry = %llu\n", $6);
					debugfv("Expire = %llu\n", $7);
					debugfv("NegativeCacheingTTL = %llu\n", $8);
					zone->soaServer = strdup($2);
					zone->soaContact = strdup($3);
					zone->soaSerialNumber = $4;
					zone->soaRefresh = $5;
					zone->soaRetry = $6;
					zone->soaExpire = $7;
					zone->soaNegativeCachingTTL = $8;
					free($2); free($3);
				}

			| TYPE GENERIC
			{
				debugfvs("%s: %s", $1, $2);
				setrdata($1, $2);
				free($1);
				free($2);
			}
	   ;

%%

int zoneparsefile(FILE * infile, FILE * outfile, DNSZONE *inzone)
{
        int result;
	records = initset(sizeof(RRECORD), (int (*)(void *, int, void *, void *))addrecord);

	zonerestart(infile);
	zoneout = outfile;
	
	zone = inzone;
	zone->zoneTTL = -1;

	record = (RRECORD *)malloc(sizeof(RRECORD));
	record->recordZoneName = strdup(zone->zoneName);
	record->recordName = NULL;
	record->recordType = NULL;
	record->recordValue = NULL;
	record->recordTTL = -1;

	result = zoneparse();

	stripset(records);
	zone->records = (RRECORD *)records->data;

	free(records);
	free(record);

	return result;
}


#ifdef DEBUG_YACC
int main(int argc, char **argv)
{
	zone = (DNSZONE *)malloc(sizeof(DNSZONE));
	zone->zoneName = strdup("localhost");
	zone->zoneType = strdup("master");
	zone->zoneFileName = strdup("localhost.zone");

	zone->records = NULL;

	int result = zoneparsefile(stdin, stdout, zone);

	printf("\nZone\n\n");
	printf("\tName: %s\n", zone->zoneName);
	printf("\tType: %s\n", zone->zoneType);
	printf("\tFilename: %s\n", zone->zoneFileName);
	printf("\tSOA Server: %s\n", zone->soaServer);
	printf("\tSOA Contact: %s\n", zone->soaContact);
	printf("\tSOA Serial: %llu\n", zone->soaSerialNumber);
	printf("\tSOA Refresh: %llu\n", zone->soaRefresh);
	printf("\tSOA Retry: %llu\n", zone->soaRetry);
	printf("\tSOA Expire: %llu\n", zone->soaExpire);
	printf("\tSOA NegCacheTTL: %llu\n", zone->soaNegativeCachingTTL);
	printf("\tZone TTL: %lld\n", zone->zoneTTL);

	printf("\nRecords\n\n");

	RRECORD *trecord = zone->records;

	while(trecord && trecord->recordName) {
	  printf("\t%s %s %s %s %lld\n", trecord->recordName, trecord->recordType, trecord->recordValue, trecord->recordClass, trecord->recordTTL);
		      trecord++;    	      
	}

	return result;
}
#endif
