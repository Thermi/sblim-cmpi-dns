/*
 * zonecache.h
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
#ifndef _ZONECACHE_H_
#define _ZONECACHE_H_
#include <fam.h>

#ifndef ALARM_INTERVAL
	#define ALARM_INTERVAL 2
#endif

#ifndef ENTRIES
	#define ENTRIES 50
#endif

struct entry{
	char *filename;
	FAMRequest fr;
};



void init_entries(void);
void destroy_entries(void);
struct entry *add_entry(char *);
struct entry *find_entry(char *);
void del_entry(struct entry *);
int init_monitor();
int monitor_file(char *);
int unmonitor_file(char *);

#endif 
