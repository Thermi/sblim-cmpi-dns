// =======================================================================
// Linux_DnsForwardZoneExternal.h
//     created on Wed, 29 Nov 2006 using ECUTE 2.2
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
#ifndef Linux_DnsForwardZoneExternal_h
#define Linux_DnsForwardZoneExternal_h


#include "Linux_DnsForwardZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsForwardZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsForwardZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsForwardZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsForwardZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsForwardZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsForwardZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardZoneInstance& anInstance);
     
    virtual Linux_DnsForwardZoneInstanceName createInstance(
      const Linux_DnsForwardZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsForwardZoneInstanceName& anInstanceName);

 
  
  };

}

#endif
