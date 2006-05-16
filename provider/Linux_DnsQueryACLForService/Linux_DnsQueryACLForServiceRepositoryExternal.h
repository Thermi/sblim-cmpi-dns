// =======================================================================
// Linux_DnsQueryACLForServiceRepositoryExternal.h
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
#ifndef Linux_DnsQueryACLForServiceRepositoryExternal_h
#define Linux_DnsQueryACLForServiceRepositoryExternal_h

#include "Linux_DnsQueryACLForServiceInstanceName.h"
#include "Linux_DnsQueryACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsQueryACLForServiceRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsQueryACLForServiceRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsQueryACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsQueryACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsQueryACLForServiceRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsQueryACLForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsQueryACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsQueryACLForServiceInstanceName createInstance(
      const Linux_DnsQueryACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsQueryACLForServiceInstanceName& anInstanceName);
  
  };

}
#endif
