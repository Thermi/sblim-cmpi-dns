 /**
 * Linux_DnsConfigurationExternal.h
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
#ifndef Linux_DnsConfigurationExternal_h
#define Linux_DnsConfigurationExternal_h

#include "Linux_DnsConfigurationInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsConfigurationExternal {
  	
    public:
    Linux_DnsConfigurationExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsConfigurationExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsConfigurationInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsConfigurationInstanceEnumeration&);
     
    virtual Linux_DnsConfigurationInstance getInstance(
     const char* *properties,
     const Linux_DnsConfigurationInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsConfigurationInstance&);
     
    virtual void createInstance(
     const Linux_DnsConfigurationInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsConfigurationInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
