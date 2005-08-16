 /**
 * Linux_DnsIPAddressExternal.h
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
#ifndef Linux_DnsIPAddressExternal_h
#define Linux_DnsIPAddressExternal_h

#include "Linux_DnsIPAddressInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsIPAddressExternal {
  	
    public:
    Linux_DnsIPAddressExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsIPAddressExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsIPAddressInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsIPAddressInstanceEnumeration&);
     
    virtual Linux_DnsIPAddressInstance getInstance(
     const char* *properties,
     const Linux_DnsIPAddressInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsIPAddressInstance&);
     
    virtual void createInstance(
     const Linux_DnsIPAddressInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsIPAddressInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
