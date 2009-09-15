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
#include "conf.parser.tab.h"

#ifdef DEBUG_LEX
#define debugf(s) printf(s)
#define debugfv(s1, s2) printf((s1),(s2))
#else
#define debugf(s)
#define debugfv(s1, s2)
#endif

%}

DIGIT		([0-9])
ALPHA		([A-Za-z])
ALPHANUMERIC	([A-Za-z0-9])
EOLN		(\n)
WHITESPACE	([\t ]+)
FILENAME	([A-Za-z0-9\.][A-Za-z0-9\.\-\+\_]*)
PATHNAME	(\/?[A-Za-z0-9\.][A-Za-z0-9\.\-\+\_]*(\/[A-Za-z0-9\.][A-Za-z0-9\.\-\+\_]*)*\/?)
HOSTNAME	([A-Za-z][A-Za-z0-9\-\_]*(\.[A-Za-z][A-Za-z0-9\-\_]*)*)

ipaddr		([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3})
ipprefix	(([0-9]{1,3})(\.([0-9]{1,3})){0,3})(\/[0-9]{1,2})


WORD		([A-Za-z][A-Za-z]*)

digit		[0-9]
letter		[a-zA-Z]
special		[/_-]
space		[\t ]
string		\"([^\\"]|\\.)*\"
literal		({letter}|{special})({letter}|{special}|{digit})*
number		[0-9]+

%option prefix="conf"
%option noyywrap
%option yylineno
%option nounput

%x mlc

%%

acl			{
			debugf("ACL\n");
			return(ACL);
			}

controls		{
			debugf("CONTROLS\n");
			return(CONTROLS);
			}

masters			{
			debugf("MASTERS\n");
			conflval.string = strdup(conftext);
			return(MASTERS);
			}

include			{
			debugf("INCLUDE\n");
			return(INCLUDE);
			}

key			{
			debugf("KEY\n");
			return(KEY);
			}

keys			{
			debugf("KEYS\n");
			return(KEYS);
			}

inet			{
			debugf("INET\n");
			return(INET);
			}

allow			{
			debugf("ALLOW\n");
			return(ALLOW);
			}

logging			{
			debugf("LOGGING\n");
			return(LOGGING);
			}

lwres			{
			debugf("LWRES\n");
			return(LWRES);
			}

options			{
			debugf("OPTIONS\n");
			return(OPTIONS);
			}

server			{
			debugf("SERVER\n");
			return(SERVER);
			}

trusted-keys		{
			debugf("TRUSTEDKEYS\n");
			return(TRUSTEDKEYS);
			}

view			{
			debugf("VIEW\n");
			return(VIEW);
			}

zone			{
			debugf("ZONE\n");
			return(ZONE);
			}

port			{
			debugf("PORT\n");
			return(PORT);
			}

\{			{
			debugf("LBRACE\n");
			return(LBRACE);
			}

\}			{
			debugf("RBRACE\n");
			return(RBRACE);
			}

,			{
			debugf("COMMA\n");
			return(COMMA);
			}

;			{
			debugf("SEMICOLON\n");
			return(SEMICOLON);
			}

\!			{
			debugf("NOT");
			return(NOT);
			}

{ipaddr}		{
			debugfv("IPADDR (%s)\n",conftext);
			conflval.string = strdup(conftext);
			return(IPADDR);
			}

{ipprefix}		{
			debugfv("IPPREFIX (%s)\n",conftext);
			conflval.string = strdup(conftext);
			return(IPPREFIX);
			}

{string}		{
			debugfv("STRING (%s)\n",conftext);
			conflval.string = strdup(conftext);
			return(STRING);
			}

"//"(.*)		/* ignore C style comments */

{literal}		{
			debugfv("LITERAL (%s)\n",conftext);
			conflval.string = strdup(conftext);
			return(LITERAL);
			}

{number}		{
			debugfv("NUMBER (%s)\n",conftext);
			conflval.num = atoll(conftext);
			return(NUMBER);
			}

{space}+		/* ignore whitespace */
"\r"+			/* ignore ^M's */

<INITIAL,mlc>\n		{
			conflineno++;
			}

"#"(.*)			/* ignore shell style comments */

"/*"			BEGIN mlc;
<mlc>"*"+[^*/]		/* ignore stray astericks */
<mlc>[^*\n]*		/* ignore anything but astericks and newlines */
<mlc>"*"+"/"		BEGIN INITIAL;

%%

void conferror(char *errmsg)
{
	fprintf(stderr, "smt_dns_ra parser, line %d: %s at '%s'\n", conflineno, errmsg, conftext);
}

#ifdef DEBUG_LEX
int main(int argc, char** argv)
{
	confin = stdin;
	confout = stdout;
	while(conflex()) { }

	return 0;
}
#endif
