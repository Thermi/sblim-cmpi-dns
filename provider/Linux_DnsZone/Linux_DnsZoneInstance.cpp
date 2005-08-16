 /**
 * Linux_DnsZoneInstance.cpp
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
#include "Linux_DnsZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsZoneInstance::
   Linux_DnsZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsZoneInstance::
   Linux_DnsZoneInstance
   (const Linux_DnsZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsZoneInstance::
   Linux_DnsZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsZoneInstanceName(cop));
    
    cmpiData = inst.getProperty("Caption");
    if(!cmpiData.isNullValue()){
      CmpiString Caption = cmpiData;
      setCaption(Caption.charPtr());
    }
    
    cmpiData = inst.getProperty("Contact");
    if(!cmpiData.isNullValue()){
      CmpiString Contact = cmpiData;
      setContact(Contact.charPtr());
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
  Linux_DnsZoneInstance::
   ~Linux_DnsZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsZoneInstance&
   Linux_DnsZoneInstance::operator=
   (const Linux_DnsZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsZoneInstance::
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

  	if(isSet.Contact){
  	  cmpiInstance.setProperty("Contact",CmpiData(m_Contact));
  	}

  	if(isSet.Description){
  	  cmpiInstance.setProperty("Description",CmpiData(m_Description));
  	}

  	if(isSet.ElementName){
  	  cmpiInstance.setProperty("ElementName",CmpiData(m_ElementName));
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
  unsigned int Linux_DnsZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsZoneInstanceName&
    Linux_DnsZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsZoneInstance::setInstanceName(
   const Linux_DnsZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int Linux_DnsZoneInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  Linux_DnsZoneInstance::
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
  const char* Linux_DnsZoneInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //Contact related methods
  unsigned int Linux_DnsZoneInstance::isContactSet() const{
    return isSet.Contact;
  }
  void  Linux_DnsZoneInstance::
   setContact(const char* val, int makeCopy){
    if (isSet.Contact) {
      delete []m_Contact;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Contact = tmpval;
    } else {
      m_Contact = val;
    }
    isSet.Contact=1;
  }       
  const char* Linux_DnsZoneInstance::
   getContact() const{
    
    if(!isSet.Contact)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Contact not set");
   	   	
    return m_Contact;
  }
       
  //Description related methods
  unsigned int Linux_DnsZoneInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  Linux_DnsZoneInstance::
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
  const char* Linux_DnsZoneInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int Linux_DnsZoneInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  Linux_DnsZoneInstance::
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
  const char* Linux_DnsZoneInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
       
  //ResourceRecordFile related methods
  unsigned int Linux_DnsZoneInstance::isResourceRecordFileSet() const{
    return isSet.ResourceRecordFile;
  }
  void  Linux_DnsZoneInstance::
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
  const char* Linux_DnsZoneInstance::
   getResourceRecordFile() const{
    
    if(!isSet.ResourceRecordFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ResourceRecordFile not set");
   	   	
    return m_ResourceRecordFile;
  }
       
  //SettingID related methods
  unsigned int Linux_DnsZoneInstance::isSettingIDSet() const{
    return isSet.SettingID;
  }
  void  Linux_DnsZoneInstance::
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
  const char* Linux_DnsZoneInstance::
   getSettingID() const{
    
    if(!isSet.SettingID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SettingID not set");
   	   	
    return m_SettingID;
  }
       
  //Type related methods
  unsigned int Linux_DnsZoneInstance::isTypeSet() const{
    return isSet.Type;
  }
  void Linux_DnsZoneInstance::
   setType(const CMPIUint16 val){
    m_Type = val;
    isSet.Type=1;
  }       
  const CMPIUint16 Linux_DnsZoneInstance::
   getType() const{
    
    if(!isSet.Type)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Type not set");
   	   	
    return m_Type;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsZoneInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.Contact=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;   	
    isSet.ResourceRecordFile=0;   	
    isSet.SettingID=0;   	
    isSet.Type=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsZoneInstance::init
   (const Linux_DnsZoneInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isCaptionSet()){
      const char* CaptionOriginal=original.getCaption();
      setCaption(CaptionOriginal, 1);
    }   	
    if(original.isContactSet()){
      const char* ContactOriginal=original.getContact();
      setContact(ContactOriginal, 1);
    }   	
    if(original.isDescriptionSet()){
      const char* DescriptionOriginal=original.getDescription();
      setDescription(DescriptionOriginal, 1);
    }   	
    if(original.isElementNameSet()){
      const char* ElementNameOriginal=original.getElementName();
      setElementName(ElementNameOriginal, 1);
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
  void Linux_DnsZoneInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.Contact)
  	  delete(m_Contact);

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
  //Linux_DnsZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsZoneInstanceEnumerationElement::
   Linux_DnsZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsZoneInstanceEnumerationElement::
   ~Linux_DnsZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsZoneInstanceEnumeration::
   Linux_DnsZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsZoneInstanceEnumeration::
   Linux_DnsZoneInstanceEnumeration(
   const Linux_DnsZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsZoneInstanceEnumeration::
   ~Linux_DnsZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsZoneInstance&  
   Linux_DnsZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsZoneInstance&
   Linux_DnsZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsZoneInstanceEnumeration::addElement
   (const Linux_DnsZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsZoneInstance(elementP);
  	}
  };  
}
 
