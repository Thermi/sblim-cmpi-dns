 /**
 * Linux_DnsAddressMatchListExternal.h
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
#ifndef Linux_DnsAddressMatchListExternal_h
#define Linux_DnsAddressMatchListExternal_h

#include "Linux_DnsAddressMatchListInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAddressMatchListExternal {
  	
    public:
    Linux_DnsAddressMatchListExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsAddressMatchListExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsAddressMatchListInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsAddressMatchListInstanceEnumeration&);
     
    virtual Linux_DnsAddressMatchListInstance getInstance(
     const char* *properties,
     const Linux_DnsAddressMatchListInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAddressMatchListInstance&);
     
    virtual void createInstance(
     const Linux_DnsAddressMatchListInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAddressMatchListInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
