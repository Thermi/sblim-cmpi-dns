// =======================================================================
// Linux_DnsMastersRepositoryExternal.h
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
#ifndef Linux_DnsMastersRepositoryExternal_h
#define Linux_DnsMastersRepositoryExternal_h

#include "Linux_DnsMastersInstanceName.h"
#include "Linux_DnsMastersRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMastersRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsMastersRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsMastersRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsMastersInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsMastersRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsMastersRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsMastersInstanceName createInstance(
      const Linux_DnsMastersRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsMastersInstanceName& anInstanceName);
  
  };

}
#endif
