 /**
 * Linux_DnsElementSettingManualInstance.cpp
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
#include "Linux_DnsElementSettingManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsElementSettingManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsElementSettingManualInstance::
   Linux_DnsElementSettingManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsElementSettingManualInstance::
   Linux_DnsElementSettingManualInstance
   (const Linux_DnsElementSettingManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsElementSettingManualInstance::
   Linux_DnsElementSettingManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsElementSettingInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsElementSettingManualInstance::
   ~Linux_DnsElementSettingManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsElementSettingManualInstance&
   Linux_DnsElementSettingManualInstance::operator=
   (const Linux_DnsElementSettingManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsElementSettingManualInstance::
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
  unsigned int Linux_DnsElementSettingManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsElementSettingInstanceName&
    Linux_DnsElementSettingManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsElementSetting instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsElementSettingManualInstance::setInstanceName(
   const Linux_DnsElementSettingInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsElementSettingManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsElementSettingManualInstance::init
   (const Linux_DnsElementSettingManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsElementSettingManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsElementSettingManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsElementSettingManualInstanceEnumerationElement::
   Linux_DnsElementSettingManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsElementSettingManualInstanceEnumerationElement::
   ~Linux_DnsElementSettingManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsElementSettingManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsElementSettingManualInstanceEnumeration::
   Linux_DnsElementSettingManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsElementSettingManualInstanceEnumeration::
   Linux_DnsElementSettingManualInstanceEnumeration(
   const Linux_DnsElementSettingManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsElementSettingManualInstanceEnumeration::
   ~Linux_DnsElementSettingManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsElementSettingManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsElementSettingManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsElementSettingManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsElementSettingManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsElementSettingManualInstance&  
   Linux_DnsElementSettingManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsElementSettingManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsElementSettingManualInstance&
   Linux_DnsElementSettingManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsElementSettingManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsElementSettingManualInstanceEnumeration::addElement
   (const Linux_DnsElementSettingManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsElementSettingManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsElementSettingManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsElementSettingManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsElementSettingManualInstance(elementP);
  	}
  };  
}
 
