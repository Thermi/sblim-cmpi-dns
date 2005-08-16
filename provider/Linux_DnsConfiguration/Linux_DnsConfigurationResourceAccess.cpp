 /**
 * Linux_DnsConfigurationResourceAccess.cpp
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
#include "Linux_DnsConfigurationResourceAccess.h"

#include "defaultvalues.h"

namespace genProvider {
  
    //Linux_DnsConfigurationResourceAccess::Linux_DnsConfigurationResourceAccess();
    Linux_DnsConfigurationResourceAccess::~Linux_DnsConfigurationResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsConfigurationResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsConfigurationInstanceNameEnumeration& instnames){
      
	Linux_DnsConfigurationInstanceName instanceName;

        instanceName.setNamespace(nsp);
        instanceName.setName(DEFAULT_SERVICE_NAME);

        instnames.addElement(instanceName);
      
    }
    
  	
    void Linux_DnsConfigurationResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsConfigurationManualInstanceEnumeration& instances){

	Linux_DnsConfigurationInstanceName instanceName;
	Linux_DnsConfigurationManualInstance aManualInstance;

        instanceName.setNamespace(nsp);
        instanceName.setName(DEFAULT_SERVICE_NAME);
	
	aManualInstance.setInstanceName(instanceName);
	aManualInstance.setConfigurationFile(DEFAULT_CONFIGURATION_FILE);

        instances.addElement(aManualInstance);
    };
  	
  	
    Linux_DnsConfigurationManualInstance 
     Linux_DnsConfigurationResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsConfigurationInstanceName& instance){

        Linux_DnsConfigurationManualInstance aManualInstance;

        aManualInstance.setInstanceName(instance);
        aManualInstance.setConfigurationFile(DEFAULT_CONFIGURATION_FILE);
	
	return aManualInstance; 
    }
  	
  	/*
    void Linux_DnsConfigurationResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsConfigurationManualInstance&){};
  	*/
  	/*
    void Linux_DnsConfigurationResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsConfigurationManualInstance&){};
  	*/
  	/*
    void Linux_DnsConfigurationResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsConfigurationInstanceName&){};
	*/
    
    /* extrinsic methods */
	
}


