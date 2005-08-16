 /**
 * Linux_DnsConfigurationRepositoryExternal.h
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
#ifndef Linux_DnsConfigurationRepositoryExternal_h
#define Linux_DnsConfigurationRepositoryExternal_h

#include "Linux_DnsConfigurationInstanceName.h"
#include "Linux_DnsConfigurationRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsConfigurationRepositoryExternal {
  	
    public:
    Linux_DnsConfigurationRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsConfigurationRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsConfigurationInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsConfigurationRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsConfigurationRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsConfigurationInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsConfigurationRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsConfigurationRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsConfigurationInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
