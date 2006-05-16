// =======================================================================
// Linux_DnsIPAddressRepositoryExternal.h
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
#ifndef Linux_DnsIPAddressRepositoryExternal_h
#define Linux_DnsIPAddressRepositoryExternal_h

#include "Linux_DnsIPAddressInstanceName.h"
#include "Linux_DnsIPAddressRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsIPAddressRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsIPAddressRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsIPAddressRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsIPAddressInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsIPAddressRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsIPAddressRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsIPAddressInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsIPAddressRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsIPAddressInstanceName createInstance(
      const Linux_DnsIPAddressRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsIPAddressInstanceName& anInstanceName);
  
  };

}
#endif
