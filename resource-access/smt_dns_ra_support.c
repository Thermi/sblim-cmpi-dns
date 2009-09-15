 /*
 * smt_dns_ra_support.c 
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
 * Author:       Viktor Mihajlovski        <MIHAJLOV@de.ibm.com> 
 *
 * Contributors: Glauber de Oliveira Costa <gocosta@br.ibm.com>
 *               Tyrel Datwyler            <tyreld@us.ibm.com>
 *
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>
#include <smt_libra_rastr.h>
#include <smt_libra_execscripts.h>
#include <smt_libra_conf.h>

#include "smt_dns_ra_rrhandle.h"
#include "smt_dns_ra_support.h"
#include "smt_dns_ra_cache.h"

#ifndef CONFFILE
  #define CONFFILE "/etc/smt_dns_ra_support.conf"
#endif

extern int confparsefile(FILE *infile, FILE *outfile, DNSCONF *conf);
extern int zoneparsefile(FILE *infile, FILE *outfile, DNSZONE *zone);

struct conf *dns_conf = NULL;

static pthread_mutex_t rw_mutex;
static pthread_once_t single_init = PTHREAD_ONCE_INIT;

void ra_mutex_init(void)
{
  pthread_mutexattr_t attr;

  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&rw_mutex, &attr);
  pthread_mutexattr_destroy(&attr);
}

char *my_script_path(char *filename){
  if (!dns_conf){
    dns_conf = read_conf(CONFFILE,CONFFILE);
  }
  
  return script_path(dns_conf,filename);
}	

void copy_zoneOpts( DNSZONE *dest, ZONEOPTS *zOpts) {

  int size = 0;
  ZONEOPTS * srcZOpts = NULL;
  ZONEOPTS * destZOpts = NULL;

  srcZOpts = zOpts;

  //find the size of the zoneOpts

  while (srcZOpts && srcZOpts->key) {
    size++;
    srcZOpts++;
  }

  //allocate space

  dest->zoneOpts = calloc((size+1), sizeof(ZONEOPTS));

  //now copy them

  srcZOpts = zOpts;
  destZOpts = dest->zoneOpts;

  while(srcZOpts && srcZOpts->key) {
    destZOpts->key = strdup(srcZOpts->key);

    if (srcZOpts->value)
      destZOpts->value = strdup(srcZOpts->value);

    destZOpts++;
    srcZOpts++;
  }

}

void copy_rrecords( DNSZONE *dest, DNSRECORD *rec) {

  int size = 0;
  DNSRECORD * srcRecords = NULL;
  DNSRECORD * destRecords = NULL;

  srcRecords = rec;

  //find the size of the records

  while (srcRecords && srcRecords->recordName) {
    size++;
    srcRecords++;
  }

  //allocate space

  dest->records = calloc((size+1), sizeof(DNSRECORD));

  //now copy them

  srcRecords = rec;
  destRecords = dest->records;

  while(srcRecords && srcRecords->recordName) {
    //copy non pointer attributes..
    destRecords->recordTTL = srcRecords->recordTTL;

    //copy the pointer-type attributes..
    destRecords->recordName = strdup(srcRecords->recordName);

    if (srcRecords->recordZoneName)
      destRecords->recordZoneName = strdup(srcRecords->recordZoneName);

    if (srcRecords->recordType)
      destRecords->recordType = strdup(srcRecords->recordType);

    if (srcRecords->recordValue)
      destRecords->recordValue = strdup(srcRecords->recordValue);

    if (srcRecords->recordClass)
      destRecords->recordClass = strdup(srcRecords->recordClass);

    destRecords++;
    srcRecords++;
  }

}

void copy_zone (DNSZONE * dest, DNSZONE *src) {

  // copy non-pointer attributes
  dest->soaSerialNumber = src->soaSerialNumber;
  dest->soaRefresh = src->soaRefresh;
  dest->soaRetry = src->soaRetry;
  dest->soaExpire = src->soaExpire;
  dest->soaNegativeCachingTTL = src->soaNegativeCachingTTL;

  dest->zoneTTL = src->zoneTTL;

  // copy pointer-type attributes
  if (src->zoneName)
    dest->zoneName=strdup(src->zoneName);
  else
    dest->zoneName=NULL;

  if (src->zoneType)
    dest->zoneType=strdup(src->zoneType);
  else
    dest->zoneType=NULL;

  if (src->zoneFileName)
    dest->zoneFileName=strdup(src->zoneFileName);
  else
    dest->zoneFileName=NULL;

  if (src->soaContact)
    dest->soaContact=strdup(src->soaContact);
  else
    dest->soaContact=NULL;

  if (src->soaServer)
    dest->soaServer=strdup(src->soaServer);
  else
    dest->soaServer=NULL;

  if (src->records)
    copy_rrecords(dest, src->records);
  else
    dest->records=NULL;

  if (src->zoneOpts)
    copy_zoneOpts(dest, src->zoneOpts);
  else
    dest->zoneOpts=NULL;

}

void deleteSubStr(char * dest, char * src) {

   char * temp, * ptr;
   int j, src_len;

   temp = dest ;
//   temp = strdup(dest);
   src_len = strlen(src);

   while ( (ptr = strstr(temp,src)) != NULL ) {
        for (j = 0; ptr[ src_len + j ] != '\0' && ptr [ src_len + j ] == ' '; j++ ) ;
        if ( ptr[ src_len + j ] != '\0' && ptr [ src_len + j ] == ';' ) j++ ;
        for (; ptr[ src_len + j ] != '\0' && ptr [ src_len + j ] == ' '; j++ ) ;

        strcpy(ptr, ( ptr + src_len + j)) ;
   }

//   free (dest);
//   dest = calloc ( strlen(temp)+1 , sizeof(char));
//   for (j = 0; temp[j] != '\0' ; j++) dest[j] = temp[j];
//   dest[j] = '\0';
//   free (temp);

}

int isIPV4(const char *str )
{
  int i = 0;
  char * pos, * dot_pos, *last_dot_pos=NULL;
  char * temp;
  unsigned int value = 0;
  int dot_count = 0;

  pos = (char *) str;

  while ( (dot_pos = strchr(pos,'.'))!=NULL) {
       dot_count ++ ;
       if (dot_count > 3) return 0;
       value = 0;
       for ( i = 1, temp = pos; temp != dot_pos; temp++, i++ ) {
          if (! isdigit(*temp)) return 0;
          value =  (10 * value ) +  ((*temp)-0x30) ;
          if (value > 255 ) return 0;
       }
       if ( i == 1 ) return 0;
       pos = dot_pos + 1;
       last_dot_pos = dot_pos;
  }
  if (dot_count != 3) return 0;
  if (last_dot_pos == NULL) return 0; 
  value = 0;
  for ( i = 1, temp = last_dot_pos +1 ; *temp!='\0' ; temp++, i++) {
     if (! isdigit(*temp)) return 0;
     value =  (10 * value ) +  ((*temp)-0x30) ;
     if (value > 255 ) return 0;
  }

  return 1;
}

int isIPV6(const char *str) {
  int i = 0; 
  char * pos, * colon_pos, *last_colon_pos=NULL;
  char * temp;
  unsigned int value = 0;
  int colon_count = 0;

  pos = (char *) str;

  while ( (colon_pos = strchr(pos,':'))!=NULL) {
       colon_count ++ ;
       if (colon_count > 7) return 0;
       value = 0;
       for ( i = 1, temp = pos; temp != colon_pos; temp++, i++ ) {
          if (! isxdigit(*temp)) return 0;
          if (isdigit(*temp))
            value =  (16 * value ) +  ((*temp)-0x30) ;
          else
            value =  (16 * value ) +  (toupper((*temp))-'A'+10);
          if (value > 0xffff ) return 0;
       }
       pos = colon_pos + 1;
       last_colon_pos = colon_pos;
  }
//if (colon_count != 7) return 0;
  if (last_colon_pos == NULL) return 0; 
  value = 0;
  for ( i = 1, temp = last_colon_pos +1 ; *temp!='\0' ; temp++, i++) {
     if (! isxdigit(*temp)) return 0;
     if (isdigit(*temp))
       value =  (16 * value ) +  ((*temp)-0x30) ;
     else
       value =  (16 * value ) +  (toupper((*temp))-'A'+10);
     if (value > 0xffff ) return 0;
  }

  return 1;
}

int isIPPrefix (const char * str) { 

  int i = 0;
  char * pos, * dot_pos;
  char * temp;
  unsigned int value = 0;
  int dot_count = 0;

  int colon_count = 0;

  char * colon_pos;

  char * last_colon_pos = NULL, * last_dot_pos = NULL;
  int valid_IP_addr = 0;


  pos = (char *) str;
  if (strchr(str,'.')) {
  while ( (dot_pos = strchr(pos,'.'))!=NULL) {
       dot_count ++ ;
       if (dot_count > 3) return 0;
       value = 0;
       for ( i = 1, temp = pos; temp != dot_pos; temp++, i++ ) {
          if (! isdigit(*temp)) return 0;
          value =  (10 * value ) +  ((*temp)-0x30) ;
          if (value > 255 ) return 0;
       }
       if( i == 1) return 0 ;
       pos = dot_pos + 1;
       last_dot_pos = dot_pos;
  }
  if (last_dot_pos == NULL) return 0; 
  value = 0;
  for ( i = 1, temp = last_dot_pos +1 ; *temp!='/' ; temp++, i++) {
     if (! isdigit(*temp)) return 0;
     value =  (10 * value ) +  ((*temp)-0x30) ;
     if (value > 255 ) return 0;
  }

  valid_IP_addr = 1;
  }
  else if (strchr(pos,':')) {

  while ( (colon_pos = strchr(pos,':'))!=NULL) {
       colon_count ++ ;
       if (colon_count > 7) return 0;
       value = 0;
       for ( i = 1, temp = pos; temp != colon_pos; temp++, i++ ) {
          if (! isxdigit(*temp)) return 0;
          if (isdigit(*temp))
            value =  (16 * value ) +  ((*temp)-0x30) ;
          else
            value =  (16 * value ) +  (toupper((*temp))-'A'+10);
          if (value > 0xffff ) return 0;
       }
       pos = colon_pos + 1;
       last_colon_pos = colon_pos;
  }
  if (last_colon_pos == NULL) return 0; 
  value = 0;
  for ( i = 1, temp = last_colon_pos +1 ; *temp!='/' ; temp++, i++) {
     if (! isxdigit(*temp)) return 0;
     if (isdigit(*temp))
       value =  (16 * value ) +  ((*temp)-0x30) ;
     else
       value =  (16 * value ) +  (toupper((*temp))-'A'+10);
     if (value > 0xffff ) return 0;
  }

  valid_IP_addr = 2;
  }

  if ( valid_IP_addr ) {

    temp++;
    value = 0;
    for (; *temp != '\0'; temp++) {
       if (! isdigit(*temp)) return 0;
       value =  (10 * value ) +  ((*temp)-0x30) ;
       if (valid_IP_addr == 1 ) {
         if (value > 32 ) return 0;
       }
       else { 
         if (value > 64 ) return 0;
       }
    }
    return 1;
  }
  else
   return 0;
}

static int sint64_to_BindTime(signed long long sll, char * time)
{
  signed long long divresult = sll;
  signed long long modresult = 0;
  char suffix = ' ';
  if (time) {
    modresult = sll % 60;
    if (modresult == 0 && (divresult / 60)) {
      divresult /= 60;
      suffix = 'M';
      if (divresult >= 60) {
	modresult = divresult % 60;
	if (modresult == 0) {
	  divresult /= 60;
	  suffix = 'H';
	  if (divresult >= 24) {
	    modresult = divresult %24;
	    if (modresult == 0) {
	      divresult /= 24;
	      suffix = 'D';
	      if (divresult >= 7) {
		modresult = divresult % 7;
		if (modresult == 0) {
		  divresult /= 7;
		  suffix = 'W';
		}
	      }
	    }
	  }
	}
      }
    }
  
    sprintf(time, "%lld%c",divresult, suffix);

    return 0;
  } else
    return 1;
}

//static void memFree_RRs( DNSRECORD * record ) {
//
//   DNSRECORD * record_start = NULL;
//
//   if (! record )
//     return ;
//
//   record_start = record;
//
//   while (record && record->recordName) {
//     free(record->recordName);
//     if (record->recordZoneName) free(record->recordZoneName);
//     if (record->recordType) free(record->recordType);
//     if (record->recordValue) free(record->recordValue);
//     if (record->recordClass) free(record->recordClass);
//
//     record++;
//   }
//
//   free(record_start) ;
//
//   return ;
//}

//static void memFree_ZoneOpts( ZONEOPTS * zOpts ) {
//
//   ZONEOPTS * zOpts_start = NULL;
//
//   if (! zOpts )
//     return ;
//
//   zOpts_start = zOpts;
//
//   while (zOpts && zOpts->key) {
//     free(zOpts->key);
//     if (zOpts->value) free(zOpts->value);
//     zOpts++;
//   }
//
//   free(zOpts_start) ;
//
//   return ;
//}

//static void memFree_Zone( DNSZONE * zone ) {
//
//   if (! zone )
//     return ;
//
//   while (zone && zone->zoneName) {
//     free(zone->zoneName);
//     if (zone->zoneType) free(zone->zoneType);
//     if (zone->zoneFileName) free(zone->zoneFileName);
//     if (zone->soaContact) free(zone->soaContact);
//     if (zone->soaServer) free(zone->soaServer);
//     
//     if (zone->records) memFree_RRs(zone->records); 
//     if (zone->zoneOpts) memFree_ZoneOpts(zone->zoneOpts); 
//
//     zone++;
//   }
//
//   return ;
//}

char * getDefaultDirectory() {

  char *conffile = NULL;
  char *tmp=NULL, *tmp2=NULL; 

  pthread_mutex_lock(&rw_mutex);

  if ( !dns_conf ) {
    dns_conf = read_conf(CONFFILE,CONFFILE);
    if ( !dns_conf ) {
      pthread_mutex_unlock(&rw_mutex);
      return strdup(BINDDIR);
    }
  }

  conffile = get_conf(dns_conf,"bindconf");

  if (!conffile) {
    conffile = strdup(BINDDIR);
  }
  else {

    tmp = strdup(conffile);
    tmp2 = tmp + strlen(tmp) ;

    while( (tmp2 != tmp) && (*tmp2 != '/')) tmp2--;
    if (tmp2 != tmp) {
      conffile = calloc(tmp2-tmp+1,sizeof(char));
      strncpy(conffile,tmp,tmp2-tmp);
    }
    else {
      if (*tmp2 == '/') 
        conffile = strdup("/"); 
      else 
        conffile = strdup(BINDDIR); 
    } 
    free(tmp); 
  } 

  pthread_mutex_unlock(&rw_mutex);
  return conffile;
}


void deleteZoneFile( const char * zoneFileName) {

  char *zone_dir;
  char *dir;
  char *tmp1, *tmp2;
  char *filename; 
  char *token; 

  int length; 
  int err = 0;


    if (!zoneFileName)
      return ;

    pthread_mutex_lock(&rw_mutex);
    zone_dir = getOption(global_dns_conf->bopts, "directory");
    pthread_mutex_unlock(&rw_mutex);

    if (! zone_dir) {
      zone_dir = getDefaultDirectory();
    }

    dir = stripQuotes(zone_dir);
    free(zone_dir);

    length = strlen(zoneFileName) + strlen(dir);
    filename = (char *)calloc((length + 2), sizeof(char));

    filename = strcat(filename, dir);
    free(dir);

    tmp1 = strdup(stripQuotes(zoneFileName));
    tmp2 = tmp1;

    while ((token = strsep(&tmp1, "/")) && tmp1) {
      filename = strcat(filename, "/");
      filename = strcat(filename, token);

      if (access(filename, F_OK)) {
	  fprintf(stderr, "The directory \"%s\" does not exists\n", filename);
	  err = 1;
	  break;
      }
    }

    filename = strcat(filename, "/");
    filename = strcat(filename, token);

    free(tmp2);

    if (!err) {
      if (!access(filename, F_OK)) {
        if (unlink(filename)) {
          fprintf(stderr,"The file \"%s\" could not be deleted\n", filename);
        }
      }
   }

   free(filename);
   return ;
}

static int uint64_to_BindTime(unsigned long long ull, char * time)
{
  unsigned long long divresult = ull;
  unsigned long long modresult = 0;
  char suffix = ' ';
  if (time) {
    /* minutes */
    modresult = ull % 60;
    if (modresult==0 && (divresult/60)) {
      divresult /= 60;
      suffix = 'M';
      if (divresult >= 60) {
	/* hours */
	modresult = divresult % 60;
	if (modresult==0) {
	  divresult /= 60;
	  suffix = 'H'; 
	  if (divresult >= 24) {
	    /* days */
	    modresult = divresult % 24;
	    if (modresult==0) {
	      divresult /= 24;
	      suffix = 'D'; 
	      if (divresult >= 7) {
		/* weeks */
		modresult = divresult % 7;
		if (modresult == 0) {
		  divresult /= 7;
		  suffix = 'W';
		}
	      }
	    }
	  }
	}
      }
    }
    
    sprintf(time,"%llu%c",divresult,suffix);
    
    return 0;
  } else {
    return -1;
  }
}

