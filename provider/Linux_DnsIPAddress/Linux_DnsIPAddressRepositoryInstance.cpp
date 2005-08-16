 /**
 * Linux_DnsIPAddressRepositoryInstance.cpp
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
#include "Linux_DnsIPAddressRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsIPAddressRepositoryInstance
  //*********************************************************

  //empty constructor
  Linux_DnsIPAddressRepositoryInstance::
   Linux_DnsIPAddressRepositoryInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsIPAddressRepositoryInstance::
   Linux_DnsIPAddressRepositoryInstance
   (const Linux_DnsIPAddressRepositoryInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsIPAddressRepositoryInstance::
   Linux_DnsIPAddressRepositoryInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsIPAddressInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsIPAddressRepositoryInstance::
   ~Linux_DnsIPAddressRepositoryInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsIPAddressRepositoryInstance&
   Linux_DnsIPAddressRepositoryInstance::operator=
   (const Linux_DnsIPAddressRepositoryInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsIPAddressRepositoryInstance::
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
  unsigned int Linux_DnsIPAddressRepositoryInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsIPAddressInstanceName&
    Linux_DnsIPAddressRepositoryInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsIPAddress instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsIPAddressRepositoryInstance::setInstanceName(
   const Linux_DnsIPAddressInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsIPAddressRepositoryInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsIPAddressRepositoryInstance::init
   (const Linux_DnsIPAddressRepositoryInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsIPAddressRepositoryInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsIPAddressRepositoryInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsIPAddressRepositoryInstanceEnumerationElement::
   Linux_DnsIPAddressRepositoryInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsIPAddressRepositoryInstanceEnumerationElement::
   ~Linux_DnsIPAddressRepositoryInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsIPAddressRepositoryInstanceNameEnumeration
  //*********************************************************

  Linux_DnsIPAddressRepositoryInstanceEnumeration::
   Linux_DnsIPAddressRepositoryInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsIPAddressRepositoryInstanceEnumeration::
   Linux_DnsIPAddressRepositoryInstanceEnumeration(
   const Linux_DnsIPAddressRepositoryInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsIPAddressRepositoryInstanceEnumeration::
   ~Linux_DnsIPAddressRepositoryInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsIPAddressRepositoryInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsIPAddressRepositoryInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsIPAddressRepositoryInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsIPAddressRepositoryInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsIPAddressRepositoryInstance&  
   Linux_DnsIPAddressRepositoryInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsIPAddressRepositoryInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsIPAddressRepositoryInstance&
   Linux_DnsIPAddressRepositoryInstanceEnumeration::getNext() {
   	
  	 Linux_DnsIPAddressRepositoryInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsIPAddressRepositoryInstanceEnumeration::addElement
   (const Linux_DnsIPAddressRepositoryInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsIPAddressRepositoryInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsIPAddressRepositoryInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsIPAddressRepositoryInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsIPAddressRepositoryInstance(elementP);
  	}
  };  
}
 
