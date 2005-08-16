 /**
 * Linux_DnsSettingContextInstance.cpp
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
#include "Linux_DnsSettingContextInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsSettingContextInstance
  //*********************************************************

  //empty constructor
  Linux_DnsSettingContextInstance::
   Linux_DnsSettingContextInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsSettingContextInstance::
   Linux_DnsSettingContextInstance
   (const Linux_DnsSettingContextInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsSettingContextInstance::
   Linux_DnsSettingContextInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsSettingContextInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsSettingContextInstance::
   ~Linux_DnsSettingContextInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSettingContextInstance&
   Linux_DnsSettingContextInstance::operator=
   (const Linux_DnsSettingContextInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsSettingContextInstance::
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
  unsigned int Linux_DnsSettingContextInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsSettingContextInstanceName&
    Linux_DnsSettingContextInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsSettingContext instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsSettingContextInstance::setInstanceName(
   const Linux_DnsSettingContextInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsSettingContextInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsSettingContextInstance::init
   (const Linux_DnsSettingContextInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsSettingContextInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsSettingContextInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsSettingContextInstanceEnumerationElement::
   Linux_DnsSettingContextInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSettingContextInstanceEnumerationElement::
   ~Linux_DnsSettingContextInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSettingContextInstanceNameEnumeration
  //*********************************************************

  Linux_DnsSettingContextInstanceEnumeration::
   Linux_DnsSettingContextInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSettingContextInstanceEnumeration::
   Linux_DnsSettingContextInstanceEnumeration(
   const Linux_DnsSettingContextInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSettingContextInstanceEnumeration::
   ~Linux_DnsSettingContextInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSettingContextInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSettingContextInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSettingContextInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSettingContextInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsSettingContextInstance&  
   Linux_DnsSettingContextInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsSettingContextInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSettingContextInstance&
   Linux_DnsSettingContextInstanceEnumeration::getNext() {
   	
  	 Linux_DnsSettingContextInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSettingContextInstanceEnumeration::addElement
   (const Linux_DnsSettingContextInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSettingContextInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSettingContextInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSettingContextInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSettingContextInstance(elementP);
  	}
  };  
}
 
