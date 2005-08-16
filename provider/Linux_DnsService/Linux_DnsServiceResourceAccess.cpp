 /**
 * Linux_DnsServiceResourceAccess.cpp
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
#include <iostream>
#include <string>

using namespace std;

#include "Linux_DnsServiceResourceAccess.h"

namespace genProvider {
  
    //Linux_DnsServiceResourceAccess::Linux_DnsServiceResourceAccess();
    Linux_DnsServiceResourceAccess::~Linux_DnsServiceResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsServiceResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsServiceInstanceNameEnumeration& instnames){
      
       Linux_DnsServiceInstanceName instanceName;

       	instanceName.setNamespace(nsp);
       	instanceName.setName(DEFAULT_SERVICE_NAME);
        instanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
        instanceName.setSystemName(DEFAULT_SYSTEM_NAME);
        instanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
       	
	instnames.addElement(instanceName);
    }
    
  	
    void Linux_DnsServiceResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	Linux_DnsServiceManualInstanceEnumeration& instances){
	
	Linux_DnsServiceManualInstance inst;
	Linux_DnsServiceInstanceName instanceName;
	
       	instanceName.setNamespace(nsp);
       	instanceName.setName(DEFAULT_SERVICE_NAME);
        instanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
        instanceName.setSystemName(DEFAULT_SYSTEM_NAME);
        instanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
	inst.setInstanceName(instanceName);

	inst.setStarted( status_service() );
	inst.setRunAsRoot( false );
	
	instances.addElement(inst); 
    };
  	
  	
    Linux_DnsServiceManualInstance 
     Linux_DnsServiceResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsServiceInstanceName& instanceName){
       
	Linux_DnsServiceManualInstance inst;
        inst.setInstanceName(instanceName);
	inst.setStarted( status_service() );
	inst.setRunAsRoot( false );
	
	return inst;
    }
  	
  	/*
    void Linux_DnsServiceResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsServiceManualInstance&){};
  	*/
  	/*
    void Linux_DnsServiceResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceManualInstance&){};
  	*/
  	/*
    void Linux_DnsServiceResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName&){};
	*/
    
    /* extrinsic methods */
    /*
    virtual CMPIUint32 Linux_DnsServiceResourceAccess::RequestStateChange(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName&,
      const CMPIUint16 &RequestedState,
      int isRequestedStatePresent,
      CIM_ConcreteJobInstanceName &Job,
      const CmpiDateTime &TimeoutPeriod,
      int isTimeoutPeriodPresent) { };
    */
   
    /*
	CMPIUint32 Linux_DnsServiceResourceAccess::StartService()
	return: 0 if sucess
		!0 if failure
    */ 
    CMPIUint32 Linux_DnsServiceResourceAccess::StartService(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName& anInstanceName) {
    
     	cout << "Linux_DnsServiceResourceAccess::StartService" << endl; 
   	return ( start_service() );
     };
    
    
    /*
	CMPIUint32 Linux_DnsServiceResourceAccess::StopService()
	return: 0 if sucess
		!0 if failure
    */ 
    CMPIUint32 Linux_DnsServiceResourceAccess::StopService(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName& anInstanceName) {

	cout << "Linux_DnsServiceResourceAccess::StopService" << endl; 
        return ( stop_service() );   
     };
    
	
}


