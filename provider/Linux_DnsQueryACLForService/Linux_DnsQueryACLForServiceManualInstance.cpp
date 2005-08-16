 /**
 * Linux_DnsQueryACLForServiceManualInstance.cpp
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
#include "Linux_DnsQueryACLForServiceManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsQueryACLForServiceManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsQueryACLForServiceManualInstance::
   Linux_DnsQueryACLForServiceManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsQueryACLForServiceManualInstance::
   Linux_DnsQueryACLForServiceManualInstance
   (const Linux_DnsQueryACLForServiceManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsQueryACLForServiceManualInstance::
   Linux_DnsQueryACLForServiceManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsQueryACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsQueryACLForServiceManualInstance::
   ~Linux_DnsQueryACLForServiceManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsQueryACLForServiceManualInstance&
   Linux_DnsQueryACLForServiceManualInstance::operator=
   (const Linux_DnsQueryACLForServiceManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsQueryACLForServiceManualInstance::
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
  unsigned int Linux_DnsQueryACLForServiceManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsQueryACLForServiceInstanceName&
    Linux_DnsQueryACLForServiceManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsQueryACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsQueryACLForServiceManualInstance::setInstanceName(
   const Linux_DnsQueryACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsQueryACLForServiceManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsQueryACLForServiceManualInstance::init
   (const Linux_DnsQueryACLForServiceManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsQueryACLForServiceManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsQueryACLForServiceManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsQueryACLForServiceManualInstanceEnumerationElement::
   Linux_DnsQueryACLForServiceManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsQueryACLForServiceManualInstanceEnumerationElement::
   ~Linux_DnsQueryACLForServiceManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsQueryACLForServiceManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsQueryACLForServiceManualInstanceEnumeration::
   Linux_DnsQueryACLForServiceManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsQueryACLForServiceManualInstanceEnumeration::
   Linux_DnsQueryACLForServiceManualInstanceEnumeration(
   const Linux_DnsQueryACLForServiceManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsQueryACLForServiceManualInstanceEnumeration::
   ~Linux_DnsQueryACLForServiceManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsQueryACLForServiceManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsQueryACLForServiceManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsQueryACLForServiceManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsQueryACLForServiceManualInstance&  
   Linux_DnsQueryACLForServiceManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsQueryACLForServiceManualInstance&
   Linux_DnsQueryACLForServiceManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsQueryACLForServiceManualInstanceEnumeration::addElement
   (const Linux_DnsQueryACLForServiceManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsQueryACLForServiceManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsQueryACLForServiceManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsQueryACLForServiceManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsQueryACLForServiceManualInstance(elementP);
  	}
  };  
}
 
