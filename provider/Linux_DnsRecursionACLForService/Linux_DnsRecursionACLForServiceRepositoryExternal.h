 /**
 * Linux_DnsRecursionACLForServiceRepositoryExternal.h
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
#ifndef Linux_DnsRecursionACLForServiceRepositoryExternal_h
#define Linux_DnsRecursionACLForServiceRepositoryExternal_h

#include "Linux_DnsRecursionACLForServiceInstanceName.h"
#include "Linux_DnsRecursionACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsRecursionACLForServiceRepositoryExternal {
  	
    public:
    Linux_DnsRecursionACLForServiceRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsRecursionACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsRecursionACLForServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsRecursionACLForServiceRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsRecursionACLForServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsRecursionACLForServiceRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsRecursionACLForServiceRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsRecursionACLForServiceInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
