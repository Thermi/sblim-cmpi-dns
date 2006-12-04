// =======================================================================
// Linux_DnsServiceSettingDataRepositoryExternal.h
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
#ifndef Linux_DnsServiceSettingDataRepositoryExternal_h
#define Linux_DnsServiceSettingDataRepositoryExternal_h

#include "Linux_DnsServiceSettingDataInstanceName.h"
#include "Linux_DnsServiceSettingDataRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceSettingDataRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsServiceSettingDataRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsServiceSettingDataRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsServiceSettingDataInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsServiceSettingDataRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsServiceSettingDataRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsServiceSettingDataInstanceName createInstance(
      const Linux_DnsServiceSettingDataRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsServiceSettingDataInstanceName& anInstanceName);
  
  };

}
#endif