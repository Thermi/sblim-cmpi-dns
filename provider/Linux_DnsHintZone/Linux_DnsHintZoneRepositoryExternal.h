 /**
 * Linux_DnsHintZoneRepositoryExternal.h
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
#ifndef Linux_DnsHintZoneRepositoryExternal_h
#define Linux_DnsHintZoneRepositoryExternal_h

#include "Linux_DnsHintZoneInstanceName.h"
#include "Linux_DnsHintZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsHintZoneRepositoryExternal {
  	
    public:
    Linux_DnsHintZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsHintZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsHintZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsHintZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsHintZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsHintZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsHintZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsHintZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsHintZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
