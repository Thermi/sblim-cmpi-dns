// =======================================================================
// Linux_DnsNotifyACLForServiceRepositoryExternal.h
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
#ifndef Linux_DnsNotifyACLForServiceRepositoryExternal_h
#define Linux_DnsNotifyACLForServiceRepositoryExternal_h

#include "Linux_DnsNotifyACLForServiceInstanceName.h"
#include "Linux_DnsNotifyACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsNotifyACLForServiceRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsNotifyACLForServiceRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsNotifyACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsNotifyACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsNotifyACLForServiceRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsNotifyACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsNotifyACLForServiceInstanceName createInstance(
      const Linux_DnsNotifyACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName);
  
  };

}
#endif
