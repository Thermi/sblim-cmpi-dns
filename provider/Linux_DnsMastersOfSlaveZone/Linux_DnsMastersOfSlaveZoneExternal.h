// =======================================================================
// Linux_DnsMastersOfSlaveZoneExternal.h
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
#ifndef Linux_DnsMastersOfSlaveZoneExternal_h
#define Linux_DnsMastersOfSlaveZoneExternal_h


#include "Linux_DnsMastersOfSlaveZoneInstance.h"
#include "Linux_DnsIPAddressInstance.h"
#include "Linux_DnsSlaveZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsMastersOfSlaveZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsMastersOfSlaveZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsMastersOfSlaveZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsMastersOfSlaveZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsMastersOfSlaveZoneInstance& anInstance);
     
    virtual Linux_DnsMastersOfSlaveZoneInstanceName createInstance(
      const Linux_DnsMastersOfSlaveZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);


    //association calls

    void referencesSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
      Linux_DnsMastersOfSlaveZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
      Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void referencesElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
      Linux_DnsMastersOfSlaveZoneInstanceEnumeration& anInstanceEnumeration);

    void referenceNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
      Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsSetting( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
      Linux_DnsIPAddressInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesSetting( 
      const char *aNameSpaceP,
      const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
      Linux_DnsIPAddressInstanceNameEnumeration& anInstanceNameEnumeration);

    void associatorsElement( 
      const char *aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
      Linux_DnsSlaveZoneInstanceEnumeration& anInstanceEnumeration);

    void associatorNamesElement( 
      const char *aNameSpaceP,
      const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
      Linux_DnsSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration); 
  
  };

}

#endif
