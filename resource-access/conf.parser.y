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
 * Contributors:
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parser_support.h"

extern FILE *confout;

extern void confrestart(FILE *input_file);
extern void conferror(char *errmsg);
extern int conflex(void);

#ifdef DEBUG_YACC
#define debugf(s) printf(s)
#define debugfv(s1, s2) printf((s1), (s2))
#define debugfvs(s1, s2, s3) printf((s1), (s2), (s3))
#else
#define debugf(s)
#define debugfv(s1, s2)
#define debugfvs(s1, s2, s3)
#endif

#define MAXSTRLENGTH 1024

static char buf[MAXSTRLENGTH];

#define MINSIZE 8
#define RESIZE_AMNT 4

DATASET *acls;
DATASET *opts;
DATASET *zoneopts;
DATASET *zones;
DATASET *masters;

OPTS master;


static inline void bufclear() { buf[0] = '\0'; }
static inline void bufcat(const char *string) { strcat(buf, string); }

%}

%defines
%name-prefix="conf"

%union {
	char *string;
	unsigned long long num;
}

%token <string> ACL CONTROLS INCLUDE KEY LOGGING OPTIONS
%token <string> SERVER TRUSTEDKEYS VIEW ZONE LBRACE PORT
%token <string> RBRACE COMMA SEMICOLON LWRES NOT MASTERS
%token <string> IPADDR IPPREFIX LITERAL STRING INET
%token <string> ALLOW KEYS
%token <num> NUMBER

%type <string> key value class name masters_element masters_elements
%type <string> address_match_list address_match_list_element
%type <num> port

%start statements

%%

statements :		statements statement
	   |		/* empty */
	   ;

statement :             OPTIONS LBRACE option_elements RBRACE SEMICOLON
				{
					debugf("option statement\n");
				}
          |             ACL acl_statement SEMICOLON
	  |		zone_statement SEMICOLON
	  |		INCLUDE STRING SEMICOLON
				{
					debugf("include statement\n");
				}
	  |		MASTERS name port LBRACE masters_elements RBRACE SEMICOLON
				{
					debugfv("masters statement (masters name = %s)\n", $2);
					bufclear();
					bufcat("{ "); bufcat($5); bufcat("}");
					master.key = $2;
					master.value = buf;
					stripset(masters);
					adddata(masters, &master, &$3);
					free($2);
				}
	  |		CONTROLS LBRACE control_elements RBRACE SEMICOLON
				{
					debugf("control statement\n");
				}
          ;

port :			PORT NUMBER
				{
					debugfv("port = %llu\n", $2);
					$$ = $2;
				}
     |			/* empty */
				{
					debugf("empty port\n");
					$$ = 0;
				}

control_elements :	control_elements control_element
				{
					debugf("control elements\n");
				}
		 |	/* empty */
		 ;

control_element :	INET IPADDR port ALLOW LBRACE address_match_list RBRACE keys SEMICOLON
				{
					debugfvs("control element (key %s : value %s)\n", $1, $2);
				}
		;

keys :			KEYS LBRACE key_list RBRACE
		|	/* empty */
		;

key_list :		key_list STRING SEMICOLON
	  |		/* empty */
	  ;

masters_elements :	masters_elements masters_element SEMICOLON
				{
					debugf("masters_elements\n");
					bufclear();
					bufcat($1); bufcat($2); bufcat("; ");
					$$ = strdup(buf);
					free($1); free($2);
				}
		 |	/* empty */
				{
					$$ = strdup("");
				}
		 ;

masters_element :	IPADDR
				{
					debugfv("masters_element (ipaddr = %s)\n", $1);
					$$ = $1;
				}
		|	IPPREFIX
				{
					debugfv("masters_element (ipprefix = %s)\n", $1);
					$$ = $1;
				}
		|	LITERAL
				{
					debugfv("masters_element (masters_list = %s)\n", $1);
					$$ = $1;
				}
		;

zone_statement :	ZONE name class LBRACE zone_elements RBRACE
				{
					debugfvs("zone_statement (zone %s: class %s)\n", $2, $3);
					stripset(zoneopts);
					adddata(zones, $2, zoneopts->data);
					zoneopts = initset(sizeof(OPTS), (int (*)(void *, int, void *, void *))addoption);
					free($2); free($3);
				}
	       ;

name :			LITERAL
				{
					$$ = $1;
				}
     |			STRING
				{
					$1++;
					$$ = strndup($1, strlen($1) - 1);
					free(--$1);
				}
     ;

class :			/* empty */	{ debugf("class (empty)\n"); $$ = strdup(""); }
      |			LITERAL
				{
					debugfv("class = %s\n", $1);
					$$ = $1;
				}
      ;

zone_elements :		/* empty */	{ debugf("zone_elements (empty)\n"); }
	      |		zone_elements zone_element SEMICOLON
				{
					debugf("zone_elements\n");
				}
	      ;

zone_element :          key value
				{
					debugfvs("zone_element = (key %s: value %s)\n", $1, $2);
					adddata(zoneopts, $1, $2);
					free($1), free($2);
				}
	     ;

acl_statement :         name LBRACE address_match_list RBRACE
				{
					debugfv("acl_statement (%s = ", $1);
					bufclear();
					bufcat("{ "); bufcat($3); bufcat("}");
					adddata(acls, $1, buf);
					free($1); free($3);
					debugfv("%s)\n", buf);
				}
              ;

