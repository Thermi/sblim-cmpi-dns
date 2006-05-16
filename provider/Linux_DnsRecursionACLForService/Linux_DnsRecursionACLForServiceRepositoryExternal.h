// =======================================================================
// Linux_DnsRecursionACLForServiceRepositoryExternal.h
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
#ifndef Linux_DnsRecursionACLForServiceRepositoryExternal_h
#define Linux_DnsRecursionACLForServiceRepositoryExternal_h

#include "Linux_DnsRecursionACLForServiceInstanceName.h"
#include "Linux_DnsRecursionACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsRecursionACLForServiceRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsRecursionACLForServiceRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsRecursionACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsRecursionACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsRecursionACLForServiceRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsRecursionACLForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsRecursionACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsRecursionACLForServiceInstanceName createInstance(
      const Linux_DnsRecursionACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsRecursionACLForServiceInstanceName& anInstanceName);
  
  };

}
#endif
