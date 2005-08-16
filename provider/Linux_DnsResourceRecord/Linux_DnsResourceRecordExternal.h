 /**
 * Linux_DnsResourceRecordExternal.h
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
#ifndef Linux_DnsResourceRecordExternal_h
#define Linux_DnsResourceRecordExternal_h

#include "Linux_DnsResourceRecordInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsResourceRecordExternal {
  	
    public:
    Linux_DnsResourceRecordExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsResourceRecordExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsResourceRecordInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsResourceRecordInstanceEnumeration&);
     
    virtual Linux_DnsResourceRecordInstance getInstance(
     const char* *properties,
     const Linux_DnsResourceRecordInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsResourceRecordInstance&);
     
    virtual void createInstance(
     const Linux_DnsResourceRecordInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsResourceRecordInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
