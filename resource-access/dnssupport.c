 /*
 * dnssupport.c 
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
 * Author: Viktor Mihajlovski <MIHAJLOV@de.ibm.com> 
 *
 * Contributors: Glauber de Oliveira Costa <gocosta@br.ibm.com>
 *
 * Description: This is the main file for the DNS provider Resource Access Layer.
 * it still uses the YaST API in an embedded perl fashion, but it shall be removed
 * soon
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
//#include <sys/select.h>
#include <sys/unistd.h>
#include <fcntl.h>
#include <EXTERN.h>
#include <perl.h>
#include "perlstr.h"
#include "rrhandle.h"
#include <rastr.h>
#include <execscripts.h>
#include <conf.h>

static PerlInterpreter *my_perl = NULL;


#include "dnssupport.h"


EXTERN_C void xs_init( pTHX );


struct conf *dns_conf;

#ifdef USE_CACHE
	#include "monitors.h"
	DNSZONE *gzones = NULL;
	BINDOPTS *gbopts = NULL;
	ACL *gacl = NULL;
	struct monitor *amon = NULL; /* acl */
	struct monitor *omon = NULL; /* opts */
	struct monitor *zmon = NULL; /* zones */

	static inline DNSRECORD *copy_records(DNSRECORD *record){
	
		DNSRECORD *r;
		int i;
		for (i = 0; record+i && record[i].recordName; i++);
		
		r = calloc(i+1,sizeof(DNSRECORD));
	
		for (i = 0; record+i && record[i].recordName; i++){
			r[i].recordName = strdup(record[i].recordName);
			if (record[i].recordZoneName)
				r[i].recordZoneName = strdup(record[i].recordZoneName);
			if (record[i].recordType)
				r[i].recordType = strdup(record[i].recordType);
			if (record[i].recordValue)
				r[i].recordValue = strdup(record[i].recordValue);
			
		}
		return r;
	}

	static inline DNSZONE *copy_zones(DNSZONE *zones){
		DNSZONE *z;
		int i;
	
		for (i= 0; zones+i && zones[i].zoneName; i++);
	
		z = calloc(i+1,sizeof(DNSZONE));

		for (i= 0; zones+i && zones[i].zoneName; i++){
			z[i].zoneName = strdup(zones[i].zoneName);
			if (zones[i].zoneType)
				z[i].zoneType = strdup(zones[i].zoneType);
			if (zones[i].zoneFileName)
				z[i].zoneFileName = strdup(zones[i].zoneFileName);
			if (zones[i].soaContact)
				z[i].soaContact = strdup(zones[i].soaContact);
			if (zones[i].soaServer)
				z[i].soaServer = strdup(zones[i].soaServer);
			z[i].soaSerialNumber = zones[i].soaSerialNumber;
			z[i].soaRefresh = zones[i].soaRefresh;
			z[i].soaRetry = zones[i].soaRetry;
			z[i].soaExpire = zones[i].soaExpire;
			z[i].soaNegativCachingTTL = zones[i].soaNegativCachingTTL;
			if (zones[i].records)
				z[i].records = copy_records(zones[i].records);
			if (zones[i].zoneOpts)
				copy_vector(zones[i].zoneOpts,z[i].zoneOpts);
		}
		return z;				
}
			
	static inline void zone_to_global(DNSZONE *zones){

		gzones = copy_zones(zones);
		
	}																			

	static inline DNSZONE *zone_from_global(void){

		return copy_zones(gzones);
		
	}

#endif


static void init_interpreter()
{
  char *argv[] = { "", "-e", "0"};
  int argc = 3;
  if (my_perl == NULL) {    
    my_perl = perl_alloc();
    perl_construct(my_perl);
    perl_parse(my_perl, xs_init, argc, argv, NULL);
  }
  PERL_SET_CONTEXT(my_perl);
}

static void term_interpreter()
{
    perl_destruct(my_perl);
    perl_free(my_perl);
    my_perl=NULL;
		PERL_SYS_TERM();
}
char *my_script_path(char *filename){

	#ifdef USE_CACHE
	static struct monitor *mon;
	#endif 
	if ((!dns_conf) || (!mon)){
		dns_conf = read_conf(CONFFILE,CONFFILE);
		#ifdef USE_CACHE
		mon = init_monitor(1);
		monitor_file(mon,CONFFILE);
		#endif
	}

	#ifdef USE_CACHE
	if (!check_events(mon)){
		dns_conf = read_conf(CONFFILE,CONFFILE);
	}
	#endif 
	return script_path(dns_conf,filename);
	 
}	


