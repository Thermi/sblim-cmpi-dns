// =======================================================================
// Linux_DnsStubZoneExternal.h
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
#ifndef Linux_DnsStubZoneExternal_h
#define Linux_DnsStubZoneExternal_h


#include "Linux_DnsStubZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsStubZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsStubZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsStubZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsStubZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsStubZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsStubZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsStubZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsStubZoneInstance& anInstance);
     
    virtual Linux_DnsStubZoneInstanceName createInstance(
      const Linux_DnsStubZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsStubZoneInstanceName& anInstanceName);

 
  
  };

}

#endif
