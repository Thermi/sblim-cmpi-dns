 /**
 * Linux_DnsSettingContextManualInstance.cpp
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
#include "Linux_DnsSettingContextManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsSettingContextManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsSettingContextManualInstance::
   Linux_DnsSettingContextManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsSettingContextManualInstance::
   Linux_DnsSettingContextManualInstance
   (const Linux_DnsSettingContextManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsSettingContextManualInstance::
   Linux_DnsSettingContextManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsSettingContextInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsSettingContextManualInstance::
   ~Linux_DnsSettingContextManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSettingContextManualInstance&
   Linux_DnsSettingContextManualInstance::operator=
   (const Linux_DnsSettingContextManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsSettingContextManualInstance::
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
  unsigned int Linux_DnsSettingContextManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsSettingContextInstanceName&
    Linux_DnsSettingContextManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsSettingContext instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsSettingContextManualInstance::setInstanceName(
   const Linux_DnsSettingContextInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsSettingContextManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsSettingContextManualInstance::init
   (const Linux_DnsSettingContextManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsSettingContextManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsSettingContextManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsSettingContextManualInstanceEnumerationElement::
   Linux_DnsSettingContextManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSettingContextManualInstanceEnumerationElement::
   ~Linux_DnsSettingContextManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSettingContextManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsSettingContextManualInstanceEnumeration::
   Linux_DnsSettingContextManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSettingContextManualInstanceEnumeration::
   Linux_DnsSettingContextManualInstanceEnumeration(
   const Linux_DnsSettingContextManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSettingContextManualInstanceEnumeration::
   ~Linux_DnsSettingContextManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSettingContextManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSettingContextManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSettingContextManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSettingContextManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsSettingContextManualInstance&  
   Linux_DnsSettingContextManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsSettingContextManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSettingContextManualInstance&
   Linux_DnsSettingContextManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsSettingContextManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSettingContextManualInstanceEnumeration::addElement
   (const Linux_DnsSettingContextManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSettingContextManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSettingContextManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSettingContextManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSettingContextManualInstance(elementP);
  	}
  };  
}
 