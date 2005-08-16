 /**
 * Linux_DnsResourceRecordInZoneRepositoryExternal.h
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#ifndef Linux_DnsResourceRecordInZoneRepositoryExternal_h
#define Linux_DnsResourceRecordInZoneRepositoryExternal_h

#include "Linux_DnsResourceRecordInZoneInstanceName.h"
#include "Linux_DnsResourceRecordInZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsResourceRecordInZoneRepositoryExternal {
  	
    public:
    Linux_DnsResourceRecordInZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsResourceRecordInZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsResourceRecordInZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsResourceRecordInZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsResourceRecordInZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsResourceRecordInZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsResourceRecordInZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsResourceRecordInZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
