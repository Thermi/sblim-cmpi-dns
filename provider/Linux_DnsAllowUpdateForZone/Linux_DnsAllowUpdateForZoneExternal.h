// =======================================================================
// Linux_DnsAllowUpdateForZoneExternal.h
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
#ifndef Linux_DnsAllowUpdateForZoneExternal_h
#define Linux_DnsAllowUpdateForZoneExternal_h


#include "Linux_DnsAllowUpdateForZoneInstance.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowUpdateForZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsAllowUpdateForZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAllowUpdateForZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsAllowUpdateForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsAllowUpdateForZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsAllowUpdateForZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowUpdateForZoneInstance& anInstance);
     
    virtual Linux_DnsAllowUpdateForZoneInstanceName createInstance(
      const Linux_DnsAllowUpdateForZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName);


    //association calls

    void referencesGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAllowUpdateForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAllowUpdateForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAllowUpdateForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAllowUpdateForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