/*
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
*/

static int ReadConf()
{
  int result = 1;

  pthread_once(&single_init, ra_mutex_init);

  pthread_mutex_lock(&rw_mutex);

  if (!global_dns_conf)
    global_dns_conf = allocDnsConf();

  char *filename = get_bindconf();
    
  struct stat buf;
  if (!stat(filename, &buf) && S_ISREG(buf.st_mode) && !access(filename, R_OK)) {
    FILE *file = fopen(filename, "r");
    
    if (file) {
      result = confparsefile(file, NULL, global_dns_conf);
      fclose(file);
    }
    else
      fprintf(stderr, "unable to open bind config file: %s", filename);
      
    if(filename) free(filename);
  }
  
  if (!result && global_dns_conf->bopts) {
    DNSZONE *zones;
    
    zones = global_dns_conf->zones;

    if (!zones) {
      zones = calloc(1, sizeof(DNSZONE));
      zones->zoneName = NULL;
    }
    
    while (!result && zones && zones->zoneName) {
      ZONEOPTS *z = findOptsInZone(zones, "type");
      if (z && z->value)
	zones->zoneType = z->value;
      
      z = findOptsInZone(zones, "file");
      if (z && z->value) {
	struct stat buf;
	char *dir;
	char *zone_dir;

	dir = getOption(global_dns_conf->bopts, "directory");
	if (!dir)
	  dir = getDefaultDirectory();

	zone_dir = stripQuotes(dir);
	
	char *filename = (char *)malloc((strlen(zone_dir) + strlen(z->value) + 2) * sizeof(char *));
	zones->zoneFileName = stripQuotes(z->value);
	
	filename[0] = '\0';
	
	strcat(filename, zone_dir);
	strcat(filename, "/");
	strcat(filename, zones->zoneFileName);    
	
	// Read in zone info
	
	if (!stat(filename, &buf) && S_ISREG(buf.st_mode) && !access(filename, R_OK)) {
	  FILE *file = fopen(filename, "r");
	  if (file) {
	    result = zoneparsefile(file, NULL, zones);
	    fclose(file);
          }
	  else
	    fprintf(stderr, "unable to open zone file for reading: %s", filename);
	}
	
	if(zone_dir) free(zone_dir);
	if (dir) free(dir);
	if (filename) free(filename);
      }
      
      zones++;
    }
  }

  pthread_mutex_unlock(&rw_mutex);
  return result;
}

