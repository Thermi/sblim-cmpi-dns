 /**
 * Linux_DnsElementSettingRepositoryInstance.cpp
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
#include "Linux_DnsElementSettingRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsElementSettingRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsElementSettingRepositoryInstance::
   Linux_DnsElementSettingRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsElementSettingRepositoryInstance::
   Linux_DnsElementSettingRepositoryInstance
   (const Linux_DnsElementSettingRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsElementSettingRepositoryInstance::
   Linux_DnsElementSettingRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsElementSettingInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsElementSettingRepositoryInstance::
   ~Linux_DnsElementSettingRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsElementSettingRepositoryInstance&
   Linux_DnsElementSettingRepositoryInstance::operator=
   (const Linux_DnsElementSettingRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsElementSettingRepositoryInstance::
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
  unsigned int Linux_DnsElementSettingRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsElementSettingInstanceName&
    Linux_DnsElementSettingRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsElementSetting instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsElementSettingRepositoryInstance::setInstanceName(
   const Linux_DnsElementSettingInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsElementSettingRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsElementSettingRepositoryInstance::init
   (const Linux_DnsElementSettingRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsElementSettingRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsElementSettingRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsElementSettingRepositoryInstanceEnumerationElement::
   Linux_DnsElementSettingRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsElementSettingRepositoryInstanceEnumerationElement::
   ~Linux_DnsElementSettingRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsElementSettingRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsElementSettingRepositoryInstanceEnumeration::
   Linux_DnsElementSettingRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsElementSettingRepositoryInstanceEnumeration::
   Linux_DnsElementSettingRepositoryInstanceEnumeration(
   const Linux_DnsElementSettingRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsElementSettingRepositoryInstanceEnumeration::
   ~Linux_DnsElementSettingRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsElementSettingRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsElementSettingRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsElementSettingRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsElementSettingRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsElementSettingRepositoryInstance&  
   Linux_DnsElementSettingRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsElementSettingRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsElementSettingRepositoryInstance&
   Linux_DnsElementSettingRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsElementSettingRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsElementSettingRepositoryInstanceEnumeration::addElement
   (const Linux_DnsElementSettingRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsElementSettingRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsElementSettingRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsElementSettingRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsElementSettingRepositoryInstance(elementP);
  	}
  };  
}
 
