 /**
 * Linux_DnsServiceDefaultImplementation.cpp
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
#include "Linux_DnsServiceDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsServiceDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsServiceInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsService"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsService");   
  }
  	
  void Linux_DnsServiceDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsServiceManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsService"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsServiceInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsServiceInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsServiceManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsServiceManualInstance 
   Linux_DnsServiceDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsServiceInstanceName&){
    cout<<"getInstance not supported for Linux_DnsService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsService");
  }
  	
  void Linux_DnsServiceDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsServiceManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsService"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsService");
  }
  	
  void Linux_DnsServiceDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsServiceManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsService");
  }
  	
  void Linux_DnsServiceDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsServiceInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsService");
  }
	
  
  /* extrinsic methods */

    CMPIUint32 Linux_DnsServiceDefaultImplementation::RequestStateChange(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName&,
      const CMPIUint16 &RequestedState,
      int isRequestedStatePresent,
      CIM_ConcreteJobInstanceName &Job,
      const CmpiDateTime &TimeoutPeriod,
      int isTimeoutPeriodPresent){
      cout<<"RequestStateChange() not supported in Linux_DnsService"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "RequestStateChange() not implemented in Linux_DnsService");
    };

    CMPIUint32 Linux_DnsServiceDefaultImplementation::StartService(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName&){
      cout<<"StartService() not supported in Linux_DnsService"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "StartService() not implemented in Linux_DnsService");
    };

    CMPIUint32 Linux_DnsServiceDefaultImplementation::StopService(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName&){
      cout<<"StopService() not supported in Linux_DnsService"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "StopService() not implemented in Linux_DnsService");
    };
	
}

