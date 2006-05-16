// =======================================================================
// Linux_DnsConfigurationRepositoryExternal.h
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
#ifndef Linux_DnsConfigurationRepositoryExternal_h
#define Linux_DnsConfigurationRepositoryExternal_h

#include "Linux_DnsConfigurationInstanceName.h"
#include "Linux_DnsConfigurationRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsConfigurationRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsConfigurationRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsConfigurationRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsConfigurationRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsConfigurationRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsConfigurationInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsConfigurationRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsConfigurationInstanceName createInstance(
      const Linux_DnsConfigurationRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsConfigurationInstanceName& anInstanceName);
  
  };

}
#endif
