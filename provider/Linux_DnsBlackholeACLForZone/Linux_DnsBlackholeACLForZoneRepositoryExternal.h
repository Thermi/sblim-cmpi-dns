// =======================================================================
// Linux_DnsBlackholeACLForZoneRepositoryExternal.h
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
#ifndef Linux_DnsBlackholeACLForZoneRepositoryExternal_h
#define Linux_DnsBlackholeACLForZoneRepositoryExternal_h

#include "Linux_DnsBlackholeACLForZoneInstanceName.h"
#include "Linux_DnsBlackholeACLForZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsBlackholeACLForZoneRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsBlackholeACLForZoneRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsBlackholeACLForZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsBlackholeACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsBlackholeACLForZoneRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeACLForZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeACLForZoneRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsBlackholeACLForZoneInstanceName createInstance(
      const Linux_DnsBlackholeACLForZoneRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsBlackholeACLForZoneInstanceName& anInstanceName);
  
  };

}
#endif
