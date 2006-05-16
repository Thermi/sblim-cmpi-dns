// =======================================================================
// Linux_DnsBlackholeACLForServiceRepositoryExternal.h
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsBlackholeACLForServiceRepositoryExternal_h
#define Linux_DnsBlackholeACLForServiceRepositoryExternal_h

#include "Linux_DnsBlackholeACLForServiceInstanceName.h"
#include "Linux_DnsBlackholeACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsBlackholeACLForServiceRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsBlackholeACLForServiceRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsBlackholeACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsBlackholeACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsBlackholeACLForServiceRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsBlackholeACLForServiceInstanceName createInstance(
      const Linux_DnsBlackholeACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName);
  
  };

}
#endif
