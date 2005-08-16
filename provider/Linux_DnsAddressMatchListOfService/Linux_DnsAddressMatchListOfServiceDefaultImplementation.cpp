 /**
 * Linux_DnsAddressMatchListOfServiceDefaultImplementation.cpp
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
#include "Linux_DnsAddressMatchListOfServiceDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsAddressMatchListOfServiceDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsAddressMatchListOfService"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsAddressMatchListOfService");   
  }
  	
  void Linux_DnsAddressMatchListOfServiceDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsAddressMatchListOfService"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsAddressMatchListOfServiceInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsAddressMatchListOfServiceManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsAddressMatchListOfServiceManualInstance 
   Linux_DnsAddressMatchListOfServiceDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsAddressMatchListOfServiceInstanceName&){
    cout<<"getInstance not supported for Linux_DnsAddressMatchListOfService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsAddressMatchListOfService");
  }
  	
  void Linux_DnsAddressMatchListOfServiceDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsAddressMatchListOfServiceManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsAddressMatchListOfService"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsAddressMatchListOfService");
  }
  	
  void Linux_DnsAddressMatchListOfServiceDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsAddressMatchListOfServiceManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsAddressMatchListOfService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsAddressMatchListOfService");
  }
  	
  void Linux_DnsAddressMatchListOfServiceDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsAddressMatchListOfServiceInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsAddressMatchListOfService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsAddressMatchListOfService");
  }
	
  
    /* Association Interface */

    void Linux_DnsAddressMatchListOfServiceDefaultImplementation::
     referencesAntecedent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getAntecedentReferences between Linux_DnsService and Linux_DnsAddressMatchList not implemented for Linux_DnsAddressMatchListOfService");
    }

    void Linux_DnsAddressMatchListOfServiceDefaultImplementation::
     referencesDependent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getDependentReferences between Linux_DnsService and Linux_DnsAddressMatchList not implemented for Linux_DnsAddressMatchListOfService");
    }

    void Linux_DnsAddressMatchListOfServiceDefaultImplementation::
     associatorsAntecedent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsAddressMatchListOfService : associatorsLinux_DnsService() ... returns one instance"<<std::endl;
      
      Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration enumeration;
      
      referencesAntecedent(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsServiceExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsAddressMatchListOfServiceManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsAddressMatchListOfServiceInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsServiceInstanceName Antecedent = 
         instanceName.getAntecedent();
         
        Linux_DnsServiceInstance inst = external.getInstance(properties,Antecedent);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsAddressMatchListOfServiceDefaultImplementation::
     associatorsDependent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsAddressMatchListOfService : associatorsLinux_DnsAddressMatchList() ... returns one instance"<<std::endl;
      
      Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration enumeration;
      
      referencesDependent(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsAddressMatchListExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsAddressMatchListOfServiceManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsAddressMatchListOfServiceInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsAddressMatchListInstanceName Dependent = 
         instanceName.getDependent();
         
        Linux_DnsAddressMatchListInstance inst = external.getInstance(properties,Dependent);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

