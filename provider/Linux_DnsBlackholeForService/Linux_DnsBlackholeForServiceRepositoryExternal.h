// =======================================================================
// Linux_DnsBlackholeForServiceRepositoryExternal.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsBlackholeForServiceRepositoryExternal_h
#define Linux_DnsBlackholeForServiceRepositoryExternal_h

#include "Linux_DnsBlackholeForServiceInstanceName.h"
#include "Linux_DnsBlackholeForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsBlackholeForServiceRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsBlackholeForServiceRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsBlackholeForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsBlackholeForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsBlackholeForServiceRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsBlackholeForServiceRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsBlackholeForServiceInstanceName createInstance(
      const Linux_DnsBlackholeForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);
  
  };

}
#endif
