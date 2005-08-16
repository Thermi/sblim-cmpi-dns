 /**
 * Linux_DnsForwardZoneRepositoryExternal.h
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
#ifndef Linux_DnsForwardZoneRepositoryExternal_h
#define Linux_DnsForwardZoneRepositoryExternal_h

#include "Linux_DnsForwardZoneInstanceName.h"
#include "Linux_DnsForwardZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsForwardZoneRepositoryExternal {
  	
    public:
    Linux_DnsForwardZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsForwardZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsForwardZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsForwardZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsForwardZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsForwardZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsForwardZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsForwardZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsForwardZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
