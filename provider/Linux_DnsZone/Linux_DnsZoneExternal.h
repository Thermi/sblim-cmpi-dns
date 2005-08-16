 /**
 * Linux_DnsZoneExternal.h
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
#ifndef Linux_DnsZoneExternal_h
#define Linux_DnsZoneExternal_h

#include "Linux_DnsZoneInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsZoneExternal {
  	
    public:
    Linux_DnsZoneExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsZoneExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsZoneInstanceEnumeration&);
     
    virtual Linux_DnsZoneInstance getInstance(
     const char* *properties,
     const Linux_DnsZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsZoneInstance&);
     
    virtual void createInstance(
     const Linux_DnsZoneInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
