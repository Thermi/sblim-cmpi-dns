// =======================================================================
// Linux_DnsAllowTransferACLForZoneRepositoryExternal.h
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
#ifndef Linux_DnsAllowTransferACLForZoneRepositoryExternal_h
#define Linux_DnsAllowTransferACLForZoneRepositoryExternal_h

#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"
#include "Linux_DnsAllowTransferACLForZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsAllowTransferACLForZoneRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAllowTransferACLForZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsAllowTransferACLForZoneRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowTransferACLForZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowTransferACLForZoneRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsAllowTransferACLForZoneInstanceName createInstance(
      const Linux_DnsAllowTransferACLForZoneRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAllowTransferACLForZoneInstanceName& anInstanceName);
  
  };

}
#endif
