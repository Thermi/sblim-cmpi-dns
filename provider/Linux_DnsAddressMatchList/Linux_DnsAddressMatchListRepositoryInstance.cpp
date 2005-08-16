 /**
 * Linux_DnsAddressMatchListRepositoryInstance.cpp
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
#include "Linux_DnsAddressMatchListRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAddressMatchListRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAddressMatchListRepositoryInstance::
   Linux_DnsAddressMatchListRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAddressMatchListRepositoryInstance::
   Linux_DnsAddressMatchListRepositoryInstance
   (const Linux_DnsAddressMatchListRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAddressMatchListRepositoryInstance::
   Linux_DnsAddressMatchListRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAddressMatchListInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAddressMatchListRepositoryInstance::
   ~Linux_DnsAddressMatchListRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAddressMatchListRepositoryInstance&
   Linux_DnsAddressMatchListRepositoryInstance::operator=
   (const Linux_DnsAddressMatchListRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAddressMatchListRepositoryInstance::
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
  unsigned int Linux_DnsAddressMatchListRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAddressMatchListInstanceName&
    Linux_DnsAddressMatchListRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAddressMatchList instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAddressMatchListRepositoryInstance::setInstanceName(
   const Linux_DnsAddressMatchListInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAddressMatchListRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAddressMatchListRepositoryInstance::init
   (const Linux_DnsAddressMatchListRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAddressMatchListRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement::
   Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement::
   ~Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAddressMatchListRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAddressMatchListRepositoryInstanceEnumeration::
   Linux_DnsAddressMatchListRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAddressMatchListRepositoryInstanceEnumeration::
   Linux_DnsAddressMatchListRepositoryInstanceEnumeration(
   const Linux_DnsAddressMatchListRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAddressMatchListRepositoryInstanceEnumeration::
   ~Linux_DnsAddressMatchListRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAddressMatchListRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAddressMatchListRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAddressMatchListRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAddressMatchListRepositoryInstance&  
   Linux_DnsAddressMatchListRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAddressMatchListRepositoryInstance&
   Linux_DnsAddressMatchListRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAddressMatchListRepositoryInstanceEnumeration::addElement
   (const Linux_DnsAddressMatchListRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAddressMatchListRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAddressMatchListRepositoryInstance(elementP);
  	}
  };  
}
 
