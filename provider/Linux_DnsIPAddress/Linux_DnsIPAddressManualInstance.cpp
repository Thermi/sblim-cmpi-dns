 /**
 * Linux_DnsIPAddressManualInstance.cpp
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
#include "Linux_DnsIPAddressManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsIPAddressManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsIPAddressManualInstance::
   Linux_DnsIPAddressManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsIPAddressManualInstance::
   Linux_DnsIPAddressManualInstance
   (const Linux_DnsIPAddressManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsIPAddressManualInstance::
   Linux_DnsIPAddressManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsIPAddressInstanceName(cop));
    
    cmpiData = inst.getProperty("Port");
    if(!cmpiData.isNullValue()){
      CMPIUint32 Port = cmpiData;
      setPort(Port);
    }
    
    cmpiData = inst.getProperty("SecurityKey");
    if(!cmpiData.isNullValue()){
      CmpiString SecurityKey = cmpiData;
      setSecurityKey(SecurityKey.charPtr());
    }
    
  }
  
  
  //Destructor
  Linux_DnsIPAddressManualInstance::
   ~Linux_DnsIPAddressManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsIPAddressManualInstance&
   Linux_DnsIPAddressManualInstance::operator=
   (const Linux_DnsIPAddressManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsIPAddressManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.Port){
  	  cmpiInstance.setProperty("Port",CmpiData(m_Port));
  	}

  	if(isSet.SecurityKey){
  	  cmpiInstance.setProperty("SecurityKey",CmpiData(m_SecurityKey));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsIPAddressManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsIPAddressInstanceName&
    Linux_DnsIPAddressManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsIPAddress instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsIPAddressManualInstance::setInstanceName(
   const Linux_DnsIPAddressInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Port related methods
  unsigned int Linux_DnsIPAddressManualInstance::isPortSet() const{
    return isSet.Port;
  }
  void Linux_DnsIPAddressManualInstance::
   setPort(const CMPIUint32 val){
    m_Port = val;
    isSet.Port=1;
  }       
  const CMPIUint32 Linux_DnsIPAddressManualInstance::
   getPort() const{
    
    if(!isSet.Port)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Port not set");
   	   	
    return m_Port;
  }
       
  //SecurityKey related methods
  unsigned int Linux_DnsIPAddressManualInstance::isSecurityKeySet() const{
    return isSet.SecurityKey;
  }
  void  Linux_DnsIPAddressManualInstance::
   setSecurityKey(const char* val, int makeCopy){
    if (isSet.SecurityKey) {
      delete []m_SecurityKey;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_SecurityKey = tmpval;
    } else {
      m_SecurityKey = val;
    }
    isSet.SecurityKey=1;
  }       
  const char* Linux_DnsIPAddressManualInstance::
   getSecurityKey() const{
    
    if(!isSet.SecurityKey)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SecurityKey not set");
   	   	
    return m_SecurityKey;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsIPAddressManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Port=0;   	
    isSet.SecurityKey=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsIPAddressManualInstance::init
   (const Linux_DnsIPAddressManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isPortSet()){
      const CMPIUint32 PortOriginal=original.getPort();
      setPort(PortOriginal);
    }   	
    if(original.isSecurityKeySet()){
      const char* SecurityKeyOriginal=original.getSecurityKey();
      setSecurityKey(SecurityKeyOriginal, 1);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsIPAddressManualInstance::reset(){
   	

  	if (isSet.SecurityKey)
  	  delete(m_SecurityKey);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsIPAddressManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsIPAddressManualInstanceEnumerationElement::
   Linux_DnsIPAddressManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsIPAddressManualInstanceEnumerationElement::
   ~Linux_DnsIPAddressManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsIPAddressManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsIPAddressManualInstanceEnumeration::
   Linux_DnsIPAddressManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsIPAddressManualInstanceEnumeration::
   Linux_DnsIPAddressManualInstanceEnumeration(
   const Linux_DnsIPAddressManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsIPAddressManualInstanceEnumeration::
   ~Linux_DnsIPAddressManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsIPAddressManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsIPAddressManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsIPAddressManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsIPAddressManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsIPAddressManualInstance&  
   Linux_DnsIPAddressManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsIPAddressManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsIPAddressManualInstance&
   Linux_DnsIPAddressManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsIPAddressManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsIPAddressManualInstanceEnumeration::addElement
   (const Linux_DnsIPAddressManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsIPAddressManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsIPAddressManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsIPAddressManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsIPAddressManualInstance(elementP);
  	}
  };  
}
 
