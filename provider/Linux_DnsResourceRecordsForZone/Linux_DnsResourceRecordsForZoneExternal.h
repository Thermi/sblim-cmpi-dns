// =======================================================================
// Linux_DnsResourceRecordsForZoneExternal.h
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
#ifndef Linux_DnsResourceRecordsForZoneExternal_h
#define Linux_DnsResourceRecordsForZoneExternal_h


#include "Linux_DnsResourceRecordsForZoneInstance.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsResourceRecordInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsResourceRecordsForZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsResourceRecordsForZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsResourceRecordsForZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsResourceRecordsForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsResourceRecordsForZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsResourceRecordsForZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordsForZoneInstance& anInstance);
     
    virtual Linux_DnsResourceRecordsForZoneInstanceName createInstance(
      const Linux_DnsResourceRecordsForZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);


    //association calls

    void referencesGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordsForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordsForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordsForZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordsForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsGroupComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesGroupComponent( 
      const char *aNameSpaceP,
      const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsPartComponent( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesPartComponent( 
      const char *aNameSpaceP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
