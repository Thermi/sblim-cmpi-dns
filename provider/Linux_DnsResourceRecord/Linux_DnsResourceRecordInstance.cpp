 /**
 * Linux_DnsResourceRecordInstance.cpp
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
#include "Linux_DnsResourceRecordInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsResourceRecordInstance
  //*********************************************************

  //empty constructor
  Linux_DnsResourceRecordInstance::
   Linux_DnsResourceRecordInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsResourceRecordInstance::
   Linux_DnsResourceRecordInstance
   (const Linux_DnsResourceRecordInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsResourceRecordInstance::
   Linux_DnsResourceRecordInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsResourceRecordInstanceName(cop));
    
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
    
    cmpiData = inst.getProperty("Family");
    if(!cmpiData.isNullValue()){
      CMPIUint16 Family = cmpiData;
      setFamily(Family);
    }
    
    cmpiData = inst.getProperty("SettingID");
    if(!cmpiData.isNullValue()){
      CmpiString SettingID = cmpiData;
      setSettingID(SettingID.charPtr());
    }
    
    cmpiData = inst.getProperty("TTL");
    if(!cmpiData.isNullValue()){
      CMPIUint32 TTL = cmpiData;
      setTTL(TTL);
    }
    
  }
  
  
  //Destructor
  Linux_DnsResourceRecordInstance::
   ~Linux_DnsResourceRecordInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsResourceRecordInstance&
   Linux_DnsResourceRecordInstance::operator=
   (const Linux_DnsResourceRecordInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsResourceRecordInstance::
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

  	if(isSet.Family){
  	  cmpiInstance.setProperty("Family",CmpiData(m_Family));
  	}

  	if(isSet.SettingID){
  	  cmpiInstance.setProperty("SettingID",CmpiData(m_SettingID));
  	}

  	if(isSet.TTL){
  	  cmpiInstance.setProperty("TTL",CmpiData(m_TTL));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsResourceRecordInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsResourceRecordInstanceName&
    Linux_DnsResourceRecordInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsResourceRecord instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsResourceRecordInstance::setInstanceName(
   const Linux_DnsResourceRecordInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int Linux_DnsResourceRecordInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  Linux_DnsResourceRecordInstance::
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
  const char* Linux_DnsResourceRecordInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //Description related methods
  unsigned int Linux_DnsResourceRecordInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  Linux_DnsResourceRecordInstance::
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
  const char* Linux_DnsResourceRecordInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int Linux_DnsResourceRecordInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  Linux_DnsResourceRecordInstance::
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
  const char* Linux_DnsResourceRecordInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
       
  //Enabled related methods
  unsigned int Linux_DnsResourceRecordInstance::isEnabledSet() const{
    return isSet.Enabled;
  }
  void Linux_DnsResourceRecordInstance::
   setEnabled(const CMPIBoolean val){
    m_Enabled = val;
    isSet.Enabled=1;
  }       
  const CMPIBoolean Linux_DnsResourceRecordInstance::
   getEnabled() const{
    
    if(!isSet.Enabled)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Enabled not set");
   	   	
    return m_Enabled;
  }
       
  //Family related methods
  unsigned int Linux_DnsResourceRecordInstance::isFamilySet() const{
    return isSet.Family;
  }
  void Linux_DnsResourceRecordInstance::
   setFamily(const CMPIUint16 val){
    m_Family = val;
    isSet.Family=1;
  }       
  const CMPIUint16 Linux_DnsResourceRecordInstance::
   getFamily() const{
    
    if(!isSet.Family)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Family not set");
   	   	
    return m_Family;
  }
       
  //SettingID related methods
  unsigned int Linux_DnsResourceRecordInstance::isSettingIDSet() const{
    return isSet.SettingID;
  }
  void  Linux_DnsResourceRecordInstance::
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
  const char* Linux_DnsResourceRecordInstance::
   getSettingID() const{
    
    if(!isSet.SettingID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SettingID not set");
   	   	
    return m_SettingID;
  }
       
  //TTL related methods
  unsigned int Linux_DnsResourceRecordInstance::isTTLSet() const{
    return isSet.TTL;
  }
  void Linux_DnsResourceRecordInstance::
   setTTL(const CMPIUint32 val){
    m_TTL = val;
    isSet.TTL=1;
  }       
  const CMPIUint32 Linux_DnsResourceRecordInstance::
   getTTL() const{
    
    if(!isSet.TTL)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "TTL not set");
   	   	
    return m_TTL;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsResourceRecordInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;   	
    isSet.Enabled=0;   	
    isSet.Family=0;   	
    isSet.SettingID=0;   	
    isSet.TTL=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsResourceRecordInstance::init
   (const Linux_DnsResourceRecordInstance& original){   	
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
    if(original.isFamilySet()){
      const CMPIUint16 FamilyOriginal=original.getFamily();
      setFamily(FamilyOriginal);
    }   	
    if(original.isSettingIDSet()){
      const char* SettingIDOriginal=original.getSettingID();
      setSettingID(SettingIDOriginal, 1);
    }   	
    if(original.isTTLSet()){
      const CMPIUint32 TTLOriginal=original.getTTL();
      setTTL(TTLOriginal);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsResourceRecordInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);

  	if (isSet.SettingID)
  	  delete(m_SettingID);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsResourceRecordInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsResourceRecordInstanceEnumerationElement::
   Linux_DnsResourceRecordInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsResourceRecordInstanceEnumerationElement::
   ~Linux_DnsResourceRecordInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsResourceRecordInstanceNameEnumeration
  //*********************************************************

  Linux_DnsResourceRecordInstanceEnumeration::
   Linux_DnsResourceRecordInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsResourceRecordInstanceEnumeration::
   Linux_DnsResourceRecordInstanceEnumeration(
   const Linux_DnsResourceRecordInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsResourceRecordInstanceEnumeration::
   ~Linux_DnsResourceRecordInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsResourceRecordInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsResourceRecordInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsResourceRecordInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsResourceRecordInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsResourceRecordInstance&  
   Linux_DnsResourceRecordInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsResourceRecordInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsResourceRecordInstance&
   Linux_DnsResourceRecordInstanceEnumeration::getNext() {
   	
  	 Linux_DnsResourceRecordInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsResourceRecordInstanceEnumeration::addElement
   (const Linux_DnsResourceRecordInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsResourceRecordInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsResourceRecordInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsResourceRecordInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsResourceRecordInstance(elementP);
  	}
  };  
}
 