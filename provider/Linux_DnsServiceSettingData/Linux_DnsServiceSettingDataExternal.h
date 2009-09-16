// =======================================================================
// Linux_DnsServiceSettingDataExternal.h
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
#ifndef Linux_DnsServiceSettingDataExternal_h
#define Linux_DnsServiceSettingDataExternal_h


#include "Linux_DnsServiceSettingDataInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceSettingDataExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsServiceSettingDataExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsServiceSettingDataExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsServiceSettingDataInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsServiceSettingDataInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsServiceSettingDataInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataInstance& anInstance);
     
    virtual Linux_DnsServiceSettingDataInstanceName createInstance(
      const Linux_DnsServiceSettingDataInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsServiceSettingDataInstanceName& anInstanceName);

 
  
  };

}

#endif
