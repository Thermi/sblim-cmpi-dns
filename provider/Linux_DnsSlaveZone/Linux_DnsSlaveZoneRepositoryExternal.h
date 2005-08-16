 /**
 * Linux_DnsSlaveZoneRepositoryExternal.h
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
#ifndef Linux_DnsSlaveZoneRepositoryExternal_h
#define Linux_DnsSlaveZoneRepositoryExternal_h

#include "Linux_DnsSlaveZoneInstanceName.h"
#include "Linux_DnsSlaveZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSlaveZoneRepositoryExternal {
  	
    public:
    Linux_DnsSlaveZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsSlaveZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsSlaveZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsSlaveZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsSlaveZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsSlaveZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsSlaveZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsSlaveZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsSlaveZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif