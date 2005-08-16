 /**
 * Linux_DnsNotifyACLForServiceRepositoryInstance.cpp
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
#include "Linux_DnsNotifyACLForServiceRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsNotifyACLForServiceRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsNotifyACLForServiceRepositoryInstance::
   Linux_DnsNotifyACLForServiceRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsNotifyACLForServiceRepositoryInstance::
   Linux_DnsNotifyACLForServiceRepositoryInstance
   (const Linux_DnsNotifyACLForServiceRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsNotifyACLForServiceRepositoryInstance::
   Linux_DnsNotifyACLForServiceRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsNotifyACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsNotifyACLForServiceRepositoryInstance::
   ~Linux_DnsNotifyACLForServiceRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsNotifyACLForServiceRepositoryInstance&
   Linux_DnsNotifyACLForServiceRepositoryInstance::operator=
   (const Linux_DnsNotifyACLForServiceRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsNotifyACLForServiceRepositoryInstance::
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
  unsigned int Linux_DnsNotifyACLForServiceRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsNotifyACLForServiceInstanceName&
    Linux_DnsNotifyACLForServiceRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsNotifyACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsNotifyACLForServiceRepositoryInstance::setInstanceName(
   const Linux_DnsNotifyACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsNotifyACLForServiceRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsNotifyACLForServiceRepositoryInstance::init
   (const Linux_DnsNotifyACLForServiceRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsNotifyACLForServiceRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement::
   Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement::
   ~Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsNotifyACLForServiceRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration(
   const Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration::
   ~Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsNotifyACLForServiceRepositoryInstance&  
   Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsNotifyACLForServiceRepositoryInstance&
   Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration::addElement
   (const Linux_DnsNotifyACLForServiceRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsNotifyACLForServiceRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsNotifyACLForServiceRepositoryInstance(elementP);
  	}
  };  
}
 
