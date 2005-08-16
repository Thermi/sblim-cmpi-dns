 /**
 * Linux_DnsSettingContextRepositoryInstance.cpp
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
#include "Linux_DnsSettingContextRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsSettingContextRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsSettingContextRepositoryInstance::
   Linux_DnsSettingContextRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsSettingContextRepositoryInstance::
   Linux_DnsSettingContextRepositoryInstance
   (const Linux_DnsSettingContextRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsSettingContextRepositoryInstance::
   Linux_DnsSettingContextRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsSettingContextInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsSettingContextRepositoryInstance::
   ~Linux_DnsSettingContextRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSettingContextRepositoryInstance&
   Linux_DnsSettingContextRepositoryInstance::operator=
   (const Linux_DnsSettingContextRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsSettingContextRepositoryInstance::
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
  unsigned int Linux_DnsSettingContextRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsSettingContextInstanceName&
    Linux_DnsSettingContextRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsSettingContext instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsSettingContextRepositoryInstance::setInstanceName(
   const Linux_DnsSettingContextInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsSettingContextRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsSettingContextRepositoryInstance::init
   (const Linux_DnsSettingContextRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsSettingContextRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsSettingContextRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsSettingContextRepositoryInstanceEnumerationElement::
   Linux_DnsSettingContextRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSettingContextRepositoryInstanceEnumerationElement::
   ~Linux_DnsSettingContextRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSettingContextRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsSettingContextRepositoryInstanceEnumeration::
   Linux_DnsSettingContextRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSettingContextRepositoryInstanceEnumeration::
   Linux_DnsSettingContextRepositoryInstanceEnumeration(
   const Linux_DnsSettingContextRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSettingContextRepositoryInstanceEnumeration::
   ~Linux_DnsSettingContextRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSettingContextRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSettingContextRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSettingContextRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSettingContextRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsSettingContextRepositoryInstance&  
   Linux_DnsSettingContextRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsSettingContextRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSettingContextRepositoryInstance&
   Linux_DnsSettingContextRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsSettingContextRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSettingContextRepositoryInstanceEnumeration::addElement
   (const Linux_DnsSettingContextRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSettingContextRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSettingContextRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSettingContextRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSettingContextRepositoryInstance(elementP);
  	}
  };  
}
 
