 /**
 * Linux_DnsZoneRepositoryExternal.h
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
#ifndef Linux_DnsZoneRepositoryExternal_h
#define Linux_DnsZoneRepositoryExternal_h

#include "Linux_DnsZoneInstanceName.h"
#include "Linux_DnsZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsZoneRepositoryExternal {
  	
    public:
    Linux_DnsZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
