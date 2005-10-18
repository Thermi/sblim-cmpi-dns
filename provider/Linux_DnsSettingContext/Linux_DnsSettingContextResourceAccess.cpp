 /**
 * Linux_DnsSettingContextResourceAccess.cpp
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
#include <iostream>

using namespace std;

#include "Linux_DnsSettingContextResourceAccess.h"

namespace genProvider {
  
    //Linux_DnsSettingContextResourceAccess::Linux_DnsSettingContextResourceAccess();
    Linux_DnsSettingContextResourceAccess::~Linux_DnsSettingContextResourceAccess() { };
    
    /* intrinsic methods */
    /*
    void Linux_DnsSettingContextResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsSettingContextInstanceNameEnumeration& instnames){
      
      int numInstanceNames=1;
      for(int i=0;i<numInstanceNames;i++){
      
        //place here the code retrieving your instanceName
      
        Linux_DnsSettingContextInstanceName instanceName;
        
      }      
    }
    */
  	/*
    void Linux_DnsSettingContextResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsSettingContextManualInstanceEnumeration& instances){};
  	*/
  	/*
    Linux_DnsSettingContextManualInstance 
     Linux_DnsSettingContextResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSettingContextInstanceName&){
      Linux_DnsSettingContextManualInstance instance;
      
    }
  	*/
  	/*
    void Linux_DnsSettingContextResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSettingContextManualInstance&){};
  	*/
  	/*
    void Linux_DnsSettingContextResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingContextManualInstance&){};
  	*/
  	/*
    void Linux_DnsSettingContextResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingContextInstanceName&){};
	*/
    
    /* Association Interface */
    
    void Linux_DnsSettingContextResourceAccess::referencesContext( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsSettingContextManualInstanceEnumeration& instEnum) {

        Linux_DnsConfigurationInstanceName configInstName;
        configInstName.setNamespace( nsp );
        configInstName.setName( DEFAULT_SERVICE_NAME );
	
	Linux_DnsSettingContextManualInstance inst;
	Linux_DnsSettingContextInstanceName instName;
	instName.setNamespace( nsp );
	instName.setContext( configInstName );
	instName.setSetting( sourceInst );
	inst.setInstanceName( instName );

        instEnum.addElement( inst );
	
    };
    
    
    void Linux_DnsSettingContextResourceAccess::referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingContextManualInstanceEnumeration& instEnum) {
	
        Linux_DnsSettingInstanceName settingInstName;
        settingInstName.setNamespace(nsp);
        settingInstName.setName(DEFAULT_SERVICE_NAME);
	
	Linux_DnsSettingContextManualInstance inst;
        Linux_DnsSettingContextInstanceName instName;
	instName.setNamespace( nsp ); 
        instName.setContext( sourceInst );
        instName.setSetting( settingInstName );
        inst.setInstanceName( instName );

	instEnum.addElement( inst );
    };
    
    
    void Linux_DnsSettingContextResourceAccess::associatorsContext( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceEnumeration& instEnum) {


	Linux_DnsConfigurationInstance configInst;
	Linux_DnsConfigurationInstanceName configInstName;

	configInstName.setNamespace( nsp );
	configInstName.setName( DEFAULT_SERVICE_NAME );
	configInst.setInstanceName( configInstName );
        configInst.setConfigurationFile( get_bindconf() );
	
	instEnum.addElement( configInst );
    };
    
    
    void Linux_DnsSettingContextResourceAccess::associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingInstanceEnumeration& instEnum) {

	Linux_DnsSettingInstance settingInst;
        Linux_DnsSettingInstanceName instanceName;

        instanceName.setNamespace(nsp);
        instanceName.setName(DEFAULT_SERVICE_NAME);

        settingInst.setInstanceName(instanceName);

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

                settingInst.setConfigurationDirectory( directory.c_str() );
        }

        char *port = getOption(bopts,"port");
        if ( port != NULL )
        {
                settingInst.setPortNumber( atoi( port ) );
                free( port );
        }

        char *tsig = getOption(bopts,"TSIG");
        if ( tsig != NULL )
        {
                settingInst.setTSIG( atoi( tsig ) );
                free( tsig );
        }

        char *ttl = getOption(bopts,"TTL");
        if ( ttl != NULL )
        {
                settingInst.setTTL( atoi( ttl ) );
                free( ttl );
        }

        instEnum.addElement(settingInst);
    };
    
   
    /* extrinsic methods */
	
}


