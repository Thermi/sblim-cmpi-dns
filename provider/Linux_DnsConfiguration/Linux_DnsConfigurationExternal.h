// =======================================================================
// Linux_DnsConfigurationExternal.h
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
#ifndef Linux_DnsConfigurationExternal_h
#define Linux_DnsConfigurationExternal_h


#include "Linux_DnsConfigurationInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsConfigurationExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsConfigurationExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsConfigurationExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsConfigurationInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsConfigurationInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsConfigurationInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsConfigurationInstance& anInstance);
     
    virtual Linux_DnsConfigurationInstanceName createInstance(
      const Linux_DnsConfigurationInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsConfigurationInstanceName& anInstanceName);

 
  
  };

}

#endif
