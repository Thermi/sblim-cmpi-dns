// =======================================================================
// Linux_DnsForwardZoneRepositoryExternal.h
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
#ifndef Linux_DnsForwardZoneRepositoryExternal_h
#define Linux_DnsForwardZoneRepositoryExternal_h

#include "Linux_DnsForwardZoneInstanceName.h"
#include "Linux_DnsForwardZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsForwardZoneRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsForwardZoneRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsForwardZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsForwardZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsForwardZoneRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsForwardZoneRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsForwardZoneRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsForwardZoneInstanceName createInstance(
      const Linux_DnsForwardZoneRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsForwardZoneInstanceName& anInstanceName);
  
  };

}
#endif
