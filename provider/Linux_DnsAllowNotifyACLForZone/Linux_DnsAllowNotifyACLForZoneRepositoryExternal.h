 /**
 * Linux_DnsAllowNotifyACLForZoneRepositoryExternal.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneRepositoryExternal_h
#define Linux_DnsAllowNotifyACLForZoneRepositoryExternal_h

#include "Linux_DnsAllowNotifyACLForZoneInstanceName.h"
#include "Linux_DnsAllowNotifyACLForZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneRepositoryExternal {
  	
    public:
    Linux_DnsAllowNotifyACLForZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsAllowNotifyACLForZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsAllowNotifyACLForZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsAllowNotifyACLForZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAllowNotifyACLForZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsAllowNotifyACLForZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAllowNotifyACLForZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
