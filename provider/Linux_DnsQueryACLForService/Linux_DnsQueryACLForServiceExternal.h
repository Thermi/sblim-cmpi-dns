 /**
 * Linux_DnsQueryACLForServiceExternal.h
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
#ifndef Linux_DnsQueryACLForServiceExternal_h
#define Linux_DnsQueryACLForServiceExternal_h

#include "Linux_DnsQueryACLForServiceInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsQueryACLForServiceExternal {
  	
    public:
    Linux_DnsQueryACLForServiceExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsQueryACLForServiceExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsQueryACLForServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsQueryACLForServiceInstanceEnumeration&);
     
    virtual Linux_DnsQueryACLForServiceInstance getInstance(
     const char* *properties,
     const Linux_DnsQueryACLForServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsQueryACLForServiceInstance&);
     
    virtual void createInstance(
     const Linux_DnsQueryACLForServiceInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsQueryACLForServiceInstanceName&);
    
    //association calls
    
    void referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsQueryACLForServiceInstanceEnumeration& instances);

    void referenceNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsQueryACLForServiceInstanceNameEnumeration& instanceNames);

    void referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsQueryACLForServiceInstanceEnumeration& instances);

    void referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsQueryACLForServiceInstanceNameEnumeration& instanceNames);

    void associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances);

    void associatorNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceNameEnumeration& instanceNames);

    void associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances);

    void associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceNameEnumeration& instanceNames);

     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
