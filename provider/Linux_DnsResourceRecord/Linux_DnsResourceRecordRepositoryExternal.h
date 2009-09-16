// =======================================================================
// Linux_DnsResourceRecordRepositoryExternal.h
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
#ifndef Linux_DnsResourceRecordRepositoryExternal_h
#define Linux_DnsResourceRecordRepositoryExternal_h

#include "Linux_DnsResourceRecordInstanceName.h"
#include "Linux_DnsResourceRecordRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsResourceRecordRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsResourceRecordRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsResourceRecordRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsResourceRecordInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsResourceRecordRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsResourceRecordRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsResourceRecordInstanceName createInstance(
      const Linux_DnsResourceRecordRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsResourceRecordInstanceName& anInstanceName);
  
  };

}
#endif
