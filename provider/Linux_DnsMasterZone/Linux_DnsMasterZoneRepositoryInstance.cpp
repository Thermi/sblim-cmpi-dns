 /**
 * Linux_DnsMasterZoneRepositoryInstance.cpp
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
#include "Linux_DnsMasterZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsMasterZoneRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsMasterZoneRepositoryInstance::
   Linux_DnsMasterZoneRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsMasterZoneRepositoryInstance::
   Linux_DnsMasterZoneRepositoryInstance
   (const Linux_DnsMasterZoneRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsMasterZoneRepositoryInstance::
   Linux_DnsMasterZoneRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsMasterZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsMasterZoneRepositoryInstance::
   ~Linux_DnsMasterZoneRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsMasterZoneRepositoryInstance&
   Linux_DnsMasterZoneRepositoryInstance::operator=
   (const Linux_DnsMasterZoneRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsMasterZoneRepositoryInstance::
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
  unsigned int Linux_DnsMasterZoneRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsMasterZoneInstanceName&
    Linux_DnsMasterZoneRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsMasterZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsMasterZoneRepositoryInstance::setInstanceName(
   const Linux_DnsMasterZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsMasterZoneRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsMasterZoneRepositoryInstance::init
   (const Linux_DnsMasterZoneRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsMasterZoneRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsMasterZoneRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsMasterZoneRepositoryInstanceEnumerationElement::
   Linux_DnsMasterZoneRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsMasterZoneRepositoryInstanceEnumerationElement::
   ~Linux_DnsMasterZoneRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsMasterZoneRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsMasterZoneRepositoryInstanceEnumeration::
   Linux_DnsMasterZoneRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsMasterZoneRepositoryInstanceEnumeration::
   Linux_DnsMasterZoneRepositoryInstanceEnumeration(
   const Linux_DnsMasterZoneRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsMasterZoneRepositoryInstanceEnumeration::
   ~Linux_DnsMasterZoneRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsMasterZoneRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsMasterZoneRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsMasterZoneRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsMasterZoneRepositoryInstance&  
   Linux_DnsMasterZoneRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsMasterZoneRepositoryInstance&
   Linux_DnsMasterZoneRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsMasterZoneRepositoryInstanceEnumeration::addElement
   (const Linux_DnsMasterZoneRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsMasterZoneRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsMasterZoneRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsMasterZoneRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsMasterZoneRepositoryInstance(elementP);
  	}
  };  
}
 