static int _writeOptions(FILE *file)
{
  BINDOPTS *bopts;
  char *buf = malloc(sizeof(char) * BUFSIZE);

  pthread_mutex_lock(&rw_mutex);

  bopts = global_dns_conf->bopts;

  snprintf(buf, BUFSIZE, "// This file was automatically generated by the sblim-cmpi-dns provider.\n\n");
  if (fputs(buf, file) == EOF)
    goto error;

  snprintf(buf, BUFSIZE, "options {\n");
  if (fputs(buf, file) == EOF)
    goto error;

  while (bopts && bopts->key && bopts->value) {
    snprintf(buf, BUFSIZE, "\t%s %s;\n", bopts->key, bopts->value);
    if (fputs(buf, file) == EOF)
      goto error;

    bopts++;
  }

  snprintf(buf, BUFSIZE, "};\n\n");
  if (fputs(buf, file) == EOF)
    goto error;

  pthread_mutex_unlock(&rw_mutex);
  return 0;

 error:
  if (ferror(file))
    fprintf(stderr, "error writing options\n");

  pthread_mutex_unlock(&rw_mutex);
  return 1;
}

static int _writeMasters(FILE *file)
{
  MASTERS *masters;
  char *buf = malloc(sizeof(char) * BUFSIZE);

  pthread_mutex_lock(&rw_mutex);

  masters = global_dns_conf->masters;

  while (masters && masters->key && masters->value) {
    if (masters->port > 0) {
      snprintf(buf, BUFSIZE, "masters %s port %llu %s;\n\n", masters->key, masters->port, masters->value);
      if (fputs(buf, file) == EOF)
	goto error;
    } else {
      snprintf(buf, BUFSIZE, "masters %s %s;\n\n", masters->key, masters->value);
      if (fputs(buf, file) == EOF)
	goto error;
    }

    masters++;
  }

  pthread_mutex_unlock(&rw_mutex);
  return 0;

 error:
  if (ferror(file))
    fprintf(stderr, "error writing masters\n");

  pthread_mutex_unlock(&rw_mutex);
  return 1;
}
	

