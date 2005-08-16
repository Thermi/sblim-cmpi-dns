 /**
 * Linux_DnsTransferACLForServiceManualInstance.cpp
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
#include "Linux_DnsTransferACLForServiceManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsTransferACLForServiceManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsTransferACLForServiceManualInstance::
   Linux_DnsTransferACLForServiceManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsTransferACLForServiceManualInstance::
   Linux_DnsTransferACLForServiceManualInstance
   (const Linux_DnsTransferACLForServiceManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsTransferACLForServiceManualInstance::
   Linux_DnsTransferACLForServiceManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsTransferACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsTransferACLForServiceManualInstance::
   ~Linux_DnsTransferACLForServiceManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsTransferACLForServiceManualInstance&
   Linux_DnsTransferACLForServiceManualInstance::operator=
   (const Linux_DnsTransferACLForServiceManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsTransferACLForServiceManualInstance::
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
  unsigned int Linux_DnsTransferACLForServiceManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsTransferACLForServiceInstanceName&
    Linux_DnsTransferACLForServiceManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsTransferACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsTransferACLForServiceManualInstance::setInstanceName(
   const Linux_DnsTransferACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsTransferACLForServiceManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsTransferACLForServiceManualInstance::init
   (const Linux_DnsTransferACLForServiceManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsTransferACLForServiceManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsTransferACLForServiceManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsTransferACLForServiceManualInstanceEnumerationElement::
   Linux_DnsTransferACLForServiceManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsTransferACLForServiceManualInstanceEnumerationElement::
   ~Linux_DnsTransferACLForServiceManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsTransferACLForServiceManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsTransferACLForServiceManualInstanceEnumeration::
   Linux_DnsTransferACLForServiceManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsTransferACLForServiceManualInstanceEnumeration::
   Linux_DnsTransferACLForServiceManualInstanceEnumeration(
   const Linux_DnsTransferACLForServiceManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsTransferACLForServiceManualInstanceEnumeration::
   ~Linux_DnsTransferACLForServiceManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsTransferACLForServiceManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsTransferACLForServiceManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsTransferACLForServiceManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsTransferACLForServiceManualInstance&  
   Linux_DnsTransferACLForServiceManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsTransferACLForServiceManualInstance&
   Linux_DnsTransferACLForServiceManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsTransferACLForServiceManualInstanceEnumeration::addElement
   (const Linux_DnsTransferACLForServiceManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsTransferACLForServiceManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsTransferACLForServiceManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsTransferACLForServiceManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsTransferACLForServiceManualInstance(elementP);
  	}
  };  
}
 
