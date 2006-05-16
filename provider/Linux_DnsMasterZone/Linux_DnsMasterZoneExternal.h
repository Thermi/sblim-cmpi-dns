// =======================================================================
// Linux_DnsMasterZoneExternal.h
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsMasterZoneExternal_h
#define Linux_DnsMasterZoneExternal_h


#include "Linux_DnsMasterZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMasterZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsMasterZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsMasterZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsMasterZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsMasterZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsMasterZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsMasterZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsMasterZoneInstance& anInstance);
     
    virtual Linux_DnsMasterZoneInstanceName createInstance(
      const Linux_DnsMasterZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsMasterZoneInstanceName& anInstanceName);

 
  
  };

}

#endif
