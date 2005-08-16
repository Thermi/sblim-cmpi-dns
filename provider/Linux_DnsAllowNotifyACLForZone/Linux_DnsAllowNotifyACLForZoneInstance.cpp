 /**
 * Linux_DnsAllowNotifyACLForZoneInstance.cpp
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
#include "Linux_DnsAllowNotifyACLForZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowNotifyACLForZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowNotifyACLForZoneInstance::
   Linux_DnsAllowNotifyACLForZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowNotifyACLForZoneInstance::
   Linux_DnsAllowNotifyACLForZoneInstance
   (const Linux_DnsAllowNotifyACLForZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowNotifyACLForZoneInstance::
   Linux_DnsAllowNotifyACLForZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowNotifyACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowNotifyACLForZoneInstance::
   ~Linux_DnsAllowNotifyACLForZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowNotifyACLForZoneInstance&
   Linux_DnsAllowNotifyACLForZoneInstance::operator=
   (const Linux_DnsAllowNotifyACLForZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowNotifyACLForZoneInstance::
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
  unsigned int Linux_DnsAllowNotifyACLForZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowNotifyACLForZoneInstanceName&
    Linux_DnsAllowNotifyACLForZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowNotifyACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowNotifyACLForZoneInstance::setInstanceName(
   const Linux_DnsAllowNotifyACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowNotifyACLForZoneInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowNotifyACLForZoneInstance::init
   (const Linux_DnsAllowNotifyACLForZoneInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowNotifyACLForZoneInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement::
   Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement::
   ~Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowNotifyACLForZoneInstanceEnumeration::
   Linux_DnsAllowNotifyACLForZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowNotifyACLForZoneInstanceEnumeration::
   Linux_DnsAllowNotifyACLForZoneInstanceEnumeration(
   const Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowNotifyACLForZoneInstanceEnumeration::
   ~Linux_DnsAllowNotifyACLForZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowNotifyACLForZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowNotifyACLForZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowNotifyACLForZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowNotifyACLForZoneInstance&  
   Linux_DnsAllowNotifyACLForZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowNotifyACLForZoneInstance&
   Linux_DnsAllowNotifyACLForZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowNotifyACLForZoneInstanceEnumeration::addElement
   (const Linux_DnsAllowNotifyACLForZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowNotifyACLForZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowNotifyACLForZoneInstance(elementP);
  	}
  };  
}
 
