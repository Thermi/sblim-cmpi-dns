 /**
 * Linux_DnsBlackholeACLForServiceExternal.h
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
#ifndef Linux_DnsBlackholeACLForServiceExternal_h
#define Linux_DnsBlackholeACLForServiceExternal_h

#include "Linux_DnsBlackholeACLForServiceInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsBlackholeACLForServiceExternal {
  	
    public:
    Linux_DnsBlackholeACLForServiceExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsBlackholeACLForServiceExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsBlackholeACLForServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsBlackholeACLForServiceInstanceEnumeration&);
     
    virtual Linux_DnsBlackholeACLForServiceInstance getInstance(
     const char* *properties,
     const Linux_DnsBlackholeACLForServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsBlackholeACLForServiceInstance&);
     
    virtual void createInstance(
     const Linux_DnsBlackholeACLForServiceInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsBlackholeACLForServiceInstanceName&);
    
    //association calls
    
    void referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsBlackholeACLForServiceInstanceEnumeration& instances);

    void referenceNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsBlackholeACLForServiceInstanceNameEnumeration& instanceNames);

    void referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsBlackholeACLForServiceInstanceEnumeration& instances);

    void referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsBlackholeACLForServiceInstanceNameEnumeration& instanceNames);

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