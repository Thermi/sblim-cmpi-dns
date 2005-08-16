 /**
 * Linux_DnsMasterZoneRepositoryExternal.h
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
#ifndef Linux_DnsMasterZoneRepositoryExternal_h
#define Linux_DnsMasterZoneRepositoryExternal_h

#include "Linux_DnsMasterZoneInstanceName.h"
#include "Linux_DnsMasterZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMasterZoneRepositoryExternal {
  	
    public:
    Linux_DnsMasterZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsMasterZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsMasterZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsMasterZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsMasterZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsMasterZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsMasterZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsMasterZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsMasterZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
