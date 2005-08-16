 /**
 * Linux_DnsElementSettingRepositoryExternal.h
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
#ifndef Linux_DnsElementSettingRepositoryExternal_h
#define Linux_DnsElementSettingRepositoryExternal_h

#include "Linux_DnsElementSettingInstanceName.h"
#include "Linux_DnsElementSettingRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsElementSettingRepositoryExternal {
  	
    public:
    Linux_DnsElementSettingRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsElementSettingRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsElementSettingInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsElementSettingRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsElementSettingRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsElementSettingInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsElementSettingRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsElementSettingRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsElementSettingInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
