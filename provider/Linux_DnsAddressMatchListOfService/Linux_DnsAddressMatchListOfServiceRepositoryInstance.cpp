 /**
 * Linux_DnsAddressMatchListOfServiceRepositoryInstance.cpp
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
#include "Linux_DnsAddressMatchListOfServiceRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAddressMatchListOfServiceRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAddressMatchListOfServiceRepositoryInstance::
   Linux_DnsAddressMatchListOfServiceRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAddressMatchListOfServiceRepositoryInstance::
   Linux_DnsAddressMatchListOfServiceRepositoryInstance
   (const Linux_DnsAddressMatchListOfServiceRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAddressMatchListOfServiceRepositoryInstance::
   Linux_DnsAddressMatchListOfServiceRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAddressMatchListOfServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAddressMatchListOfServiceRepositoryInstance::
   ~Linux_DnsAddressMatchListOfServiceRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAddressMatchListOfServiceRepositoryInstance&
   Linux_DnsAddressMatchListOfServiceRepositoryInstance::operator=
   (const Linux_DnsAddressMatchListOfServiceRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAddressMatchListOfServiceRepositoryInstance::
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
  unsigned int Linux_DnsAddressMatchListOfServiceRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAddressMatchListOfServiceInstanceName&
    Linux_DnsAddressMatchListOfServiceRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAddressMatchListOfService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAddressMatchListOfServiceRepositoryInstance::setInstanceName(
   const Linux_DnsAddressMatchListOfServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAddressMatchListOfServiceRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAddressMatchListOfServiceRepositoryInstance::init
   (const Linux_DnsAddressMatchListOfServiceRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAddressMatchListOfServiceRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement::
   Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement::
   ~Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAddressMatchListOfServiceRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration::
   Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration::
   Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration(
   const Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration::
   ~Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAddressMatchListOfServiceRepositoryInstance&  
   Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAddressMatchListOfServiceRepositoryInstance&
   Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration::addElement
   (const Linux_DnsAddressMatchListOfServiceRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAddressMatchListOfServiceRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAddressMatchListOfServiceRepositoryInstance(elementP);
  	}
  };  
}
 
