 /**
 * Linux_DnsAllowTransferACLForZoneManualInstance.cpp
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
#include "Linux_DnsAllowTransferACLForZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAllowTransferACLForZoneManualInstance::
   Linux_DnsAllowTransferACLForZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAllowTransferACLForZoneManualInstance::
   Linux_DnsAllowTransferACLForZoneManualInstance
   (const Linux_DnsAllowTransferACLForZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAllowTransferACLForZoneManualInstance::
   Linux_DnsAllowTransferACLForZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAllowTransferACLForZoneInstanceName(cop));
    
  }
  
  
  //Destructor
  Linux_DnsAllowTransferACLForZoneManualInstance::
   ~Linux_DnsAllowTransferACLForZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowTransferACLForZoneManualInstance&
   Linux_DnsAllowTransferACLForZoneManualInstance::operator=
   (const Linux_DnsAllowTransferACLForZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAllowTransferACLForZoneManualInstance::
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
  unsigned int Linux_DnsAllowTransferACLForZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAllowTransferACLForZoneInstanceName&
    Linux_DnsAllowTransferACLForZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAllowTransferACLForZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAllowTransferACLForZoneManualInstance::setInstanceName(
   const Linux_DnsAllowTransferACLForZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAllowTransferACLForZoneManualInstance::init(){
   	isSet.instanceName=0;
   	  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAllowTransferACLForZoneManualInstance::init
   (const Linux_DnsAllowTransferACLForZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAllowTransferACLForZoneManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement::
   Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement::
   ~Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration::
   Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration::
   Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration(
   const Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration::
   ~Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAllowTransferACLForZoneManualInstance&  
   Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowTransferACLForZoneManualInstance&
   Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration::addElement
   (const Linux_DnsAllowTransferACLForZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowTransferACLForZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowTransferACLForZoneManualInstance(elementP);
  	}
  };  
}
 
