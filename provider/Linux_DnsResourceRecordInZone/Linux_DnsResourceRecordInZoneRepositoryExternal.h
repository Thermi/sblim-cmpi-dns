// =======================================================================
// Linux_DnsResourceRecordInZoneRepositoryExternal.h
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
#ifndef Linux_DnsResourceRecordInZoneRepositoryExternal_h
#define Linux_DnsResourceRecordInZoneRepositoryExternal_h

#include "Linux_DnsResourceRecordInZoneInstanceName.h"
#include "Linux_DnsResourceRecordInZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsResourceRecordInZoneRepositoryExternal {
     
    private:
    CmpiBroker  m_broker;
    CmpiContext m_context;
    const static char *s_shadowNameSpaceP;
  	
    public:
    Linux_DnsResourceRecordInZoneRepositoryExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsResourceRecordInZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
      Linux_DnsResourceRecordInZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char** aPropertiesPP,
      Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration& aRepositoryInstanceEnumeration);
     
    virtual Linux_DnsResourceRecordInZoneRepositoryInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInZoneRepositoryInstance& aRepositoryInstance);
     
    virtual Linux_DnsResourceRecordInZoneInstanceName createInstance(
      const Linux_DnsResourceRecordInZoneRepositoryInstance& aRepositoryInstance);
     
    virtual void deleteInstance(
      const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);
  
  };

}
#endif
