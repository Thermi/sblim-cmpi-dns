 /**
 * Linux_DnsAllowTransferACLForZoneRepositoryExternal.h
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
#ifndef Linux_DnsAllowTransferACLForZoneRepositoryExternal_h
#define Linux_DnsAllowTransferACLForZoneRepositoryExternal_h

#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"
#include "Linux_DnsAllowTransferACLForZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneRepositoryExternal {
  	
    public:
    Linux_DnsAllowTransferACLForZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsAllowTransferACLForZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsAllowTransferACLForZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsAllowTransferACLForZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAllowTransferACLForZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsAllowTransferACLForZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAllowTransferACLForZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
