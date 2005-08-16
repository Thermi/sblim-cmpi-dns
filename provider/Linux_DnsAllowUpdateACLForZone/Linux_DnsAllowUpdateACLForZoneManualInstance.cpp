 /**
 * Linux_DnsAllowUpdateACLForZoneManualInstance.cpp
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
#include "Linux_DnsAllowUpdateACLForZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowUpdateACLForZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowUpdateACLForZoneManualInstance::
   Linux_DnsAllowUpdateACLForZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowUpdateACLForZoneManualInstance::
   Linux_DnsAllowUpdateACLForZoneManualInstance
   (const Linux_DnsAllowUpdateACLForZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowUpdateACLForZoneManualInstance::
   Linux_DnsAllowUpdateACLForZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowUpdateACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowUpdateACLForZoneManualInstance::
   ~Linux_DnsAllowUpdateACLForZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowUpdateACLForZoneManualInstance&
   Linux_DnsAllowUpdateACLForZoneManualInstance::operator=
   (const Linux_DnsAllowUpdateACLForZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowUpdateACLForZoneManualInstance::
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
  unsigned int Linux_DnsAllowUpdateACLForZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowUpdateACLForZoneInstanceName&
    Linux_DnsAllowUpdateACLForZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowUpdateACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowUpdateACLForZoneManualInstance::setInstanceName(
   const Linux_DnsAllowUpdateACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowUpdateACLForZoneManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowUpdateACLForZoneManualInstance::init
   (const Linux_DnsAllowUpdateACLForZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowUpdateACLForZoneManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement::
   Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement::
   ~Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowUpdateACLForZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration::
   Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration::
   Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration(
   const Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration::
   ~Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowUpdateACLForZoneManualInstance&  
   Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowUpdateACLForZoneManualInstance&
   Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration::addElement
   (const Linux_DnsAllowUpdateACLForZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowUpdateACLForZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowUpdateACLForZoneManualInstance(elementP);
  	}
  };  
}
 
