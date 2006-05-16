// =======================================================================
// Linux_DnsConfigurationResourceAccess.cpp
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
#include "Linux_DnsConfigurationResourceAccess.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_defaultvalues.h"
#include "smt_dns_ra_support.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsConfigurationResourceAccess::Linux_DnsConfigurationResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsConfigurationResourceAccess::~Linux_DnsConfigurationResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsConfigurationResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsConfigurationInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsConfiguration::enumInstanceNames" << endl;
#endif
    Linux_DnsConfigurationInstanceName instanceName;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    
    anInstanceNameEnumeration.addElement(instanceName);

#ifdef DEBUG
    cout << "exiting Linux_DnsConfiguration::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsConfigurationResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsConfiguration::enumInstances" << endl;
#endif

    Linux_DnsConfigurationInstanceName instanceName;
    Linux_DnsConfigurationManualInstance aManualInstance;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    
    aManualInstance.setInstanceName(instanceName);
    aManualInstance.setConfigurationFile(get_bindconf());
    
    aManualInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsConfiguration::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsConfigurationManualInstance 
  Linux_DnsConfigurationResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsConfigurationInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsConfiguration::getInstance" << endl;
#endif

    Linux_DnsConfigurationManualInstance aManualInstance;
    
    aManualInstance.setInstanceName(anInstanceName);
    aManualInstance.setConfigurationFile(get_bindconf());
    
#ifdef DEBUG
    cout << "exiting Linux_DnsConfiguration::getInstance" << endl;
#endif
    return aManualInstance;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsConfigurationResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsConfigurationManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsConfigurationInstanceName
  Linux_DnsConfigurationResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsConfigurationManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsConfigurationResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsConfigurationInstanceName& anInstanceName) { }
	*/
	

  
  // extrinsic methods

	
}


