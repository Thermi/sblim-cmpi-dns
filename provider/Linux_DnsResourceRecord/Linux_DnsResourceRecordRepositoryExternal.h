 /**
 * Linux_DnsResourceRecordRepositoryExternal.h
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
#ifndef Linux_DnsResourceRecordRepositoryExternal_h
#define Linux_DnsResourceRecordRepositoryExternal_h

#include "Linux_DnsResourceRecordInstanceName.h"
#include "Linux_DnsResourceRecordRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsResourceRecordRepositoryExternal {
  	
    public:
    Linux_DnsResourceRecordRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsResourceRecordRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsResourceRecordInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsResourceRecordRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsResourceRecordRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsResourceRecordInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsResourceRecordRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsResourceRecordRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsResourceRecordInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
