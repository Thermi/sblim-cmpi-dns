/*
 * parser_support.c
 *
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser_support.h"

DATASET *initset(int datasize, int (*add)(void *, int, void *, void *))
{
  DATASET *set = (DATASET *)malloc(sizeof(DATASET));

  if (!set)
    goto fail;

  set->count = 0;
  set->size = DEFAULT_SET_SIZE;
  set->datasize = datasize;
  set->add = add;

  set->data = calloc(DEFAULT_SET_SIZE + 1, datasize);

  if (!set->data)
    goto fail;

  return set;

 fail:
  return NULL;
}

static void growset(DATASET *set)
{
  int resize = set->size + SIZE_INCREMENT;
  void *tdata = realloc(set->data, (set->datasize * (resize + 1)));

  if (tdata) {
    set->data = tdata;
    set->size = resize;
  }
}

void adddata(DATASET *set, void *data1, void *data2)
{
  if (set->count >= set->size) {
    growset(set);
    if (set->count >= set->size)
      return;
  }

  set->add(set->data, set->count, data1, data2);

  set->count++;
}

int addrecord(RRECORD *records, int index, RRECORD *record, void *ignr)
{
  records[index].recordName = strdup(record->recordName);
  records[index].recordZoneName = strdup(record->recordZoneName);
  records[index].recordType = strdup(record->recordType);
  records[index].recordValue = strdup(record->recordValue);
  if (record->recordClass)
    records[index].recordClass = strdup(record->recordClass);
  else
    records[index].recordClass = NULL;
  records[index].recordTTL = record->recordTTL;

  index++;

  records[index].recordName = NULL;
  records[index].recordZoneName = NULL;
  records[index].recordType = NULL;
  records[index].recordValue = NULL;
  records[index].recordClass = NULL;
  records[index].recordTTL = -1;

  return 1;
}

int addoption(OPTS *opts, int index, char *key, char *value)
{
  opts[index].key = strdup(key);
  opts[index].value = strdup(value);

  index++;

  opts[index].key = NULL;
  opts[index].value = NULL;

  return 1;
}

int addmaster(MASTER *masters, int index, OPTS *opts, UL64 *port)
{
  masters[index].key = strdup(opts->key);
  masters[index].value = strdup(opts->value);
  masters[index].port = *port;

  index++;

  masters[index].key = NULL;
  masters[index].value = NULL;
  masters[index].port = 0;

  return 1;
}

int addzone(DNSZONE *zones, int index, char *zoneName, OPTS *zopts)
{
  zones[index].zoneName = strdup(zoneName);
  zones[index].zopts = zopts;

  index++;

  zones[index].zoneName = NULL;
  zones[index].zoneType = NULL;
  zones[index].zoneFileName = NULL;
  zones[index].soaContact = NULL;
  zones[index].soaServer = NULL;
  zones[index].soaSerialNumber = 0;
  zones[index].soaRefresh = 0;
  zones[index].soaRetry = 0;
  zones[index].soaExpire = 0;
  zones[index].soaNegativeCachingTTL = 0;
  zones[index].zoneTTL = -1;
  zones[index].records = NULL;
  zones[index].zopts = NULL;

  return 1;
}

DATASET *stripset(DATASET *set)
{
  void *tdata;
  if (set->count < set->size) {
    tdata = realloc(set->data, (set->datasize * (set->count + 1)));
    if (tdata) {
      set->data = tdata;
      set->size = set->count;
    }
  }

  return set;
}

#ifdef _NO_DEF

void printopts(OPTSET *options)
{
  printf("\nSize: %d\tCount: %d\n\n", options->size, options->count);

  OPTS *opts = options->opts;

  while (opts && opts->value && opts->key) {
    printf("\tValue: %s\tKey: %s\n", opts->key, opts->value);
    opts++;
  }
}

#endif

#ifdef DEBUG_SUPPORT
int main(int argc, char **argv)
{
  OPTSET *testopts;

  testopts = initset();

  printopts(testopts);

  addoption(testopts, "car", "mustang");
  addoption(testopts, "dodge", "ram");
  addoption(testopts, "bloody mary", "brunch");

  printopts(testopts);

  stripset(testopts);

  printopts(testopts);

  addoption(testopts, "lex", "flex");
  addoption(testopts, "yacc", "bison");

  printopts(testopts);

  stripset(testopts);

  printopts(testopts);

  return(0);
}
#endif
