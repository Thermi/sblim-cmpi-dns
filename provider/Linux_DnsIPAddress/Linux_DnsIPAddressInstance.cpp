 /**
 * Linux_DnsIPAddressInstance.cpp
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
#include "Linux_DnsIPAddressInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsIPAddressInstance
  //*********************************************************

  //empty constructor
  Linux_DnsIPAddressInstance::
   Linux_DnsIPAddressInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsIPAddressInstance::
   Linux_DnsIPAddressInstance
   (const Linux_DnsIPAddressInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsIPAddressInstance::
   Linux_DnsIPAddressInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsIPAddressInstanceName(cop));
    
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
    
    cmpiData = inst.getProperty("Port");
    if(!cmpiData.isNullValue()){
      CMPIUint32 Port = cmpiData;
      setPort(Port);
    }
    
    cmpiData = inst.getProperty("SecurityKey");
    if(!cmpiData.isNullValue()){
      CmpiString SecurityKey = cmpiData;
      setSecurityKey(SecurityKey.charPtr());
    }
    
    cmpiData = inst.getProperty("SettingID");
    if(!cmpiData.isNullValue()){
      CmpiString SettingID = cmpiData;
      setSettingID(SettingID.charPtr());
    }
    
  }
  
  
  //Destructor
  Linux_DnsIPAddressInstance::
   ~Linux_DnsIPAddressInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsIPAddressInstance&
   Linux_DnsIPAddressInstance::operator=
   (const Linux_DnsIPAddressInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsIPAddressInstance::
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

  	if(isSet.Port){
  	  cmpiInstance.setProperty("Port",CmpiData(m_Port));
  	}

  	if(isSet.SecurityKey){
  	  cmpiInstance.setProperty("SecurityKey",CmpiData(m_SecurityKey));
  	}

  	if(isSet.SettingID){
  	  cmpiInstance.setProperty("SettingID",CmpiData(m_SettingID));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsIPAddressInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsIPAddressInstanceName&
    Linux_DnsIPAddressInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsIPAddress instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsIPAddressInstance::setInstanceName(
   const Linux_DnsIPAddressInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int Linux_DnsIPAddressInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  Linux_DnsIPAddressInstance::
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
  const char* Linux_DnsIPAddressInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //Description related methods
  unsigned int Linux_DnsIPAddressInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  Linux_DnsIPAddressInstance::
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
  const char* Linux_DnsIPAddressInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int Linux_DnsIPAddressInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  Linux_DnsIPAddressInstance::
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
  const char* Linux_DnsIPAddressInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
       
  //Port related methods
  unsigned int Linux_DnsIPAddressInstance::isPortSet() const{
    return isSet.Port;
  }
  void Linux_DnsIPAddressInstance::
   setPort(const CMPIUint32 val){
    m_Port = val;
    isSet.Port=1;
  }       
  const CMPIUint32 Linux_DnsIPAddressInstance::
   getPort() const{
    
    if(!isSet.Port)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Port not set");
   	   	
    return m_Port;
  }
       
  //SecurityKey related methods
  unsigned int Linux_DnsIPAddressInstance::isSecurityKeySet() const{
    return isSet.SecurityKey;
  }
  void  Linux_DnsIPAddressInstance::
   setSecurityKey(const char* val, int makeCopy){
    if (isSet.SecurityKey) {
      delete []m_SecurityKey;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_SecurityKey = tmpval;
    } else {
      m_SecurityKey = val;
    }
    isSet.SecurityKey=1;
  }       
  const char* Linux_DnsIPAddressInstance::
   getSecurityKey() const{
    
    if(!isSet.SecurityKey)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SecurityKey not set");
   	   	
    return m_SecurityKey;
  }
       
  //SettingID related methods
  unsigned int Linux_DnsIPAddressInstance::isSettingIDSet() const{
    return isSet.SettingID;
  }
  void  Linux_DnsIPAddressInstance::
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
  const char* Linux_DnsIPAddressInstance::
   getSettingID() const{
    
    if(!isSet.SettingID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SettingID not set");
   	   	
    return m_SettingID;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsIPAddressInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;   	
    isSet.Port=0;   	
    isSet.SecurityKey=0;   	
    isSet.SettingID=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsIPAddressInstance::init
   (const Linux_DnsIPAddressInstance& original){   	
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
    if(original.isPortSet()){
      const CMPIUint32 PortOriginal=original.getPort();
      setPort(PortOriginal);
    }   	
    if(original.isSecurityKeySet()){
      const char* SecurityKeyOriginal=original.getSecurityKey();
      setSecurityKey(SecurityKeyOriginal, 1);
    }   	
    if(original.isSettingIDSet()){
      const char* SettingIDOriginal=original.getSettingID();
      setSettingID(SettingIDOriginal, 1);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsIPAddressInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);

  	if (isSet.SecurityKey)
  	  delete(m_SecurityKey);

  	if (isSet.SettingID)
  	  delete(m_SettingID);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsIPAddressInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsIPAddressInstanceEnumerationElement::
   Linux_DnsIPAddressInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsIPAddressInstanceEnumerationElement::
   ~Linux_DnsIPAddressInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsIPAddressInstanceNameEnumeration
  //*********************************************************

  Linux_DnsIPAddressInstanceEnumeration::
   Linux_DnsIPAddressInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsIPAddressInstanceEnumeration::
   Linux_DnsIPAddressInstanceEnumeration(
   const Linux_DnsIPAddressInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsIPAddressInstanceEnumeration::
   ~Linux_DnsIPAddressInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsIPAddressInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsIPAddressInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsIPAddressInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsIPAddressInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsIPAddressInstance&  
   Linux_DnsIPAddressInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsIPAddressInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsIPAddressInstance&
   Linux_DnsIPAddressInstanceEnumeration::getNext() {
   	
  	 Linux_DnsIPAddressInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsIPAddressInstanceEnumeration::addElement
   (const Linux_DnsIPAddressInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsIPAddressInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsIPAddressInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsIPAddressInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsIPAddressInstance(elementP);
  	}
  };  
}
 
