 /**
 * Linux_DnsNotifyACLForServiceManualInstance.cpp
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
#include "Linux_DnsNotifyACLForServiceManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsNotifyACLForServiceManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsNotifyACLForServiceManualInstance::
   Linux_DnsNotifyACLForServiceManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsNotifyACLForServiceManualInstance::
   Linux_DnsNotifyACLForServiceManualInstance
   (const Linux_DnsNotifyACLForServiceManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsNotifyACLForServiceManualInstance::
   Linux_DnsNotifyACLForServiceManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsNotifyACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsNotifyACLForServiceManualInstance::
   ~Linux_DnsNotifyACLForServiceManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsNotifyACLForServiceManualInstance&
   Linux_DnsNotifyACLForServiceManualInstance::operator=
   (const Linux_DnsNotifyACLForServiceManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsNotifyACLForServiceManualInstance::
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
  unsigned int Linux_DnsNotifyACLForServiceManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsNotifyACLForServiceInstanceName&
    Linux_DnsNotifyACLForServiceManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsNotifyACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsNotifyACLForServiceManualInstance::setInstanceName(
   const Linux_DnsNotifyACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsNotifyACLForServiceManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsNotifyACLForServiceManualInstance::init
   (const Linux_DnsNotifyACLForServiceManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsNotifyACLForServiceManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement::
   Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement::
   ~Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsNotifyACLForServiceManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsNotifyACLForServiceManualInstanceEnumeration::
   Linux_DnsNotifyACLForServiceManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsNotifyACLForServiceManualInstanceEnumeration::
   Linux_DnsNotifyACLForServiceManualInstanceEnumeration(
   const Linux_DnsNotifyACLForServiceManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsNotifyACLForServiceManualInstanceEnumeration::
   ~Linux_DnsNotifyACLForServiceManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsNotifyACLForServiceManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsNotifyACLForServiceManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsNotifyACLForServiceManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsNotifyACLForServiceManualInstance&  
   Linux_DnsNotifyACLForServiceManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsNotifyACLForServiceManualInstance&
   Linux_DnsNotifyACLForServiceManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsNotifyACLForServiceManualInstanceEnumeration::addElement
   (const Linux_DnsNotifyACLForServiceManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsNotifyACLForServiceManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsNotifyACLForServiceManualInstance(elementP);
  	}
  };  
}
 
