 /**
 * Linux_DnsRecursionACLForServiceManualInstance.cpp
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
#include "Linux_DnsRecursionACLForServiceManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsRecursionACLForServiceManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsRecursionACLForServiceManualInstance::
   Linux_DnsRecursionACLForServiceManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsRecursionACLForServiceManualInstance::
   Linux_DnsRecursionACLForServiceManualInstance
   (const Linux_DnsRecursionACLForServiceManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsRecursionACLForServiceManualInstance::
   Linux_DnsRecursionACLForServiceManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsRecursionACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsRecursionACLForServiceManualInstance::
   ~Linux_DnsRecursionACLForServiceManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsRecursionACLForServiceManualInstance&
   Linux_DnsRecursionACLForServiceManualInstance::operator=
   (const Linux_DnsRecursionACLForServiceManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsRecursionACLForServiceManualInstance::
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
  unsigned int Linux_DnsRecursionACLForServiceManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsRecursionACLForServiceInstanceName&
    Linux_DnsRecursionACLForServiceManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsRecursionACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsRecursionACLForServiceManualInstance::setInstanceName(
   const Linux_DnsRecursionACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsRecursionACLForServiceManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsRecursionACLForServiceManualInstance::init
   (const Linux_DnsRecursionACLForServiceManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsRecursionACLForServiceManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement::
   Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement::
   ~Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsRecursionACLForServiceManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsRecursionACLForServiceManualInstanceEnumeration::
   Linux_DnsRecursionACLForServiceManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsRecursionACLForServiceManualInstanceEnumeration::
   Linux_DnsRecursionACLForServiceManualInstanceEnumeration(
   const Linux_DnsRecursionACLForServiceManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsRecursionACLForServiceManualInstanceEnumeration::
   ~Linux_DnsRecursionACLForServiceManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsRecursionACLForServiceManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsRecursionACLForServiceManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsRecursionACLForServiceManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsRecursionACLForServiceManualInstance&  
   Linux_DnsRecursionACLForServiceManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsRecursionACLForServiceManualInstance&
   Linux_DnsRecursionACLForServiceManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsRecursionACLForServiceManualInstanceEnumeration::addElement
   (const Linux_DnsRecursionACLForServiceManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsRecursionACLForServiceManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsRecursionACLForServiceManualInstance(elementP);
  	}
  };  
}
 
