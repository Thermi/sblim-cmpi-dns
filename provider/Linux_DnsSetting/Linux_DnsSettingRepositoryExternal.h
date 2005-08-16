 /**
 * Linux_DnsSettingRepositoryExternal.h
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
#ifndef Linux_DnsSettingRepositoryExternal_h
#define Linux_DnsSettingRepositoryExternal_h

#include "Linux_DnsSettingInstanceName.h"
#include "Linux_DnsSettingRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSettingRepositoryExternal {
  	
    public:
    Linux_DnsSettingRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsSettingRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsSettingInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsSettingRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsSettingRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsSettingInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsSettingRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsSettingRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsSettingInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
