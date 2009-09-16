// =======================================================================
// Linux_DnsServiceConfigurationForServiceExternal.h
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
#ifndef Linux_DnsServiceConfigurationForServiceExternal_h
#define Linux_DnsServiceConfigurationForServiceExternal_h


#include "Linux_DnsServiceConfigurationForServiceInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsServiceConfigurationInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceConfigurationForServiceExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsServiceConfigurationForServiceExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsServiceConfigurationForServiceExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsServiceConfigurationForServiceInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsServiceConfigurationForServiceInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationForServiceInstance& anInstance);
     
    virtual Linux_DnsServiceConfigurationForServiceInstanceName createInstance(
      const Linux_DnsServiceConfigurationForServiceInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);


    //association calls

    void referencesElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesConfiguration( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesConfiguration( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsConfiguration( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesConfiguration( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
