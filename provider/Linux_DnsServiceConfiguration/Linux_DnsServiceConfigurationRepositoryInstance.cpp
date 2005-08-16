 /**
 * Linux_DnsServiceConfigurationRepositoryInstance.cpp
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
#include "Linux_DnsServiceConfigurationRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsServiceConfigurationRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsServiceConfigurationRepositoryInstance::
   Linux_DnsServiceConfigurationRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsServiceConfigurationRepositoryInstance::
   Linux_DnsServiceConfigurationRepositoryInstance
   (const Linux_DnsServiceConfigurationRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsServiceConfigurationRepositoryInstance::
   Linux_DnsServiceConfigurationRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsServiceConfigurationInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsServiceConfigurationRepositoryInstance::
   ~Linux_DnsServiceConfigurationRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsServiceConfigurationRepositoryInstance&
   Linux_DnsServiceConfigurationRepositoryInstance::operator=
   (const Linux_DnsServiceConfigurationRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsServiceConfigurationRepositoryInstance::
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
  unsigned int Linux_DnsServiceConfigurationRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsServiceConfigurationInstanceName&
    Linux_DnsServiceConfigurationRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsServiceConfiguration instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsServiceConfigurationRepositoryInstance::setInstanceName(
   const Linux_DnsServiceConfigurationInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsServiceConfigurationRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsServiceConfigurationRepositoryInstance::init
   (const Linux_DnsServiceConfigurationRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsServiceConfigurationRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement::
   Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement::
   ~Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsServiceConfigurationRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsServiceConfigurationRepositoryInstanceEnumeration::
   Linux_DnsServiceConfigurationRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsServiceConfigurationRepositoryInstanceEnumeration::
   Linux_DnsServiceConfigurationRepositoryInstanceEnumeration(
   const Linux_DnsServiceConfigurationRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsServiceConfigurationRepositoryInstanceEnumeration::
   ~Linux_DnsServiceConfigurationRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsServiceConfigurationRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsServiceConfigurationRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsServiceConfigurationRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsServiceConfigurationRepositoryInstance&  
   Linux_DnsServiceConfigurationRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsServiceConfigurationRepositoryInstance&
   Linux_DnsServiceConfigurationRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsServiceConfigurationRepositoryInstanceEnumeration::addElement
   (const Linux_DnsServiceConfigurationRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsServiceConfigurationRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsServiceConfigurationRepositoryInstance(elementP);
  	}
  };  
}
 
