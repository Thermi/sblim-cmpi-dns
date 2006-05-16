// =======================================================================
// Linux_DnsAllowNotifyACLForZoneRepositoryExternal.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneRepositoryExternal_h
#define Linux_DnsAllowNotifyACLForZoneRepositoryExternal_h

#include "Linux_DnsAllowNotifyACLForZoneInstanceName.h"
#include "Linux_DnsAllowNotifyACLForZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsAllowNotifyACLForZoneRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAllowNotifyACLForZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsAllowNotifyACLForZoneRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsAllowNotifyACLForZoneInstanceName createInstance(
      const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName);
  
  };

}
#endif
