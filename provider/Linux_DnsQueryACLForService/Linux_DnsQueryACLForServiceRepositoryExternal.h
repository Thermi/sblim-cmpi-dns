 /**
 * Linux_DnsQueryACLForServiceRepositoryExternal.h
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
#ifndef Linux_DnsQueryACLForServiceRepositoryExternal_h
#define Linux_DnsQueryACLForServiceRepositoryExternal_h

#include "Linux_DnsQueryACLForServiceInstanceName.h"
#include "Linux_DnsQueryACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsQueryACLForServiceRepositoryExternal {
  	
    public:
    Linux_DnsQueryACLForServiceRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsQueryACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsQueryACLForServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsQueryACLForServiceRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsQueryACLForServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsQueryACLForServiceRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsQueryACLForServiceRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsQueryACLForServiceInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
