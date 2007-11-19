// =======================================================================
// Linux_DnsForwardersRepositoryExternal.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://www.opensource.org/licenses/cpl1.0.txt
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
#ifndef Linux_DnsForwardersRepositoryExternal_h
#define Linux_DnsForwardersRepositoryExternal_h

#include "Linux_DnsForwardersInstanceName.h"
#include "Linux_DnsForwardersRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsForwardersRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsForwardersRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsForwardersRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsForwardersInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsForwardersRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsForwardersRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardersInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardersRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsForwardersInstanceName createInstance(
      const Linux_DnsForwardersRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsForwardersInstanceName& anInstanceName);
  
  };

}
#endif
