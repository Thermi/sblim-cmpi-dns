 /**
 * Linux_DnsSettingContextRepositoryExternal.h
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
#ifndef Linux_DnsSettingContextRepositoryExternal_h
#define Linux_DnsSettingContextRepositoryExternal_h

#include "Linux_DnsSettingContextInstanceName.h"
#include "Linux_DnsSettingContextRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSettingContextRepositoryExternal {
  	
    public:
    Linux_DnsSettingContextRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsSettingContextRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsSettingContextInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsSettingContextRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsSettingContextRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsSettingContextInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsSettingContextRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsSettingContextRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsSettingContextInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
