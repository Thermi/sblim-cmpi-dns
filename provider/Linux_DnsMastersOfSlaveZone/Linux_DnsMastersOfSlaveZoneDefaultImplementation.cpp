 /**
 * Linux_DnsMastersOfSlaveZoneDefaultImplementation.cpp
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
#include "Linux_DnsMastersOfSlaveZoneDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsMastersOfSlaveZoneDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsMastersOfSlaveZone"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsMastersOfSlaveZone");   
  }
  	
  void Linux_DnsMastersOfSlaveZoneDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsMastersOfSlaveZone"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsMastersOfSlaveZoneInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsMastersOfSlaveZoneManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsMastersOfSlaveZoneManualInstance 
   Linux_DnsMastersOfSlaveZoneDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsMastersOfSlaveZoneInstanceName&){
    cout<<"getInstance not supported for Linux_DnsMastersOfSlaveZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsMastersOfSlaveZone");
  }
  	
  void Linux_DnsMastersOfSlaveZoneDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsMastersOfSlaveZoneManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsMastersOfSlaveZone"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsMastersOfSlaveZone");
  }
  	
  void Linux_DnsMastersOfSlaveZoneDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsMastersOfSlaveZoneManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsMastersOfSlaveZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsMastersOfSlaveZone");
  }
  	
  void Linux_DnsMastersOfSlaveZoneDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsMastersOfSlaveZoneInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsMastersOfSlaveZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsMastersOfSlaveZone");
  }
	
  
    /* Association Interface */

    void Linux_DnsMastersOfSlaveZoneDefaultImplementation::
     referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getElementReferences between Linux_DnsSlaveZone and Linux_DnsIPAddress not implemented for Linux_DnsMastersOfSlaveZone");
    }

    void Linux_DnsMastersOfSlaveZoneDefaultImplementation::
     referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getSettingReferences between Linux_DnsSlaveZone and Linux_DnsIPAddress not implemented for Linux_DnsMastersOfSlaveZone");
    }

    void Linux_DnsMastersOfSlaveZoneDefaultImplementation::
     associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsSlaveZoneInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsMastersOfSlaveZone : associatorsLinux_DnsSlaveZone() ... returns one instance"<<std::endl;
      
      Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration enumeration;
      
      referencesElement(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsSlaveZoneExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsMastersOfSlaveZoneManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsMastersOfSlaveZoneInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsSlaveZoneInstanceName Element = 
         instanceName.getElement();
         
        Linux_DnsSlaveZoneInstance inst = external.getInstance(properties,Element);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsMastersOfSlaveZoneDefaultImplementation::
     associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsIPAddressInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsMastersOfSlaveZone : associatorsLinux_DnsIPAddress() ... returns one instance"<<std::endl;
      
      Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration enumeration;
      
      referencesSetting(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsIPAddressExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsMastersOfSlaveZoneManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsMastersOfSlaveZoneInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsIPAddressInstanceName Setting = 
         instanceName.getSetting();
         
        Linux_DnsIPAddressInstance inst = external.getInstance(properties,Setting);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

