 /**
 * Linux_DnsHintZoneManualInstance.cpp
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
#include "Linux_DnsHintZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsHintZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsHintZoneManualInstance::
   Linux_DnsHintZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsHintZoneManualInstance::
   Linux_DnsHintZoneManualInstance
   (const Linux_DnsHintZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsHintZoneManualInstance::
   Linux_DnsHintZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsHintZoneInstanceName(cop));
    
    cmpiData = inst.getProperty("ResourceRecordFile");
    if(!cmpiData.isNullValue()){
      CmpiString ResourceRecordFile = cmpiData;
      setResourceRecordFile(ResourceRecordFile.charPtr());
    }
    
    cmpiData = inst.getProperty("Type");
    if(!cmpiData.isNullValue()){
      CMPIUint16 Type = cmpiData;
      setType(Type);
    }
    
  }
  
  
  //Destructor
  Linux_DnsHintZoneManualInstance::
   ~Linux_DnsHintZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsHintZoneManualInstance&
   Linux_DnsHintZoneManualInstance::operator=
   (const Linux_DnsHintZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsHintZoneManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.ResourceRecordFile){
  	  cmpiInstance.setProperty("ResourceRecordFile",CmpiData(m_ResourceRecordFile));
  	}

  	if(isSet.Type){
  	  cmpiInstance.setProperty("Type",CmpiData(m_Type));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsHintZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsHintZoneInstanceName&
    Linux_DnsHintZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsHintZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsHintZoneManualInstance::setInstanceName(
   const Linux_DnsHintZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //ResourceRecordFile related methods
  unsigned int Linux_DnsHintZoneManualInstance::isResourceRecordFileSet() const{
    return isSet.ResourceRecordFile;
  }
  void  Linux_DnsHintZoneManualInstance::
   setResourceRecordFile(const char* val, int makeCopy){
    if (isSet.ResourceRecordFile) {
      delete []m_ResourceRecordFile;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ResourceRecordFile = tmpval;
    } else {
      m_ResourceRecordFile = val;
    }
    isSet.ResourceRecordFile=1;
  }       
  const char* Linux_DnsHintZoneManualInstance::
   getResourceRecordFile() const{
    
    if(!isSet.ResourceRecordFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ResourceRecordFile not set");
   	   	
    return m_ResourceRecordFile;
  }
       
  //Type related methods
  unsigned int Linux_DnsHintZoneManualInstance::isTypeSet() const{
    return isSet.Type;
  }
  void Linux_DnsHintZoneManualInstance::
   setType(const CMPIUint16 val){
    m_Type = val;
    isSet.Type=1;
  }       
  const CMPIUint16 Linux_DnsHintZoneManualInstance::
   getType() const{
    
    if(!isSet.Type)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Type not set");
   	   	
    return m_Type;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsHintZoneManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.ResourceRecordFile=0;   	
    isSet.Type=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsHintZoneManualInstance::init
   (const Linux_DnsHintZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isResourceRecordFileSet()){
      const char* ResourceRecordFileOriginal=original.getResourceRecordFile();
      setResourceRecordFile(ResourceRecordFileOriginal, 1);
    }   	
    if(original.isTypeSet()){
      const CMPIUint16 TypeOriginal=original.getType();
      setType(TypeOriginal);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsHintZoneManualInstance::reset(){
   	

  	if (isSet.ResourceRecordFile)
  	  delete(m_ResourceRecordFile);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsHintZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsHintZoneManualInstanceEnumerationElement::
   Linux_DnsHintZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsHintZoneManualInstanceEnumerationElement::
   ~Linux_DnsHintZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsHintZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsHintZoneManualInstanceEnumeration::
   Linux_DnsHintZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsHintZoneManualInstanceEnumeration::
   Linux_DnsHintZoneManualInstanceEnumeration(
   const Linux_DnsHintZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsHintZoneManualInstanceEnumeration::
   ~Linux_DnsHintZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsHintZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsHintZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsHintZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsHintZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsHintZoneManualInstance&  
   Linux_DnsHintZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsHintZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsHintZoneManualInstance&
   Linux_DnsHintZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsHintZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsHintZoneManualInstanceEnumeration::addElement
   (const Linux_DnsHintZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsHintZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsHintZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsHintZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsHintZoneManualInstance(elementP);
  	}
  };  
}
 
