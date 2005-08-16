 /**
 * Linux_DnsConfigurationRepositoryInstance.cpp
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
#include "Linux_DnsConfigurationRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsConfigurationRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsConfigurationRepositoryInstance::
   Linux_DnsConfigurationRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsConfigurationRepositoryInstance::
   Linux_DnsConfigurationRepositoryInstance
   (const Linux_DnsConfigurationRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsConfigurationRepositoryInstance::
   Linux_DnsConfigurationRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsConfigurationInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsConfigurationRepositoryInstance::
   ~Linux_DnsConfigurationRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsConfigurationRepositoryInstance&
   Linux_DnsConfigurationRepositoryInstance::operator=
   (const Linux_DnsConfigurationRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsConfigurationRepositoryInstance::
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
  unsigned int Linux_DnsConfigurationRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsConfigurationInstanceName&
    Linux_DnsConfigurationRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsConfiguration instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsConfigurationRepositoryInstance::setInstanceName(
   const Linux_DnsConfigurationInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsConfigurationRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsConfigurationRepositoryInstance::init
   (const Linux_DnsConfigurationRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsConfigurationRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsConfigurationRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsConfigurationRepositoryInstanceEnumerationElement::
   Linux_DnsConfigurationRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsConfigurationRepositoryInstanceEnumerationElement::
   ~Linux_DnsConfigurationRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsConfigurationRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsConfigurationRepositoryInstanceEnumeration::
   Linux_DnsConfigurationRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsConfigurationRepositoryInstanceEnumeration::
   Linux_DnsConfigurationRepositoryInstanceEnumeration(
   const Linux_DnsConfigurationRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsConfigurationRepositoryInstanceEnumeration::
   ~Linux_DnsConfigurationRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsConfigurationRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsConfigurationRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsConfigurationRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsConfigurationRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsConfigurationRepositoryInstance&  
   Linux_DnsConfigurationRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsConfigurationRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsConfigurationRepositoryInstance&
   Linux_DnsConfigurationRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsConfigurationRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsConfigurationRepositoryInstanceEnumeration::addElement
   (const Linux_DnsConfigurationRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsConfigurationRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsConfigurationRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsConfigurationRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsConfigurationRepositoryInstance(elementP);
  	}
  };  
}
 
