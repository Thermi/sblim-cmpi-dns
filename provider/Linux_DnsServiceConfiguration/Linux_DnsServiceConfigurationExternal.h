// =======================================================================
// Linux_DnsServiceConfigurationExternal.h
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
#ifndef Linux_DnsServiceConfigurationExternal_h
#define Linux_DnsServiceConfigurationExternal_h


#include "Linux_DnsServiceConfigurationInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceConfigurationExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsServiceConfigurationExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsServiceConfigurationExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsServiceConfigurationInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstance& anInstance);
     
    virtual Linux_DnsServiceConfigurationInstanceName createInstance(
      const Linux_DnsServiceConfigurationInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsServiceConfigurationInstanceName& anInstanceName);

 
  
  };

}

#endif
