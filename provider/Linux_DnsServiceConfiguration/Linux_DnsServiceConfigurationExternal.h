 /**
 * Linux_DnsServiceConfigurationExternal.h
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
#ifndef Linux_DnsServiceConfigurationExternal_h
#define Linux_DnsServiceConfigurationExternal_h

#include "Linux_DnsServiceConfigurationInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsConfigurationInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceConfigurationExternal {
  	
    public:
    Linux_DnsServiceConfigurationExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsServiceConfigurationExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsServiceConfigurationInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsServiceConfigurationInstanceEnumeration&);
     
    virtual Linux_DnsServiceConfigurationInstance getInstance(
     const char* *properties,
     const Linux_DnsServiceConfigurationInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsServiceConfigurationInstance&);
     
    virtual void createInstance(
     const Linux_DnsServiceConfigurationInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsServiceConfigurationInstanceName&);
    
    //association calls
    
    void referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsServiceConfigurationInstanceEnumeration& instances);

    void referenceNamesElement( 
     const char *nsp,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsServiceConfigurationInstanceNameEnumeration& instanceNames);

    void referencesConfiguration( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsServiceConfigurationInstanceEnumeration& instances);

    void referenceNamesConfiguration( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsServiceConfigurationInstanceNameEnumeration& instanceNames);

    void associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances);

    void associatorNamesElement( 
     const char *nsp,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsServiceInstanceNameEnumeration& instanceNames);

    void associatorsConfiguration( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceEnumeration& instances);

    void associatorNamesConfiguration( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceNameEnumeration& instanceNames);

     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
