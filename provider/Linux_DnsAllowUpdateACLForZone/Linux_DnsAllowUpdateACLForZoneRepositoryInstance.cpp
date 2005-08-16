 /**
 * Linux_DnsAllowUpdateACLForZoneRepositoryInstance.cpp
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
#include "Linux_DnsAllowUpdateACLForZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowUpdateACLForZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowUpdateACLForZoneRepositoryInstance::
   Linux_DnsAllowUpdateACLForZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowUpdateACLForZoneRepositoryInstance::
   Linux_DnsAllowUpdateACLForZoneRepositoryInstance
   (const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowUpdateACLForZoneRepositoryInstance::
   Linux_DnsAllowUpdateACLForZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowUpdateACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowUpdateACLForZoneRepositoryInstance::
   ~Linux_DnsAllowUpdateACLForZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowUpdateACLForZoneRepositoryInstance&
   Linux_DnsAllowUpdateACLForZoneRepositoryInstance::operator=
   (const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowUpdateACLForZoneRepositoryInstance::
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
  unsigned int Linux_DnsAllowUpdateACLForZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowUpdateACLForZoneInstanceName&
    Linux_DnsAllowUpdateACLForZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowUpdateACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowUpdateACLForZoneRepositoryInstance::setInstanceName(
   const Linux_DnsAllowUpdateACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowUpdateACLForZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowUpdateACLForZoneRepositoryInstance::init
   (const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowUpdateACLForZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement::
   Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowUpdateACLForZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration::
   Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration::
   Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration(
   const Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration::
   ~Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowUpdateACLForZoneRepositoryInstance&  
   Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowUpdateACLForZoneRepositoryInstance&
   Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowUpdateACLForZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowUpdateACLForZoneRepositoryInstance(elementP);
  	}
  };  
}
 
