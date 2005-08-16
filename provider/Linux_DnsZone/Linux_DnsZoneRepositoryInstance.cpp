 /**
 * Linux_DnsZoneRepositoryInstance.cpp
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
#include "Linux_DnsZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsZoneRepositoryInstance::
   Linux_DnsZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsZoneRepositoryInstance::
   Linux_DnsZoneRepositoryInstance
   (const Linux_DnsZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsZoneRepositoryInstance::
   Linux_DnsZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsZoneRepositoryInstance::
   ~Linux_DnsZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsZoneRepositoryInstance&
   Linux_DnsZoneRepositoryInstance::operator=
   (const Linux_DnsZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsZoneRepositoryInstance::
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
  unsigned int Linux_DnsZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsZoneInstanceName&
    Linux_DnsZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsZoneRepositoryInstance::setInstanceName(
   const Linux_DnsZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsZoneRepositoryInstance::init
   (const Linux_DnsZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsZoneRepositoryInstanceEnumerationElement::
   Linux_DnsZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsZoneRepositoryInstanceEnumeration::
   Linux_DnsZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsZoneRepositoryInstanceEnumeration::
   Linux_DnsZoneRepositoryInstanceEnumeration(
   const Linux_DnsZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsZoneRepositoryInstanceEnumeration::
   ~Linux_DnsZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsZoneRepositoryInstance&  
   Linux_DnsZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsZoneRepositoryInstance&
   Linux_DnsZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsZoneRepositoryInstance(elementP);
  	}
  };  
}
 
