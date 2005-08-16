 /**
 * perlstr.h
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
 * author:    Glauber de Oliveira Costa <gocosta@br.ibm.com> 
 *
 * Contributors:
 *
 */
#define PERLPREF "use lib '/usr/share/YaST2/modules';\n" \
                 "use YaPI::DNSD;\n"

#define RECORDIN "  ,\n" \
                 "  'records' => [\n" 
                 

#define RECORDOUT  "  ]\n"


/* Record substitutions: value, type, key */
#define RECORDDEF  "   {\n" \
                   "    'value' => '%s',\n" \
		   "    'type' => '%s',\n" \
                   "    'key' => '%s'\n" \
                   "   }\n"


#define ZONEIN   "my $zones = [];\n" \
                 

#define WRITEZONES  "my $w = YaPI::DNSD->WriteZones ({}, $zones); $wstatus = ${w};\n"


/* Zone substitutions: type, file, zone, file, type, min, expire, serial, 
                       retry, refresh, contact, server */
#define ZONEDEF "$$zones[$#$zones +1] = { \n" \
        "  'options' => [\n" \
        "   {\n" \
        "     'value' => '%s',\n" \
        "     'key' => 'type'\n" \
        "   },\n" \
        "   {\n" \
        "     'value' => '\"%s\"',\n" \
        "     'key' => 'file'\n" \
        "   }\n" \
        "  ],\n" \
        "  'zone' => '%s',\n" \
        "  'file' => '%s',\n" \
        "  'type' => '%s',\n" \
        "  'soa' => {\n" \
        "   'minimum' => '%s',\n" \
        "   'expiry' => '%s',\n" \
        "   'serial' => '%lld',\n" \
        "   'retry' => '%s',\n" \
        "   'refresh' => '%s',\n" \
        "   'mail' => '%s',\n" \
        "   'server' => '%s'\n" \
	"  }\n"

#define ZONEEND " };\n"

#define ZONEOPT " $zone = $$zones[-1];\n" \
								" $opt = $$zone{'options'};\n" \
								" $$opt[$#$opt +1] =" \
								" {\n" \
								" 	'value' => '%s', \n" \
								" 	'key' => '%s'\n" \
								" };\n" 

#define MASTERS  "$zone = $$zones[-1];\n" \
								 "$zone->{'masters'} = '%s';\n"

#define OPTIN  "my $options = [];\n"

#define OPTDEF "$$options[$#$options +1] = {\n" \
							 " 'value' => '%s', \n"\
							 " 'key' => '%s' \n"\
							 " };\n"

#define ACLIN "my $acl = [];\n"

#define ACLDEF "$$acl[$#$acl+1] = '%s %s'\n" \

