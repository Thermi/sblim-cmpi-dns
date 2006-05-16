// =======================================================================
// Linux_DnsElementSettingRepositoryExternal.h
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
#ifndef Linux_DnsElementSettingRepositoryExternal_h
#define Linux_DnsElementSettingRepositoryExternal_h

#include "Linux_DnsElementSettingInstanceName.h"
#include "Linux_DnsElementSettingRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsElementSettingRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsElementSettingRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsElementSettingRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsElementSettingInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsElementSettingRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsElementSettingRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsElementSettingInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsElementSettingRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsElementSettingInstanceName createInstance(
      const Linux_DnsElementSettingRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsElementSettingInstanceName& anInstanceName);
  
  };

}
#endif
