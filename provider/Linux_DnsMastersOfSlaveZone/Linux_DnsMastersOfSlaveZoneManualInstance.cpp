 /**
 * Linux_DnsMastersOfSlaveZoneManualInstance.cpp
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
#include "Linux_DnsMastersOfSlaveZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsMastersOfSlaveZoneManualInstance::
   Linux_DnsMastersOfSlaveZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsMastersOfSlaveZoneManualInstance::
   Linux_DnsMastersOfSlaveZoneManualInstance
   (const Linux_DnsMastersOfSlaveZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsMastersOfSlaveZoneManualInstance::
   Linux_DnsMastersOfSlaveZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsMastersOfSlaveZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsMastersOfSlaveZoneManualInstance::
   ~Linux_DnsMastersOfSlaveZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsMastersOfSlaveZoneManualInstance&
   Linux_DnsMastersOfSlaveZoneManualInstance::operator=
   (const Linux_DnsMastersOfSlaveZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsMastersOfSlaveZoneManualInstance::
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
  unsigned int Linux_DnsMastersOfSlaveZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsMastersOfSlaveZoneInstanceName&
    Linux_DnsMastersOfSlaveZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsMastersOfSlaveZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsMastersOfSlaveZoneManualInstance::setInstanceName(
   const Linux_DnsMastersOfSlaveZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsMastersOfSlaveZoneManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsMastersOfSlaveZoneManualInstance::init
   (const Linux_DnsMastersOfSlaveZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsMastersOfSlaveZoneManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement::
   Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement::
   ~Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration::
   Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration::
   Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration(
   const Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration::
   ~Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsMastersOfSlaveZoneManualInstance&  
   Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsMastersOfSlaveZoneManualInstance&
   Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration::addElement
   (const Linux_DnsMastersOfSlaveZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsMastersOfSlaveZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsMastersOfSlaveZoneManualInstance(elementP);
  	}
  };  
}
 
