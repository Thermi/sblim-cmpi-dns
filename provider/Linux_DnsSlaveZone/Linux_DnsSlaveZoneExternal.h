 /**
 * Linux_DnsSlaveZoneExternal.h
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
#ifndef Linux_DnsSlaveZoneExternal_h
#define Linux_DnsSlaveZoneExternal_h

#include "Linux_DnsSlaveZoneInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSlaveZoneExternal {
  	
    public:
    Linux_DnsSlaveZoneExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsSlaveZoneExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsSlaveZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsSlaveZoneInstanceEnumeration&);
     
    virtual Linux_DnsSlaveZoneInstance getInstance(
     const char* *properties,
     const Linux_DnsSlaveZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsSlaveZoneInstance&);
     
    virtual void createInstance(
     const Linux_DnsSlaveZoneInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsSlaveZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
