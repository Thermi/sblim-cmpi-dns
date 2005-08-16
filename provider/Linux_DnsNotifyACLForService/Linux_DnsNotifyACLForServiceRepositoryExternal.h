 /**
 * Linux_DnsNotifyACLForServiceRepositoryExternal.h
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
#ifndef Linux_DnsNotifyACLForServiceRepositoryExternal_h
#define Linux_DnsNotifyACLForServiceRepositoryExternal_h

#include "Linux_DnsNotifyACLForServiceInstanceName.h"
#include "Linux_DnsNotifyACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsNotifyACLForServiceRepositoryExternal {
  	
    public:
    Linux_DnsNotifyACLForServiceRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsNotifyACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsNotifyACLForServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsNotifyACLForServiceRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsNotifyACLForServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsNotifyACLForServiceRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsNotifyACLForServiceRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsNotifyACLForServiceInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
