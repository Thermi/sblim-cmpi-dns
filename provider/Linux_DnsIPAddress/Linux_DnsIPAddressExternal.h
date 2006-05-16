// =======================================================================
// Linux_DnsIPAddressExternal.h
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
#ifndef Linux_DnsIPAddressExternal_h
#define Linux_DnsIPAddressExternal_h


#include "Linux_DnsIPAddressInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsIPAddressExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    Linux_DnsIPAddressExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~Linux_DnsIPAddressExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      Linux_DnsIPAddressInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      Linux_DnsIPAddressInstanceEnumeration& anInstanceEnumeration);
     
    virtual Linux_DnsIPAddressInstance getInstance(
      const char** aPropertiesPP,
      const Linux_DnsIPAddressInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const Linux_DnsIPAddressInstance& anInstance);
     
    virtual Linux_DnsIPAddressInstanceName createInstance(
      const Linux_DnsIPAddressInstance& anInstance);
     
    virtual void deleteInstance(
      const Linux_DnsIPAddressInstanceName& anInstanceName);

 
  
  };

}

#endif
