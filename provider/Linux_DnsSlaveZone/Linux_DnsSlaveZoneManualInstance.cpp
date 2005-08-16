 /**
 * Linux_DnsSlaveZoneManualInstance.cpp
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
#include "Linux_DnsSlaveZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsSlaveZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsSlaveZoneManualInstance::
   Linux_DnsSlaveZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsSlaveZoneManualInstance::
   Linux_DnsSlaveZoneManualInstance
   (const Linux_DnsSlaveZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsSlaveZoneManualInstance::
   Linux_DnsSlaveZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsSlaveZoneInstanceName(cop));
    
    cmpiData = inst.getProperty("Forward");
    if(!cmpiData.isNullValue()){
      CMPIUint16 Forward = cmpiData;
      setForward(Forward);
    }
    
    cmpiData = inst.getProperty("Forwarders");
    if(!cmpiData.isNullValue()){
      CmpiArray Forwarders = cmpiData;
      unsigned int ForwardersSize;
      const char** ForwardersArray;
      ArrayConverter::makeArray(Forwarders, (char***)&ForwardersArray, ForwardersSize);
      setForwarders(ForwardersArray, ForwardersSize, 0);
    }
    
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
  Linux_DnsSlaveZoneManualInstance::
   ~Linux_DnsSlaveZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSlaveZoneManualInstance&
   Linux_DnsSlaveZoneManualInstance::operator=
   (const Linux_DnsSlaveZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsSlaveZoneManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.Forward){
  	  cmpiInstance.setProperty("Forward",CmpiData(m_Forward));
  	}

  	if(isSet.Forwarders){
  	  unsigned int ForwardersSize;
      const char** arrayForwarders=getForwarders(ForwardersSize);
      CmpiArray arrayCmpiForwarders=CmpiArray(ForwardersSize,CMPI_chars);
      for(unsigned int i=0;i<ForwardersSize;i++)
        arrayCmpiForwarders[i]=CmpiData(arrayForwarders[i]);
  	cmpiInstance.setProperty("Forwarders",CmpiData(arrayCmpiForwarders));
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
  unsigned int Linux_DnsSlaveZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsSlaveZoneInstanceName&
    Linux_DnsSlaveZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsSlaveZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsSlaveZoneManualInstance::setInstanceName(
   const Linux_DnsSlaveZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Forward related methods
  unsigned int Linux_DnsSlaveZoneManualInstance::isForwardSet() const{
    return isSet.Forward;
  }
  void Linux_DnsSlaveZoneManualInstance::
   setForward(const CMPIUint16 val){
    m_Forward = val;
    isSet.Forward=1;
  }       
  const CMPIUint16 Linux_DnsSlaveZoneManualInstance::
   getForward() const{
    
    if(!isSet.Forward)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forward not set");
   	   	
    return m_Forward;
  }
       
  //Forwarders related methods
  unsigned int Linux_DnsSlaveZoneManualInstance::isForwardersSet() const{
    return isSet.Forwarders;
  }
  void  Linux_DnsSlaveZoneManualInstance::
   setForwarders(const char** val, const unsigned int size, int makeCopy){
    ForwardersArraySize=size;
    if (isSet.Forwarders) {
      delete m_Forwarders;
    }
    if (makeCopy&&val) {
      m_Forwarders = new const char*[size];
      for(unsigned int i=0;i<size;i++){
        char* aString = new char[strlen(val[i])+1];
        strcpy(aString,val[i]);
        m_Forwarders[i]=aString;
      }      
    } else {
      m_Forwarders = val;
    }
    isSet.Forwarders=1;
  }       
  const char** Linux_DnsSlaveZoneManualInstance::
   getForwarders(unsigned int& size) const{
    
    if(!isSet.Forwarders)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forwarders not set");
   	   	
    size=ForwardersArraySize;
    return m_Forwarders;
  }
       
  //ResourceRecordFile related methods
  unsigned int Linux_DnsSlaveZoneManualInstance::isResourceRecordFileSet() const{
    return isSet.ResourceRecordFile;
  }
  void  Linux_DnsSlaveZoneManualInstance::
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
  const char* Linux_DnsSlaveZoneManualInstance::
   getResourceRecordFile() const{
    
    if(!isSet.ResourceRecordFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ResourceRecordFile not set");
   	   	
    return m_ResourceRecordFile;
  }
       
  //Type related methods
  unsigned int Linux_DnsSlaveZoneManualInstance::isTypeSet() const{
    return isSet.Type;
  }
  void Linux_DnsSlaveZoneManualInstance::
   setType(const CMPIUint16 val){
    m_Type = val;
    isSet.Type=1;
  }       
  const CMPIUint16 Linux_DnsSlaveZoneManualInstance::
   getType() const{
    
    if(!isSet.Type)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Type not set");
   	   	
    return m_Type;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsSlaveZoneManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Forward=0;   	
    isSet.Forwarders=0;   	
    ForwardersArraySize=0;   	
    isSet.ResourceRecordFile=0;   	
    isSet.Type=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsSlaveZoneManualInstance::init
   (const Linux_DnsSlaveZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isForwardSet()){
      const CMPIUint16 ForwardOriginal=original.getForward();
      setForward(ForwardOriginal);
    }   	
    if(original.isForwardersSet()){
      unsigned int sizeForwarders;
    const char** ForwardersOriginal=original.getForwarders(sizeForwarders);
      setForwarders(ForwardersOriginal, sizeForwarders, 1);
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
  void Linux_DnsSlaveZoneManualInstance::reset(){
   	

  	if (isSet.Forwarders){
  	  ArrayConverter::destructArray((char**)(char**)m_Forwarders,ForwardersArraySize);
  	}

  	if (isSet.ResourceRecordFile)
  	  delete(m_ResourceRecordFile);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsSlaveZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsSlaveZoneManualInstanceEnumerationElement::
   Linux_DnsSlaveZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSlaveZoneManualInstanceEnumerationElement::
   ~Linux_DnsSlaveZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSlaveZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsSlaveZoneManualInstanceEnumeration::
   Linux_DnsSlaveZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSlaveZoneManualInstanceEnumeration::
   Linux_DnsSlaveZoneManualInstanceEnumeration(
   const Linux_DnsSlaveZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSlaveZoneManualInstanceEnumeration::
   ~Linux_DnsSlaveZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSlaveZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSlaveZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSlaveZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSlaveZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsSlaveZoneManualInstance&  
   Linux_DnsSlaveZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsSlaveZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSlaveZoneManualInstance&
   Linux_DnsSlaveZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsSlaveZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSlaveZoneManualInstanceEnumeration::addElement
   (const Linux_DnsSlaveZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSlaveZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSlaveZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSlaveZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSlaveZoneManualInstance(elementP);
  	}
  };  
}
 