static int _writeACLs(FILE *file)
{
  ACL *acls;
  char *buf = malloc(sizeof(char) * BUFSIZE);

  pthread_mutex_lock(&rw_mutex);

  acls = global_dns_conf->acls;

  while (acls && acls->key && acls->value) {
    snprintf(buf, BUFSIZE, "acl %s %s;\n\n", acls->key, acls->value);
    if (fputs(buf, file) == EOF)
      goto error;

    acls++;
  }

  pthread_mutex_unlock(&rw_mutex);
  return 0;

 error:
  if (ferror(file))
    fprintf(stderr, "error writing acls\n");

  pthread_mutex_unlock(&rw_mutex);
  return 1;
}

static int _writeZones(FILE *file)
{
  DNSZONE *zones;
  char *buf = malloc(sizeof(char) * BUFSIZE);
  
  pthread_mutex_lock(&rw_mutex);

  zones = global_dns_conf->zones;

  while (zones && zones->zoneName && zones->zoneOpts) {
    ZONEOPTS *zopts = zones->zoneOpts;

    snprintf(buf, BUFSIZE, "zone \"%s\" IN {\n", zones->zoneName);
    if (fputs(buf, file) == EOF)
      goto error;

    while (zopts && zopts->key && zopts->value) {
      snprintf(buf, BUFSIZE, "\t%s %s;\n", zopts->key, zopts->value);
      if (fputs(buf, file) == EOF)
	goto error;

      zopts++;
    }

    snprintf(buf, BUFSIZE, "};\n\n");
    if (fputs(buf, file) == EOF)
      goto error;
 
    zones++;
  }

  pthread_mutex_unlock(&rw_mutex);
  return 0;

 error:
  if (ferror(file))
    fprintf(stderr, "error writing zones\n");

  pthread_mutex_unlock(&rw_mutex);
  return 1;
}

static int WriteConf()
{
  int result = 1;

  pthread_mutex_lock(&rw_mutex);

  if (global_dns_conf) {
    char *filename = get_bindconf();    
    char *newfilename = (char *)malloc(sizeof(char) * (strlen(filename) + 5));

    *newfilename = '\0';
    newfilename = strcat(newfilename, filename);
    newfilename = strcat(newfilename, ".old");

    if (!access(filename, W_OK)) {
      FILE *file;

      if (!access(filename, F_OK))
	rename(filename, newfilename);
	
      mode_t prev_umask = umask(S_IWOTH|S_IWGRP);
      file = fopen(filename, "w");
	  umask(prev_umask);

      // Write Out "named.conf"

      if (file) {

	if (_writeOptions(file) || 
	    _writeMasters(file) || 
	    _writeACLs(file) || 
	    _writeZones(file)) {
	  fclose(file);
	  rename(newfilename, filename);
	} else {
	  result = fclose(file);
	}
      } else {
	fprintf(stderr, "unable to open configuration file for writing: %s\n", filename);
      }

      free(filename);
      free(newfilename);
    }
  }

  pthread_mutex_unlock(&rw_mutex);
  return result;
}

DNSZONE *getZones()
{
  DNSZONE *zones;

  pthread_once(&single_init, ra_mutex_init);
  pthread_mutex_lock(&rw_mutex);

  if (!global_dns_conf) {
    if (ReadConf()) {
      pthread_mutex_unlock(&rw_mutex);
      return NULL;
    }
  }

  zones = zone_from_global();

  pthread_mutex_unlock(&rw_mutex);
  return zones;
}

DNSZONE* __addZone(DNSZONE** zones, DNSZONE *newzone)
{
    off_t num;
    DNSZONE *zone;
    if (zones && newzone) {
	if (*zones == NULL) {
	    *zones = calloc(2,sizeof(DNSZONE));
	    num=0;
	} else {
	    num=0;
	    while((*zones)[num].zoneName) {
	      if (!strcmp((*zones)[num].zoneName, newzone->zoneName))
		goto duplicate;
	      num++;
	    }
	    *zones = realloc(*zones, sizeof(DNSZONE)*(num+2));
	}

    duplicate:
	zone = &((*zones)[num]);
//	zone = memcpy(zone, newzone, sizeof(DNSZONE));
        copy_zone(zone, newzone); 
	zone++;
	zone = memset(zone, 0, sizeof(DNSZONE));

	//	(*zones)[num] = (*zones)[num - 1]; 
	//      (*zones)[num-1] = *newzone; 

	return &(*zones)[num-1];
    } 
    return NULL;
}

int validrr(DNSRECORD *records){
  if (!records->recordName || 
      !records->recordValue ||
      !records->recordType )
    return 0;
  
  return 1;

}

DNSZONE* addZone(DNSZONE *zone,DNSRECORD *records){
	DNSZONE *actual_zones;
	actual_zones = getZones();

	while (records && records->recordName){
		if (!validrr(records)){
		        fprintf(stderr, "problem adding record.\n");
			records++;
			continue;
		}

		addRecord(zone,records);
		records++;	
	}	
	
	__addZone(&actual_zones,zone);
	if (!updateZones(actual_zones))
		return actual_zones; 

	freeZones( actual_zones );
	return NULL;

}

DNSZONE* findZone(DNSZONE* zones, const char * zonename)
{
    DNSZONE* iter_zones = zones;

    while(iter_zones && iter_zones->zoneName) {
	if (strcmp(iter_zones->zoneName,zonename)==0) {
	    return iter_zones;
	}
	iter_zones ++;
    }
    return NULL;
}

/*
  static int validzone(DNSZONE *dz){
  
  if (!strcmp(dz->zoneType,"master") && 
  (!dz || 
  !dz->zoneName ||
  !dz->zoneFileName ||
  !dz->zoneType ||
  !dz->soaContact ||
  !dz->soaServer ))
  return 0;
  
  if ((!strcmp(dz->zoneType,"slave") ||
  !strcmp(dz->zoneType,"stub")) &&
  (!dz || 
  !dz->zoneName ||
  !dz->zoneFileName ||
  !dz->zoneType ) )
  return 0;
  
  if (!strcmp(dz->zoneType,"hint") &&
  (!dz || 
  !dz->zoneName ||
  !dz->zoneFileName ||
  !dz->zoneType )) 
  return 0;
  
  if (!strcmp(dz->zoneType,"forward") &&	
  (!dz || 
  !dz->zoneName ||
  !dz->zoneType )) 
  return 0;
  
  return 1;	

  }
*/

