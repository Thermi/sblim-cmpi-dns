// =======================================================================
// Linux_DnsAllowQueryForServiceRepositoryExternal.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
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
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsAllowQueryForServiceRepositoryExternal_h
#define Linux_DnsAllowQueryForServiceRepositoryExternal_h

#include "Linux_DnsAllowQueryForServiceInstanceName.h"
#include "Linux_DnsAllowQueryForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowQueryForServiceRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsAllowQueryForServiceRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAllowQueryForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsAllowQueryForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsAllowQueryForServiceRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsAllowQueryForServiceRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowQueryForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsAllowQueryForServiceInstanceName createInstance(
      const Linux_DnsAllowQueryForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);
  
  };

}
#endif