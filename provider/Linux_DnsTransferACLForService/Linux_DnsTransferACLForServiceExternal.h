// =======================================================================
// Linux_DnsTransferACLForServiceExternal.h
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
#ifndef Linux_DnsTransferACLForServiceExternal_h
#define Linux_DnsTransferACLForServiceExternal_h


#include "Linux_DnsTransferACLForServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsServiceInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsTransferACLForServiceExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsTransferACLForServiceExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsTransferACLForServiceExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsTransferACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsTransferACLForServiceInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsTransferACLForServiceInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsTransferACLForServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsTransferACLForServiceInstance& anInstance);
     
    virtual Linux_DnsTransferACLForServiceInstanceName createInstance(
      const Linux_DnsTransferACLForServiceInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsTransferACLForServiceInstanceName& anInstanceName);


    //association calls

    void referencesSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsTransferACLForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsTransferACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsTransferACLForServiceInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsTransferACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
