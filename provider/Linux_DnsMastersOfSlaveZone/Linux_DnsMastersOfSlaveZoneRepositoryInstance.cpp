 /**
 * Linux_DnsMastersOfSlaveZoneRepositoryInstance.cpp
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
#include "Linux_DnsMastersOfSlaveZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsMastersOfSlaveZoneRepositoryInstance::
   Linux_DnsMastersOfSlaveZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsMastersOfSlaveZoneRepositoryInstance::
   Linux_DnsMastersOfSlaveZoneRepositoryInstance
   (const Linux_DnsMastersOfSlaveZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsMastersOfSlaveZoneRepositoryInstance::
   Linux_DnsMastersOfSlaveZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsMastersOfSlaveZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsMastersOfSlaveZoneRepositoryInstance::
   ~Linux_DnsMastersOfSlaveZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsMastersOfSlaveZoneRepositoryInstance&
   Linux_DnsMastersOfSlaveZoneRepositoryInstance::operator=
   (const Linux_DnsMastersOfSlaveZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsMastersOfSlaveZoneRepositoryInstance::
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
  unsigned int Linux_DnsMastersOfSlaveZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsMastersOfSlaveZoneInstanceName&
    Linux_DnsMastersOfSlaveZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsMastersOfSlaveZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsMastersOfSlaveZoneRepositoryInstance::setInstanceName(
   const Linux_DnsMastersOfSlaveZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsMastersOfSlaveZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsMastersOfSlaveZoneRepositoryInstance::init
   (const Linux_DnsMastersOfSlaveZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsMastersOfSlaveZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement::
   Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration::
   Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration::
   Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration(
   const Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration::
   ~Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsMastersOfSlaveZoneRepositoryInstance&  
   Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsMastersOfSlaveZoneRepositoryInstance&
   Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsMastersOfSlaveZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsMastersOfSlaveZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsMastersOfSlaveZoneRepositoryInstance(elementP);
  	}
  };  
}
 
