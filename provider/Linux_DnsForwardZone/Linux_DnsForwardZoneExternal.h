 /**
 * Linux_DnsForwardZoneExternal.h
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
#ifndef Linux_DnsForwardZoneExternal_h
#define Linux_DnsForwardZoneExternal_h

#include "Linux_DnsForwardZoneInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsForwardZoneExternal {
  	
    public:
    Linux_DnsForwardZoneExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsForwardZoneExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsForwardZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsForwardZoneInstanceEnumeration&);
     
    virtual Linux_DnsForwardZoneInstance getInstance(
     const char* *properties,
     const Linux_DnsForwardZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsForwardZoneInstance&);
     
    virtual void createInstance(
     const Linux_DnsForwardZoneInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsForwardZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
