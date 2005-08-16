 /**
 * Linux_DnsSettingRepositoryInstance.cpp
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
#include "Linux_DnsSettingRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsSettingRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsSettingRepositoryInstance::
   Linux_DnsSettingRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsSettingRepositoryInstance::
   Linux_DnsSettingRepositoryInstance
   (const Linux_DnsSettingRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsSettingRepositoryInstance::
   Linux_DnsSettingRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsSettingInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsSettingRepositoryInstance::
   ~Linux_DnsSettingRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSettingRepositoryInstance&
   Linux_DnsSettingRepositoryInstance::operator=
   (const Linux_DnsSettingRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsSettingRepositoryInstance::
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
  unsigned int Linux_DnsSettingRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsSettingInstanceName&
    Linux_DnsSettingRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsSetting instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsSettingRepositoryInstance::setInstanceName(
   const Linux_DnsSettingInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsSettingRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsSettingRepositoryInstance::init
   (const Linux_DnsSettingRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsSettingRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsSettingRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsSettingRepositoryInstanceEnumerationElement::
   Linux_DnsSettingRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSettingRepositoryInstanceEnumerationElement::
   ~Linux_DnsSettingRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSettingRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsSettingRepositoryInstanceEnumeration::
   Linux_DnsSettingRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSettingRepositoryInstanceEnumeration::
   Linux_DnsSettingRepositoryInstanceEnumeration(
   const Linux_DnsSettingRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSettingRepositoryInstanceEnumeration::
   ~Linux_DnsSettingRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSettingRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSettingRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSettingRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSettingRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsSettingRepositoryInstance&  
   Linux_DnsSettingRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsSettingRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSettingRepositoryInstance&
   Linux_DnsSettingRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsSettingRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSettingRepositoryInstanceEnumeration::addElement
   (const Linux_DnsSettingRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSettingRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSettingRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSettingRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSettingRepositoryInstance(elementP);
  	}
  };  
}
 
