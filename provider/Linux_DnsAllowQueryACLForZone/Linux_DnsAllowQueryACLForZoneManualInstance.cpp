 /**
 * Linux_DnsAllowQueryACLForZoneManualInstance.cpp
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
#include "Linux_DnsAllowQueryACLForZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowQueryACLForZoneManualInstance::
   Linux_DnsAllowQueryACLForZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowQueryACLForZoneManualInstance::
   Linux_DnsAllowQueryACLForZoneManualInstance
   (const Linux_DnsAllowQueryACLForZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowQueryACLForZoneManualInstance::
   Linux_DnsAllowQueryACLForZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowQueryACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowQueryACLForZoneManualInstance::
   ~Linux_DnsAllowQueryACLForZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowQueryACLForZoneManualInstance&
   Linux_DnsAllowQueryACLForZoneManualInstance::operator=
   (const Linux_DnsAllowQueryACLForZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowQueryACLForZoneManualInstance::
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
  unsigned int Linux_DnsAllowQueryACLForZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowQueryACLForZoneInstanceName&
    Linux_DnsAllowQueryACLForZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowQueryACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowQueryACLForZoneManualInstance::setInstanceName(
   const Linux_DnsAllowQueryACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowQueryACLForZoneManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowQueryACLForZoneManualInstance::init
   (const Linux_DnsAllowQueryACLForZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowQueryACLForZoneManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement::
   Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement::
   ~Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration::
   Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration::
   Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration(
   const Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration::
   ~Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowQueryACLForZoneManualInstance&  
   Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowQueryACLForZoneManualInstance&
   Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration::addElement
   (const Linux_DnsAllowQueryACLForZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowQueryACLForZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowQueryACLForZoneManualInstance(elementP);
  	}
  };  
}
 
