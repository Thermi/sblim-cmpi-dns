 /**
 * Linux_DnsRecursionACLForServiceRepositoryInstance.cpp
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
#include "Linux_DnsRecursionACLForServiceRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsRecursionACLForServiceRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsRecursionACLForServiceRepositoryInstance::
   Linux_DnsRecursionACLForServiceRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsRecursionACLForServiceRepositoryInstance::
   Linux_DnsRecursionACLForServiceRepositoryInstance
   (const Linux_DnsRecursionACLForServiceRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsRecursionACLForServiceRepositoryInstance::
   Linux_DnsRecursionACLForServiceRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsRecursionACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsRecursionACLForServiceRepositoryInstance::
   ~Linux_DnsRecursionACLForServiceRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsRecursionACLForServiceRepositoryInstance&
   Linux_DnsRecursionACLForServiceRepositoryInstance::operator=
   (const Linux_DnsRecursionACLForServiceRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsRecursionACLForServiceRepositoryInstance::
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
  unsigned int Linux_DnsRecursionACLForServiceRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsRecursionACLForServiceInstanceName&
    Linux_DnsRecursionACLForServiceRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsRecursionACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsRecursionACLForServiceRepositoryInstance::setInstanceName(
   const Linux_DnsRecursionACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsRecursionACLForServiceRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsRecursionACLForServiceRepositoryInstance::init
   (const Linux_DnsRecursionACLForServiceRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsRecursionACLForServiceRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement::
   Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement::
   ~Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsRecursionACLForServiceRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration(
   const Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration::
   ~Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsRecursionACLForServiceRepositoryInstance&  
   Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsRecursionACLForServiceRepositoryInstance&
   Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration::addElement
   (const Linux_DnsRecursionACLForServiceRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsRecursionACLForServiceRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsRecursionACLForServiceRepositoryInstance(elementP);
  	}
  };  
}
 
