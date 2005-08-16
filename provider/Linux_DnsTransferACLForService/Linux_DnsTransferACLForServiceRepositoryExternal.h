 /**
 * Linux_DnsTransferACLForServiceRepositoryExternal.h
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
#ifndef Linux_DnsTransferACLForServiceRepositoryExternal_h
#define Linux_DnsTransferACLForServiceRepositoryExternal_h

#include "Linux_DnsTransferACLForServiceInstanceName.h"
#include "Linux_DnsTransferACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsTransferACLForServiceRepositoryExternal {
  	
    public:
    Linux_DnsTransferACLForServiceRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsTransferACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsTransferACLForServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsTransferACLForServiceRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsTransferACLForServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsTransferACLForServiceRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsTransferACLForServiceRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsTransferACLForServiceInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
