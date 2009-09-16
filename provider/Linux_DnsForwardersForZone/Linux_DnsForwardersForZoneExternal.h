// =======================================================================
// Linux_DnsForwardersForZoneExternal.h
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
#ifndef Linux_DnsForwardersForZoneExternal_h
#define Linux_DnsForwardersForZoneExternal_h


#include "Linux_DnsForwardersForZoneInstance.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsForwardersInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsForwardersForZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsForwardersForZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsForwardersForZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsForwardersForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsForwardersForZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsForwardersForZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardersForZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardersForZoneInstance& anInstance);
     
    virtual Linux_DnsForwardersForZoneInstanceName createInstance(
      const Linux_DnsForwardersForZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsForwardersForZoneInstanceName& anInstanceName);


    //association calls

    void referencesGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsForwardersInstanceName& aSourceInstanceName,
      Linux_DnsForwardersForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsForwardersInstanceName& aSourceInstanceName,
      Linux_DnsForwardersForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsForwardersForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsForwardersForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsForwardersInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsForwardersInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsForwardersInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsForwardersInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
