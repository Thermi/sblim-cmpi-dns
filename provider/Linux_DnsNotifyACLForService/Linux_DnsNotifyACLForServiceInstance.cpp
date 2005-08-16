 /**
 * Linux_DnsNotifyACLForServiceInstance.cpp
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
#include "Linux_DnsNotifyACLForServiceInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsNotifyACLForServiceInstance
  //*********************************************************

  //empty constructor
  Linux_DnsNotifyACLForServiceInstance::
   Linux_DnsNotifyACLForServiceInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsNotifyACLForServiceInstance::
   Linux_DnsNotifyACLForServiceInstance
   (const Linux_DnsNotifyACLForServiceInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsNotifyACLForServiceInstance::
   Linux_DnsNotifyACLForServiceInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsNotifyACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsNotifyACLForServiceInstance::
   ~Linux_DnsNotifyACLForServiceInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsNotifyACLForServiceInstance&
   Linux_DnsNotifyACLForServiceInstance::operator=
   (const Linux_DnsNotifyACLForServiceInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsNotifyACLForServiceInstance::
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
  unsigned int Linux_DnsNotifyACLForServiceInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsNotifyACLForServiceInstanceName&
    Linux_DnsNotifyACLForServiceInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsNotifyACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsNotifyACLForServiceInstance::setInstanceName(
   const Linux_DnsNotifyACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsNotifyACLForServiceInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsNotifyACLForServiceInstance::init
   (const Linux_DnsNotifyACLForServiceInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsNotifyACLForServiceInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsNotifyACLForServiceInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsNotifyACLForServiceInstanceEnumerationElement::
   Linux_DnsNotifyACLForServiceInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsNotifyACLForServiceInstanceEnumerationElement::
   ~Linux_DnsNotifyACLForServiceInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsNotifyACLForServiceInstanceNameEnumeration
  //*********************************************************

  Linux_DnsNotifyACLForServiceInstanceEnumeration::
   Linux_DnsNotifyACLForServiceInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsNotifyACLForServiceInstanceEnumeration::
   Linux_DnsNotifyACLForServiceInstanceEnumeration(
   const Linux_DnsNotifyACLForServiceInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsNotifyACLForServiceInstanceEnumeration::
   ~Linux_DnsNotifyACLForServiceInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsNotifyACLForServiceInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsNotifyACLForServiceInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsNotifyACLForServiceInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsNotifyACLForServiceInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsNotifyACLForServiceInstance&  
   Linux_DnsNotifyACLForServiceInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsNotifyACLForServiceInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsNotifyACLForServiceInstance&
   Linux_DnsNotifyACLForServiceInstanceEnumeration::getNext() {
   	
  	 Linux_DnsNotifyACLForServiceInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsNotifyACLForServiceInstanceEnumeration::addElement
   (const Linux_DnsNotifyACLForServiceInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsNotifyACLForServiceInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsNotifyACLForServiceInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsNotifyACLForServiceInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsNotifyACLForServiceInstance(elementP);
  	}
  };  
}
 
