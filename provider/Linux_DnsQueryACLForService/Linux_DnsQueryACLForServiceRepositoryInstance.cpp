 /**
 * Linux_DnsQueryACLForServiceRepositoryInstance.cpp
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
#include "Linux_DnsQueryACLForServiceRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsQueryACLForServiceRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsQueryACLForServiceRepositoryInstance::
   Linux_DnsQueryACLForServiceRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsQueryACLForServiceRepositoryInstance::
   Linux_DnsQueryACLForServiceRepositoryInstance
   (const Linux_DnsQueryACLForServiceRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsQueryACLForServiceRepositoryInstance::
   Linux_DnsQueryACLForServiceRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsQueryACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsQueryACLForServiceRepositoryInstance::
   ~Linux_DnsQueryACLForServiceRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsQueryACLForServiceRepositoryInstance&
   Linux_DnsQueryACLForServiceRepositoryInstance::operator=
   (const Linux_DnsQueryACLForServiceRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsQueryACLForServiceRepositoryInstance::
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
  unsigned int Linux_DnsQueryACLForServiceRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsQueryACLForServiceInstanceName&
    Linux_DnsQueryACLForServiceRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsQueryACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsQueryACLForServiceRepositoryInstance::setInstanceName(
   const Linux_DnsQueryACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsQueryACLForServiceRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsQueryACLForServiceRepositoryInstance::init
   (const Linux_DnsQueryACLForServiceRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsQueryACLForServiceRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement::
   Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement::
   ~Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsQueryACLForServiceRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration(
   const Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration::
   ~Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsQueryACLForServiceRepositoryInstance&  
   Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsQueryACLForServiceRepositoryInstance&
   Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration::addElement
   (const Linux_DnsQueryACLForServiceRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsQueryACLForServiceRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsQueryACLForServiceRepositoryInstance(elementP);
  	}
  };  
}
 
