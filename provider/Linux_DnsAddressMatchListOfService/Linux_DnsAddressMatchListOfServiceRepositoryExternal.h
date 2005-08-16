 /**
 * Linux_DnsAddressMatchListOfServiceRepositoryExternal.h
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
#ifndef Linux_DnsAddressMatchListOfServiceRepositoryExternal_h
#define Linux_DnsAddressMatchListOfServiceRepositoryExternal_h

#include "Linux_DnsAddressMatchListOfServiceInstanceName.h"
#include "Linux_DnsAddressMatchListOfServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceRepositoryExternal {
  	
    public:
    Linux_DnsAddressMatchListOfServiceRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsAddressMatchListOfServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsAddressMatchListOfServiceRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsAddressMatchListOfServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAddressMatchListOfServiceRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsAddressMatchListOfServiceRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAddressMatchListOfServiceInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
