 /**
 * Linux_DnsElementSettingInstance.cpp
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
#include "Linux_DnsElementSettingInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsElementSettingInstance
  //*********************************************************

  //empty constructor
  Linux_DnsElementSettingInstance::
   Linux_DnsElementSettingInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsElementSettingInstance::
   Linux_DnsElementSettingInstance
   (const Linux_DnsElementSettingInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsElementSettingInstance::
   Linux_DnsElementSettingInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsElementSettingInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsElementSettingInstance::
   ~Linux_DnsElementSettingInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsElementSettingInstance&
   Linux_DnsElementSettingInstance::operator=
   (const Linux_DnsElementSettingInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsElementSettingInstance::
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
  unsigned int Linux_DnsElementSettingInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsElementSettingInstanceName&
    Linux_DnsElementSettingInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsElementSetting instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsElementSettingInstance::setInstanceName(
   const Linux_DnsElementSettingInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsElementSettingInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsElementSettingInstance::init
   (const Linux_DnsElementSettingInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsElementSettingInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsElementSettingInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsElementSettingInstanceEnumerationElement::
   Linux_DnsElementSettingInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsElementSettingInstanceEnumerationElement::
   ~Linux_DnsElementSettingInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsElementSettingInstanceNameEnumeration
  //*********************************************************

  Linux_DnsElementSettingInstanceEnumeration::
   Linux_DnsElementSettingInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsElementSettingInstanceEnumeration::
   Linux_DnsElementSettingInstanceEnumeration(
   const Linux_DnsElementSettingInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsElementSettingInstanceEnumeration::
   ~Linux_DnsElementSettingInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsElementSettingInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsElementSettingInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsElementSettingInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsElementSettingInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsElementSettingInstance&  
   Linux_DnsElementSettingInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsElementSettingInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsElementSettingInstance&
   Linux_DnsElementSettingInstanceEnumeration::getNext() {
   	
  	 Linux_DnsElementSettingInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsElementSettingInstanceEnumeration::addElement
   (const Linux_DnsElementSettingInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsElementSettingInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsElementSettingInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsElementSettingInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsElementSettingInstance(elementP);
  	}
  };  
}
 
