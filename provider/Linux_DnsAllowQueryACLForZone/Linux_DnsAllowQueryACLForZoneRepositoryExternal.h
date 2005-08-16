 /**
 * Linux_DnsAllowQueryACLForZoneRepositoryExternal.h
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
#ifndef Linux_DnsAllowQueryACLForZoneRepositoryExternal_h
#define Linux_DnsAllowQueryACLForZoneRepositoryExternal_h

#include "Linux_DnsAllowQueryACLForZoneInstanceName.h"
#include "Linux_DnsAllowQueryACLForZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowQueryACLForZoneRepositoryExternal {
  	
    public:
    Linux_DnsAllowQueryACLForZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsAllowQueryACLForZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsAllowQueryACLForZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsAllowQueryACLForZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAllowQueryACLForZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsAllowQueryACLForZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAllowQueryACLForZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