static int uint64_to_BindTime(unsigned long long ull, char * time)
{
  unsigned long long divresult=ull;
  unsigned long long modresult=0;
  char suffix=' ';
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

    sprintf(time,"%lld%c",divresult,suffix);

    return 0;
  } else {
    return -1;
  }
}

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

static DNSRECORD *parseRecords(FILE *fp){
	DNSRECORD *record = NULL;

	char *buf = malloc(BUFSIZE);
	char *ptr;
	char token;
	int size;
	int i= -1;
	char *buf_addr; /* the original pointer to the buffer */
	buf_addr = buf;


	while(!feof(fp)){
		buf = buf_addr;
		
		fgets(buf,BUFSIZE,fp);

		if (!strncmp(buf,"ENDRRS",6))
			break;

		ptr = strchr(buf,'\n');
		if (ptr)
			*ptr = '\0';

		token = *(strsep(&buf,":"));
	
		if ((token != '#') && !record)
			return NULL;
		
		switch (token){
			case '#':
				size = atoi(buf) + 1;
				record = calloc(size,sizeof(DNSRECORD));
				break;
			case 'N':
				i++;
				record[i].recordName = strdup(buf);
				break;
			case 'Z':
				record[i].recordZoneName = strdup(buf);
				break;
			case 'T':
				record[i].recordType = strdup(buf);
				break;
			case 'V':
				record[i].recordValue = strdup(buf);
				break;
			default:
				break;
		}
	}
	free(buf_addr);
	return record;
}

static ZONEOPTS *parseOpts(FILE *fp){

	ZONEOPTS *opts = NULL;

	char *buf = malloc(BUFSIZE);
	char *ptr;
	char token;
	int size;
	int i= -1;
	char *buf_addr; /* the original pointer to the buffer */
	buf_addr = buf;


	while(!feof(fp)){
		buf = buf_addr;
		fgets(buf,BUFSIZE,fp);

		if (!strncmp(buf,"ENDOPTS",7))
			break;

		ptr = strchr(buf,'\n');
		if (ptr)
			*ptr = '\0';

		token = *(strsep(&buf,":"));
	
		if ((token != '#') && !opts)
			return NULL;
		
		switch (token){
			case '#':
				size = atoi(buf) + 1;
				opts = calloc(size,sizeof(ZONEOPTS));
				break;
			case 'K':
				i++;
				opts[i].key = strdup(buf);
				break;
			case 'V':
				opts[i].value = strdup(buf);
				break;
			default:
				break;
		}
	}
	free(buf_addr);
	return opts;

}


static void *parseZones(int pipeid){
	
	DNSZONE *zones = NULL;

	FILE *fp = fdopen(pipeid,"r");

	char *buf = malloc(BUFSIZE);
	char *ptr;
	char token;
	int size;
	int i= -1;
	char *buf_addr; /* the original pointer to the buffer */
	buf_addr = buf;

	struct timeval tv = {0,50};
	fd_set fset;
	FD_ZERO(&fset);
	FD_SET(fileno(fp),&fset);

	if (!select(fileno(fp)+1,&fset,NULL,NULL,&tv)){
		errno = -EAGAIN;
		goto out;
	}
	
	while (!feof(fp)){
		buf = buf_addr;
		fgets(buf,BUFSIZE,fp);

		if (!strncmp(buf,"ENDZONES",8))
			break;
		if (!strncmp(buf,"OPTS",4)){
			if (!zones){
				return NULL;
			}
			else{
				zones[i].zoneOpts = parseOpts(fp);
				continue;
			}
		}
		
		if (!strncmp(buf,"RRS",3)){
			if (!zones){
				return NULL;
			}
			else{
				zones[i].records = parseRecords(fp);
				continue;
			}
		}
		ptr = strchr(buf,'\n');
		if (ptr)
			*ptr = '\0';

		token = *(strsep(&buf,":"));
		if ((token != '#') && !zones)
			return NULL; /* change this */

		switch (token){
			case '#':
				size = atoi(buf) + 1;
				zones = calloc(size,sizeof(DNSZONE));
				break;
			case 'N':
				i++;
				zones[i].zoneName = strdup(buf);
				break;
			case 'T':
				zones[i].zoneType = strdup(buf);
				break;
			case 'F':
				zones[i].zoneFileName = strdup(buf);
				break;
			case 'C':
				zones[i].soaContact = strdup(buf);
				break;
			case 'S':
				zones[i].soaServer = strdup(buf);
				break;
			case 'U':
				zones[i].soaSerialNumber = (UL64)atoll((buf));
				break;
			case 'R':
				bindTime2uint64(&zones[i].soaRefresh,buf);
				break;
			case 'Y':
				bindTime2uint64(&zones[i].soaRetry,buf);
				break;
			case 'E':
				bindTime2uint64(&zones[i].soaExpire,buf);
				break;
			case 'L':
	//			zones[i].soaNegativeCachingTTL = strdup(buf);
				break;
		
			default:
				break;
		}
	}

out:
	free(buf_addr);
	fclose(fp);
	return (void *)zones;
}

