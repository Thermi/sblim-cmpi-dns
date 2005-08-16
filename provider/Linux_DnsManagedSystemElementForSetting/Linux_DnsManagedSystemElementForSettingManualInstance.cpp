 /**
 * Linux_DnsManagedSystemElementForSettingManualInstance.cpp
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
#include "Linux_DnsManagedSystemElementForSettingManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsManagedSystemElementForSettingManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsManagedSystemElementForSettingManualInstance::
   Linux_DnsManagedSystemElementForSettingManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsManagedSystemElementForSettingManualInstance::
   Linux_DnsManagedSystemElementForSettingManualInstance
   (const Linux_DnsManagedSystemElementForSettingManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsManagedSystemElementForSettingManualInstance::
   Linux_DnsManagedSystemElementForSettingManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsManagedSystemElementForSettingInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsManagedSystemElementForSettingManualInstance::
   ~Linux_DnsManagedSystemElementForSettingManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsManagedSystemElementForSettingManualInstance&
   Linux_DnsManagedSystemElementForSettingManualInstance::operator=
   (const Linux_DnsManagedSystemElementForSettingManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsManagedSystemElementForSettingManualInstance::
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
  unsigned int Linux_DnsManagedSystemElementForSettingManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsManagedSystemElementForSettingInstanceName&
    Linux_DnsManagedSystemElementForSettingManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsManagedSystemElementForSetting instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsManagedSystemElementForSettingManualInstance::setInstanceName(
   const Linux_DnsManagedSystemElementForSettingInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsManagedSystemElementForSettingManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsManagedSystemElementForSettingManualInstance::init
   (const Linux_DnsManagedSystemElementForSettingManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsManagedSystemElementForSettingManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement::
   Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement::
   ~Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsManagedSystemElementForSettingManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration::
   Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration::
   Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration(
   const Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration::
   ~Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsManagedSystemElementForSettingManualInstance&  
   Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsManagedSystemElementForSettingManualInstance&
   Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration::addElement
   (const Linux_DnsManagedSystemElementForSettingManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsManagedSystemElementForSettingManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsManagedSystemElementForSettingManualInstance(elementP);
  	}
  };  
}
 
