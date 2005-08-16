 /**
 * Linux_DnsAllowTransferACLForZoneInstance.cpp
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
#include "Linux_DnsAllowTransferACLForZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowTransferACLForZoneInstance::
   Linux_DnsAllowTransferACLForZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowTransferACLForZoneInstance::
   Linux_DnsAllowTransferACLForZoneInstance
   (const Linux_DnsAllowTransferACLForZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowTransferACLForZoneInstance::
   Linux_DnsAllowTransferACLForZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowTransferACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowTransferACLForZoneInstance::
   ~Linux_DnsAllowTransferACLForZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowTransferACLForZoneInstance&
   Linux_DnsAllowTransferACLForZoneInstance::operator=
   (const Linux_DnsAllowTransferACLForZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowTransferACLForZoneInstance::
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
  unsigned int Linux_DnsAllowTransferACLForZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowTransferACLForZoneInstanceName&
    Linux_DnsAllowTransferACLForZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowTransferACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowTransferACLForZoneInstance::setInstanceName(
   const Linux_DnsAllowTransferACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowTransferACLForZoneInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowTransferACLForZoneInstance::init
   (const Linux_DnsAllowTransferACLForZoneInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowTransferACLForZoneInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement::
   Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement::
   ~Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowTransferACLForZoneInstanceEnumeration::
   Linux_DnsAllowTransferACLForZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowTransferACLForZoneInstanceEnumeration::
   Linux_DnsAllowTransferACLForZoneInstanceEnumeration(
   const Linux_DnsAllowTransferACLForZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowTransferACLForZoneInstanceEnumeration::
   ~Linux_DnsAllowTransferACLForZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowTransferACLForZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowTransferACLForZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowTransferACLForZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowTransferACLForZoneInstance&  
   Linux_DnsAllowTransferACLForZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowTransferACLForZoneInstance&
   Linux_DnsAllowTransferACLForZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowTransferACLForZoneInstanceEnumeration::addElement
   (const Linux_DnsAllowTransferACLForZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowTransferACLForZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowTransferACLForZoneInstance(elementP);
  	}
  };  
}
 
