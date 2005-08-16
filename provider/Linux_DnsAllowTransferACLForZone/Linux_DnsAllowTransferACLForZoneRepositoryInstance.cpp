 /**
 * Linux_DnsAllowTransferACLForZoneRepositoryInstance.cpp
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
#include "Linux_DnsAllowTransferACLForZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowTransferACLForZoneRepositoryInstance::
   Linux_DnsAllowTransferACLForZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowTransferACLForZoneRepositoryInstance::
   Linux_DnsAllowTransferACLForZoneRepositoryInstance
   (const Linux_DnsAllowTransferACLForZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowTransferACLForZoneRepositoryInstance::
   Linux_DnsAllowTransferACLForZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowTransferACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowTransferACLForZoneRepositoryInstance::
   ~Linux_DnsAllowTransferACLForZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowTransferACLForZoneRepositoryInstance&
   Linux_DnsAllowTransferACLForZoneRepositoryInstance::operator=
   (const Linux_DnsAllowTransferACLForZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowTransferACLForZoneRepositoryInstance::
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
  unsigned int Linux_DnsAllowTransferACLForZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowTransferACLForZoneInstanceName&
    Linux_DnsAllowTransferACLForZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowTransferACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowTransferACLForZoneRepositoryInstance::setInstanceName(
   const Linux_DnsAllowTransferACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowTransferACLForZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowTransferACLForZoneRepositoryInstance::init
   (const Linux_DnsAllowTransferACLForZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowTransferACLForZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement::
   Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration::
   Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration::
   Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration(
   const Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration::
   ~Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowTransferACLForZoneRepositoryInstance&  
   Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowTransferACLForZoneRepositoryInstance&
   Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsAllowTransferACLForZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowTransferACLForZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowTransferACLForZoneRepositoryInstance(elementP);
  	}
  };  
}
 
