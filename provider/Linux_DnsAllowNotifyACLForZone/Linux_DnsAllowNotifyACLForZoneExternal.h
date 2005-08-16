 /**
 * Linux_DnsAllowNotifyACLForZoneExternal.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneExternal_h
#define Linux_DnsAllowNotifyACLForZoneExternal_h

#include "Linux_DnsAllowNotifyACLForZoneInstance.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneExternal {
  	
    public:
    Linux_DnsAllowNotifyACLForZoneExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsAllowNotifyACLForZoneExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsAllowNotifyACLForZoneInstanceEnumeration&);
     
    virtual Linux_DnsAllowNotifyACLForZoneInstance getInstance(
     const char* *properties,
     const Linux_DnsAllowNotifyACLForZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAllowNotifyACLForZoneInstance&);
     
    virtual void createInstance(
     const Linux_DnsAllowNotifyACLForZoneInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAllowNotifyACLForZoneInstanceName&);
    
    //association calls
    
    void referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& instances);

    void referenceNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& instanceNames);

    void referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& instances);

    void referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& instanceNames);

    void associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances);

    void associatorNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceNameEnumeration& instanceNames);

    void associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances);

    void associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceNameEnumeration& instanceNames);

     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
