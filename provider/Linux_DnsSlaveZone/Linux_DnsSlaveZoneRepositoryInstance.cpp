 /**
 * Linux_DnsSlaveZoneRepositoryInstance.cpp
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
#include "Linux_DnsSlaveZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsSlaveZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsSlaveZoneRepositoryInstance::
   Linux_DnsSlaveZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsSlaveZoneRepositoryInstance::
   Linux_DnsSlaveZoneRepositoryInstance
   (const Linux_DnsSlaveZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsSlaveZoneRepositoryInstance::
   Linux_DnsSlaveZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsSlaveZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsSlaveZoneRepositoryInstance::
   ~Linux_DnsSlaveZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSlaveZoneRepositoryInstance&
   Linux_DnsSlaveZoneRepositoryInstance::operator=
   (const Linux_DnsSlaveZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsSlaveZoneRepositoryInstance::
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
  unsigned int Linux_DnsSlaveZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsSlaveZoneInstanceName&
    Linux_DnsSlaveZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsSlaveZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsSlaveZoneRepositoryInstance::setInstanceName(
   const Linux_DnsSlaveZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsSlaveZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsSlaveZoneRepositoryInstance::init
   (const Linux_DnsSlaveZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsSlaveZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement::
   Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSlaveZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsSlaveZoneRepositoryInstanceEnumeration::
   Linux_DnsSlaveZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSlaveZoneRepositoryInstanceEnumeration::
   Linux_DnsSlaveZoneRepositoryInstanceEnumeration(
   const Linux_DnsSlaveZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSlaveZoneRepositoryInstanceEnumeration::
   ~Linux_DnsSlaveZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSlaveZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSlaveZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSlaveZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsSlaveZoneRepositoryInstance&  
   Linux_DnsSlaveZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSlaveZoneRepositoryInstance&
   Linux_DnsSlaveZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSlaveZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsSlaveZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSlaveZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSlaveZoneRepositoryInstance(elementP);
  	}
  };  
}
 
