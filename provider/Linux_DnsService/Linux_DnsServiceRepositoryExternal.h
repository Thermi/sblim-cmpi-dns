 /**
 * Linux_DnsServiceRepositoryExternal.h
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
#ifndef Linux_DnsServiceRepositoryExternal_h
#define Linux_DnsServiceRepositoryExternal_h

#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceRepositoryExternal {
  	
    public:
    Linux_DnsServiceRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsServiceRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsServiceRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsServiceRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsServiceRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsServiceInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
