// =======================================================================
// Linux_DnsAddressMatchListOfServiceExternal.h
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
#ifndef Linux_DnsAddressMatchListOfServiceExternal_h
#define Linux_DnsAddressMatchListOfServiceExternal_h


#include "Linux_DnsAddressMatchListOfServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsServiceInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsAddressMatchListOfServiceExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAddressMatchListOfServiceExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsAddressMatchListOfServiceInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsAddressMatchListOfServiceInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListOfServiceInstance& anInstance);
     
    virtual Linux_DnsAddressMatchListOfServiceInstanceName createInstance(
      const Linux_DnsAddressMatchListOfServiceInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName);


    //association calls

    void referencesDependent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListOfServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesDependent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesAntecedent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListOfServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesAntecedent( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsDependent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesDependent( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsAntecedent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesAntecedent( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
