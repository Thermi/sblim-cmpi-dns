// =======================================================================
// Linux_DnsBlackholeForServiceExternal.h
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
#ifndef Linux_DnsBlackholeForServiceExternal_h
#define Linux_DnsBlackholeForServiceExternal_h


#include "Linux_DnsBlackholeForServiceInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsBlackholeForServiceExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsBlackholeForServiceExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsBlackholeForServiceExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsBlackholeForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsBlackholeForServiceInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsBlackholeForServiceInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsBlackholeForServiceInstance& anInstance);
     
    virtual Linux_DnsBlackholeForServiceInstanceName createInstance(
      const Linux_DnsBlackholeForServiceInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);


    //association calls

    void referencesGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsBlackholeForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsBlackholeForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsBlackholeForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsBlackholeForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
