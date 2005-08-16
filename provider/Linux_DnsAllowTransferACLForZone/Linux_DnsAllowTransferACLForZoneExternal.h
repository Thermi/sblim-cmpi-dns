 /**
 * Linux_DnsAllowTransferACLForZoneExternal.h
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
#ifndef Linux_DnsAllowTransferACLForZoneExternal_h
#define Linux_DnsAllowTransferACLForZoneExternal_h

#include "Linux_DnsAllowTransferACLForZoneInstance.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneExternal {
  	
    public:
    Linux_DnsAllowTransferACLForZoneExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsAllowTransferACLForZoneExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsAllowTransferACLForZoneInstanceEnumeration&);
     
    virtual Linux_DnsAllowTransferACLForZoneInstance getInstance(
     const char* *properties,
     const Linux_DnsAllowTransferACLForZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAllowTransferACLForZoneInstance&);
     
    virtual void createInstance(
     const Linux_DnsAllowTransferACLForZoneInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAllowTransferACLForZoneInstanceName&);
    
    //association calls
    
    void referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowTransferACLForZoneInstanceEnumeration& instances);

    void referenceNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration& instanceNames);

    void referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowTransferACLForZoneInstanceEnumeration& instances);

    void referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration& instanceNames);

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
