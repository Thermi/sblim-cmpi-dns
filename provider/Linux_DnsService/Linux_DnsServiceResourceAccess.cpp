// =======================================================================
// Linux_DnsServiceResourceAccess.cpp
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
#include "Linux_DnsServiceResourceAccess.h"

#include <iostream>
#include <string>

using namespace std;

#include "smt_dns_ra_support.h" 
#include "smt_dns_defaultvalues.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceResourceAccess::Linux_DnsServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsServiceResourceAccess::~Linux_DnsServiceResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
      cout << "entering Linux_DnsService::enumInstanceNames" << endl;
#endif

    Linux_DnsServiceInstanceName instanceName;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    instanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
    instanceName.setSystemName(DEFAULT_SYSTEM_NAME);
    instanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
    
    anInstanceNameEnumeration.addElement(instanceName);

#ifdef DEBUG
      cout << "exiting Linux_DnsService::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsService::enumInstances" << endl;
#endif

    Linux_DnsServiceManualInstance inst;
    Linux_DnsServiceInstanceName instanceName;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    instanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
    instanceName.setSystemName(DEFAULT_SYSTEM_NAME);
    instanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
    inst.setInstanceName(instanceName);
    
    inst.setStarted( status_service() );
    inst.setRunAsRoot( false );
    
    aManualInstanceEnumeration.addElement(inst); 

#ifdef DEBUG
      cout << "exiting Linux_DnsService::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsServiceManualInstance 
  Linux_DnsServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& anInstanceName) {

#ifdef DEBUG
      cout << "entering Linux_DnsService::getInstance" << endl;
#endif

    Linux_DnsServiceManualInstance inst;
    inst.setInstanceName(anInstanceName);
    inst.setStarted( status_service() );
    inst.setRunAsRoot( false );
    
#ifdef DEBUG
      cout << "exiting Linux_DnsService::getInstance" << endl;
#endif
    return inst;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsServiceInstanceName
  Linux_DnsServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceInstanceName& anInstanceName) { }
	*/
	

  
  // extrinsic methods

  /*
  CMPIUint32 Linux_DnsServiceResourceAccess::RequestStateChange(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceInstanceName& anInstanceName,
      const CMPIUint16& RequestedState,
      int isRequestedStatePresent,
      CIM_ConcreteJobInstanceName& Job,
      const CmpiDateTime& TimeoutPeriod,
      int isTimeoutPeriodPresent) { }
  */


  CMPIUint32 Linux_DnsServiceResourceAccess::StartService(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsService::StartService" << endl;
#endif
    
    CMPIUint32 res_start = start_service();
    
#ifdef DEBUG
    cout << "\tReturn value of start service: "<< res_start << endl;
#endif
    
#ifdef DEBUG
    cout << "exiting Linux_DnsService::StartService" << endl;
#endif
    return ( res_start );
  }



  CMPIUint32 Linux_DnsServiceResourceAccess::StopService(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsService::StopService" << endl;
#endif
    
    CMPIUint32 res_stop = stop_service();
    
#ifdef DEBUG
    cout << "\tReturn value of stop service: "<< res_stop << endl;
#endif
    
#ifdef DEBUG
      cout << "exiting Linux_DnsService::StopService" << endl;
#endif
    return ( res_stop );
  }


	
}


