 /**
 * Linux_DnsSettingContextDefaultImplementation.cpp
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
#include "Linux_DnsSettingContextDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsSettingContextDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsSettingContextInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsSettingContext"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsSettingContext");   
  }
  	
  void Linux_DnsSettingContextDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsSettingContextManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsSettingContext"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsSettingContextInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsSettingContextInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsSettingContextManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsSettingContextManualInstance 
   Linux_DnsSettingContextDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsSettingContextInstanceName&){
    cout<<"getInstance not supported for Linux_DnsSettingContext"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsSettingContext");
  }
  	
  void Linux_DnsSettingContextDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsSettingContextManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsSettingContext"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsSettingContext");
  }
  	
  void Linux_DnsSettingContextDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsSettingContextManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsSettingContext"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsSettingContext");
  }
  	
  void Linux_DnsSettingContextDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsSettingContextInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsSettingContext"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsSettingContext");
  }
	
  
    /* Association Interface */

    void Linux_DnsSettingContextDefaultImplementation::
     referencesContext( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsSettingContextManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getContextReferences between Linux_DnsConfiguration and Linux_DnsSetting not implemented for Linux_DnsSettingContext");
    }

    void Linux_DnsSettingContextDefaultImplementation::
     referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingContextManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getSettingReferences between Linux_DnsConfiguration and Linux_DnsSetting not implemented for Linux_DnsSettingContext");
    }

    void Linux_DnsSettingContextDefaultImplementation::
     associatorsContext( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsSettingContext : associatorsLinux_DnsConfiguration() ... returns one instance"<<std::endl;
      
      Linux_DnsSettingContextManualInstanceEnumeration enumeration;
      
      referencesContext(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsConfigurationExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsSettingContextManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsSettingContextInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsConfigurationInstanceName Context = 
         instanceName.getContext();
         
        Linux_DnsConfigurationInstance inst = external.getInstance(properties,Context);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsSettingContextDefaultImplementation::
     associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsSettingContext : associatorsLinux_DnsSetting() ... returns one instance"<<std::endl;
      
      Linux_DnsSettingContextManualInstanceEnumeration enumeration;
      
      referencesSetting(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsSettingExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsSettingContextManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsSettingContextInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsSettingInstanceName Setting = 
         instanceName.getSetting();
         
        Linux_DnsSettingInstance inst = external.getInstance(properties,Setting);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