#ifdef USE_CACHE
DNSZONE *__getZones(){
#else
DNSZONE *getZones(){
#endif 

	DNSZONE *zones = NULL;
	char *script = my_script_path(GETZONES);

	zones = (DNSZONE *)readData(script,parseZones);

	free(script);


	return zones;
}

#ifdef USE_CACHE
DNSZONE *getZones(){
	char *conffile;
	char *binddir,*filename,*tmp;
	int i;
	

	if (!gzones){
		if (!zmon)
			zmon = init_monitor(50);
		if (!zmon){
			return __getZones();
		}
		conffile = get_conf(dns_conf,"bindconf");
		if (!conffile)
			conffile = strdup(BINDCONF);
		gzones = __getZones();
		monitor_file(zmon,conffile);
		tmp = getOption(ReadOptions(),"directory");
		if (!tmp)
			binddir = strdup(BINDDIR);	
		else{ /* Don't loose memory reference*/
			binddir = noquotes(tmp);
			free(tmp);
		}
		for (i = 0; (gzones+i) && gzones[i].zoneName; i++){
			if (gzones[i].zoneFileName){
				asprintf(&filename,"%s/%s",binddir,gzones[i].zoneFileName);
				monitor_file(zmon,filename);
				free(filename);
			}
		}
		free(conffile);
		free(binddir);
	}
	if (!check_events(zmon)){
		gzones = __getZones();
	}
	return zone_from_global();
}	
#endif 

/*
DNSZONE* getZonesByType(char *type){

	DNSZONE *zone,*szone,*all_zones;
	int i = 0;
	init_interpreter();
	eval_pv(PERLPREF,TRUE);

	szone = NULL;
	all_zones = getZones();
	for (zone = all_zones; zone && zone->zoneName; ++zone){
			if (!strcasecmp(zone->zoneType,type)){
				szone = realloc(szone,++i*sizeof(DNSZONE));
				memcpy(szone+i-1,zone,sizeof(DNSZONE));
			}
	}
	szone = realloc(szone,++i*sizeof(DNSZONE));
	memset(szone+i-1,0,sizeof(DNSZONE));
	freeZones( all_zones );
	//term_interpreter();
	return szone;
}
*/

DNSZONE* __addZone(DNSZONE** zones, DNSZONE *newzone)
{
    off_t num;
    if (zones && newzone) {
	if (*zones == NULL) {
	    *zones = calloc(2,sizeof(DNSZONE));
	    num=1;
	} else {
	    num=0;
	    while((*zones)[num++].zoneName);
	    *zones = realloc(*zones, sizeof(DNSZONE)*(num+1));
	}	
	(*zones)[num] = (*zones)[num-1]; 
	(*zones)[num-1] = *newzone; 
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
			printf("problem	adding records.\n");
			records++;
			continue;
		}

		addRecord(zone,records);
		records++;	
	}	
	
	__addZone(&actual_zones,zone);
	if (updateZones(actual_zones))
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

static int addRecordString(int firstrecord, char ** script, DNSRECORD* dr)
{
    off_t index;
    if (!firstrecord) {
	index = strlen(*script);
	*script = realloc(*script,index+1+strlen("   ,\n"));
	strcpy(*script+index,"   ,\n");
    }
    index = strlen(*script);
    *script = realloc(*script,index+1+strlen(RECORDDEF)+strlen(dr->recordName)
		      +strlen(dr->recordType)+strlen(dr->recordValue));    
    index += sprintf(*script+index,RECORDDEF,
		     dr->recordValue,
		     dr->recordType,
		     dr->recordName);
    return 0;
}

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

static void *realloc_zone(void *ptr,DNSZONE *dz)
{
	/* do a realloc according to the meaning of the zone. 
		everytime a field has no meaning, we sum 1, for NULL to fit */

	if (!dz)
		return 0;
	if (!strcmp(dz->zoneType,"master"))
		return realloc(ptr,strlen(ZONEDEF)+2*strlen(dz->zoneName)+
				   2*strlen(dz->zoneFileName) + 2*strlen(dz->zoneType)+ 
			     strlen(dz->soaContact) + strlen(dz->soaServer) +
		  	   5*strlen("9223372036854775808"));  
	if (!strcmp(dz->zoneType,"hint"))
		return realloc(ptr,strlen(ZONEDEF)+2*strlen(dz->zoneName)+
				   2*strlen(dz->zoneFileName) + 2*strlen(dz->zoneType)+ 
			     1 + 1 +
		  	   5*strlen("9223372036854775808"));  
	if (!strcmp(dz->zoneType,"slave") || !strcmp(dz->zoneType,"stub"))
		return realloc(ptr,strlen(ZONEDEF)+2*strlen(dz->zoneName)+
				   2*strlen(dz->zoneFileName) + 2*strlen(dz->zoneType)+ 
			     1 + 1 +
		  	   5*strlen("9223372036854775808")); 
	
/*	if (!strcmp(dz->zoneType,"forward"))
		return realloc(ptr,strlen(ZONEDEF)+2*strlen(dz->zoneName)+
				   2*strlen(dz->zoneFileName) + 2*strlen(dz->zoneType)+ 
			     1 + 1 +
		  	   5*strlen("9223372036854775808")); */

	if (!strcmp(dz->zoneType,"forward"))
		return realloc(ptr,strlen(ZONEDEF)+2*strlen(dz->zoneName)+
				   + 2*strlen(dz->zoneType)+ 
			     1 + 1 + 1 +
		  	   5*strlen("9223372036854775808"));
	return NULL;
}
static int addZoneString(int firstzone, char ** script, DNSZONE* dz)
{
    off_t index;
    int   firstrecord=1;
    char  expire[20];
    char  retry[20];
    char  refresh[20];
    char  minimum[20];
 
	if (!validzone(dz))   
		return 1;
	
    if (!firstzone) {
//	index = strlen(*script);
//	*script = realloc(*script,index+1+strlen(" ,\n"));
//	strcpy(*script+index," ,\n"); //
    }
    uint64_to_BindTime(dz->soaExpire,expire);    
    uint64_to_BindTime(dz->soaRetry,retry);
    uint64_to_BindTime(dz->soaRefresh,refresh);
    uint64_to_BindTime(0ULL,minimum);
  //  index = strlen(*script);
/* Zone substitutions: type, file, zone, file, type, min, expire, serial, 
                       retry, refresh, contact, server */
    *script = realloc_zone(*script,dz); 
   
//	 index += sprintf(*script+index,ZONEDEF,
	 index = sprintf(*script,ZONEDEF,
		     dz->zoneType,
		     dz->zoneFileName,
		     dz->zoneName,
		     dz->zoneFileName,
		     dz->zoneType,
		     minimum, 
		     expire,
		     dz->soaSerialNumber,
		     retry, 
		     refresh,
		     dz->soaContact, 
		     dz->soaServer 
		     );
    if (dz->records) {
	*script = realloc(*script,index + 1 + strlen(RECORDIN));
	strcpy(*script + index, RECORDIN);
	while (dz->records && dz->records->recordName) {
	    addRecordString(firstrecord,script,dz->records);
	    if (firstrecord) firstrecord = 0;
	    dz->records++;
	}
	index = strlen(*script);
	*script = realloc(*script, index + 1 + strlen(RECORDOUT));
	strcpy(*script + index, RECORDOUT);
	index += strlen(RECORDOUT);
    }
    *script = realloc(*script, index + 1 + strlen(ZONEEND));
    strcpy(*script + index,ZONEEND);
    return 0;
}

int updateZones(DNSZONE* dz)
{
	/* Return Values: 1 = ok. 0 = failed */
    int first = 1;
    char *updateScript = malloc(1); /* to enable us using realloc later */ 
		int wstatus;
		DNSZONE *zones;
		ZONEOPTS *zopts;

    init_interpreter();
		eval_pv(PERLPREF,TRUE);
		eval_pv(ZONEIN,TRUE); 
	
		zones = dz;
    while (dz && dz->zoneName) {
		if (addZoneString(first,&updateScript,dz) == 0 && first) first = 0;
			eval_pv(updateScript,TRUE);
			*updateScript = '\0';

			zopts = dz->zoneOpts;
			while (zopts && zopts->key){
					if (!strcmp(dz->zoneType,"slave") && !strcmp(zopts->key,"masters")){
						updateScript = realloc(updateScript,strlen(MASTERS) + strlen(zopts->value) + 1);
						sprintf(updateScript,MASTERS,zopts->value);
					}
					else { 
						updateScript = realloc(updateScript,strlen(ZONEOPT)+ 
																	strlen(zopts->key) + 
																	strlen(zopts->value) + 1);
						sprintf(updateScript,ZONEOPT,zopts->value,zopts->key);
					}
					eval_pv(updateScript,TRUE);
					zopts++;
			}
			dz++;
    }
		*updateScript = '\0';
    updateScript = realloc(updateScript,strlen(updateScript)+1+strlen(WRITEZONES)); 
    strcat(updateScript,WRITEZONES);
    eval_pv (updateScript, TRUE);
		wstatus = SvIV(get_sv("wstatus",FALSE));
		eval_pv("undef $zones; undef $zone; undef $opt;",TRUE);
		free(updateScript);
		#ifdef USE_CACHE
		if (gzones)
			freeZones(gzones);
		zone_to_global(zones);
		#endif
    return wstatus;
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

DNSZONE* addMasters(DNSZONE* zones, const char *zonename, const char *masters){
	DNSZONE *dz = findZone(zones,zonename);
	ZONEOPTS *zopts;
	int i = 0;
	if (!dz)
		return NULL; /* users of this function must be careful with this. */

	zopts = dz->zoneOpts;
	while (zopts && zopts->key){
			i++;
			zopts++;
	}
	dz->zoneOpts = realloc(dz->zoneOpts,(i+2)*sizeof(ZONEOPTS));
	dz->zoneOpts[i].key = strdup("masters");
	dz->zoneOpts[i].value = strdup(masters);

	dz->zoneOpts[i+1].key  = NULL;
	dz->zoneOpts[i+1].value = NULL;
 
	if (updateZones( zones ))
		return zones; 

	return NULL;

	
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

void freeACL(ACL *acl){
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

int WriteOptions(BINDOPTS *bopts){

	char *script = malloc(1);
	BINDOPTS *boptsptr = bopts;	

	init_interpreter();
	eval_pv(PERLPREF,TRUE);

	eval_pv(OPTIN,TRUE);

	while (boptsptr && boptsptr->key && boptsptr->value){
		script = realloc(script,strlen(OPTDEF)+strlen(boptsptr->key) + strlen(boptsptr->value) + 1) ;
		sprintf(script,OPTDEF,boptsptr->value,boptsptr->key);
		eval_pv(script,TRUE);
		boptsptr++;
	}		

	SV *status = eval_pv("${YaPI::DNSD->WriteGlobalOptions({},$options);}",TRUE);
	eval_pv("undef $options;",TRUE);
	#ifdef USE_CACHE
	if (gbopts)
		freeOptions(gbopts);
	copy_to_global(bopts);
	#endif
	return SvIV( status);
}

static void *r_opts(int pipefd){

	char *ptr,*buf = malloc(BUFSIZE);
	char *buf_addr = buf;
	FILE *fp = fdopen(pipefd,"r");
	BINDOPTS *bopts = NULL;
	char token;
	int i,size;

	i = -1;

	if (!fp)
		return NULL;

	struct timeval tv = {0,50};
	fd_set fset;
	FD_ZERO(&fset);
	FD_SET(fileno(fp),&fset);

	if (!select(fileno(fp)+1,&fset,NULL,NULL,&tv)){
		errno = -EAGAIN;
		goto out;
	}
	while (!feof(fp)){
		buf = buf_addr;
		fgets(buf,BUFSIZE,fp);
		
		if (!strncmp(buf,"ENDOPTS",6))
			break;

		ptr = strchr(buf,'\n');
		if (ptr)
			*ptr = '\0';

		token = *(strsep(&buf,":"));
		if ( (token != '#') && !bopts)
			return NULL;
		switch (token){		
			case '#':
				size = atoi(buf) + 1;
				bopts = calloc(size,sizeof(BINDOPTS));
				break;
			case 'K':
				i++;
				bopts[i].key = strip(buf);
				break;
			case 'V':
				bopts[i].value = strip(buf);
				break;
			default:
				break;
		}
	}
out:
		free(buf_addr);
		return (void *)bopts;
}

	
#ifdef USE_CACHE
BINDOPTS *__ReadOptions(){
#else
BINDOPTS *ReadOptions(){
#endif

	char *script = my_script_path("getopts.pl");
	char *filename = get_conf(dns_conf,"bindconf");
	BINDOPTS *bopts = (BINDOPTS *)readData1(script,filename,r_opts);
	free(script);
	free(filename);
	return bopts;

}
#ifdef USE_CACHE
BINDOPTS *ReadOptions(){

	char *conffile;
	BINDOPTS *bopts;
	
	if (!gbopts){
		if (!omon)
			omon = init_monitor(1);
		if (!omon)
			return __ReadOptions();
		conffile = get_conf(dns_conf,"bindconf");
		if (!conffile)
			conffile = strdup(BINDCONF);
		gbopts = __ReadOptions();
		monitor_file(omon,conffile);
		free(conffile);
	}	
	if (!check_events(omon))
		gbopts = __ReadOptions();
	if (gbopts) {
		copy_from_global(bopts);
	}
	else
		return NULL;

	return bopts;
}
#endif

int addOption(BINDOPTS *bopt){
	BINDOPTS *opts;
	int i;

	opts = ReadOptions();

	i = 0;
	while (opts && opts[i].key && opts[i].value){
		i++;
	}		
	opts = realloc(opts,(i+2)*sizeof(BINDOPTS));
	opts[i].key = strdup(bopt->key);
	opts[i].value = strdup(bopt->value);
	opts[i+1].key = NULL;
	opts[i+1].value = NULL;

	return WriteOptions(opts);
	
}

char *getOption(BINDOPTS *bopt_par, const char *key){

	BINDOPTS *bopt = bopt_par;
	char *value = NULL;

	while (bopt && bopt->key && bopt->value){
		if (!strcmp(key,bopt->key)){
			value = strdup(bopt->value);
			break;
		}
		bopt++;
	}

	return value;
}

int setOption(BINDOPTS *bopt_par, const char *key, const char *value){

	BINDOPTS *bopt = bopt_par;
	
	while (bopt && bopt->key && bopt->value){
		if (!strcmp(key,bopt->key)){
			if (bopt->value)
				free(bopt->value);
			bopt->value = strdup(value);
			return WriteOptions(bopt_par);
		}
		bopt++;
	}

	BINDOPTS *myOpt = malloc( sizeof( BINDOPTS ) );	
	myOpt->key = strdup( key );
	myOpt->value = strdup( value );

	int ret = addOption(myOpt);

	free( myOpt->key );
	free( myOpt->value );
	free( myOpt );	
	return ret;
}


static void *r_acl(int pipefd){

	char *ptr,*buf = malloc(BUFSIZE);
	char *buf_addr = buf;
	FILE *fp = fdopen(pipefd,"r");
	ACL *acl = NULL;
	char token;
	int i,size;

	i = -1;

	if (!fp)
		return NULL;

	struct timeval tv = {0,50};
	fd_set fset;
	FD_ZERO(&fset);
	FD_SET(fileno(fp),&fset);

	if (!select(fileno(fp)+1,&fset,NULL,NULL,&tv)){
		errno = -EAGAIN;
		goto out;
	}
	while (!feof(fp)){
		buf = buf_addr;
		fgets(buf,BUFSIZE,fp);
		
		if (!strncmp(buf,"ENDACL",6))
			break;

		ptr = strchr(buf,'\n');
		if (ptr)
			*ptr = '\0';

		token = *(strsep(&buf,":"));
		if ( (token != '#') && !acl)
			return NULL;
		switch (token){		
			case '#':
				size = atoi(buf) + 1;
				acl = calloc(size,sizeof(ACL));
				break;
			case 'K':
				i++;
				acl[i].key = strip(buf);
				break;
			case 'V':
				acl[i].value = strip(buf);
				break;
			default:
				break;
		}
	}
out:
		free(buf_addr);
		return (void *)acl;
}
ACL* addBuiltinACL(ACL *acls)
{
	/*ACL builtin[] = {
			{ "localhost", 	"{ localhost; }" },
			{ "localnet",  	"{ localnet; }" },
			{ "none",	"{ none; }" },
			{ "any",	"{ any; }"},
			{ NULL,		NULL }
		       };*/

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

	if ( ! acls )
		return builtin;

        int i = 0;

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
	if ( 	strcmp( key, "localhost" ) 
		&& strcmp( key, "localnets" ) 
		&& strcmp( key, "none" )
		&& strcmp( key, "any")
	   )
		return 0;

	return 1;
	
}

#ifdef USE_CACHE
ACL *__ReadACL(void){
#else
ACL *ReadACL(void){
#endif
 	char *script = my_script_path("readacl.pl");	
	char *filename = get_conf(dns_conf,"bindconf");
	if (!filename)
		filename = strdup(BINDCONF);

	ACL *acl = (ACL *)readData1(script,filename,r_acl);
	free(script);
	free(filename);

	return addBuiltinACL( acl );
}

#ifdef USE_CACHE
ACL *ReadACL(void){
	char *conffile;
	ACL *acl;

	if (!gacl){
		if (!amon)
			amon = init_monitor(1);
		if (!amon)
			return __ReadACL();
		conffile = get_conf(dns_conf,"bindconf");
		if (!conffile)
			conffile = strdup(CONFFILE);
		monitor_file(amon,conffile);
		gacl = __ReadACL();
		free(conffile);
	}
	if (!check_events(amon))
		gacl = __ReadACL();

	copy_from_global(acl);
	return acl;
					
}

#endif 
int WriteACL(ACL *acl){

	char *script = malloc(1);
	char *uselib;
	ACL *aclptr = acl;
	asprintf(&uselib,"use lib '%s';use ACL;\n",my_script_path(""));	

	init_interpreter();
	eval_pv(uselib,TRUE);

	eval_pv(ACLIN,TRUE);
	while (aclptr && aclptr->key && aclptr->value){
		if ( checkBuiltinACL( aclptr->key ) )
		{	
			aclptr++;
			continue;
		}
		script = realloc(script,strlen(ACLDEF)+strlen(aclptr->key) + strlen(aclptr->value) + 1) ;
		sprintf(script,ACLDEF,aclptr->key,aclptr->value);
		eval_pv(script,TRUE);
		aclptr++;
	}		


	SV *status = eval_pv("${ACL::WriteAcl({},$acl)};",TRUE);
	eval_pv("undef $acl;",TRUE);
	#ifdef USE_CACHE
	if (gacl)
		freeACL(gacl);
	copy_to_global(acl);
	#endif
	//term_interpreter();
	return SvIV( status);


}
int addACL(ACL *acl){

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
char *getACL(ACL *acl_par, const char *key){


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

int setACL(BINDOPTS *acl_par, const char *key, const char *value){

	BINDOPTS *acl = acl_par;
	
	while (acl && acl->key && acl->value){
		if (!strcmp(key,acl->key)){
			if (acl->value)
				free(acl->value);
			acl->value = strdup(value);
			return WriteACL(acl_par);
		}
		acl++;
	}

	ACL *myAcl = malloc( sizeof( ACL ) );	
	myAcl->key = strdup( key );
	myAcl->value = strdup( value );

	int ret = addACL(myAcl);

	free( myAcl->key );
	free( myAcl->value );
	free( myAcl );	
	return ret;
}


int disableZone(const char *name){
	char *script= my_script_path("disable.sh");
	char *conffile = get_conf(dns_conf,"bindconf");	
	int ret =0;
	if (!conffile)
		conffile = strdup(BINDCONF);
	
	ret = execScript2(script,name,conffile);
	
	free(script);
	free(conffile);
	return ret;
}

int enableZone(const char *name){
	char *script= my_script_path("enable.sh");
	char *conffile = get_conf(dns_conf,"bindconf");
	int ret = 0;
		
	if (!conffile)
		conffile = strdup(BINDCONF);
	
	ret = execScript2(script,name,conffile);
	free(script);
	free(conffile);
	return ret;
}

int deleteZone(const char *name){
	DNSZONE *dz = getZones();
	int size,off;

	for (size = 0,off=0; dz+size && dz[size].zoneName;  size++){
		if (!strcmp(name,dz[size].zoneName))
			off = size;
	}

	if (!off && size){ /* means the zone was not found */
		freeZones(dz);
		return 0;
	}

	memmove(dz+off,dz+off+1,(size-off)*sizeof(DNSZONE));
	
	int ret = updateZones(dz);
	freeZones( dz );
	return ret;

}



