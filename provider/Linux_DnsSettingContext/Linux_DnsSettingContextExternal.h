// =======================================================================
// Linux_DnsSettingContextExternal.h
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
#ifndef Linux_DnsSettingContextExternal_h
#define Linux_DnsSettingContextExternal_h


#include "Linux_DnsSettingContextInstance.h"
#include "Linux_DnsSettingInstance.h"
#include "Linux_DnsConfigurationInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSettingContextExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsSettingContextExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsSettingContextExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsSettingContextInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsSettingContextInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsSettingContextInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsSettingContextInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsSettingContextInstance& anInstance);
     
    virtual Linux_DnsSettingContextInstanceName createInstance(
      const Linux_DnsSettingContextInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsSettingContextInstanceName& anInstanceName);


    //association calls

    void referencesSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsSettingContextInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsSettingContextInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesContext( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSettingInstanceName& aSourceInstanceName,
      Linux_DnsSettingContextInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesContext( 
      const char *aNameSpaceP,
      const Linux_DnsSettingInstanceName& aSourceInstanceName,
      Linux_DnsSettingContextInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsSettingInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsSettingInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsContext( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSettingInstanceName& aSourceInstanceName,
      Linux_DnsConfigurationInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesContext( 
      const char *aNameSpaceP,
      const Linux_DnsSettingInstanceName& aSourceInstanceName,
      Linux_DnsConfigurationInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