static int _writeRecord(FILE *file, DNSZONE *zone)
{
  DNSRECORD *records = zone->records;
  int result = 0;
  char *time;
  char *buf = malloc(sizeof(char) * BUFSIZE);

  time = (char *)malloc(sizeof(char) * 15);

  if (!(zone->zoneTTL < 0)) {
    sint64_to_BindTime(zone->zoneTTL, time);
    snprintf(buf, BUFSIZE, "$TTL %s\n", time);
    if (fputs(buf, file) == EOF)
      goto error;
  }

  if (zone->soaContact && zone->soaServer) {
    snprintf(buf, BUFSIZE, "@\t\tIN SOA\t\t%s %s   (\n", zone->soaServer, zone->soaContact);
    if (fputs(buf, file) == EOF)
      goto error;

    snprintf(buf, BUFSIZE, "\t\t\t\t%llu\t\t; serial\n", zone->soaSerialNumber);
    if (fputs(buf, file) == EOF)
      goto error;

    result += uint64_to_BindTime(zone->soaRefresh, time);
    snprintf(buf, BUFSIZE, "\t\t\t\t%s\t\t; refresh\n", time);
    if (fputs(buf, file) == EOF)
      goto error;

    result += uint64_to_BindTime(zone->soaRetry, time);
    snprintf(buf, BUFSIZE, "\t\t\t\t%s\t\t; retry\n", time);
    if (fputs(buf, file) == EOF)
      goto error;

    result += uint64_to_BindTime(zone->soaExpire, time);
    snprintf(buf, BUFSIZE, "\t\t\t\t%s\t\t; expire\n", time);
    if (fputs(buf, file) == EOF)
      goto error;

    result += uint64_to_BindTime(zone->soaNegativeCachingTTL, time);
    snprintf(buf, BUFSIZE, "\t\t\t\t%s )\t\t; minimum ttl\n\n", time);
    if (fputs(buf, file) == EOF)
      goto error;
  }

  if (result < 0)
    return 1;

  while (records && 
	 records->recordName && 
	 records->recordType && 
	 records->recordValue) {
    char *class;

    if (records->recordClass)
      class = strdup(records->recordClass);
    else
      class = strdup("");

    if (records->recordTTL < 0)
      *time = '\0';
    else 
      sint64_to_BindTime(records->recordTTL, time);

    snprintf(buf, BUFSIZE, "%s\t\t%s %s %s\t\t%s\n", records->recordName, time, class, records->recordType, records->recordValue);
    free(class);
    if (fputs(buf, file) == EOF)
      goto error;

    records++;
  }

  free(time);

  return 0;

 error:
  if (ferror(file))
    fprintf(stderr, "error writing a zone file: %s", zone->zoneFileName);

  free(time);

  return 1;
}

static int WriteRRecords()
{
  DNSZONE *zones = global_dns_conf->zones;
  char *zone_dir;
  char *dir;

  while (zones && zones->zoneName) {
    int length = 0;
    char *filename;
    char *token;
    char *tmp1;
    char *tmp2;

    if (!zones->zoneFileName) {
      zones++;
      continue;
    }
    
    zone_dir = getOption(global_dns_conf->bopts, "directory");
    if (!zone_dir)
      zone_dir = getDefaultDirectory();

    dir = stripQuotes(zone_dir);

    length = strlen(zones->zoneFileName) + strlen(zone_dir);
    filename = (char *)malloc(sizeof(char) * (length + 2));
    
    *filename = '\0';
    filename = strcat(filename, dir);
    free(zone_dir);
    free(dir);

    tmp1 = strdup(stripQuotes(zones->zoneFileName));
    tmp2 = tmp1;

    while ((token = strsep(&tmp1, "/")) && tmp1) {
      filename = strcat(filename, "/");
      filename = strcat(filename, token);
      
      if (access(filename, F_OK)) {
	if (mkdir(filename, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)) {
	  fprintf(stderr, "failed to create directory: %s\n", filename);
	}
      }
    }

    filename = strcat(filename, "/");
    filename = strcat(filename, token);

    free(tmp2);

    if (access(filename, F_OK) || !access(filename, W_OK)) {
      FILE *file;
      mode_t prev_umask = umask(S_IWOTH|S_IWGRP);
      file = fopen(filename, "w");
      umask(prev_umask);

      if (file) {

	if (_writeRecord(file, zones)) {
	  fclose(file);
	  return 1;
	}

	if (fclose(file))
	  return 1;
      } else {
	fprintf(stderr, "unable to open zone file for writing: %s\n", filename);
      }
    }

    free(filename);
    
    zones++;
  }

  return 0;
}

int updateZones(DNSZONE *zones)
{
  DNSZONE *tmp;
  char *zone_dir;
  char *dir;;
  char *filename;
  int length;

  zone_dir = getOption(global_dns_conf->bopts, "directory");
  if (!zone_dir)
    zone_dir = getDefaultDirectory();

  dir = stripQuotes(zone_dir);

  pthread_mutex_lock(&rw_mutex);

  if (global_dns_conf && global_dns_conf->zones) {
      tmp = zone_from_global();

      while (tmp && tmp->zoneName) {
        if (tmp->zoneFileName) { 
          length = strlen(tmp->zoneFileName) + strlen(zone_dir);
          filename = (char *)malloc(sizeof(char) * (length + 2));
	
	  *filename = '\0';
	  filename = strcat(filename, dir);
	
	  filename = strcat(filename, "/");
	  filename = strcat(filename, stripQuotes(tmp->zoneFileName));
	
	  removeRR(filename);
	  free(filename);
        }
	
        tmp++;
      }
      
      freeZones(global_dns_conf->zones);
  }

  zone_to_global(zones);

  if (WriteConf()) {
    pthread_mutex_unlock(&rw_mutex);
    return 1;
  }
  
  if (WriteRRecords()) {
    pthread_mutex_unlock(&rw_mutex);
    return 1;
  }

  pthread_mutex_unlock(&rw_mutex);
  return 0;
}

DNSZONE* addOptsToZone(DNSZONE* zone, const char *key, const char *value){
        ZONEOPTS *zopts;
        int i = 0;
        if (!zone)
                return NULL; /* users of this function must be careful with this. */

        zopts = zone->zoneOpts;
        while (zopts && zopts->key){
                        i++;
                        zopts++;
        }
        zone->zoneOpts = realloc(zone->zoneOpts,(i+2)*sizeof(ZONEOPTS));
        zone->zoneOpts[i].key = strdup(key);
        zone->zoneOpts[i].value = strdup(value);

        zone->zoneOpts[i+1].key  = NULL;
        zone->zoneOpts[i+1].value = NULL;

//	addZone(zone, NULL);

        return zone;
}

ZONEOPTS* findOptsInZone(DNSZONE* zone, const char *key)
{
        ZONEOPTS *zopts;
        if (!zone)
                return NULL; 

        zopts = zone->zoneOpts;
        while (zopts && zopts->key){
		if ( strcmp(zopts->key,key) == 0 )
			return zopts;

		zopts++;
        }
	return NULL;
}

int delOptsFromZone(DNSZONE* zone, const char *key)
{
       ZONEOPTS* zopts = NULL; 
       int i = 0,j = 0;
       int found = 0;

//       DNSZONE * zones = NULL;  
//       DNSZONE * all_zones_start = NULL; 
//       DNSZONE * myZone = NULL; 
  
       if (!zone)
          return 0;
       
//       zones = getZones(); 
//       all_zones_start = zones; 

//       myZone = findZone(zones, zone->zoneName); 
 
//       if (myZone) { 
//         printf("\n Found myZone...\n"); 
//         zopts = myZone->zoneOpts; 
         zopts = zone->zoneOpts; 
//       } 
 
       while (zopts && zopts->key){
//           printf("zopts->key = %s; zopts->value = %s\n",zopts->key, zopts->value);
           if(found == 0 && strcmp(zopts->key, key) == 0) {
             j=i;
             found=1;
//             printf("Found the key...\n"); 
           }
           i++;
           zopts++;
       }
//       printf("Indexes - i = %d - j = %d\n",i, j);
       if (found) {
//           printf("%s - %s \n",myZone->zoneOpts[j].key, myZone->zoneOpts[j].value); 
//           printf("%s - %s \n",myZone->zoneOpts[i-1].key, myZone->zoneOpts[i-1].value); 

           zone->zoneOpts[j].key = strdup(zone->zoneOpts[i-1].key);
           zone->zoneOpts[j].value = strdup(zone->zoneOpts[i-1].value);
           zone->zoneOpts[i-1].key  = NULL;
           zone->zoneOpts[i-1].value = NULL;
           zone->zoneOpts = realloc(zone->zoneOpts,(i)*sizeof(ZONEOPTS));

//           updateZones(all_zones_start);
       }

//       free(all_zones_start); 

       return 1;
}

void freeZones(DNSZONE* dz)
{
	DNSZONE *dzptr = dz;
	DNSRECORD *r;
	ZONEOPTS *opts;

	if (!dz || !dz->zoneName)
		return;
	while (dz && dz->zoneName){
		if (dz->records){
			for (r = dz->records ; r && r->recordName; r++){
			  if (r->recordName)
			    free(r->recordName);
				if (r->recordZoneName)
					free(r->recordZoneName);
				if (r->recordType)
					free(r->recordType);
				if (r->recordValue)
					free(r->recordValue);
			} 
		//	free(dz->records);
		}
		if (dz->zoneOpts){
			for (opts = dz->zoneOpts ; opts && opts->key; opts++){
				free(opts->key);
				if (opts->value)
					free(opts->value);
			} 
		//	free(dz->zoneOpts);
		}
		dz++;
	}

	free(dzptr);
	dzptr = NULL;
}

void freeACL(ACL *acl)
{
	ACL *acpt = acl;
	if (!acl || !acl->key)
		return ;
	while (acl && acl->key){
		if (acl->value)
			free(acl->value);
		free(acl->key);
		acl++;
	}
	
	free(acpt);
}

int deleteACL(const char *name)
{
        ACL *acls = ReadACL();
        int size,off;
	int ret;
        
        DNSZONE * all_zones, *all_zones_Start;
        ZONEOPTS *zoneOpts; 
        int zoneModified = 0; 

        for (size = 0,off=-1; acls+size && acls[size].key;  size++){
                if (!strcmp(name,acls[size].key))
                        off = size;
        }

        if ((off < 0) && size){ /* means the ACL was not found */
                freeACL(acls);
                return 0;
        }

        memmove(acls+off,acls+off+1,(size-off)*sizeof(ACL));
        ret =  WriteACL(acls);
	freeACL(acls);

        acls = ReadACL();
        for (size = 0; acls+size && acls[size].key;  size++){
           deleteSubStr(acls[size].value, (char *)name);
        }
        ret = WriteACL(acls);
        freeACL(acls);

        all_zones = getZones();
        if (all_zones) {
          all_zones_Start = all_zones;

          for ( ; all_zones->zoneName != NULL; all_zones ++) {
             zoneOpts = findOptsInZone(all_zones, "allow-notify");
             if (zoneOpts) {
               deleteSubStr(zoneOpts->value, (char *)name);
               zoneModified = 1;
             }
             zoneOpts = findOptsInZone(all_zones, "allow-query");
             if (zoneOpts) {
               deleteSubStr(zoneOpts->value, (char *)name);
               zoneModified = 1;
             }
             zoneOpts = findOptsInZone(all_zones, "allow-transfer");
             if (zoneOpts) {
               deleteSubStr(zoneOpts->value, (char *)name);
               zoneModified = 1;
             }
             zoneOpts = findOptsInZone(all_zones, "allow-update");
             if (zoneOpts) {
               deleteSubStr(zoneOpts->value, (char *)name);
               zoneModified = 1;
             }
             zoneOpts = findOptsInZone(all_zones, "allow-recursion");
             if (zoneOpts) {
               deleteSubStr(zoneOpts->value, (char *)name);
               zoneModified = 1;
             }
             zoneOpts = findOptsInZone(all_zones, "blackhole");
             if (zoneOpts) {
               deleteSubStr(zoneOpts->value, (char *)name);
               zoneModified = 1;
             }
          }
          if (zoneModified)
            updateZones(all_zones_Start);
          free(all_zones_Start);
        }

	return ret;
}

void freeOptions(BINDOPTS *bopts)
{
       	BINDOPTS *opts = bopts;
        if (!opts || !opts->key)
                return ;
        while (opts && opts->key){
                if (opts->value)
                        free(opts->value);
                free(opts->key);
                opts++;
        }

        free(bopts);
}

int WriteOptions(BINDOPTS *bopts) 
{
  int result;

  pthread_mutex_lock(&rw_mutex);

  if (global_dns_conf && global_dns_conf->bopts)
    freeOptions(global_dns_conf->bopts);

  copy_to_global(bopts);

  result = WriteConf();
  pthread_mutex_unlock(&rw_mutex);

  return result;
}

BINDOPTS *ReadOptions()
{ 
  BINDOPTS *bopts = NULL;

  pthread_once(&single_init, ra_mutex_init);
  pthread_mutex_lock(&rw_mutex);

  if (!global_dns_conf) {
    if (ReadConf()) {
      pthread_mutex_unlock(&rw_mutex);
      return NULL;
    }
  }
  
  if (global_dns_conf->bopts)
    copy_from_global(bopts);

  pthread_mutex_unlock(&rw_mutex);

  return bopts;
}

int addOption(BINDOPTS *bopt)
{
  BINDOPTS *opts;
  int i = 0, ret=0;

  opts = ReadOptions();

  while (opts && opts[i].key && opts[i].value){
    if (!strcmp(opts[i].key, bopt->key))
      break;
    i++;
  }

  if (opts[i].key && !strcmp(opts[i].key, bopt->key))
    opts[i].value = strdup(bopt->value);
  else {
    opts = realloc(opts,(i+2)*sizeof(BINDOPTS));
    opts[i].key = strdup(bopt->key);
    opts[i].value = strdup(bopt->value);
    opts[i+1].key = NULL;
    opts[i+1].value = NULL;
  }

  ret = WriteOptions(opts);
  freeOptions(opts);

  return ret;
}

int deleteOption(const char *optionName)
{
  BINDOPTS *opts;
  int i = 0,j = 0, ret=0;
  int found = 0;

  opts = ReadOptions();

  while (opts && opts[i].key && opts[i].value){
    if (found == 0 && strcmp(opts[i].key, optionName)==0) {
      found = 1;
      j=i;
    }
    i++;
  }
  if (found) {
    opts[j].key=strdup(opts[i-1].key);
    opts[j].value=strdup(opts[i-1].value);
    opts[i-1].key = NULL;
    opts[i-1].value = NULL;
    opts = realloc(opts,(i)*sizeof(BINDOPTS));
  }
  ret = WriteOptions(opts);
  freeOptions(opts);

  return ret;
}

char *getOption(BINDOPTS *bopt_par, const char *key)
{
  BINDOPTS *bopt = bopt_par;
  char *value = NULL;

  while (bopt && bopt->key && bopt->value){
    if (!strcmp(key,bopt->key)){
      value = strdup(bopt->value);
      break;
    }
    bopt++;
  }
  
  return stripQuotes(value);
}

