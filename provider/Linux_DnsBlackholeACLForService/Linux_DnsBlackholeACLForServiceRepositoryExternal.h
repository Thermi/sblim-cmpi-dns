 /**
 * Linux_DnsBlackholeACLForServiceRepositoryExternal.h
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
#ifndef Linux_DnsBlackholeACLForServiceRepositoryExternal_h
#define Linux_DnsBlackholeACLForServiceRepositoryExternal_h

#include "Linux_DnsBlackholeACLForServiceInstanceName.h"
#include "Linux_DnsBlackholeACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsBlackholeACLForServiceRepositoryExternal {
  	
    public:
    Linux_DnsBlackholeACLForServiceRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsBlackholeACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsBlackholeACLForServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsBlackholeACLForServiceRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsBlackholeACLForServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsBlackholeACLForServiceRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsBlackholeACLForServiceRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsBlackholeACLForServiceInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
