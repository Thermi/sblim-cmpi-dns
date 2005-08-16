 /**
 * Linux_DnsAllowNotifyACLForZoneRepositoryInstance.cpp
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
#include "Linux_DnsAllowNotifyACLForZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowNotifyACLForZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowNotifyACLForZoneRepositoryInstance::
   Linux_DnsAllowNotifyACLForZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowNotifyACLForZoneRepositoryInstance::
   Linux_DnsAllowNotifyACLForZoneRepositoryInstance
   (const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowNotifyACLForZoneRepositoryInstance::
   Linux_DnsAllowNotifyACLForZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowNotifyACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowNotifyACLForZoneRepositoryInstance::
   ~Linux_DnsAllowNotifyACLForZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowNotifyACLForZoneRepositoryInstance&
   Linux_DnsAllowNotifyACLForZoneRepositoryInstance::operator=
   (const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowNotifyACLForZoneRepositoryInstance::
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
  unsigned int Linux_DnsAllowNotifyACLForZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowNotifyACLForZoneInstanceName&
    Linux_DnsAllowNotifyACLForZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowNotifyACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowNotifyACLForZoneRepositoryInstance::setInstanceName(
   const Linux_DnsAllowNotifyACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowNotifyACLForZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowNotifyACLForZoneRepositoryInstance::init
   (const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowNotifyACLForZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement::
   Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowNotifyACLForZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration::
   Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration::
   Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration(
   const Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration::
   ~Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowNotifyACLForZoneRepositoryInstance&  
   Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowNotifyACLForZoneRepositoryInstance&
   Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowNotifyACLForZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowNotifyACLForZoneRepositoryInstance(elementP);
  	}
  };  
}
 
