// =======================================================================
// Linux_DnsZoneExternal.h
//     created on Tue, 7 Mar 2006 using ECUTE
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
//                Rodrigo Ceron    <rceron@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsZoneExternal_h
#define Linux_DnsZoneExternal_h


#include "Linux_DnsZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsZoneInstance& anInstance);
     
    virtual Linux_DnsZoneInstanceName createInstance(
      const Linux_DnsZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsZoneInstanceName& anInstanceName);

 
  
  };

}

#endif
