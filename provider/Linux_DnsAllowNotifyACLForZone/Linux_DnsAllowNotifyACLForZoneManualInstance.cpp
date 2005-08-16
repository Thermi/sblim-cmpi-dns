 /**
 * Linux_DnsAllowNotifyACLForZoneManualInstance.cpp
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
#include "Linux_DnsAllowNotifyACLForZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowNotifyACLForZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowNotifyACLForZoneManualInstance::
   Linux_DnsAllowNotifyACLForZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowNotifyACLForZoneManualInstance::
   Linux_DnsAllowNotifyACLForZoneManualInstance
   (const Linux_DnsAllowNotifyACLForZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowNotifyACLForZoneManualInstance::
   Linux_DnsAllowNotifyACLForZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowNotifyACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowNotifyACLForZoneManualInstance::
   ~Linux_DnsAllowNotifyACLForZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowNotifyACLForZoneManualInstance&
   Linux_DnsAllowNotifyACLForZoneManualInstance::operator=
   (const Linux_DnsAllowNotifyACLForZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowNotifyACLForZoneManualInstance::
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
  unsigned int Linux_DnsAllowNotifyACLForZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowNotifyACLForZoneInstanceName&
    Linux_DnsAllowNotifyACLForZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowNotifyACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowNotifyACLForZoneManualInstance::setInstanceName(
   const Linux_DnsAllowNotifyACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowNotifyACLForZoneManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowNotifyACLForZoneManualInstance::init
   (const Linux_DnsAllowNotifyACLForZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowNotifyACLForZoneManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement::
   Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement::
   ~Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowNotifyACLForZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration::
   Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration::
   Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration(
   const Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration::
   ~Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowNotifyACLForZoneManualInstance&  
   Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowNotifyACLForZoneManualInstance&
   Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration::addElement
   (const Linux_DnsAllowNotifyACLForZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowNotifyACLForZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowNotifyACLForZoneManualInstance(elementP);
  	}
  };  
}
 
