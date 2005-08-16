 /**
 * Linux_DnsServiceConfigurationManualInstance.cpp
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
#include "Linux_DnsServiceConfigurationManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsServiceConfigurationManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsServiceConfigurationManualInstance::
   Linux_DnsServiceConfigurationManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsServiceConfigurationManualInstance::
   Linux_DnsServiceConfigurationManualInstance
   (const Linux_DnsServiceConfigurationManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsServiceConfigurationManualInstance::
   Linux_DnsServiceConfigurationManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsServiceConfigurationInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsServiceConfigurationManualInstance::
   ~Linux_DnsServiceConfigurationManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsServiceConfigurationManualInstance&
   Linux_DnsServiceConfigurationManualInstance::operator=
   (const Linux_DnsServiceConfigurationManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsServiceConfigurationManualInstance::
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
  unsigned int Linux_DnsServiceConfigurationManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsServiceConfigurationInstanceName&
    Linux_DnsServiceConfigurationManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsServiceConfiguration instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsServiceConfigurationManualInstance::setInstanceName(
   const Linux_DnsServiceConfigurationInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsServiceConfigurationManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsServiceConfigurationManualInstance::init
   (const Linux_DnsServiceConfigurationManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsServiceConfigurationManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsServiceConfigurationManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsServiceConfigurationManualInstanceEnumerationElement::
   Linux_DnsServiceConfigurationManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsServiceConfigurationManualInstanceEnumerationElement::
   ~Linux_DnsServiceConfigurationManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsServiceConfigurationManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsServiceConfigurationManualInstanceEnumeration::
   Linux_DnsServiceConfigurationManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsServiceConfigurationManualInstanceEnumeration::
   Linux_DnsServiceConfigurationManualInstanceEnumeration(
   const Linux_DnsServiceConfigurationManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsServiceConfigurationManualInstanceEnumeration::
   ~Linux_DnsServiceConfigurationManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsServiceConfigurationManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsServiceConfigurationManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsServiceConfigurationManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsServiceConfigurationManualInstance&  
   Linux_DnsServiceConfigurationManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsServiceConfigurationManualInstance&
   Linux_DnsServiceConfigurationManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsServiceConfigurationManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsServiceConfigurationManualInstanceEnumeration::addElement
   (const Linux_DnsServiceConfigurationManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsServiceConfigurationManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsServiceConfigurationManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsServiceConfigurationManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsServiceConfigurationManualInstance(elementP);
  	}
  };  
}
 
