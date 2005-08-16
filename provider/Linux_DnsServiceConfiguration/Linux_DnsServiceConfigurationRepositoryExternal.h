 /**
 * Linux_DnsServiceConfigurationRepositoryExternal.h
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
#ifndef Linux_DnsServiceConfigurationRepositoryExternal_h
#define Linux_DnsServiceConfigurationRepositoryExternal_h

#include "Linux_DnsServiceConfigurationInstanceName.h"
#include "Linux_DnsServiceConfigurationRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceConfigurationRepositoryExternal {
  	
    public:
    Linux_DnsServiceConfigurationRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsServiceConfigurationRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsServiceConfigurationInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsServiceConfigurationRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsServiceConfigurationRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsServiceConfigurationInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsServiceConfigurationRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsServiceConfigurationRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsServiceConfigurationInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
