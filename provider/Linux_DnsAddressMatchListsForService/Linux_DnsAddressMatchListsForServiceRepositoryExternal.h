// =======================================================================
// Linux_DnsAddressMatchListsForServiceRepositoryExternal.h
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
#ifndef Linux_DnsAddressMatchListsForServiceRepositoryExternal_h
#define Linux_DnsAddressMatchListsForServiceRepositoryExternal_h

#include "Linux_DnsAddressMatchListsForServiceInstanceName.h"
#include "Linux_DnsAddressMatchListsForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAddressMatchListsForServiceRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsAddressMatchListsForServiceRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAddressMatchListsForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsAddressMatchListsForServiceRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListsForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsAddressMatchListsForServiceInstanceName createInstance(
      const Linux_DnsAddressMatchListsForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);
  
  };

}
#endif
