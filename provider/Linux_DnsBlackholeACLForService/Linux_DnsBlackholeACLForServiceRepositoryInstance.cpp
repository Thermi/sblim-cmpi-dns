 /**
 * Linux_DnsBlackholeACLForServiceRepositoryInstance.cpp
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
#include "Linux_DnsBlackholeACLForServiceRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsBlackholeACLForServiceRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsBlackholeACLForServiceRepositoryInstance::
   Linux_DnsBlackholeACLForServiceRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsBlackholeACLForServiceRepositoryInstance::
   Linux_DnsBlackholeACLForServiceRepositoryInstance
   (const Linux_DnsBlackholeACLForServiceRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsBlackholeACLForServiceRepositoryInstance::
   Linux_DnsBlackholeACLForServiceRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsBlackholeACLForServiceInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsBlackholeACLForServiceRepositoryInstance::
   ~Linux_DnsBlackholeACLForServiceRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsBlackholeACLForServiceRepositoryInstance&
   Linux_DnsBlackholeACLForServiceRepositoryInstance::operator=
   (const Linux_DnsBlackholeACLForServiceRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsBlackholeACLForServiceRepositoryInstance::
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
  unsigned int Linux_DnsBlackholeACLForServiceRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsBlackholeACLForServiceInstanceName&
    Linux_DnsBlackholeACLForServiceRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsBlackholeACLForService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsBlackholeACLForServiceRepositoryInstance::setInstanceName(
   const Linux_DnsBlackholeACLForServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsBlackholeACLForServiceRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsBlackholeACLForServiceRepositoryInstance::init
   (const Linux_DnsBlackholeACLForServiceRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsBlackholeACLForServiceRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement::
   Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement::
   ~Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsBlackholeACLForServiceRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration::
   Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration(
   const Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration::
   ~Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsBlackholeACLForServiceRepositoryInstance&  
   Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsBlackholeACLForServiceRepositoryInstance&
   Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration::addElement
   (const Linux_DnsBlackholeACLForServiceRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsBlackholeACLForServiceRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsBlackholeACLForServiceRepositoryInstance(elementP);
  	}
  };  
}
 
