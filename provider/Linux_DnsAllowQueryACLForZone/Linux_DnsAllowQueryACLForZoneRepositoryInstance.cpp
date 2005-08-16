 /**
 * Linux_DnsAllowQueryACLForZoneRepositoryInstance.cpp
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
#include "Linux_DnsAllowQueryACLForZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowQueryACLForZoneRepositoryInstance::
   Linux_DnsAllowQueryACLForZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowQueryACLForZoneRepositoryInstance::
   Linux_DnsAllowQueryACLForZoneRepositoryInstance
   (const Linux_DnsAllowQueryACLForZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowQueryACLForZoneRepositoryInstance::
   Linux_DnsAllowQueryACLForZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowQueryACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowQueryACLForZoneRepositoryInstance::
   ~Linux_DnsAllowQueryACLForZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowQueryACLForZoneRepositoryInstance&
   Linux_DnsAllowQueryACLForZoneRepositoryInstance::operator=
   (const Linux_DnsAllowQueryACLForZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowQueryACLForZoneRepositoryInstance::
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
  unsigned int Linux_DnsAllowQueryACLForZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowQueryACLForZoneInstanceName&
    Linux_DnsAllowQueryACLForZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowQueryACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowQueryACLForZoneRepositoryInstance::setInstanceName(
   const Linux_DnsAllowQueryACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowQueryACLForZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowQueryACLForZoneRepositoryInstance::init
   (const Linux_DnsAllowQueryACLForZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowQueryACLForZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement::
   Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration::
   Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration::
   Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration(
   const Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration::
   ~Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowQueryACLForZoneRepositoryInstance&  
   Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowQueryACLForZoneRepositoryInstance&
   Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsAllowQueryACLForZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowQueryACLForZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowQueryACLForZoneRepositoryInstance(elementP);
  	}
  };  
}
 
