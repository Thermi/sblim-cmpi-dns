 /**
 * Linux_DnsResourceRecordRepositoryInstance.cpp
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
#include "Linux_DnsResourceRecordRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsResourceRecordRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsResourceRecordRepositoryInstance::
   Linux_DnsResourceRecordRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsResourceRecordRepositoryInstance::
   Linux_DnsResourceRecordRepositoryInstance
   (const Linux_DnsResourceRecordRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsResourceRecordRepositoryInstance::
   Linux_DnsResourceRecordRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsResourceRecordInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsResourceRecordRepositoryInstance::
   ~Linux_DnsResourceRecordRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsResourceRecordRepositoryInstance&
   Linux_DnsResourceRecordRepositoryInstance::operator=
   (const Linux_DnsResourceRecordRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsResourceRecordRepositoryInstance::
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
  unsigned int Linux_DnsResourceRecordRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsResourceRecordInstanceName&
    Linux_DnsResourceRecordRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsResourceRecord instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsResourceRecordRepositoryInstance::setInstanceName(
   const Linux_DnsResourceRecordInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsResourceRecordRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsResourceRecordRepositoryInstance::init
   (const Linux_DnsResourceRecordRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsResourceRecordRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsResourceRecordRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsResourceRecordRepositoryInstanceEnumerationElement::
   Linux_DnsResourceRecordRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsResourceRecordRepositoryInstanceEnumerationElement::
   ~Linux_DnsResourceRecordRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsResourceRecordRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsResourceRecordRepositoryInstanceEnumeration::
   Linux_DnsResourceRecordRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsResourceRecordRepositoryInstanceEnumeration::
   Linux_DnsResourceRecordRepositoryInstanceEnumeration(
   const Linux_DnsResourceRecordRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsResourceRecordRepositoryInstanceEnumeration::
   ~Linux_DnsResourceRecordRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsResourceRecordRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsResourceRecordRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsResourceRecordRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsResourceRecordRepositoryInstance&  
   Linux_DnsResourceRecordRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsResourceRecordRepositoryInstance&
   Linux_DnsResourceRecordRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsResourceRecordRepositoryInstanceEnumeration::addElement
   (const Linux_DnsResourceRecordRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsResourceRecordRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsResourceRecordRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsResourceRecordRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsResourceRecordRepositoryInstance(elementP);
  	}
  };  
}
 
