// =======================================================================
// Linux_DnsMastersForServiceRepositoryExternal.h
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
#ifndef Linux_DnsMastersForServiceRepositoryExternal_h
#define Linux_DnsMastersForServiceRepositoryExternal_h

#include "Linux_DnsMastersForServiceInstanceName.h"
#include "Linux_DnsMastersForServiceRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMastersForServiceRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsMastersForServiceRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsMastersForServiceRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsMastersForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsMastersForServiceRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsMastersForServiceRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsMastersForServiceInstanceName createInstance(
      const Linux_DnsMastersForServiceRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsMastersForServiceInstanceName& anInstanceName);
  
  };

}
#endif