int setOption(BINDOPTS *bopt_par, const char *key, const char *value)
{
  BINDOPTS *bopt = bopt_par;
  BINDOPTS *myOpt;
  int ret = 1;
  char *tmp_value; 
  
  if (!value)
    return -EINVAL;
  
  tmp_value = strdup(value); 
  if ( strcmp(key,"directory")==0)
    addQuotes(&tmp_value); 
   
  while (bopt && bopt->key && bopt->value){
    if (!strcmp(key,bopt->key)){
      if (bopt->value)
	free(bopt->value);
      bopt->value = strdup(tmp_value);
      free(tmp_value); 
      return WriteOptions(bopt_par);
    }
    bopt++;
  }
  
  myOpt = malloc( sizeof( BINDOPTS ) );	
  myOpt->key = strdup( key );
  myOpt->value = strdup( tmp_value );
  free(tmp_value); 
  
  ret = addOption(myOpt);
  
  free( myOpt->key );
  free( myOpt->value );
  free( myOpt );	
  return ret;
}

ACL* addBuiltinACL(ACL *acls)
{
  int i = 0;
  ACL *builtin = (ACL*) malloc( 5*sizeof(ACL) );
  
  builtin[0].key = strdup("localhost");
  builtin[0].value = strdup("{ localhost; }");
  
  builtin[1].key = strdup("localnets");
  builtin[1].value = strdup("{ localnets; }");
  
  builtin[2].key = strdup("none");
  builtin[2].value = strdup("{ none; }");
  
  builtin[3].key = strdup("any");
  builtin[3].value = strdup("{ any; }");
  
  builtin[4].key = NULL;
  builtin[4].value = NULL; 
  
  if (!acls)
    return builtin;
  
  while (acls && acls[i].key && acls[i].value){
    i++;
  }
  acls = realloc(acls,(i+5)*sizeof(ACL));
  
  memcpy(acls+i,builtin,5*sizeof(ACL));
  free( builtin );
  return acls;
}

int checkBuiltinACL(char *key)
{
  if (strcmp( key, "localhost" ) 
      && strcmp( key, "localnets" ) 
      && strcmp( key, "none" )
      && strcmp( key, "any")
      )
    return 0;

  return 1;
}

ACL *ReadACL()
{
  ACL *acls = NULL;

  pthread_once(&single_init, ra_mutex_init);
  pthread_mutex_lock(&rw_mutex);

  if (!global_dns_conf) {
    if (ReadConf()) {
      pthread_mutex_unlock(&rw_mutex);
      return NULL;
    }
  }

  if (global_dns_conf->acls)
    copy_from_global(acls);

  pthread_mutex_unlock(&rw_mutex);

  return acls;
}

int WriteACL(ACL *acls)
{
  int result;

  pthread_mutex_lock(&rw_mutex);

  if (global_dns_conf && global_dns_conf->acls)
    freeACL(global_dns_conf->acls);

  copy_to_global(acls);

  result = WriteConf();

  pthread_mutex_unlock(&rw_mutex);
  return result;
}

int addACL(ACL *acl)
{
  ACL *oldacl = ReadACL();
  
  int ret,i = 0;
  
  while (oldacl && oldacl[i].key && oldacl[i].value){
    i++;
	}		
  oldacl = realloc(oldacl,(i+2)*sizeof(ACL));
  oldacl[i].key = strdup(acl->key);
  oldacl[i].value = strdup(acl->value);
  oldacl[i+1].key = NULL;
  oldacl[i+1].value = NULL;
  
  ret = WriteACL(oldacl);
  freeACL(oldacl);
  return ret;
}

char *getACL(ACL *acl_par, const char *key)
{
  ACL *acl = acl_par;
  char *value = NULL;
  
  while (acl && acl->key && acl->value){
    if (!strcmp(key,acl->key)){
      value = strdup(acl->value);
      break;
		}
    acl++;
  }
  
  return value;
}

//int setACL(ACL *acl_par, const char *key, const char *value)
//{
//  ACL *acl = acl_par;
//  ACL *myAcl;
//  int ret;
//	
//  while (acl && acl->key && acl->value){
//    if (!strcmp(key,acl->key)){
//      if (acl->value)
//	free(acl->value);
//      acl->value = strdup(value);
//      return WriteACL(acl_par);
//    }
//    acl++;
//  }
//  
//  myAcl = malloc( sizeof( ACL ) );	
//  myAcl->key = strdup( key );
//  myAcl->value = strdup( value );
//  
//  ret = addACL(myAcl);
//  
//  free( myAcl->key );
//  free( myAcl->value );
//  free( myAcl );	
//  return ret;
//}

MASTERS *ReadMasters()
{
  MASTERS *masters = NULL;

  pthread_once(&single_init, ra_mutex_init);
  pthread_mutex_lock(&rw_mutex);

  if (!global_dns_conf) {
    if (ReadConf()) {
      pthread_mutex_unlock(&rw_mutex);
      return NULL;
    }
  }

  if (global_dns_conf->masters) {
    copy_from_global(masters);
  }

  pthread_mutex_unlock(&rw_mutex);

  return masters;
}

int WriteMasters(MASTERS *masters)
{
  int result;

  pthread_mutex_lock(&rw_mutex);

  if (global_dns_conf && global_dns_conf->masters)
    freeMasters(global_dns_conf->masters);

  copy_to_global(masters);

  result = WriteConf();

  pthread_mutex_unlock(&rw_mutex);

  return result;
}

void freeMasters(MASTERS *masters)
{
	MASTERS *masterspt = masters;
	if (!masters || !masters->key)
		return ;
	while (masters && masters->key){
		if (masters->value)
			free(masters->value);
		free(masters->key);
		masters++;
	}
	
	free(masterspt);
}

int deleteMasters(const char *name)
{

        MASTERS *masters = ReadMasters();
        int size,off;
        int ret;

        DNSZONE * all_zones, * all_zones_Start;
        ZONEOPTS * zoneOpts;

        int zoneModified = 0;

        for (size = 0,off=-1; masters+size && masters[size].key;  size++){
                if (!strcmp(name,masters[size].key))
                        off = size;
        }

        if ((off < 0) && size){ /* means the ACL was not found */
                freeMasters(masters);
                return 0; 
        }

        memmove(masters+off,masters+off+1,(size-off)*sizeof(MASTERS));
        ret =  WriteMasters(masters);
        freeMasters(masters);

        masters = ReadMasters();
        for (size = 0; masters+size && masters[size].key;  size++){
           deleteSubStr(masters[size].value, (char *)name);
        }
        ret = WriteMasters(masters);
        freeMasters(masters);
        
        all_zones = getZones();
        if (all_zones) {
          all_zones_Start = all_zones;

          for ( ; all_zones->zoneName != NULL; all_zones ++) {
             zoneOpts = findOptsInZone(all_zones, "masters");
             if (zoneOpts) {
               deleteSubStr(zoneOpts->value, (char *)name);
               zoneModified = 1;
             }
          }
          if (zoneModified)
            updateZones(all_zones_Start);
          free(all_zones_Start);
        }

        return ret;
}

int addMasters(MASTERS *masters)
{
  MASTERS *oldMasters = ReadMasters();
  
  int ret,i = 0;
  
  while (oldMasters && oldMasters[i].key && oldMasters[i].value){
    i++;
	}		
  oldMasters = realloc(oldMasters,(i+2)*sizeof(MASTERS));
  oldMasters[i].key = strdup(masters->key);
  oldMasters[i].value = strdup(masters->value);
  oldMasters[i].port = masters->port;
  oldMasters[i+1].key = NULL;
  oldMasters[i+1].value = NULL;
  oldMasters[i+1].port = 0;
  
  ret = WriteMasters(oldMasters);
  freeMasters(oldMasters);
  return ret;
}

