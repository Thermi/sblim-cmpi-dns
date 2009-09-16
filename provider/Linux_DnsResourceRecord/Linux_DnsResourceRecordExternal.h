// =======================================================================
// Linux_DnsResourceRecordExternal.h
//     created on Fri, 1 Dec 2006 using ECUTE 2.2
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
#ifndef Linux_DnsResourceRecordExternal_h
#define Linux_DnsResourceRecordExternal_h


#include "Linux_DnsResourceRecordInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsResourceRecordExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsResourceRecordExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsResourceRecordExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsResourceRecordInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsResourceRecordInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsResourceRecordInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInstance& anInstance);
     
    virtual Linux_DnsResourceRecordInstanceName createInstance(
      const Linux_DnsResourceRecordInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsResourceRecordInstanceName& anInstanceName);

 
  
  };

}

#endif
