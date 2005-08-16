 /**
 * Linux_DnsManagedSystemElementForSettingRepositoryExternal.h
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
#ifndef Linux_DnsManagedSystemElementForSettingRepositoryExternal_h
#define Linux_DnsManagedSystemElementForSettingRepositoryExternal_h

#include "Linux_DnsManagedSystemElementForSettingInstanceName.h"
#include "Linux_DnsManagedSystemElementForSettingRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingRepositoryExternal {
  	
    public:
    Linux_DnsManagedSystemElementForSettingRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsManagedSystemElementForSettingRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsManagedSystemElementForSettingRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsManagedSystemElementForSettingInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsManagedSystemElementForSettingRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsManagedSystemElementForSettingRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsManagedSystemElementForSettingInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
