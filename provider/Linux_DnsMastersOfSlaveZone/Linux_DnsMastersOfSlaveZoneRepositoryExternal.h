// =======================================================================
// Linux_DnsMastersOfSlaveZoneRepositoryExternal.h
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
#ifndef Linux_DnsMastersOfSlaveZoneRepositoryExternal_h
#define Linux_DnsMastersOfSlaveZoneRepositoryExternal_h

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"
#include "Linux_DnsMastersOfSlaveZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsMastersOfSlaveZoneRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsMastersOfSlaveZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsMastersOfSlaveZoneRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersOfSlaveZoneRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsMastersOfSlaveZoneInstanceName createInstance(
      const Linux_DnsMastersOfSlaveZoneRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);
  
  };

}
#endif
