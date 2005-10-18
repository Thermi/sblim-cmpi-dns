 /**
 * Linux_DnsElementSettingResourceAccess.cpp
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
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#include "Linux_DnsElementSettingResourceAccess.h"

namespace genProvider {
  
    //Linux_DnsElementSettingResourceAccess::Linux_DnsElementSettingResourceAccess();
    Linux_DnsElementSettingResourceAccess::~Linux_DnsElementSettingResourceAccess() { };
    
    /* intrinsic methods */
    /*
    void Linux_DnsElementSettingResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsElementSettingInstanceNameEnumeration& instnames){
      
      int numInstanceNames=1;
      for(int i=0;i<numInstanceNames;i++){
      
        //place here the code retrieving your instanceName
      
        Linux_DnsElementSettingInstanceName instanceName;
        
      }      
    }
    */
  	/*
    void Linux_DnsElementSettingResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsElementSettingManualInstanceEnumeration& instances){};
  	*/
  	/*
    Linux_DnsElementSettingManualInstance 
     Linux_DnsElementSettingResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsElementSettingInstanceName&){
      Linux_DnsElementSettingManualInstance instance;
      
    }
  	*/
  	/*
    void Linux_DnsElementSettingResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsElementSettingManualInstance&){};
  	*/
  	/*
    void Linux_DnsElementSettingResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsElementSettingManualInstance&){};
  	*/
  	/*
    void Linux_DnsElementSettingResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsElementSettingInstanceName&){};
	*/
    
    /* Association Interface */
    
    void Linux_DnsElementSettingResourceAccess::referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsElementSettingManualInstanceEnumeration& instEnum) {
	Linux_DnsServiceInstanceName serviceInstName;
        serviceInstName.setNamespace(nsp);
        serviceInstName.setName(DEFAULT_SERVICE_NAME);
        serviceInstName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
        serviceInstName.setSystemName(DEFAULT_SYSTEM_NAME);
        serviceInstName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);

	Linux_DnsElementSettingManualInstance inst;
	Linux_DnsElementSettingInstanceName instName;
	instName.setNamespace( nsp );
	instName.setElement( serviceInstName );
	instName.setSetting( sourceInst );
	inst.setInstanceName( instName );

	instEnum.addElement( inst );
    };
    
    
    void Linux_DnsElementSettingResourceAccess::referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsElementSettingManualInstanceEnumeration& instEnum) {

        Linux_DnsSettingInstanceName settingInstName;

        settingInstName.setNamespace(nsp);
        settingInstName.setName(DEFAULT_SERVICE_NAME);

        Linux_DnsElementSettingManualInstance inst;
        Linux_DnsElementSettingInstanceName instName;
	instName.setNamespace( nsp );
        instName.setElement( sourceInst );
        instName.setSetting( settingInstName );
        inst.setInstanceName( instName );

        instEnum.addElement( inst );

    };
    
    
    void Linux_DnsElementSettingResourceAccess::associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instEnum) {

	Linux_DnsServiceInstance inst;
        Linux_DnsServiceInstanceName instanceName;

        instanceName.setNamespace(nsp);
        instanceName.setName(DEFAULT_SERVICE_NAME);
        instanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
        instanceName.setSystemName(DEFAULT_SYSTEM_NAME);
        instanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
        inst.setInstanceName(instanceName);

        instEnum.addElement(inst);

    };
   
    void Linux_DnsElementSettingResourceAccess::associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsSettingInstanceEnumeration& instEnum) {
   
        Linux_DnsSettingInstance aManualInstance;
        Linux_DnsSettingInstanceName instanceName;

        instanceName.setNamespace(nsp);
        instanceName.setName(DEFAULT_SERVICE_NAME);

        aManualInstance.setInstanceName(instanceName);

	BINDOPTS *bopts = ReadOptions();

        string directory = string( getOption(bopts,"directory") );
        if ( directory.length() )
        {
                string::size_type pos = 0;
                while (pos != string::npos)
                {
                        pos = directory.find("\"",pos);
                        if (pos != string::npos)
                                directory.erase(pos,1);
                }

                aManualInstance.setConfigurationDirectory( directory.c_str() );
        }

        char *forward = getOption(bopts,"forward");
        if ( forward )
        {
                if ( strcmp( forward, "first" ) )
                        aManualInstance.setForward( DNS_FORWARD_FIRST  );

                if ( strcmp( forward, "only" ) )
                        aManualInstance.setForward( DNS_FORWARD_ONLY );

                free( forward );
        }

        char* forwarders = getOption( bopts, "forwarders" );
        if ( forwarders )
        {
                DnsArray da = DnsArray( forwarders );
                aManualInstance.setForwarders( da.toArray(), da.size() );
                free( forwarders );
        }

        char *port = getOption(bopts,"port");
        if ( port != NULL )
        {
                aManualInstance.setPortNumber( atoi( port ) );
                free( port );
        }

        char *tsig = getOption(bopts,"TSIG");
        if ( tsig != NULL )
        {
                aManualInstance.setTSIG( atoi( tsig ) );
                free( tsig );
        }

        char *ttl = getOption(bopts,"TTL");
        if ( ttl != NULL )
        {
                aManualInstance.setTTL( atoi( ttl ) );
                free( ttl );
        }

        instEnum.addElement(aManualInstance);
   };
    
   
    /* extrinsic methods */
	
}


