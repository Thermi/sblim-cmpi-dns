// =======================================================================
// Linux_DnsAllowTransferForServiceExternal.h
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
#ifndef Linux_DnsAllowTransferForServiceExternal_h
#define Linux_DnsAllowTransferForServiceExternal_h


#include "Linux_DnsAllowTransferForServiceInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowTransferForServiceExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsAllowTransferForServiceExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAllowTransferForServiceExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsAllowTransferForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsAllowTransferForServiceInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsAllowTransferForServiceInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowTransferForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowTransferForServiceInstance& anInstance);
     
    virtual Linux_DnsAllowTransferForServiceInstanceName createInstance(
      const Linux_DnsAllowTransferForServiceInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAllowTransferForServiceInstanceName& anInstanceName);


    //association calls

    void referencesGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAllowTransferForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAllowTransferForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAllowTransferForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAllowTransferForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

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
