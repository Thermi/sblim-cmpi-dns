 /**
 * Linux_DnsResourceRecordInZoneRepositoryInstance.cpp
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
#include "Linux_DnsResourceRecordInZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsResourceRecordInZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsResourceRecordInZoneRepositoryInstance::
   Linux_DnsResourceRecordInZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsResourceRecordInZoneRepositoryInstance::
   Linux_DnsResourceRecordInZoneRepositoryInstance
   (const Linux_DnsResourceRecordInZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsResourceRecordInZoneRepositoryInstance::
   Linux_DnsResourceRecordInZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsResourceRecordInZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsResourceRecordInZoneRepositoryInstance::
   ~Linux_DnsResourceRecordInZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsResourceRecordInZoneRepositoryInstance&
   Linux_DnsResourceRecordInZoneRepositoryInstance::operator=
   (const Linux_DnsResourceRecordInZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsResourceRecordInZoneRepositoryInstance::
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
  unsigned int Linux_DnsResourceRecordInZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsResourceRecordInZoneInstanceName&
    Linux_DnsResourceRecordInZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsResourceRecordInZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsResourceRecordInZoneRepositoryInstance::setInstanceName(
   const Linux_DnsResourceRecordInZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsResourceRecordInZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsResourceRecordInZoneRepositoryInstance::init
   (const Linux_DnsResourceRecordInZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsResourceRecordInZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement::
   Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsResourceRecordInZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration::
   Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration::
   Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration(
   const Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration::
   ~Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsResourceRecordInZoneRepositoryInstance&  
   Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsResourceRecordInZoneRepositoryInstance&
   Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsResourceRecordInZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsResourceRecordInZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsResourceRecordInZoneRepositoryInstance(elementP);
  	}
  };  
}
 
