// =======================================================================
// Linux_DnsHintZoneExternal.h
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
#ifndef Linux_DnsHintZoneExternal_h
#define Linux_DnsHintZoneExternal_h


#include "Linux_DnsHintZoneInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsHintZoneExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsHintZoneExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsHintZoneExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsHintZoneInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsHintZoneInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsHintZoneInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsHintZoneInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsHintZoneInstance& anInstance);
     
    virtual Linux_DnsHintZoneInstanceName createInstance(
      const Linux_DnsHintZoneInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsHintZoneInstanceName& anInstanceName);

 
  
  };

}

#endif
