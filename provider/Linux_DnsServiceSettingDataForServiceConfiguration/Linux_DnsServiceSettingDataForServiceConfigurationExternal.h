// =======================================================================
// Linux_DnsServiceSettingDataForServiceConfigurationExternal.h
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
#ifndef Linux_DnsServiceSettingDataForServiceConfigurationExternal_h
#define Linux_DnsServiceSettingDataForServiceConfigurationExternal_h


#include "Linux_DnsServiceSettingDataForServiceConfigurationInstance.h"
#include "Linux_DnsServiceConfigurationInstance.h"
#include "Linux_DnsServiceSettingDataInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceSettingDataForServiceConfigurationExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsServiceSettingDataForServiceConfigurationExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsServiceSettingDataForServiceConfigurationExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsServiceSettingDataForServiceConfigurationInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataForServiceConfigurationInstance& anInstance);
     
    virtual Linux_DnsServiceSettingDataForServiceConfigurationInstanceName createInstance(
      const Linux_DnsServiceSettingDataForServiceConfigurationInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName);


    //association calls

    void referencesGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataInstanceName& aSourceInstanceName,
      Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceSettingDataInstanceName& aSourceInstanceName,
      Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceSettingDataInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceSettingDataInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceSettingDataInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif