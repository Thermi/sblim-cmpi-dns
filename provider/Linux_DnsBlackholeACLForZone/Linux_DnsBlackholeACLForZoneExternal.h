// =======================================================================
// Linux_DnsBlackholeACLForZoneExternal.h
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
#ifndef Linux_DnsBlackholeACLForZoneExternal_h
#define Linux_DnsBlackholeACLForZoneExternal_h


#include "Linux_DnsBlackholeACLForZoneInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsBlackholeACLForZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsBlackholeACLForZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsBlackholeACLForZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsBlackholeACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsBlackholeACLForZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsBlackholeACLForZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeACLForZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeACLForZoneInstance& anInstance);
     
    virtual Linux_DnsBlackholeACLForZoneInstanceName createInstance(
      const Linux_DnsBlackholeACLForZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsBlackholeACLForZoneInstanceName& anInstanceName);


    //association calls

    void referencesSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsBlackholeACLForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsBlackholeACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsBlackholeACLForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsBlackholeACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

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
