 /**
 * Linux_DnsResourceRecordInZoneInstance.cpp
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
#include "Linux_DnsResourceRecordInZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsResourceRecordInZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsResourceRecordInZoneInstance::
   Linux_DnsResourceRecordInZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsResourceRecordInZoneInstance::
   Linux_DnsResourceRecordInZoneInstance
   (const Linux_DnsResourceRecordInZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsResourceRecordInZoneInstance::
   Linux_DnsResourceRecordInZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsResourceRecordInZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsResourceRecordInZoneInstance::
   ~Linux_DnsResourceRecordInZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsResourceRecordInZoneInstance&
   Linux_DnsResourceRecordInZoneInstance::operator=
   (const Linux_DnsResourceRecordInZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsResourceRecordInZoneInstance::
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
  unsigned int Linux_DnsResourceRecordInZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsResourceRecordInZoneInstanceName&
    Linux_DnsResourceRecordInZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsResourceRecordInZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsResourceRecordInZoneInstance::setInstanceName(
   const Linux_DnsResourceRecordInZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsResourceRecordInZoneInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsResourceRecordInZoneInstance::init
   (const Linux_DnsResourceRecordInZoneInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsResourceRecordInZoneInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsResourceRecordInZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsResourceRecordInZoneInstanceEnumerationElement::
   Linux_DnsResourceRecordInZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsResourceRecordInZoneInstanceEnumerationElement::
   ~Linux_DnsResourceRecordInZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsResourceRecordInZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsResourceRecordInZoneInstanceEnumeration::
   Linux_DnsResourceRecordInZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsResourceRecordInZoneInstanceEnumeration::
   Linux_DnsResourceRecordInZoneInstanceEnumeration(
   const Linux_DnsResourceRecordInZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsResourceRecordInZoneInstanceEnumeration::
   ~Linux_DnsResourceRecordInZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsResourceRecordInZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsResourceRecordInZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsResourceRecordInZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsResourceRecordInZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsResourceRecordInZoneInstance&  
   Linux_DnsResourceRecordInZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsResourceRecordInZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsResourceRecordInZoneInstance&
   Linux_DnsResourceRecordInZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsResourceRecordInZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsResourceRecordInZoneInstanceEnumeration::addElement
   (const Linux_DnsResourceRecordInZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsResourceRecordInZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsResourceRecordInZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsResourceRecordInZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsResourceRecordInZoneInstance(elementP);
  	}
  };  
}
 
