 /**
 * Linux_DnsForwardZoneRepositoryInstance.cpp
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
#include "Linux_DnsForwardZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsForwardZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsForwardZoneRepositoryInstance::
   Linux_DnsForwardZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsForwardZoneRepositoryInstance::
   Linux_DnsForwardZoneRepositoryInstance
   (const Linux_DnsForwardZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsForwardZoneRepositoryInstance::
   Linux_DnsForwardZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsForwardZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsForwardZoneRepositoryInstance::
   ~Linux_DnsForwardZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsForwardZoneRepositoryInstance&
   Linux_DnsForwardZoneRepositoryInstance::operator=
   (const Linux_DnsForwardZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsForwardZoneRepositoryInstance::
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
  unsigned int Linux_DnsForwardZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsForwardZoneInstanceName&
    Linux_DnsForwardZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsForwardZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsForwardZoneRepositoryInstance::setInstanceName(
   const Linux_DnsForwardZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsForwardZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsForwardZoneRepositoryInstance::init
   (const Linux_DnsForwardZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsForwardZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsForwardZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsForwardZoneRepositoryInstanceEnumerationElement::
   Linux_DnsForwardZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsForwardZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsForwardZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsForwardZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsForwardZoneRepositoryInstanceEnumeration::
   Linux_DnsForwardZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsForwardZoneRepositoryInstanceEnumeration::
   Linux_DnsForwardZoneRepositoryInstanceEnumeration(
   const Linux_DnsForwardZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsForwardZoneRepositoryInstanceEnumeration::
   ~Linux_DnsForwardZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsForwardZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsForwardZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsForwardZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsForwardZoneRepositoryInstance&  
   Linux_DnsForwardZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsForwardZoneRepositoryInstance&
   Linux_DnsForwardZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsForwardZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsForwardZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsForwardZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsForwardZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsForwardZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsForwardZoneRepositoryInstance(elementP);
  	}
  };  
}
 
