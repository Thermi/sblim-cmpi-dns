 /**
 * Linux_DnsResourceRecordInZoneDefaultImplementation.cpp
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
#include "Linux_DnsResourceRecordInZoneDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsResourceRecordInZoneDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsResourceRecordInZoneInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsResourceRecordInZone"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsResourceRecordInZone");   
  }
  	
  void Linux_DnsResourceRecordInZoneDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsResourceRecordInZoneManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsResourceRecordInZone"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsResourceRecordInZoneInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsResourceRecordInZoneInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsResourceRecordInZoneManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsResourceRecordInZoneManualInstance 
   Linux_DnsResourceRecordInZoneDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsResourceRecordInZoneInstanceName&){
    cout<<"getInstance not supported for Linux_DnsResourceRecordInZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsResourceRecordInZone");
  }
  	
  void Linux_DnsResourceRecordInZoneDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsResourceRecordInZoneManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsResourceRecordInZone"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsResourceRecordInZone");
  }
  	
  void Linux_DnsResourceRecordInZoneDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsResourceRecordInZoneManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsResourceRecordInZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsResourceRecordInZone");
  }
  	
  void Linux_DnsResourceRecordInZoneDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsResourceRecordInZoneInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsResourceRecordInZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsResourceRecordInZone");
  }
	
  
    /* Association Interface */

    void Linux_DnsResourceRecordInZoneDefaultImplementation::
     referencesGroupComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getGroupComponentReferences between Linux_DnsZone and Linux_DnsResourceRecord not implemented for Linux_DnsResourceRecordInZone");
    }

    void Linux_DnsResourceRecordInZoneDefaultImplementation::
     referencesPartComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getPartComponentReferences between Linux_DnsZone and Linux_DnsResourceRecord not implemented for Linux_DnsResourceRecordInZone");
    }

    void Linux_DnsResourceRecordInZoneDefaultImplementation::
     associatorsGroupComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsResourceRecordInZone : associatorsLinux_DnsZone() ... returns one instance"<<std::endl;
      
      Linux_DnsResourceRecordInZoneManualInstanceEnumeration enumeration;
      
      referencesGroupComponent(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsZoneExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsResourceRecordInZoneManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsResourceRecordInZoneInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsZoneInstanceName GroupComponent = 
         instanceName.getGroupComponent();
         
        Linux_DnsZoneInstance inst = external.getInstance(properties,GroupComponent);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsResourceRecordInZoneDefaultImplementation::
     associatorsPartComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsResourceRecordInZone : associatorsLinux_DnsResourceRecord() ... returns one instance"<<std::endl;
      
      Linux_DnsResourceRecordInZoneManualInstanceEnumeration enumeration;
      
      referencesPartComponent(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsResourceRecordExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsResourceRecordInZoneManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsResourceRecordInZoneInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsResourceRecordInstanceName PartComponent = 
         instanceName.getPartComponent();
         
        Linux_DnsResourceRecordInstance inst = external.getInstance(properties,PartComponent);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