option_elements	:	/* empty */	{ debugf("option_elements (empty)\n"); }
		|	option_elements option_element SEMICOLON
				{
					debugf("option_elements\n");
				}
		;

option_element :	key value
				{
					debugfvs("option_element = (key %s: value %s)\n", $1, $2);
					adddata(opts, $1, $2);
					free($1); free($2);
				}
	       ;

key :			LITERAL
				{
					debugfv("key = %s\n", $1);
					$$ = $1;
				}
    |			MASTERS
				{
					debugfv("key = %s\n", $1);
					$$ = $1;
				}
    ;

value :			LITERAL
				{
					debugfv("value (literal = %s)\n", $1);
					$$ = $1;
				}
      |			STRING
				{
					debugfv("value (string = %s)\n", $1);
					$$ = $1;
				}
      |			LBRACE address_match_list RBRACE
				{
					debugf("value (address match list");
					bufclear();
					bufcat("{ "); bufcat($2); bufcat("}");
					$$ = strdup(buf);
					free($2);
					debugfv(" = %s)\n", buf);
				}
      ;


// Configuration File Elements

address_match_list :	/* empty */	{ debugf("address_match_list (empty)\n"); $$ = strdup(""); }
		   |	address_match_list address_match_list_element SEMICOLON
				{
					debugf("address_match_list");
					bufclear();
					bufcat($1); bufcat($3); bufcat("; ");
					$$ = strdup(buf);
					free($1); free($2);
					debugfv(" = %s\n", buf);					
				}
		   |	address_match_list NOT address_match_list_element SEMICOLON
				{
					debugf("address_match_list");
					bufclear();
					bufcat($1); bufcat(" !"); bufcat($3); bufcat(";");
					$$ = strdup(buf);
					free($1); free($3);
					debugfv(" = %s\n", buf);
				}
		   ;
   

address_match_list_element :	IPADDR
					{
						debugfv("address_match_list_element (ipaddr = %s)\n", $1);
						$$ = $1;
					}
			   |	IPPREFIX
					{
						debugfv("address_match_list_element (ipprefix = %s)\n", $1);
						$$ = $1;
					}
			   |	LITERAL
					{
						debugfv("address_match_list_element (acl_name = %s)\n", $1); 
						$$ = $1;
					}
			   |	LBRACE address_match_list RBRACE
					{
						debugf("address_match_list_element (address match list");
						bufclear(); 
						bufcat("{ "); bufcat($2); bufcat("}");
						$$ = strdup(buf); 
						free($2);
						debugfv(" = %s\n", buf);
					}
			   ;

%%

static void initstructures()
{
  acls = initset(sizeof(OPTS), (int (*)(void *, int, void *, void *))addoption);
  opts = initset(sizeof(OPTS), (int (*)(void *, int, void *, void *))addoption);
  zoneopts = initset(sizeof(OPTS), (int (*)(void *, int, void *, void *))addoption);
  zones = initset(sizeof(DNSZONE), (int (*)(void *, int, void *, void *))addzone);
  masters = initset(sizeof(MASTER), (int (*)(void *, int, void *, void*))addmaster);
}

int confparsefile(FILE * infile, FILE * outfile, CONF* conf)
{
  int result;

  initstructures();

  bufclear();

  confrestart(infile);
  confout = outfile;
  result = confparse();

  stripset(opts);
  stripset(acls);
  stripset(zones);
  stripset(masters);

  if (conf) { 
    conf->opts = (OPTS *)opts->data;
    conf->acls = (OPTS *)acls->data;
    conf->zones = (DNSZONE *)zones->data;
    conf->masters = (MASTER *)masters->data;
  }

  free(opts);
  free(acls);
  free(zones);
  free(zoneopts);
  free(masters);
  
  return result;
}


#ifdef DEBUG_YACC
int main(int argc, char **argv)
{
  CONF *conf = (CONF *)malloc(sizeof(CONF));
  int result = confparsefile(stdin, stdout, conf);

  if (result) {
    printf("encounterd parsing error\n");
    return(result);
  }

  OPTS *opt = conf->opts;
  OPTS *acl = conf->acls;
  DNSZONE *zone = conf->zones;
  MASTER *masters = conf->masters;

  printf("\nOptions\n\n");

  while (opt && opt->key && opt->value) {
    printf("Key: %s\nValue: %s\n\n", opt->key, opt->value);
    opt++;
  }

  printf("\nACLs\n\n");

  while (acl && acl->key && acl->value) {
    printf("Key: %s\nValue: %s\n\n", acl->key, acl->value);
    acl++;
  }

  printf("\nZones\n\n");

  while (zone && zone->zoneName && zone->zopts) {
    printf("Zone : %s\n", zone->zoneName);
    printf("Options :\n");
    OPTS *topts = zone->zopts;
    while (topts && topts->key && topts->value) {
      printf("\tKey: %s\n\tValue: %s\n", topts->key, topts->value);
      topts++;
    }
    printf("\n");
    zone++;
  }

  printf("\nMasters\n\n");

  while (masters && masters->key && masters->value) {
	printf("Key: %s\nValue: %s\nPort: %llu\n\n", masters->key, masters->value, masters->port);
	masters++;
  }

  return result;
}
#endif
