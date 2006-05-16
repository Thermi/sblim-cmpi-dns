// =======================================================================
// Linux_DnsAddressMatchListExternal.h
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
#ifndef Linux_DnsAddressMatchListExternal_h
#define Linux_DnsAddressMatchListExternal_h


#include "Linux_DnsAddressMatchListInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAddressMatchListExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsAddressMatchListExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsAddressMatchListExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsAddressMatchListInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstance& anInstance);
     
    virtual Linux_DnsAddressMatchListInstanceName createInstance(
      const Linux_DnsAddressMatchListInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsAddressMatchListInstanceName& anInstanceName);

 
  
  };

}

#endif
