 /**
 * Linux_DnsAllowQueryACLForZoneInstance.cpp
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
#include "Linux_DnsAllowQueryACLForZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowQueryACLForZoneInstance::
   Linux_DnsAllowQueryACLForZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowQueryACLForZoneInstance::
   Linux_DnsAllowQueryACLForZoneInstance
   (const Linux_DnsAllowQueryACLForZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowQueryACLForZoneInstance::
   Linux_DnsAllowQueryACLForZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowQueryACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowQueryACLForZoneInstance::
   ~Linux_DnsAllowQueryACLForZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowQueryACLForZoneInstance&
   Linux_DnsAllowQueryACLForZoneInstance::operator=
   (const Linux_DnsAllowQueryACLForZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowQueryACLForZoneInstance::
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
  unsigned int Linux_DnsAllowQueryACLForZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowQueryACLForZoneInstanceName&
    Linux_DnsAllowQueryACLForZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowQueryACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowQueryACLForZoneInstance::setInstanceName(
   const Linux_DnsAllowQueryACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowQueryACLForZoneInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowQueryACLForZoneInstance::init
   (const Linux_DnsAllowQueryACLForZoneInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowQueryACLForZoneInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement::
   Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement::
   ~Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowQueryACLForZoneInstanceEnumeration::
   Linux_DnsAllowQueryACLForZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowQueryACLForZoneInstanceEnumeration::
   Linux_DnsAllowQueryACLForZoneInstanceEnumeration(
   const Linux_DnsAllowQueryACLForZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowQueryACLForZoneInstanceEnumeration::
   ~Linux_DnsAllowQueryACLForZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowQueryACLForZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowQueryACLForZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowQueryACLForZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowQueryACLForZoneInstance&  
   Linux_DnsAllowQueryACLForZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowQueryACLForZoneInstance&
   Linux_DnsAllowQueryACLForZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowQueryACLForZoneInstanceEnumeration::addElement
   (const Linux_DnsAllowQueryACLForZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowQueryACLForZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowQueryACLForZoneInstance(elementP);
  	}
  };  
}
 
