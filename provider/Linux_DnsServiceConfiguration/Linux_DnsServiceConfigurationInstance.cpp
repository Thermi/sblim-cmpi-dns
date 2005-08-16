 /**
 * Linux_DnsServiceConfigurationInstance.cpp
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
#include "Linux_DnsServiceConfigurationInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsServiceConfigurationInstance
  //*********************************************************

  //empty constructor
  Linux_DnsServiceConfigurationInstance::
   Linux_DnsServiceConfigurationInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsServiceConfigurationInstance::
   Linux_DnsServiceConfigurationInstance
   (const Linux_DnsServiceConfigurationInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsServiceConfigurationInstance::
   Linux_DnsServiceConfigurationInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsServiceConfigurationInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsServiceConfigurationInstance::
   ~Linux_DnsServiceConfigurationInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsServiceConfigurationInstance&
   Linux_DnsServiceConfigurationInstance::operator=
   (const Linux_DnsServiceConfigurationInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsServiceConfigurationInstance::
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
  unsigned int Linux_DnsServiceConfigurationInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsServiceConfigurationInstanceName&
    Linux_DnsServiceConfigurationInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsServiceConfiguration instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsServiceConfigurationInstance::setInstanceName(
   const Linux_DnsServiceConfigurationInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsServiceConfigurationInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsServiceConfigurationInstance::init
   (const Linux_DnsServiceConfigurationInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsServiceConfigurationInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsServiceConfigurationInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsServiceConfigurationInstanceEnumerationElement::
   Linux_DnsServiceConfigurationInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsServiceConfigurationInstanceEnumerationElement::
   ~Linux_DnsServiceConfigurationInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsServiceConfigurationInstanceNameEnumeration
  //*********************************************************

  Linux_DnsServiceConfigurationInstanceEnumeration::
   Linux_DnsServiceConfigurationInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsServiceConfigurationInstanceEnumeration::
   Linux_DnsServiceConfigurationInstanceEnumeration(
   const Linux_DnsServiceConfigurationInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsServiceConfigurationInstanceEnumeration::
   ~Linux_DnsServiceConfigurationInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsServiceConfigurationInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsServiceConfigurationInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsServiceConfigurationInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsServiceConfigurationInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsServiceConfigurationInstance&  
   Linux_DnsServiceConfigurationInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsServiceConfigurationInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsServiceConfigurationInstance&
   Linux_DnsServiceConfigurationInstanceEnumeration::getNext() {
   	
  	 Linux_DnsServiceConfigurationInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsServiceConfigurationInstanceEnumeration::addElement
   (const Linux_DnsServiceConfigurationInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsServiceConfigurationInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsServiceConfigurationInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsServiceConfigurationInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsServiceConfigurationInstance(elementP);
  	}
  };  
}
 