int disableZone(const char *name) {
	char *script= my_script_path("disable.sh");
	char *conffile = get_bindconf();	
	int ret =0;
	
	ret = execScript2(script,name,conffile);
	
	free(script);
	free(conffile);
	return ret;
}

int enableZone(const char *name) {
	char *script= my_script_path("enable.sh");
	char *conffile = get_bindconf();
	int ret = 0;
		
	ret = execScript2(script,name,conffile);
	free(script);
	free(conffile);
	return ret;
}

int deleteZone(const char *name) {
	DNSZONE *dz = getZones();
	int size, off, ret;

	for (size = 0,off=0; dz+size && dz[size].zoneName;  size++){
		if (!strcmp(name,dz[size].zoneName))
			off = size;
	}

	if (!off && size){ /* means the zone was not found */
		freeZones(dz);
		return 0;
	}

//  This is not required now.. Tyrels fix works now...
/*        if (dz[off].zoneFileName) {
          deleteZoneFile(dz[off].zoneFileName); 
        }
     
        memFree_Zone((DNSZONE *) &dz[size]); */

	memmove(dz+off,dz+off+1,(size-off)*sizeof(DNSZONE));
	
	ret = updateZones(dz);
	freeZones( dz );
	return ret;

}

char *get_bindconf()
{
  char *conffile;

  pthread_mutex_lock(&rw_mutex);

  conffile = get_conf(dns_conf,"bindconf");
  if (!conffile)
    {
      dns_conf = read_conf(CONFFILE,CONFFILE);
      conffile = get_conf(dns_conf,"bindconf");
      if (!conffile) {
	conffile = strdup(BINDCONF);
      }
    }
  
  pthread_mutex_unlock(&rw_mutex);
  return conffile;
}

int set_bindconf(const char *name) {
  int result;

  pthread_mutex_lock(&rw_mutex);

  if (!dns_conf)
    dns_conf = read_conf(CONFFILE,CONFFILE);

  if (!dns_conf) {
    pthread_mutex_unlock(&rw_mutex);
    return -1;
  }

  dns_conf = set_conf(&dns_conf, "bindconf", name);

  result = write_conf(CONFFILE, dns_conf);

  pthread_mutex_unlock(&rw_mutex);

  return result;
}

int isNestedACL(const char *name) { 

        ACL *acls = ReadACL();
        int size,off;

        DNSZONE * all_zones, *all_zones_Start;
        ZONEOPTS *zoneOpts;
        int isNestedACLFlag = 0;

        for (size = 0,off=-1; acls+size && acls[size].key;  size++){
                if (!strcmp(name,acls[size].key))
                        off = size;
        }

        if ((off < 0) && size){ /* means the ACL was not found */
                freeACL(acls);
                return 0;
        }

        for (size = 0; acls+size && acls[size].key;  size++){
           if (strstr(acls[size].value, (char *)name)) 
             isNestedACLFlag = 1; 
        }
        freeACL(acls);
   
        if (isNestedACLFlag) return 1; 

        all_zones = getZones();
        if (all_zones) {
          all_zones_Start = all_zones;

          for ( ; all_zones->zoneName != NULL; all_zones ++) {
             zoneOpts = findOptsInZone(all_zones, "allow-notify");
             if (zoneOpts) {
               if (strstr(zoneOpts->value, (char *)name))
                 isNestedACLFlag = 1; 
             }
             zoneOpts = findOptsInZone(all_zones, "allow-query");
             if (zoneOpts) {
               if (strstr(zoneOpts->value, (char *)name))
                 isNestedACLFlag = 1;
             }
             zoneOpts = findOptsInZone(all_zones, "allow-transfer");
             if (zoneOpts) {
               if (strstr(zoneOpts->value, (char *)name))
                 isNestedACLFlag = 1;
             }
             zoneOpts = findOptsInZone(all_zones, "allow-update");
             if (zoneOpts) {
               if (strstr(zoneOpts->value, (char *)name))
                 isNestedACLFlag = 1;
             }
             zoneOpts = findOptsInZone(all_zones, "allow-recursion");
             if (zoneOpts) {
               if (strstr(zoneOpts->value, (char *)name))
                 isNestedACLFlag = 1;
             }
             zoneOpts = findOptsInZone(all_zones, "blackhole");
             if (zoneOpts) {
               if (strstr(zoneOpts->value, (char *)name))
                 isNestedACLFlag = 1;
             }
          }
          free(all_zones_Start);
          if (isNestedACLFlag) return 1; 
        }


  return 0; 
}

int isNestedMaster(const char *name) { 

        MASTERS *masters = ReadMasters();
        int size,off;
     
        DNSZONE * all_zones, * all_zones_Start;
        ZONEOPTS * zoneOpts;

        int isNestedMasterFlag = 0;

        for (size = 0,off=-1; masters+size && masters[size].key;  size++){
                if (!strcmp(name,masters[size].key))
                        off = size;
        }

        if ((off < 0) && size){ /* means the ACL was not found */
                freeMasters(masters);
                return 0;
        }
        
        for (size = 0; masters+size && masters[size].key;  size++){
           if (strstr(masters[size].value, (char *)name))
             isNestedMasterFlag = 1; 
        }
        freeMasters(masters);
          
        if (isNestedMasterFlag) return 1; 

        all_zones = getZones();
        if (all_zones) {
          all_zones_Start = all_zones;

          for ( ; all_zones->zoneName != NULL; all_zones ++) {
             zoneOpts = findOptsInZone(all_zones, "masters");
             if (zoneOpts) {
               if (strstr(zoneOpts->value, (char *)name))
                 isNestedMasterFlag = 1; 
             }
          }
          free(all_zones_Start);
          if (isNestedMasterFlag) return 1;         
        }

  return 0; 
} 

int isPredefinedACL(const char * name) { 
 
   if (strcmp("any",name) == 0 ) return 1; 
   else if (strcmp("none",name) == 0 ) return 1; 
   else if (strcmp("localhost",name) == 0 ) return 1; 
   else if (strcmp("localnets",name) == 0 ) return 1; 
   
   return 0; 
}
 
int isKey(const char * name) { 

   return 0; 
}

int getACLType(const char* aclValue) {

  if (isPredefinedACL(aclValue)) return 1; 
  else if (isIPV4(aclValue)) return 2; 
  else if (isIPV6(aclValue)) return 3; 
  else if (isIPPrefix(aclValue)) return 4; 
  else if (isKey(aclValue)) return 5; 
  else if (isNestedACL(aclValue)) return 6; 

  return 0; 
}

int getMastersType(const char* mastersValue) {
  
  if ( isIPV4(mastersValue) ) return 1; 
  else if ( isIPV6(mastersValue)) return 2; 
  else if ( isNestedMaster(mastersValue)) return 3; 

  return 0; 
}

int getForwardersType(const char* forwardersValue) {
  
  if ( isIPV4(forwardersValue) ) return 1; 
  else if ( isIPV6(forwardersValue)) return 2; 

 return 0;
}

