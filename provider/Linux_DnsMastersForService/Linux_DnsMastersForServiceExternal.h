// =======================================================================
// Linux_DnsMastersForServiceExternal.h
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
#ifndef Linux_DnsMastersForServiceExternal_h
#define Linux_DnsMastersForServiceExternal_h


#include "Linux_DnsMastersForServiceInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsMastersInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMastersForServiceExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsMastersForServiceExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsMastersForServiceExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsMastersForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsMastersForServiceInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsMastersForServiceInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersForServiceInstance& anInstance);
     
    virtual Linux_DnsMastersForServiceInstanceName createInstance(
      const Linux_DnsMastersForServiceInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsMastersForServiceInstanceName& anInstanceName);


    //association calls

    void referencesGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsMastersInstanceName& aSourceInstanceName,
      Linux_DnsMastersForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsMastersInstanceName& aSourceInstanceName,
      Linux_DnsMastersForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsMastersForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsMastersForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsMastersInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsMastersInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsMastersInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsMastersInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
