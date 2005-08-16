 /**
 * Linux_DnsAddressMatchListRepositoryExternal.h
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
#ifndef Linux_DnsAddressMatchListRepositoryExternal_h
#define Linux_DnsAddressMatchListRepositoryExternal_h

#include "Linux_DnsAddressMatchListInstanceName.h"
#include "Linux_DnsAddressMatchListRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAddressMatchListRepositoryExternal {
  	
    public:
    Linux_DnsAddressMatchListRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsAddressMatchListRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsAddressMatchListInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsAddressMatchListRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsAddressMatchListRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsAddressMatchListInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAddressMatchListRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsAddressMatchListRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAddressMatchListInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
