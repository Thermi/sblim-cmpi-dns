// =======================================================================
// Linux_DnsManagedSystemElementForSettingRepositoryExternal.h
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
#ifndef Linux_DnsManagedSystemElementForSettingRepositoryExternal_h
#define Linux_DnsManagedSystemElementForSettingRepositoryExternal_h

#include "Linux_DnsManagedSystemElementForSettingInstanceName.h"
#include "Linux_DnsManagedSystemElementForSettingRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsManagedSystemElementForSettingRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsManagedSystemElementForSettingRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsManagedSystemElementForSettingRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsManagedSystemElementForSettingRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsManagedSystemElementForSettingInstanceName createInstance(
      const Linux_DnsManagedSystemElementForSettingRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);
  
  };

}
#endif
