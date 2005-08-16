 /**
 * Linux_DnsAllowUpdateACLForZoneRepositoryExternal.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneRepositoryExternal_h
#define Linux_DnsAllowUpdateACLForZoneRepositoryExternal_h

#include "Linux_DnsAllowUpdateACLForZoneInstanceName.h"
#include "Linux_DnsAllowUpdateACLForZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowUpdateACLForZoneRepositoryExternal {
  	
    public:
    Linux_DnsAllowUpdateACLForZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsAllowUpdateACLForZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsAllowUpdateACLForZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsAllowUpdateACLForZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAllowUpdateACLForZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsAllowUpdateACLForZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAllowUpdateACLForZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
