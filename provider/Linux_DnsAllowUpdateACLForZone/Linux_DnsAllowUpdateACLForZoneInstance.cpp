 /**
 * Linux_DnsAllowUpdateACLForZoneInstance.cpp
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
#include "Linux_DnsAllowUpdateACLForZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowUpdateACLForZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowUpdateACLForZoneInstance::
   Linux_DnsAllowUpdateACLForZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowUpdateACLForZoneInstance::
   Linux_DnsAllowUpdateACLForZoneInstance
   (const Linux_DnsAllowUpdateACLForZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowUpdateACLForZoneInstance::
   Linux_DnsAllowUpdateACLForZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowUpdateACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowUpdateACLForZoneInstance::
   ~Linux_DnsAllowUpdateACLForZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowUpdateACLForZoneInstance&
   Linux_DnsAllowUpdateACLForZoneInstance::operator=
   (const Linux_DnsAllowUpdateACLForZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowUpdateACLForZoneInstance::
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
  unsigned int Linux_DnsAllowUpdateACLForZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowUpdateACLForZoneInstanceName&
    Linux_DnsAllowUpdateACLForZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowUpdateACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowUpdateACLForZoneInstance::setInstanceName(
   const Linux_DnsAllowUpdateACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowUpdateACLForZoneInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowUpdateACLForZoneInstance::init
   (const Linux_DnsAllowUpdateACLForZoneInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowUpdateACLForZoneInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement::
   Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement::
   ~Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowUpdateACLForZoneInstanceEnumeration::
   Linux_DnsAllowUpdateACLForZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowUpdateACLForZoneInstanceEnumeration::
   Linux_DnsAllowUpdateACLForZoneInstanceEnumeration(
   const Linux_DnsAllowUpdateACLForZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowUpdateACLForZoneInstanceEnumeration::
   ~Linux_DnsAllowUpdateACLForZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowUpdateACLForZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowUpdateACLForZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowUpdateACLForZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowUpdateACLForZoneInstance&  
   Linux_DnsAllowUpdateACLForZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowUpdateACLForZoneInstance&
   Linux_DnsAllowUpdateACLForZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowUpdateACLForZoneInstanceEnumeration::addElement
   (const Linux_DnsAllowUpdateACLForZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowUpdateACLForZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowUpdateACLForZoneInstance(elementP);
  	}
  };  
}
 
