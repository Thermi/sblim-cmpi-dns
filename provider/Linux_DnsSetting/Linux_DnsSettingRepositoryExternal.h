// =======================================================================
// Linux_DnsSettingRepositoryExternal.h
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
#ifndef Linux_DnsSettingRepositoryExternal_h
#define Linux_DnsSettingRepositoryExternal_h

#include "Linux_DnsSettingInstanceName.h"
#include "Linux_DnsSettingRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSettingRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsSettingRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsSettingRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsSettingInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsSettingRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsSettingRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsSettingInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsSettingRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsSettingInstanceName createInstance(
      const Linux_DnsSettingRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsSettingInstanceName& anInstanceName);
  
  };

}
#endif
