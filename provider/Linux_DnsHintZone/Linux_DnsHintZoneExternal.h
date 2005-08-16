 /**
 * Linux_DnsHintZoneExternal.h
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
#ifndef Linux_DnsHintZoneExternal_h
#define Linux_DnsHintZoneExternal_h

#include "Linux_DnsHintZoneInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsHintZoneExternal {
  	
    public:
    Linux_DnsHintZoneExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsHintZoneExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsHintZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsHintZoneInstanceEnumeration&);
     
    virtual Linux_DnsHintZoneInstance getInstance(
     const char* *properties,
     const Linux_DnsHintZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsHintZoneInstance&);
     
    virtual void createInstance(
     const Linux_DnsHintZoneInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsHintZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
