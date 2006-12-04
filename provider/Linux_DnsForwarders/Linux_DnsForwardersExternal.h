// =======================================================================
// Linux_DnsForwardersExternal.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
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
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsForwardersExternal_h
#define Linux_DnsForwardersExternal_h


#include "Linux_DnsForwardersInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsForwardersExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsForwardersExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsForwardersExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsForwardersInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsForwardersInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsForwardersInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardersInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardersInstance& anInstance);
     
    virtual Linux_DnsForwardersInstanceName createInstance(
      const Linux_DnsForwardersInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsForwardersInstanceName& anInstanceName);

 
  
  };

}

#endif