 /**
 * Linux_DnsSettingExternal.h
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
#ifndef Linux_DnsSettingExternal_h
#define Linux_DnsSettingExternal_h

#include "Linux_DnsSettingInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSettingExternal {
  	
    public:
    Linux_DnsSettingExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsSettingExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsSettingInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsSettingInstanceEnumeration&);
     
    virtual Linux_DnsSettingInstance getInstance(
     const char* *properties,
     const Linux_DnsSettingInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsSettingInstance&);
     
    virtual void createInstance(
     const Linux_DnsSettingInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsSettingInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
