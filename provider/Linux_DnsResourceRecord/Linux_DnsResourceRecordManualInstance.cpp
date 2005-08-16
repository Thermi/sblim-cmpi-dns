 /**
 * Linux_DnsResourceRecordManualInstance.cpp
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
#include "Linux_DnsResourceRecordManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsResourceRecordManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsResourceRecordManualInstance::
   Linux_DnsResourceRecordManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsResourceRecordManualInstance::
   Linux_DnsResourceRecordManualInstance
   (const Linux_DnsResourceRecordManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsResourceRecordManualInstance::
   Linux_DnsResourceRecordManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
   /* 
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsResourceRecordInstanceName(cop));
    */
    Linux_DnsResourceRecordInstanceName instanceName;
    instanceName.setNamespace(instanceNamespace);
    instanceName.setName( inst.getProperty("Name") );
    instanceName.setZoneName ( inst.getProperty("ZoneName") );
    instanceName.setType( inst.getProperty("Type") );
    instanceName.setValue( inst.getProperty("Value") );
    setInstanceName( instanceName );

    cmpiData = inst.getProperty("Family");
    if(!cmpiData.isNullValue()){
      CMPIUint16 Family = cmpiData;
      setFamily(Family);
    }
    
    cmpiData = inst.getProperty("TTL");
    if(!cmpiData.isNullValue()){
      CMPIUint32 TTL = cmpiData;
      setTTL(TTL);
    }
    
  }
  
  
  //Destructor
  Linux_DnsResourceRecordManualInstance::
   ~Linux_DnsResourceRecordManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsResourceRecordManualInstance&
   Linux_DnsResourceRecordManualInstance::operator=
   (const Linux_DnsResourceRecordManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsResourceRecordManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.Family){
  	  cmpiInstance.setProperty("Family",CmpiData(m_Family));
  	}

  	if(isSet.TTL){
  	  cmpiInstance.setProperty("TTL",CmpiData(m_TTL));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsResourceRecordManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsResourceRecordInstanceName&
    Linux_DnsResourceRecordManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsResourceRecord instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsResourceRecordManualInstance::setInstanceName(
   const Linux_DnsResourceRecordInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Family related methods
  unsigned int Linux_DnsResourceRecordManualInstance::isFamilySet() const{
    return isSet.Family;
  }
  void Linux_DnsResourceRecordManualInstance::
   setFamily(const CMPIUint16 val){
    m_Family = val;
    isSet.Family=1;
  }       
  const CMPIUint16 Linux_DnsResourceRecordManualInstance::
   getFamily() const{
    
    if(!isSet.Family)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Family not set");
   	   	
    return m_Family;
  }
       
  //TTL related methods
  unsigned int Linux_DnsResourceRecordManualInstance::isTTLSet() const{
    return isSet.TTL;
  }
  void Linux_DnsResourceRecordManualInstance::
   setTTL(const CMPIUint32 val){
    m_TTL = val;
    isSet.TTL=1;
  }       
  const CMPIUint32 Linux_DnsResourceRecordManualInstance::
   getTTL() const{
    
    if(!isSet.TTL)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "TTL not set");
   	   	
    return m_TTL;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsResourceRecordManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Family=0;   	
    isSet.TTL=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsResourceRecordManualInstance::init
   (const Linux_DnsResourceRecordManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isFamilySet()){
      const CMPIUint16 FamilyOriginal=original.getFamily();
      setFamily(FamilyOriginal);
    }   	
    if(original.isTTLSet()){
      const CMPIUint32 TTLOriginal=original.getTTL();
      setTTL(TTLOriginal);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsResourceRecordManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsResourceRecordManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsResourceRecordManualInstanceEnumerationElement::
   Linux_DnsResourceRecordManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsResourceRecordManualInstanceEnumerationElement::
   ~Linux_DnsResourceRecordManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsResourceRecordManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsResourceRecordManualInstanceEnumeration::
   Linux_DnsResourceRecordManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsResourceRecordManualInstanceEnumeration::
   Linux_DnsResourceRecordManualInstanceEnumeration(
   const Linux_DnsResourceRecordManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsResourceRecordManualInstanceEnumeration::
   ~Linux_DnsResourceRecordManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsResourceRecordManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsResourceRecordManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsResourceRecordManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsResourceRecordManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsResourceRecordManualInstance&  
   Linux_DnsResourceRecordManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsResourceRecordManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsResourceRecordManualInstance&
   Linux_DnsResourceRecordManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsResourceRecordManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsResourceRecordManualInstanceEnumeration::addElement
   (const Linux_DnsResourceRecordManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsResourceRecordManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsResourceRecordManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsResourceRecordManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsResourceRecordManualInstance(elementP);
  	}
  };  
}
 
