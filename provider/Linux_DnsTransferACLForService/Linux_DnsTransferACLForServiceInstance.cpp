 /**
 * Linux_DnsTransferACLForServiceInstance.cpp
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
#include "Linux_DnsTransferACLForServiceInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsTransferACLForServiceInstance
  //*********************************************************

  //empty constructor
  Linux_DnsTransferACLForServiceInstance::
   Linux_DnsTransferACLForServiceInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsTransferACLForServiceInstance::
   Linux_DnsTransferACLForServiceInstance
   (const Linux_DnsTransferACLForServiceInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsTransferACLForServiceInstance::
   Linux_DnsTransferACLForServiceInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsTransferACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsTransferACLForServiceInstance::
   ~Linux_DnsTransferACLForServiceInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsTransferACLForServiceInstance&
   Linux_DnsTransferACLForServiceInstance::operator=
   (const Linux_DnsTransferACLForServiceInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsTransferACLForServiceInstance::
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
  unsigned int Linux_DnsTransferACLForServiceInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsTransferACLForServiceInstanceName&
    Linux_DnsTransferACLForServiceInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsTransferACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsTransferACLForServiceInstance::setInstanceName(
   const Linux_DnsTransferACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsTransferACLForServiceInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsTransferACLForServiceInstance::init
   (const Linux_DnsTransferACLForServiceInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsTransferACLForServiceInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsTransferACLForServiceInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsTransferACLForServiceInstanceEnumerationElement::
   Linux_DnsTransferACLForServiceInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsTransferACLForServiceInstanceEnumerationElement::
   ~Linux_DnsTransferACLForServiceInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsTransferACLForServiceInstanceNameEnumeration
  //*********************************************************

  Linux_DnsTransferACLForServiceInstanceEnumeration::
   Linux_DnsTransferACLForServiceInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsTransferACLForServiceInstanceEnumeration::
   Linux_DnsTransferACLForServiceInstanceEnumeration(
   const Linux_DnsTransferACLForServiceInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsTransferACLForServiceInstanceEnumeration::
   ~Linux_DnsTransferACLForServiceInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsTransferACLForServiceInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsTransferACLForServiceInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsTransferACLForServiceInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsTransferACLForServiceInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsTransferACLForServiceInstance&  
   Linux_DnsTransferACLForServiceInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsTransferACLForServiceInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsTransferACLForServiceInstance&
   Linux_DnsTransferACLForServiceInstanceEnumeration::getNext() {
   	
  	 Linux_DnsTransferACLForServiceInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsTransferACLForServiceInstanceEnumeration::addElement
   (const Linux_DnsTransferACLForServiceInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsTransferACLForServiceInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsTransferACLForServiceInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsTransferACLForServiceInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsTransferACLForServiceInstance(elementP);
  	}
  };  
}
 
