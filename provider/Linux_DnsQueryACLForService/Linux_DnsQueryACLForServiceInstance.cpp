 /**
 * Linux_DnsQueryACLForServiceInstance.cpp
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
#include "Linux_DnsQueryACLForServiceInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsQueryACLForServiceInstance
  //*********************************************************

  //empty constructor
  Linux_DnsQueryACLForServiceInstance::
   Linux_DnsQueryACLForServiceInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsQueryACLForServiceInstance::
   Linux_DnsQueryACLForServiceInstance
   (const Linux_DnsQueryACLForServiceInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsQueryACLForServiceInstance::
   Linux_DnsQueryACLForServiceInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsQueryACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsQueryACLForServiceInstance::
   ~Linux_DnsQueryACLForServiceInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsQueryACLForServiceInstance&
   Linux_DnsQueryACLForServiceInstance::operator=
   (const Linux_DnsQueryACLForServiceInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsQueryACLForServiceInstance::
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
  unsigned int Linux_DnsQueryACLForServiceInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsQueryACLForServiceInstanceName&
    Linux_DnsQueryACLForServiceInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsQueryACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsQueryACLForServiceInstance::setInstanceName(
   const Linux_DnsQueryACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsQueryACLForServiceInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsQueryACLForServiceInstance::init
   (const Linux_DnsQueryACLForServiceInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsQueryACLForServiceInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsQueryACLForServiceInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsQueryACLForServiceInstanceEnumerationElement::
   Linux_DnsQueryACLForServiceInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsQueryACLForServiceInstanceEnumerationElement::
   ~Linux_DnsQueryACLForServiceInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsQueryACLForServiceInstanceNameEnumeration
  //*********************************************************

  Linux_DnsQueryACLForServiceInstanceEnumeration::
   Linux_DnsQueryACLForServiceInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsQueryACLForServiceInstanceEnumeration::
   Linux_DnsQueryACLForServiceInstanceEnumeration(
   const Linux_DnsQueryACLForServiceInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsQueryACLForServiceInstanceEnumeration::
   ~Linux_DnsQueryACLForServiceInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsQueryACLForServiceInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsQueryACLForServiceInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsQueryACLForServiceInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsQueryACLForServiceInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsQueryACLForServiceInstance&  
   Linux_DnsQueryACLForServiceInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsQueryACLForServiceInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsQueryACLForServiceInstance&
   Linux_DnsQueryACLForServiceInstanceEnumeration::getNext() {
   	
  	 Linux_DnsQueryACLForServiceInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsQueryACLForServiceInstanceEnumeration::addElement
   (const Linux_DnsQueryACLForServiceInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsQueryACLForServiceInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsQueryACLForServiceInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsQueryACLForServiceInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsQueryACLForServiceInstance(elementP);
  	}
  };  
}
 
