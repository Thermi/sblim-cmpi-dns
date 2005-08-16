 /**
 * Linux_DnsManagedSystemElementForSettingRepositoryInstance.cpp
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
#include "Linux_DnsManagedSystemElementForSettingRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsManagedSystemElementForSettingRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::
   Linux_DnsManagedSystemElementForSettingRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::
   Linux_DnsManagedSystemElementForSettingRepositoryInstance
   (const Linux_DnsManagedSystemElementForSettingRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::
   Linux_DnsManagedSystemElementForSettingRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsManagedSystemElementForSettingInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::
   ~Linux_DnsManagedSystemElementForSettingRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsManagedSystemElementForSettingRepositoryInstance&
   Linux_DnsManagedSystemElementForSettingRepositoryInstance::operator=
   (const Linux_DnsManagedSystemElementForSettingRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsManagedSystemElementForSettingRepositoryInstance::
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
  unsigned int Linux_DnsManagedSystemElementForSettingRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsManagedSystemElementForSettingInstanceName&
    Linux_DnsManagedSystemElementForSettingRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsManagedSystemElementForSetting instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsManagedSystemElementForSettingRepositoryInstance::setInstanceName(
   const Linux_DnsManagedSystemElementForSettingInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsManagedSystemElementForSettingRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsManagedSystemElementForSettingRepositoryInstance::init
   (const Linux_DnsManagedSystemElementForSettingRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsManagedSystemElementForSettingRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement::
   Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement::
   ~Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsManagedSystemElementForSettingRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::
   Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::
   Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration(
   const Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::
   ~Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsManagedSystemElementForSettingRepositoryInstance&  
   Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsManagedSystemElementForSettingRepositoryInstance&
   Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::addElement
   (const Linux_DnsManagedSystemElementForSettingRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsManagedSystemElementForSettingRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsManagedSystemElementForSettingRepositoryInstance(elementP);
  	}
  };  
}
 
