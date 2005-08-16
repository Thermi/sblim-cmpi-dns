 /**
 * Linux_DnsSlaveZoneInstance.cpp
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
#include "Linux_DnsSlaveZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsSlaveZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsSlaveZoneInstance::
   Linux_DnsSlaveZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsSlaveZoneInstance::
   Linux_DnsSlaveZoneInstance
   (const Linux_DnsSlaveZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsSlaveZoneInstance::
   Linux_DnsSlaveZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsSlaveZoneInstanceName(cop));
    
    cmpiData = inst.getProperty("Caption");
    if(!cmpiData.isNullValue()){
      CmpiString Caption = cmpiData;
      setCaption(Caption.charPtr());
    }
    
    cmpiData = inst.getProperty("Description");
    if(!cmpiData.isNullValue()){
      CmpiString Description = cmpiData;
      setDescription(Description.charPtr());
    }
    
    cmpiData = inst.getProperty("ElementName");
    if(!cmpiData.isNullValue()){
      CmpiString ElementName = cmpiData;
      setElementName(ElementName.charPtr());
    }
    
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
    
    cmpiData = inst.getProperty("SettingID");
    if(!cmpiData.isNullValue()){
      CmpiString SettingID = cmpiData;
      setSettingID(SettingID.charPtr());
    }
    
    cmpiData = inst.getProperty("Type");
    if(!cmpiData.isNullValue()){
      CMPIUint16 Type = cmpiData;
      setType(Type);
    }
    
  }
  
  
  //Destructor
  Linux_DnsSlaveZoneInstance::
   ~Linux_DnsSlaveZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSlaveZoneInstance&
   Linux_DnsSlaveZoneInstance::operator=
   (const Linux_DnsSlaveZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsSlaveZoneInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.Caption){
  	  cmpiInstance.setProperty("Caption",CmpiData(m_Caption));
  	}

  	if(isSet.Description){
  	  cmpiInstance.setProperty("Description",CmpiData(m_Description));
  	}

  	if(isSet.ElementName){
  	  cmpiInstance.setProperty("ElementName",CmpiData(m_ElementName));
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

  	if(isSet.SettingID){
  	  cmpiInstance.setProperty("SettingID",CmpiData(m_SettingID));
  	}

  	if(isSet.Type){
  	  cmpiInstance.setProperty("Type",CmpiData(m_Type));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsSlaveZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsSlaveZoneInstanceName&
    Linux_DnsSlaveZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsSlaveZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsSlaveZoneInstance::setInstanceName(
   const Linux_DnsSlaveZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int Linux_DnsSlaveZoneInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  Linux_DnsSlaveZoneInstance::
   setCaption(const char* val, int makeCopy){
    if (isSet.Caption) {
      delete []m_Caption;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Caption = tmpval;
    } else {
      m_Caption = val;
    }
    isSet.Caption=1;
  }       
  const char* Linux_DnsSlaveZoneInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //Description related methods
  unsigned int Linux_DnsSlaveZoneInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  Linux_DnsSlaveZoneInstance::
   setDescription(const char* val, int makeCopy){
    if (isSet.Description) {
      delete []m_Description;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Description = tmpval;
    } else {
      m_Description = val;
    }
    isSet.Description=1;
  }       
  const char* Linux_DnsSlaveZoneInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int Linux_DnsSlaveZoneInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  Linux_DnsSlaveZoneInstance::
   setElementName(const char* val, int makeCopy){
    if (isSet.ElementName) {
      delete []m_ElementName;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ElementName = tmpval;
    } else {
      m_ElementName = val;
    }
    isSet.ElementName=1;
  }       
  const char* Linux_DnsSlaveZoneInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
       
  //Forward related methods
  unsigned int Linux_DnsSlaveZoneInstance::isForwardSet() const{
    return isSet.Forward;
  }
  void Linux_DnsSlaveZoneInstance::
   setForward(const CMPIUint16 val){
    m_Forward = val;
    isSet.Forward=1;
  }       
  const CMPIUint16 Linux_DnsSlaveZoneInstance::
   getForward() const{
    
    if(!isSet.Forward)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forward not set");
   	   	
    return m_Forward;
  }
       
  //Forwarders related methods
  unsigned int Linux_DnsSlaveZoneInstance::isForwardersSet() const{
    return isSet.Forwarders;
  }
  void  Linux_DnsSlaveZoneInstance::
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
  const char** Linux_DnsSlaveZoneInstance::
   getForwarders(unsigned int& size) const{
    
    if(!isSet.Forwarders)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forwarders not set");
   	   	
    size=ForwardersArraySize;
    return m_Forwarders;
  }
       
  //ResourceRecordFile related methods
  unsigned int Linux_DnsSlaveZoneInstance::isResourceRecordFileSet() const{
    return isSet.ResourceRecordFile;
  }
  void  Linux_DnsSlaveZoneInstance::
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
  const char* Linux_DnsSlaveZoneInstance::
   getResourceRecordFile() const{
    
    if(!isSet.ResourceRecordFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ResourceRecordFile not set");
   	   	
    return m_ResourceRecordFile;
  }
       
  //SettingID related methods
  unsigned int Linux_DnsSlaveZoneInstance::isSettingIDSet() const{
    return isSet.SettingID;
  }
  void  Linux_DnsSlaveZoneInstance::
   setSettingID(const char* val, int makeCopy){
    if (isSet.SettingID) {
      delete []m_SettingID;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_SettingID = tmpval;
    } else {
      m_SettingID = val;
    }
    isSet.SettingID=1;
  }       
  const char* Linux_DnsSlaveZoneInstance::
   getSettingID() const{
    
    if(!isSet.SettingID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SettingID not set");
   	   	
    return m_SettingID;
  }
       
  //Type related methods
  unsigned int Linux_DnsSlaveZoneInstance::isTypeSet() const{
    return isSet.Type;
  }
  void Linux_DnsSlaveZoneInstance::
   setType(const CMPIUint16 val){
    m_Type = val;
    isSet.Type=1;
  }       
  const CMPIUint16 Linux_DnsSlaveZoneInstance::
   getType() const{
    
    if(!isSet.Type)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Type not set");
   	   	
    return m_Type;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsSlaveZoneInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;   	
    isSet.Forward=0;   	
    isSet.Forwarders=0;   	
    ForwardersArraySize=0;   	
    isSet.ResourceRecordFile=0;   	
    isSet.SettingID=0;   	
    isSet.Type=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsSlaveZoneInstance::init
   (const Linux_DnsSlaveZoneInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isCaptionSet()){
      const char* CaptionOriginal=original.getCaption();
      setCaption(CaptionOriginal, 1);
    }   	
    if(original.isDescriptionSet()){
      const char* DescriptionOriginal=original.getDescription();
      setDescription(DescriptionOriginal, 1);
    }   	
    if(original.isElementNameSet()){
      const char* ElementNameOriginal=original.getElementName();
      setElementName(ElementNameOriginal, 1);
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
    if(original.isSettingIDSet()){
      const char* SettingIDOriginal=original.getSettingID();
      setSettingID(SettingIDOriginal, 1);
    }   	
    if(original.isTypeSet()){
      const CMPIUint16 TypeOriginal=original.getType();
      setType(TypeOriginal);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsSlaveZoneInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);

  	if (isSet.Forwarders){
  	  ArrayConverter::destructArray((char**)(char**)m_Forwarders,ForwardersArraySize);
  	}

  	if (isSet.ResourceRecordFile)
  	  delete(m_ResourceRecordFile);

  	if (isSet.SettingID)
  	  delete(m_SettingID);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsSlaveZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsSlaveZoneInstanceEnumerationElement::
   Linux_DnsSlaveZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSlaveZoneInstanceEnumerationElement::
   ~Linux_DnsSlaveZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSlaveZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsSlaveZoneInstanceEnumeration::
   Linux_DnsSlaveZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSlaveZoneInstanceEnumeration::
   Linux_DnsSlaveZoneInstanceEnumeration(
   const Linux_DnsSlaveZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSlaveZoneInstanceEnumeration::
   ~Linux_DnsSlaveZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSlaveZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSlaveZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSlaveZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSlaveZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsSlaveZoneInstance&  
   Linux_DnsSlaveZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsSlaveZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSlaveZoneInstance&
   Linux_DnsSlaveZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsSlaveZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSlaveZoneInstanceEnumeration::addElement
   (const Linux_DnsSlaveZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSlaveZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSlaveZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSlaveZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSlaveZoneInstance(elementP);
  	}
  };  
}
 
