 /**
 * Linux_DnsResourceRecordInZoneManualInstance.cpp
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
#include "Linux_DnsResourceRecordInZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsResourceRecordInZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsResourceRecordInZoneManualInstance::
   Linux_DnsResourceRecordInZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsResourceRecordInZoneManualInstance::
   Linux_DnsResourceRecordInZoneManualInstance
   (const Linux_DnsResourceRecordInZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsResourceRecordInZoneManualInstance::
   Linux_DnsResourceRecordInZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsResourceRecordInZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsResourceRecordInZoneManualInstance::
   ~Linux_DnsResourceRecordInZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsResourceRecordInZoneManualInstance&
   Linux_DnsResourceRecordInZoneManualInstance::operator=
   (const Linux_DnsResourceRecordInZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsResourceRecordInZoneManualInstance::
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
  unsigned int Linux_DnsResourceRecordInZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsResourceRecordInZoneInstanceName&
    Linux_DnsResourceRecordInZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsResourceRecordInZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsResourceRecordInZoneManualInstance::setInstanceName(
   const Linux_DnsResourceRecordInZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsResourceRecordInZoneManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsResourceRecordInZoneManualInstance::init
   (const Linux_DnsResourceRecordInZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsResourceRecordInZoneManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement::
   Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement::
   ~Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsResourceRecordInZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsResourceRecordInZoneManualInstanceEnumeration::
   Linux_DnsResourceRecordInZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsResourceRecordInZoneManualInstanceEnumeration::
   Linux_DnsResourceRecordInZoneManualInstanceEnumeration(
   const Linux_DnsResourceRecordInZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsResourceRecordInZoneManualInstanceEnumeration::
   ~Linux_DnsResourceRecordInZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsResourceRecordInZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsResourceRecordInZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsResourceRecordInZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsResourceRecordInZoneManualInstance&  
   Linux_DnsResourceRecordInZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsResourceRecordInZoneManualInstance&
   Linux_DnsResourceRecordInZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsResourceRecordInZoneManualInstanceEnumeration::addElement
   (const Linux_DnsResourceRecordInZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsResourceRecordInZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsResourceRecordInZoneManualInstance(elementP);
  	}
  };  
}
 
