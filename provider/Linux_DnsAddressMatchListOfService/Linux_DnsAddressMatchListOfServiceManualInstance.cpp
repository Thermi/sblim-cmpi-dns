 /**
 * Linux_DnsAddressMatchListOfServiceManualInstance.cpp
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
#include "Linux_DnsAddressMatchListOfServiceManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAddressMatchListOfServiceManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAddressMatchListOfServiceManualInstance::
   Linux_DnsAddressMatchListOfServiceManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAddressMatchListOfServiceManualInstance::
   Linux_DnsAddressMatchListOfServiceManualInstance
   (const Linux_DnsAddressMatchListOfServiceManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAddressMatchListOfServiceManualInstance::
   Linux_DnsAddressMatchListOfServiceManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAddressMatchListOfServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAddressMatchListOfServiceManualInstance::
   ~Linux_DnsAddressMatchListOfServiceManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAddressMatchListOfServiceManualInstance&
   Linux_DnsAddressMatchListOfServiceManualInstance::operator=
   (const Linux_DnsAddressMatchListOfServiceManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAddressMatchListOfServiceManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsAddressMatchListOfServiceManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAddressMatchListOfServiceInstanceName&
    Linux_DnsAddressMatchListOfServiceManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAddressMatchListOfService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAddressMatchListOfServiceManualInstance::setInstanceName(
   const Linux_DnsAddressMatchListOfServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAddressMatchListOfServiceManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAddressMatchListOfServiceManualInstance::init
   (const Linux_DnsAddressMatchListOfServiceManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAddressMatchListOfServiceManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement::
   Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement::
   ~Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAddressMatchListOfServiceManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration::
   Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration::
   Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration(
   const Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration::
   ~Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAddressMatchListOfServiceManualInstance&  
   Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAddressMatchListOfServiceManualInstance&
   Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration::addElement
   (const Linux_DnsAddressMatchListOfServiceManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAddressMatchListOfServiceManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAddressMatchListOfServiceManualInstance(elementP);
  	}
  };  
}
 
