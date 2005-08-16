 /**
 * Linux_DnsServiceConfigurationResourceAccess.cpp
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
#include "Linux_DnsServiceConfigurationResourceAccess.h"

namespace genProvider {
  
    //Linux_DnsServiceConfigurationResourceAccess::Linux_DnsServiceConfigurationResourceAccess();
    Linux_DnsServiceConfigurationResourceAccess::~Linux_DnsServiceConfigurationResourceAccess() { };
    
    /* intrinsic methods */
    /*
    void Linux_DnsServiceConfigurationResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsServiceConfigurationInstanceNameEnumeration& instnames){
      
      int numInstanceNames=1;
      for(int i=0;i<numInstanceNames;i++){
      
        //place here the code retrieving your instanceName
      
        Linux_DnsServiceConfigurationInstanceName instanceName;
        
      }      
    }
    */
  	/*
    void Linux_DnsServiceConfigurationResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsServiceConfigurationManualInstanceEnumeration& instances){};
  	*/
  	/*
    Linux_DnsServiceConfigurationManualInstance 
     Linux_DnsServiceConfigurationResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsServiceConfigurationInstanceName&){
      Linux_DnsServiceConfigurationManualInstance instance;
      
    }
  	*/
  	/*
    void Linux_DnsServiceConfigurationResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsServiceConfigurationManualInstance&){};
  	*/
  	/*
    void Linux_DnsServiceConfigurationResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceConfigurationManualInstance&){};
  	*/
  	/*
    void Linux_DnsServiceConfigurationResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceConfigurationInstanceName&){};
	*/
    
    /* Association Interface */
    
    void Linux_DnsServiceConfigurationResourceAccess::referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsServiceConfigurationManualInstanceEnumeration& instEnum) {

     	Linux_DnsServiceInstanceName serviceInstanceName;
	
       	serviceInstanceName.setNamespace(nsp);
       	serviceInstanceName.setName(DEFAULT_SERVICE_NAME);
        serviceInstanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
        serviceInstanceName.setSystemName(DEFAULT_SYSTEM_NAME);
        serviceInstanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);

	Linux_DnsServiceConfigurationManualInstance aManualInstance;
	Linux_DnsServiceConfigurationInstanceName instanceName;
	instanceName.setNamespace( nsp );	
	instanceName.setElement( serviceInstanceName );
	instanceName.setConfiguration( sourceInst );
	
	aManualInstance.setInstanceName(instanceName);

        instEnum.addElement(aManualInstance);
     };


    void Linux_DnsServiceConfigurationResourceAccess::referencesConfiguration( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsServiceConfigurationManualInstanceEnumeration& instEnum) {
	
	Linux_DnsConfigurationInstanceName confInstanceName;
        confInstanceName.setNamespace(nsp);
        confInstanceName.setName(DEFAULT_SERVICE_NAME);
	
	Linux_DnsServiceConfigurationManualInstance aManualInstance;
	Linux_DnsServiceConfigurationInstanceName instanceName;
	instanceName.setNamespace( nsp );
	instanceName.setElement( sourceInst );
	instanceName.setConfiguration( confInstanceName );
	
	aManualInstance.setInstanceName(instanceName);

        instEnum.addElement(aManualInstance);

     };
    
    void Linux_DnsServiceConfigurationResourceAccess::associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
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
     
    void Linux_DnsServiceConfigurationResourceAccess::associatorsConfiguration( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceEnumeration& instEnum) {
	Linux_DnsConfigurationInstanceName instanceName;
	Linux_DnsConfigurationInstance aManualInstance;

        instanceName.setNamespace(nsp);
        instanceName.setName(DEFAULT_SERVICE_NAME);
	
	aManualInstance.setInstanceName(instanceName);
	aManualInstance.setConfigurationFile(DEFAULT_CONFIGURATION_FILE);

        instEnum.addElement(aManualInstance);
     };
    
     
    /* extrinsic methods */
	
}


