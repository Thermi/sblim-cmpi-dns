// =======================================================================
// Linux_DnsServiceExternal.h
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
#ifndef Linux_DnsServiceExternal_h
#define Linux_DnsServiceExternal_h


#include "Linux_DnsServiceInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsServiceExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsServiceExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsServiceExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsServiceInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsServiceInstance& anInstance);
     
    virtual Linux_DnsServiceInstanceName createInstance(
      const Linux_DnsServiceInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsServiceInstanceName& anInstanceName);

 
  
  };

}

#endif
