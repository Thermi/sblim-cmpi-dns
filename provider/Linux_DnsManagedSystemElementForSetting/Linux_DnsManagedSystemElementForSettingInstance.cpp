 /**
 * Linux_DnsManagedSystemElementForSettingInstance.cpp
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
#include "Linux_DnsManagedSystemElementForSettingInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsManagedSystemElementForSettingInstance
  //*********************************************************

  //empty constructor
  Linux_DnsManagedSystemElementForSettingInstance::
   Linux_DnsManagedSystemElementForSettingInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsManagedSystemElementForSettingInstance::
   Linux_DnsManagedSystemElementForSettingInstance
   (const Linux_DnsManagedSystemElementForSettingInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsManagedSystemElementForSettingInstance::
   Linux_DnsManagedSystemElementForSettingInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsManagedSystemElementForSettingInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsManagedSystemElementForSettingInstance::
   ~Linux_DnsManagedSystemElementForSettingInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsManagedSystemElementForSettingInstance&
   Linux_DnsManagedSystemElementForSettingInstance::operator=
   (const Linux_DnsManagedSystemElementForSettingInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsManagedSystemElementForSettingInstance::
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
  unsigned int Linux_DnsManagedSystemElementForSettingInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsManagedSystemElementForSettingInstanceName&
    Linux_DnsManagedSystemElementForSettingInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsManagedSystemElementForSetting instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsManagedSystemElementForSettingInstance::setInstanceName(
   const Linux_DnsManagedSystemElementForSettingInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsManagedSystemElementForSettingInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsManagedSystemElementForSettingInstance::init
   (const Linux_DnsManagedSystemElementForSettingInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsManagedSystemElementForSettingInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement::
   Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement::
   ~Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration
  //*********************************************************

  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::
   Linux_DnsManagedSystemElementForSettingInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::
   Linux_DnsManagedSystemElementForSettingInstanceEnumeration(
   const Linux_DnsManagedSystemElementForSettingInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::
   ~Linux_DnsManagedSystemElementForSettingInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsManagedSystemElementForSettingInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsManagedSystemElementForSettingInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsManagedSystemElementForSettingInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsManagedSystemElementForSettingInstance&  
   Linux_DnsManagedSystemElementForSettingInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsManagedSystemElementForSettingInstance&
   Linux_DnsManagedSystemElementForSettingInstanceEnumeration::getNext() {
   	
  	 Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsManagedSystemElementForSettingInstanceEnumeration::addElement
   (const Linux_DnsManagedSystemElementForSettingInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsManagedSystemElementForSettingInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsManagedSystemElementForSettingInstance(elementP);
  	}
  };  
}
 
