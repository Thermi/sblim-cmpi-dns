 /**
 * Linux_DnsHintZoneInstance.cpp
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
#include "Linux_DnsHintZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsHintZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsHintZoneInstance::
   Linux_DnsHintZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsHintZoneInstance::
   Linux_DnsHintZoneInstance
   (const Linux_DnsHintZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsHintZoneInstance::
   Linux_DnsHintZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsHintZoneInstanceName(cop));
    
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
   
    cmpiData = inst.getProperty("Enabled");
    if(!cmpiData.isNullValue()){
      CMPIBoolean Enabled = cmpiData;
      setEnabled(Enabled);
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
  Linux_DnsHintZoneInstance::
   ~Linux_DnsHintZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsHintZoneInstance&
   Linux_DnsHintZoneInstance::operator=
   (const Linux_DnsHintZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsHintZoneInstance::
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

        if(isSet.Enabled){
         cmpiInstance.setProperty("Enabled",CmpiBooleanData(m_Enabled));
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
  unsigned int Linux_DnsHintZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsHintZoneInstanceName&
    Linux_DnsHintZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsHintZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsHintZoneInstance::setInstanceName(
   const Linux_DnsHintZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int Linux_DnsHintZoneInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  Linux_DnsHintZoneInstance::
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
  const char* Linux_DnsHintZoneInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //Description related methods
  unsigned int Linux_DnsHintZoneInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  Linux_DnsHintZoneInstance::
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
  const char* Linux_DnsHintZoneInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int Linux_DnsHintZoneInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  Linux_DnsHintZoneInstance::
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
  const char* Linux_DnsHintZoneInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
      
  //Enabled related methods
  unsigned int Linux_DnsHintZoneInstance::isEnabledSet() const{
    return isSet.Enabled;
  }
  void Linux_DnsHintZoneInstance::
   setEnabled(const CMPIBoolean val){
    m_Enabled = val;
    isSet.Enabled=1;
  }
  const CMPIBoolean Linux_DnsHintZoneInstance::
   getEnabled() const{

    if(!isSet.Enabled)
          throw CmpiErrorFormater::getErrorException(
           CmpiErrorFormater::NOT_SET,
           "Enabled not set");

    return m_Enabled;
  }
 
  //ResourceRecordFile related methods
  unsigned int Linux_DnsHintZoneInstance::isResourceRecordFileSet() const{
    return isSet.ResourceRecordFile;
  }
  void  Linux_DnsHintZoneInstance::
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
  const char* Linux_DnsHintZoneInstance::
   getResourceRecordFile() const{
    
    if(!isSet.ResourceRecordFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ResourceRecordFile not set");
   	   	
    return m_ResourceRecordFile;
  }
       
  //SettingID related methods
  unsigned int Linux_DnsHintZoneInstance::isSettingIDSet() const{
    return isSet.SettingID;
  }
  void  Linux_DnsHintZoneInstance::
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
  const char* Linux_DnsHintZoneInstance::
   getSettingID() const{
    
    if(!isSet.SettingID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SettingID not set");
   	   	
    return m_SettingID;
  }
       
  //Type related methods
  unsigned int Linux_DnsHintZoneInstance::isTypeSet() const{
    return isSet.Type;
  }
  void Linux_DnsHintZoneInstance::
   setType(const CMPIUint16 val){
    m_Type = val;
    isSet.Type=1;
  }       
  const CMPIUint16 Linux_DnsHintZoneInstance::
   getType() const{
    
    if(!isSet.Type)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Type not set");
   	   	
    return m_Type;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsHintZoneInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;   	
    isSet.Enabled=0;
    isSet.ResourceRecordFile=0;   	
    isSet.SettingID=0;   	
    isSet.Type=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsHintZoneInstance::init
   (const Linux_DnsHintZoneInstance& original){   	
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
    if(original.isEnabledSet()){
      const CMPIBoolean EnabledOriginal=original.getEnabled();
      setEnabled(EnabledOriginal);
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
  void Linux_DnsHintZoneInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);

  	if (isSet.ResourceRecordFile)
  	  delete(m_ResourceRecordFile);

  	if (isSet.SettingID)
  	  delete(m_SettingID);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsHintZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsHintZoneInstanceEnumerationElement::
   Linux_DnsHintZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsHintZoneInstanceEnumerationElement::
   ~Linux_DnsHintZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsHintZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsHintZoneInstanceEnumeration::
   Linux_DnsHintZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsHintZoneInstanceEnumeration::
   Linux_DnsHintZoneInstanceEnumeration(
   const Linux_DnsHintZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsHintZoneInstanceEnumeration::
   ~Linux_DnsHintZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsHintZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsHintZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsHintZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsHintZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsHintZoneInstance&  
   Linux_DnsHintZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsHintZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsHintZoneInstance&
   Linux_DnsHintZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsHintZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsHintZoneInstanceEnumeration::addElement
   (const Linux_DnsHintZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsHintZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsHintZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsHintZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsHintZoneInstance(elementP);
  	}
  };  
}
 
