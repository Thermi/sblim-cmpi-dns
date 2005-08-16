 /**
 * Linux_DnsIPAddressRepositoryExternal.h
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
#ifndef Linux_DnsIPAddressRepositoryExternal_h
#define Linux_DnsIPAddressRepositoryExternal_h

#include "Linux_DnsIPAddressInstanceName.h"
#include "Linux_DnsIPAddressRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsIPAddressRepositoryExternal {
  	
    public:
    Linux_DnsIPAddressRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsIPAddressRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsIPAddressInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsIPAddressRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsIPAddressRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsIPAddressInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsIPAddressRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsIPAddressRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsIPAddressInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif