 /**
 * Linux_DnsServiceExternal.h
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
#ifndef Linux_DnsServiceExternal_h
#define Linux_DnsServiceExternal_h

#include "Linux_DnsServiceInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceExternal {
  	
    public:
    Linux_DnsServiceExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsServiceExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsServiceInstanceEnumeration&);
     
    virtual Linux_DnsServiceInstance getInstance(
     const char* *properties,
     const Linux_DnsServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsServiceInstance&);
     
    virtual void createInstance(
     const Linux_DnsServiceInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsServiceInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
