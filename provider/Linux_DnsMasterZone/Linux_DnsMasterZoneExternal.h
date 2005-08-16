 /**
 * Linux_DnsMasterZoneExternal.h
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
#ifndef Linux_DnsMasterZoneExternal_h
#define Linux_DnsMasterZoneExternal_h

#include "Linux_DnsMasterZoneInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMasterZoneExternal {
  	
    public:
    Linux_DnsMasterZoneExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsMasterZoneExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsMasterZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsMasterZoneInstanceEnumeration&);
     
    virtual Linux_DnsMasterZoneInstance getInstance(
     const char* *properties,
     const Linux_DnsMasterZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsMasterZoneInstance&);
     
    virtual void createInstance(
     const Linux_DnsMasterZoneInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsMasterZoneInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
