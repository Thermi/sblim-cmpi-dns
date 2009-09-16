// =======================================================================
// Linux_DnsSlaveZoneExternal.h
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
#ifndef Linux_DnsSlaveZoneExternal_h
#define Linux_DnsSlaveZoneExternal_h


#include "Linux_DnsSlaveZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSlaveZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsSlaveZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsSlaveZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsSlaveZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsSlaveZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsSlaveZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsSlaveZoneInstance& anInstance);
     
    virtual Linux_DnsSlaveZoneInstanceName createInstance(
      const Linux_DnsSlaveZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsSlaveZoneInstanceName& anInstanceName);

 
  
  };

}

#endif
