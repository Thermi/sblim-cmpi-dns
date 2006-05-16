// =======================================================================
// Linux_DnsMasterZoneRepositoryExternal.h
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
#ifndef Linux_DnsMasterZoneRepositoryExternal_h
#define Linux_DnsMasterZoneRepositoryExternal_h

#include "Linux_DnsMasterZoneInstanceName.h"
#include "Linux_DnsMasterZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMasterZoneRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsMasterZoneRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsMasterZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsMasterZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsMasterZoneRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsMasterZoneRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsMasterZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsMasterZoneRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsMasterZoneInstanceName createInstance(
      const Linux_DnsMasterZoneRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsMasterZoneInstanceName& anInstanceName);
  
  };

}
#endif
