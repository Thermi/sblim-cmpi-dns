// =======================================================================
// Linux_DnsAllowNotifyACLForZoneExternal.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneExternal_h
#define Linux_DnsAllowNotifyACLForZoneExternal_h


#include "Linux_DnsAllowNotifyACLForZoneInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsAllowNotifyACLForZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAllowNotifyACLForZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsAllowNotifyACLForZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowNotifyACLForZoneInstance& anInstance);
     
    virtual Linux_DnsAllowNotifyACLForZoneInstanceName createInstance(
      const Linux_DnsAllowNotifyACLForZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName);


    //association calls

    void referencesSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

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
