// =======================================================================
// Linux_DnsTransferACLForServiceRepositoryExternal.h
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
#ifndef Linux_DnsTransferACLForServiceRepositoryExternal_h
#define Linux_DnsTransferACLForServiceRepositoryExternal_h

#include "Linux_DnsTransferACLForServiceInstanceName.h"
#include "Linux_DnsTransferACLForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsTransferACLForServiceRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsTransferACLForServiceRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsTransferACLForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsTransferACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsTransferACLForServiceRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsTransferACLForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsTransferACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsTransferACLForServiceInstanceName createInstance(
      const Linux_DnsTransferACLForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsTransferACLForServiceInstanceName& anInstanceName);
  
  };

}
#endif
