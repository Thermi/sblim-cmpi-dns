 /**
 * Linux_DnsMastersOfSlaveZoneInstance.cpp
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
#include "Linux_DnsMastersOfSlaveZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsMastersOfSlaveZoneInstance::
   Linux_DnsMastersOfSlaveZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsMastersOfSlaveZoneInstance::
   Linux_DnsMastersOfSlaveZoneInstance
   (const Linux_DnsMastersOfSlaveZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsMastersOfSlaveZoneInstance::
   Linux_DnsMastersOfSlaveZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsMastersOfSlaveZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsMastersOfSlaveZoneInstance::
   ~Linux_DnsMastersOfSlaveZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsMastersOfSlaveZoneInstance&
   Linux_DnsMastersOfSlaveZoneInstance::operator=
   (const Linux_DnsMastersOfSlaveZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsMastersOfSlaveZoneInstance::
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
  unsigned int Linux_DnsMastersOfSlaveZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsMastersOfSlaveZoneInstanceName&
    Linux_DnsMastersOfSlaveZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsMastersOfSlaveZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsMastersOfSlaveZoneInstance::setInstanceName(
   const Linux_DnsMastersOfSlaveZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsMastersOfSlaveZoneInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsMastersOfSlaveZoneInstance::init
   (const Linux_DnsMastersOfSlaveZoneInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsMastersOfSlaveZoneInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement::
   Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement::
   ~Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsMastersOfSlaveZoneInstanceEnumeration::
   Linux_DnsMastersOfSlaveZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsMastersOfSlaveZoneInstanceEnumeration::
   Linux_DnsMastersOfSlaveZoneInstanceEnumeration(
   const Linux_DnsMastersOfSlaveZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsMastersOfSlaveZoneInstanceEnumeration::
   ~Linux_DnsMastersOfSlaveZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsMastersOfSlaveZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsMastersOfSlaveZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsMastersOfSlaveZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsMastersOfSlaveZoneInstance&  
   Linux_DnsMastersOfSlaveZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsMastersOfSlaveZoneInstance&
   Linux_DnsMastersOfSlaveZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsMastersOfSlaveZoneInstanceEnumeration::addElement
   (const Linux_DnsMastersOfSlaveZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsMastersOfSlaveZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsMastersOfSlaveZoneInstance(elementP);
  	}
  };  
}
 
