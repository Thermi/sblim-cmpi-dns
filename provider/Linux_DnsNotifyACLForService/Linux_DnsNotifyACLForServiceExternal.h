 /**
 * Linux_DnsNotifyACLForServiceExternal.h
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
#ifndef Linux_DnsNotifyACLForServiceExternal_h
#define Linux_DnsNotifyACLForServiceExternal_h

#include "Linux_DnsNotifyACLForServiceInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsNotifyACLForServiceExternal {
  	
    public:
    Linux_DnsNotifyACLForServiceExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsNotifyACLForServiceExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsNotifyACLForServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsNotifyACLForServiceInstanceEnumeration&);
     
    virtual Linux_DnsNotifyACLForServiceInstance getInstance(
     const char* *properties,
     const Linux_DnsNotifyACLForServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsNotifyACLForServiceInstance&);
     
    virtual void createInstance(
     const Linux_DnsNotifyACLForServiceInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsNotifyACLForServiceInstanceName&);
    
    //association calls
    
    void referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceInstanceEnumeration& instances);

    void referenceNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceInstanceNameEnumeration& instanceNames);

    void referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceInstanceEnumeration& instances);

    void referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceInstanceNameEnumeration& instanceNames);

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
