 /**
 * Linux_DnsTransferACLForServiceRepositoryInstance.cpp
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
#include "Linux_DnsTransferACLForServiceRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsTransferACLForServiceRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsTransferACLForServiceRepositoryInstance::
   Linux_DnsTransferACLForServiceRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsTransferACLForServiceRepositoryInstance::
   Linux_DnsTransferACLForServiceRepositoryInstance
   (const Linux_DnsTransferACLForServiceRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsTransferACLForServiceRepositoryInstance::
   Linux_DnsTransferACLForServiceRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsTransferACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsTransferACLForServiceRepositoryInstance::
   ~Linux_DnsTransferACLForServiceRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsTransferACLForServiceRepositoryInstance&
   Linux_DnsTransferACLForServiceRepositoryInstance::operator=
   (const Linux_DnsTransferACLForServiceRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsTransferACLForServiceRepositoryInstance::
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
  unsigned int Linux_DnsTransferACLForServiceRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsTransferACLForServiceInstanceName&
    Linux_DnsTransferACLForServiceRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsTransferACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsTransferACLForServiceRepositoryInstance::setInstanceName(
   const Linux_DnsTransferACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsTransferACLForServiceRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsTransferACLForServiceRepositoryInstance::init
   (const Linux_DnsTransferACLForServiceRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsTransferACLForServiceRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement::
   Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement::
   ~Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsTransferACLForServiceRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration(
   const Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration::
   ~Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsTransferACLForServiceRepositoryInstance&  
   Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsTransferACLForServiceRepositoryInstance&
   Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration::addElement
   (const Linux_DnsTransferACLForServiceRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsTransferACLForServiceRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsTransferACLForServiceRepositoryInstance(elementP);
  	}
  };  
}
 
