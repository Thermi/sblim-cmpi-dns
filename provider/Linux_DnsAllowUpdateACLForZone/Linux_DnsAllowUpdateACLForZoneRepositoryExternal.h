// =======================================================================
// Linux_DnsAllowUpdateACLForZoneRepositoryExternal.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneRepositoryExternal_h
#define Linux_DnsAllowUpdateACLForZoneRepositoryExternal_h

#include "Linux_DnsAllowUpdateACLForZoneInstanceName.h"
#include "Linux_DnsAllowUpdateACLForZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAllowUpdateACLForZoneRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsAllowUpdateACLForZoneRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAllowUpdateACLForZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsAllowUpdateACLForZoneRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowUpdateACLForZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsAllowUpdateACLForZoneInstanceName createInstance(
      const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAllowUpdateACLForZoneInstanceName& anInstanceName);
  
  };

}
#endif
