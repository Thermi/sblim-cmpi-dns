// =======================================================================
// Linux_DnsAddressMatchListRepositoryExternal.h
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
#ifndef Linux_DnsAddressMatchListRepositoryExternal_h
#define Linux_DnsAddressMatchListRepositoryExternal_h

#include "Linux_DnsAddressMatchListInstanceName.h"
#include "Linux_DnsAddressMatchListRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAddressMatchListRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsAddressMatchListRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAddressMatchListRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsAddressMatchListRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsAddressMatchListRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsAddressMatchListInstanceName createInstance(
      const Linux_DnsAddressMatchListRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAddressMatchListInstanceName& anInstanceName);
  
  };

}
#endif
