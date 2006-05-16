// =======================================================================
// Linux_DnsManagedSystemElementForSettingExternal.h
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
#ifndef Linux_DnsManagedSystemElementForSettingExternal_h
#define Linux_DnsManagedSystemElementForSettingExternal_h


#include "Linux_DnsManagedSystemElementForSettingInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsManagedSystemElementForSettingExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsManagedSystemElementForSettingExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsManagedSystemElementForSettingInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsManagedSystemElementForSettingInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsManagedSystemElementForSettingInstance& anInstance);
     
    virtual Linux_DnsManagedSystemElementForSettingInstanceName createInstance(
      const Linux_DnsManagedSystemElementForSettingInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);


    //association calls

    void referencesSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsManagedSystemElementForSettingInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsManagedSystemElementForSettingInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
