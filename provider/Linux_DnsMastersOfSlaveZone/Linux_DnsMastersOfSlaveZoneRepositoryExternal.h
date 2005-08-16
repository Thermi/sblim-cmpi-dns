 /**
 * Linux_DnsMastersOfSlaveZoneRepositoryExternal.h
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
#ifndef Linux_DnsMastersOfSlaveZoneRepositoryExternal_h
#define Linux_DnsMastersOfSlaveZoneRepositoryExternal_h

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"
#include "Linux_DnsMastersOfSlaveZoneRepositoryInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneRepositoryExternal {
  	
    public:
    Linux_DnsMastersOfSlaveZoneRepositoryExternal(
     const CmpiBroker& brkr,
     const CmpiContext& ctx);
    virtual ~Linux_DnsMastersOfSlaveZoneRepositoryExternal();
    
    virtual void enumInstanceNames(
     Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char* *properties,
     Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration&);
     
    virtual Linux_DnsMastersOfSlaveZoneRepositoryInstance getInstance(
     const char* *properties,
     const Linux_DnsMastersOfSlaveZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsMastersOfSlaveZoneRepositoryInstance&);
     
    virtual void createInstance(
     const Linux_DnsMastersOfSlaveZoneRepositoryInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsMastersOfSlaveZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
    const static char *nsp;
  };
}
#endif
