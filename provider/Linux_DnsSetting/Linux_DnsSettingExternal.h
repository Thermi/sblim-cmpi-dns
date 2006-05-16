// =======================================================================
// Linux_DnsSettingExternal.h
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
#ifndef Linux_DnsSettingExternal_h
#define Linux_DnsSettingExternal_h


#include "Linux_DnsSettingInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSettingExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsSettingExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsSettingExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsSettingInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsSettingInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsSettingInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsSettingInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsSettingInstance& anInstance);
     
    virtual Linux_DnsSettingInstanceName createInstance(
      const Linux_DnsSettingInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsSettingInstanceName& anInstanceName);

 
  
  };

}

#endif
