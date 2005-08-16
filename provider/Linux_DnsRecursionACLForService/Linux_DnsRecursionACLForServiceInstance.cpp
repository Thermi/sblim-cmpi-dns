 /**
 * Linux_DnsRecursionACLForServiceInstance.cpp
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
#include "Linux_DnsRecursionACLForServiceInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsRecursionACLForServiceInstance
  //*********************************************************

  //empty constructor
  Linux_DnsRecursionACLForServiceInstance::
   Linux_DnsRecursionACLForServiceInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsRecursionACLForServiceInstance::
   Linux_DnsRecursionACLForServiceInstance
   (const Linux_DnsRecursionACLForServiceInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsRecursionACLForServiceInstance::
   Linux_DnsRecursionACLForServiceInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsRecursionACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsRecursionACLForServiceInstance::
   ~Linux_DnsRecursionACLForServiceInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsRecursionACLForServiceInstance&
   Linux_DnsRecursionACLForServiceInstance::operator=
   (const Linux_DnsRecursionACLForServiceInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsRecursionACLForServiceInstance::
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
  unsigned int Linux_DnsRecursionACLForServiceInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsRecursionACLForServiceInstanceName&
    Linux_DnsRecursionACLForServiceInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsRecursionACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsRecursionACLForServiceInstance::setInstanceName(
   const Linux_DnsRecursionACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsRecursionACLForServiceInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsRecursionACLForServiceInstance::init
   (const Linux_DnsRecursionACLForServiceInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsRecursionACLForServiceInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsRecursionACLForServiceInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsRecursionACLForServiceInstanceEnumerationElement::
   Linux_DnsRecursionACLForServiceInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsRecursionACLForServiceInstanceEnumerationElement::
   ~Linux_DnsRecursionACLForServiceInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsRecursionACLForServiceInstanceNameEnumeration
  //*********************************************************

  Linux_DnsRecursionACLForServiceInstanceEnumeration::
   Linux_DnsRecursionACLForServiceInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsRecursionACLForServiceInstanceEnumeration::
   Linux_DnsRecursionACLForServiceInstanceEnumeration(
   const Linux_DnsRecursionACLForServiceInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsRecursionACLForServiceInstanceEnumeration::
   ~Linux_DnsRecursionACLForServiceInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsRecursionACLForServiceInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsRecursionACLForServiceInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsRecursionACLForServiceInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsRecursionACLForServiceInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsRecursionACLForServiceInstance&  
   Linux_DnsRecursionACLForServiceInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsRecursionACLForServiceInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsRecursionACLForServiceInstance&
   Linux_DnsRecursionACLForServiceInstanceEnumeration::getNext() {
   	
  	 Linux_DnsRecursionACLForServiceInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsRecursionACLForServiceInstanceEnumeration::addElement
   (const Linux_DnsRecursionACLForServiceInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsRecursionACLForServiceInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsRecursionACLForServiceInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsRecursionACLForServiceInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsRecursionACLForServiceInstance(elementP);
  	}
  };  
}
 
