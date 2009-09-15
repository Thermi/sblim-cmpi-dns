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
#include <ctype.h>
#include <stdlib.h>

#include "zone.parser.tab.h"

#ifdef DEBUG_LEX
#define debugf(s) printf(s)
#define debugfv(s1, s2) printf((s1),(s2))
#else
#define debugf(s) printf(s)
#define debugfv(s1, s2) printf((s1),(s2))
#endif

static int bindTime2uint64(unsigned long long *ull, const char *time) 
{
    if (time) {
        char * copytime = strdup(time);
        char c = time[strlen(time)-1];
        unsigned factor = 1;
        if (isalpha(c)) {
            switch (c) {
                case 'm':
                case 'M':
                    factor=60;
                    break;
                case 'h':
                case 'H':
                    factor=60*60;
                    break;
                case 'd':
                case 'D':
                    factor=24*60*60;
                    break;              
                case 'w':
                case 'W':
                    factor=7*24*60*60;
                    break;
                default:
                    factor=0;
                    break;
            }
            copytime[strlen(time)-1] = 0;
        }
        *ull = atoll(copytime) * factor;
    } else {
        *ull = 0ULL;
    }
    return 0;
}

%}

ipaddr		([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3})

eoln		(\r\n)|([\r\n])

digit		[0-9]
letter		[a-zA-Z]
special		[/_-]
space		[\t ]

literal		({letter}|{special})({letter}|{special}|{digit})*
number		[0-9]+
t_let		[sSmMhHdDwWmMyY]
time		({number}{t_let})+

domain		(([a-zA-Z]([a-zA-Z0-9\-]*[a-zA-Z0-9]+)*)(\.[a-zA-Z]([a-zA-Z0-9\-]*[a-zA-Z0-9]+)*)*)*(\.)?
new_domain  [a-zA-Z0-9][-.a-zA-Z0-9]*

%option prefix="zone"
%option noyywrap
%option yylineno
%option nounput

%s ignr_lnbrk
%x generic

%%

<INITIAL>{eoln}	        {
			debugf("LINEBREAK\n");
			zonelineno++;
			return(EOLN);
			}

<ignr_lnbrk>{eoln}	{
			debugf("IGNORED LINEBREAK\n");
			zonelineno++;
			}

{number}		{
			debugfv("NUMBER (%s)\n", zonetext);
			zonelval.num = atoll(zonetext);
			return(NUMBER);
			}

{time}			{
			debugfv("TIME (%s)\n", zonetext);
			bindTime2uint64(&zonelval.num, zonetext);
			return(TIME);
			}

\$TTL			{
			debugf("$TTL\n");
			return(TTL);
			}

\$ORIGIN		{
			debugf("$ORIGIN\n");
			return(ORIGIN);
			}

{ipaddr}		{
			debugfv("IPADDR (%s)\n", zonetext);
			zonelval.string = strdup(zonetext);
			return(IPADDR);
			}

IN			{
			debugf("IN\n");
			zonelval.string = strdup(zonetext);
			return(CLASS);
			}

SOA			{
			debugf("SOA\n");
			return(SOA);
			}

	/* all the different rr-types we know and handle */
A		|
AAAA	|
A6		|
AFSDB	|
APL		|
CERT	|
CNAME	|
DNAME	|
GPOS	|
HINFO	|
ISDN	|
KEY		|
KX		|
LOC		|
MX		|
NAPTR	|
NSAP	|
NS		|
NXT		|
PTR		|
PX		|
RP		|
RT		|
SIG		|
SRV		|
TXT		|
WKS		|
X25		{
			debugfv("TYPE (%s)\n", zonetext);
			zonelval.string = strdup(zonetext);
			BEGIN generic;
			return TYPE;
		}

{domain} |
{new_domain} |
\@			{
			debugfv("DOMAIN (%s)\n", zonetext);
			zonelval.string = strdup(zonetext);
			return(DOMAIN);
			}

"("			{
			debugf("LPAREN\n");
			BEGIN ignr_lnbrk;
			}

")"			{
			debugf("RPAREN\n");
			BEGIN INITIAL;
			}

<generic>[^ \t\n\r]([^\n\r])* {
			debugfv("GENERIC (%s)\n", zonetext);
			zonelval.string = strdup(zonetext);
			BEGIN INITIAL;
			return GENERIC;
			}

<*>{space}+		/* ignore whitespace */
<*>"\r"+			/* ignore ^M's */

";"(.*)			{
			debugfv("COMMENT (%s)\n", zonetext);
			}

<*>.			{
			debugfv("Unknown (%s)\n", zonetext);
			}

%%

void zoneerror(char *errmsg)
{
	fprintf(stderr, "smt_dns_ra parser, line %d: %s at '%s'\n", zonelineno, errmsg, zonetext);
}

#ifdef DEBUG_LEX
int main(int argc, char** argv)
{
	zonein = stdin;
	zoneout = stdout;
	while(zonelex()) { }

	return 0;
}
#endif
