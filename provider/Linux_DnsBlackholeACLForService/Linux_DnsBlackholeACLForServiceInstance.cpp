 /**
 * Linux_DnsBlackholeACLForServiceInstance.cpp
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
#include "Linux_DnsBlackholeACLForServiceInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsBlackholeACLForServiceInstance
  //*********************************************************

  //empty constructor
  Linux_DnsBlackholeACLForServiceInstance::
   Linux_DnsBlackholeACLForServiceInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsBlackholeACLForServiceInstance::
   Linux_DnsBlackholeACLForServiceInstance
   (const Linux_DnsBlackholeACLForServiceInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsBlackholeACLForServiceInstance::
   Linux_DnsBlackholeACLForServiceInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsBlackholeACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsBlackholeACLForServiceInstance::
   ~Linux_DnsBlackholeACLForServiceInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsBlackholeACLForServiceInstance&
   Linux_DnsBlackholeACLForServiceInstance::operator=
   (const Linux_DnsBlackholeACLForServiceInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsBlackholeACLForServiceInstance::
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
  unsigned int Linux_DnsBlackholeACLForServiceInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsBlackholeACLForServiceInstanceName&
    Linux_DnsBlackholeACLForServiceInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsBlackholeACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsBlackholeACLForServiceInstance::setInstanceName(
   const Linux_DnsBlackholeACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsBlackholeACLForServiceInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsBlackholeACLForServiceInstance::init
   (const Linux_DnsBlackholeACLForServiceInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsBlackholeACLForServiceInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsBlackholeACLForServiceInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsBlackholeACLForServiceInstanceEnumerationElement::
   Linux_DnsBlackholeACLForServiceInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsBlackholeACLForServiceInstanceEnumerationElement::
   ~Linux_DnsBlackholeACLForServiceInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsBlackholeACLForServiceInstanceNameEnumeration
  //*********************************************************

  Linux_DnsBlackholeACLForServiceInstanceEnumeration::
   Linux_DnsBlackholeACLForServiceInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsBlackholeACLForServiceInstanceEnumeration::
   Linux_DnsBlackholeACLForServiceInstanceEnumeration(
   const Linux_DnsBlackholeACLForServiceInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsBlackholeACLForServiceInstanceEnumeration::
   ~Linux_DnsBlackholeACLForServiceInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsBlackholeACLForServiceInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsBlackholeACLForServiceInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsBlackholeACLForServiceInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsBlackholeACLForServiceInstance&  
   Linux_DnsBlackholeACLForServiceInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsBlackholeACLForServiceInstance&
   Linux_DnsBlackholeACLForServiceInstanceEnumeration::getNext() {
   	
  	 Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsBlackholeACLForServiceInstanceEnumeration::addElement
   (const Linux_DnsBlackholeACLForServiceInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsBlackholeACLForServiceInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsBlackholeACLForServiceInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsBlackholeACLForServiceInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsBlackholeACLForServiceInstance(elementP);
  	}
  };  
}
 
