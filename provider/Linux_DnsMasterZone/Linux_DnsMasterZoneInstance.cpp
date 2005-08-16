 /**
 * Linux_DnsMasterZoneInstance.cpp
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
#include "Linux_DnsMasterZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsMasterZoneInstance
  //*********************************************************

  //empty constructor
  Linux_DnsMasterZoneInstance::
   Linux_DnsMasterZoneInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsMasterZoneInstance::
   Linux_DnsMasterZoneInstance
   (const Linux_DnsMasterZoneInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsMasterZoneInstance::
   Linux_DnsMasterZoneInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsMasterZoneInstanceName(cop));
    
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
    
    cmpiData = inst.getProperty("Expire");
    if(!cmpiData.isNullValue()){
      CMPIUint32 Expire = cmpiData;
      setExpire(Expire);
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
    
    cmpiData = inst.getProperty("NegativeCachingTTL");
    if(!cmpiData.isNullValue()){
      CMPIUint32 NegativeCachingTTL = cmpiData;
      setNegativeCachingTTL(NegativeCachingTTL);
    }
    
    cmpiData = inst.getProperty("Refresh");
    if(!cmpiData.isNullValue()){
      CMPIUint32 Refresh = cmpiData;
      setRefresh(Refresh);
    }
    
    cmpiData = inst.getProperty("ResourceRecordFile");
    if(!cmpiData.isNullValue()){
      CmpiString ResourceRecordFile = cmpiData;
      setResourceRecordFile(ResourceRecordFile.charPtr());
    }
    
    cmpiData = inst.getProperty("Retry");
    if(!cmpiData.isNullValue()){
      CMPIUint32 Retry = cmpiData;
      setRetry(Retry);
    }
    
    cmpiData = inst.getProperty("SerialNumber");
    if(!cmpiData.isNullValue()){
      CmpiString SerialNumber = cmpiData;
      setSerialNumber(SerialNumber.charPtr());
    }
    
    cmpiData = inst.getProperty("Server");
    if(!cmpiData.isNullValue()){
      CmpiString Server = cmpiData;
      setServer(Server.charPtr());
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
  Linux_DnsMasterZoneInstance::
   ~Linux_DnsMasterZoneInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsMasterZoneInstance&
   Linux_DnsMasterZoneInstance::operator=
   (const Linux_DnsMasterZoneInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsMasterZoneInstance::
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

  	if(isSet.Expire){
  	  cmpiInstance.setProperty("Expire",CmpiData(m_Expire));
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

  	if(isSet.NegativeCachingTTL){
  	  cmpiInstance.setProperty("NegativeCachingTTL",CmpiData(m_NegativeCachingTTL));
  	}

  	if(isSet.Refresh){
  	  cmpiInstance.setProperty("Refresh",CmpiData(m_Refresh));
  	}

  	if(isSet.ResourceRecordFile){
  	  cmpiInstance.setProperty("ResourceRecordFile",CmpiData(m_ResourceRecordFile));
  	}

  	if(isSet.Retry){
  	  cmpiInstance.setProperty("Retry",CmpiData(m_Retry));
  	}

  	if(isSet.SerialNumber){
  	  cmpiInstance.setProperty("SerialNumber",CmpiData(m_SerialNumber));
  	}

  	if(isSet.Server){
  	  cmpiInstance.setProperty("Server",CmpiData(m_Server));
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
  unsigned int Linux_DnsMasterZoneInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsMasterZoneInstanceName&
    Linux_DnsMasterZoneInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsMasterZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsMasterZoneInstance::setInstanceName(
   const Linux_DnsMasterZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int Linux_DnsMasterZoneInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  Linux_DnsMasterZoneInstance::
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
  const char* Linux_DnsMasterZoneInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //Contact related methods
  unsigned int Linux_DnsMasterZoneInstance::isContactSet() const{
    return isSet.Contact;
  }
  void  Linux_DnsMasterZoneInstance::
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
  const char* Linux_DnsMasterZoneInstance::
   getContact() const{
    
    if(!isSet.Contact)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Contact not set");
   	   	
    return m_Contact;
  }
       
  //Description related methods
  unsigned int Linux_DnsMasterZoneInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  Linux_DnsMasterZoneInstance::
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
  const char* Linux_DnsMasterZoneInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int Linux_DnsMasterZoneInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  Linux_DnsMasterZoneInstance::
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
  const char* Linux_DnsMasterZoneInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
       
  //Expire related methods
  unsigned int Linux_DnsMasterZoneInstance::isExpireSet() const{
    return isSet.Expire;
  }
  void Linux_DnsMasterZoneInstance::
   setExpire(const CMPIUint32 val){
    m_Expire = val;
    isSet.Expire=1;
  }       
  const CMPIUint32 Linux_DnsMasterZoneInstance::
   getExpire() const{
    
    if(!isSet.Expire)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Expire not set");
   	   	
    return m_Expire;
  }
       
  //Forward related methods
  unsigned int Linux_DnsMasterZoneInstance::isForwardSet() const{
    return isSet.Forward;
  }
  void Linux_DnsMasterZoneInstance::
   setForward(const CMPIUint16 val){
    m_Forward = val;
    isSet.Forward=1;
  }       
  const CMPIUint16 Linux_DnsMasterZoneInstance::
   getForward() const{
    
    if(!isSet.Forward)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forward not set");
   	   	
    return m_Forward;
  }
       
  //Forwarders related methods
  unsigned int Linux_DnsMasterZoneInstance::isForwardersSet() const{
    return isSet.Forwarders;
  }
  void  Linux_DnsMasterZoneInstance::
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
  const char** Linux_DnsMasterZoneInstance::
   getForwarders(unsigned int& size) const{
    
    if(!isSet.Forwarders)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forwarders not set");
   	   	
    size=ForwardersArraySize;
    return m_Forwarders;
  }
       
  //NegativeCachingTTL related methods
  unsigned int Linux_DnsMasterZoneInstance::isNegativeCachingTTLSet() const{
    return isSet.NegativeCachingTTL;
  }
  void Linux_DnsMasterZoneInstance::
   setNegativeCachingTTL(const CMPIUint32 val){
    m_NegativeCachingTTL = val;
    isSet.NegativeCachingTTL=1;
  }       
  const CMPIUint32 Linux_DnsMasterZoneInstance::
   getNegativeCachingTTL() const{
    
    if(!isSet.NegativeCachingTTL)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NegativeCachingTTL not set");
   	   	
    return m_NegativeCachingTTL;
  }
       
  //Refresh related methods
  unsigned int Linux_DnsMasterZoneInstance::isRefreshSet() const{
    return isSet.Refresh;
  }
  void Linux_DnsMasterZoneInstance::
   setRefresh(const CMPIUint32 val){
    m_Refresh = val;
    isSet.Refresh=1;
  }       
  const CMPIUint32 Linux_DnsMasterZoneInstance::
   getRefresh() const{
    
    if(!isSet.Refresh)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Refresh not set");
   	   	
    return m_Refresh;
  }
       
  //ResourceRecordFile related methods
  unsigned int Linux_DnsMasterZoneInstance::isResourceRecordFileSet() const{
    return isSet.ResourceRecordFile;
  }
  void  Linux_DnsMasterZoneInstance::
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
  const char* Linux_DnsMasterZoneInstance::
   getResourceRecordFile() const{
    
    if(!isSet.ResourceRecordFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ResourceRecordFile not set");
   	   	
    return m_ResourceRecordFile;
  }
       
  //Retry related methods
  unsigned int Linux_DnsMasterZoneInstance::isRetrySet() const{
    return isSet.Retry;
  }
  void Linux_DnsMasterZoneInstance::
   setRetry(const CMPIUint32 val){
    m_Retry = val;
    isSet.Retry=1;
  }       
  const CMPIUint32 Linux_DnsMasterZoneInstance::
   getRetry() const{
    
    if(!isSet.Retry)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Retry not set");
   	   	
    return m_Retry;
  }
       
  //SerialNumber related methods
  unsigned int Linux_DnsMasterZoneInstance::isSerialNumberSet() const{
    return isSet.SerialNumber;
  }
  void  Linux_DnsMasterZoneInstance::
   setSerialNumber(const char* val, int makeCopy){
    if (isSet.SerialNumber) {
      delete []m_SerialNumber;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_SerialNumber = tmpval;
    } else {
      m_SerialNumber = val;
    }
    isSet.SerialNumber=1;
  }       
  const char* Linux_DnsMasterZoneInstance::
   getSerialNumber() const{
    
    if(!isSet.SerialNumber)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SerialNumber not set");
   	   	
    return m_SerialNumber;
  }
       
  //Server related methods
  unsigned int Linux_DnsMasterZoneInstance::isServerSet() const{
    return isSet.Server;
  }
  void  Linux_DnsMasterZoneInstance::
   setServer(const char* val, int makeCopy){
    if (isSet.Server) {
      delete []m_Server;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Server = tmpval;
    } else {
      m_Server = val;
    }
    isSet.Server=1;
  }       
  const char* Linux_DnsMasterZoneInstance::
   getServer() const{
    
    if(!isSet.Server)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Server not set");
   	   	
    return m_Server;
  }
       
  //SettingID related methods
  unsigned int Linux_DnsMasterZoneInstance::isSettingIDSet() const{
    return isSet.SettingID;
  }
  void  Linux_DnsMasterZoneInstance::
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
  const char* Linux_DnsMasterZoneInstance::
   getSettingID() const{
    
    if(!isSet.SettingID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SettingID not set");
   	   	
    return m_SettingID;
  }
       
  //Type related methods
  unsigned int Linux_DnsMasterZoneInstance::isTypeSet() const{
    return isSet.Type;
  }
  void Linux_DnsMasterZoneInstance::
   setType(const CMPIUint16 val){
    m_Type = val;
    isSet.Type=1;
  }       
  const CMPIUint16 Linux_DnsMasterZoneInstance::
   getType() const{
    
    if(!isSet.Type)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Type not set");
   	   	
    return m_Type;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsMasterZoneInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.Contact=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;   	
    isSet.Expire=0;   	
    isSet.Forward=0;   	
    isSet.Forwarders=0;   	
    ForwardersArraySize=0;   	
    isSet.NegativeCachingTTL=0;   	
    isSet.Refresh=0;   	
    isSet.ResourceRecordFile=0;   	
    isSet.Retry=0;   	
    isSet.SerialNumber=0;   	
    isSet.Server=0;   	
    isSet.SettingID=0;   	
    isSet.Type=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsMasterZoneInstance::init
   (const Linux_DnsMasterZoneInstance& original){   	
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
    if(original.isExpireSet()){
      const CMPIUint32 ExpireOriginal=original.getExpire();
      setExpire(ExpireOriginal);
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
    if(original.isNegativeCachingTTLSet()){
      const CMPIUint32 NegativeCachingTTLOriginal=original.getNegativeCachingTTL();
      setNegativeCachingTTL(NegativeCachingTTLOriginal);
    }   	
    if(original.isRefreshSet()){
      const CMPIUint32 RefreshOriginal=original.getRefresh();
      setRefresh(RefreshOriginal);
    }   	
    if(original.isResourceRecordFileSet()){
      const char* ResourceRecordFileOriginal=original.getResourceRecordFile();
      setResourceRecordFile(ResourceRecordFileOriginal, 1);
    }   	
    if(original.isRetrySet()){
      const CMPIUint32 RetryOriginal=original.getRetry();
      setRetry(RetryOriginal);
    }   	
    if(original.isSerialNumberSet()){
      const char* SerialNumberOriginal=original.getSerialNumber();
      setSerialNumber(SerialNumberOriginal, 1);
    }   	
    if(original.isServerSet()){
      const char* ServerOriginal=original.getServer();
      setServer(ServerOriginal, 1);
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
  void Linux_DnsMasterZoneInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.Contact)
  	  delete(m_Contact);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);

  	if (isSet.Forwarders){
  	  ArrayConverter::destructArray((char**)(char**)m_Forwarders,ForwardersArraySize);
  	}

  	if (isSet.ResourceRecordFile)
  	  delete(m_ResourceRecordFile);

  	if (isSet.SerialNumber)
  	  delete(m_SerialNumber);

  	if (isSet.Server)
  	  delete(m_Server);

  	if (isSet.SettingID)
  	  delete(m_SettingID);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsMasterZoneInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsMasterZoneInstanceEnumerationElement::
   Linux_DnsMasterZoneInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsMasterZoneInstanceEnumerationElement::
   ~Linux_DnsMasterZoneInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsMasterZoneInstanceNameEnumeration
  //*********************************************************

  Linux_DnsMasterZoneInstanceEnumeration::
   Linux_DnsMasterZoneInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsMasterZoneInstanceEnumeration::
   Linux_DnsMasterZoneInstanceEnumeration(
   const Linux_DnsMasterZoneInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsMasterZoneInstanceEnumeration::
   ~Linux_DnsMasterZoneInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsMasterZoneInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsMasterZoneInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsMasterZoneInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsMasterZoneInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsMasterZoneInstance&  
   Linux_DnsMasterZoneInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsMasterZoneInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsMasterZoneInstance&
   Linux_DnsMasterZoneInstanceEnumeration::getNext() {
   	
  	 Linux_DnsMasterZoneInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsMasterZoneInstanceEnumeration::addElement
   (const Linux_DnsMasterZoneInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsMasterZoneInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsMasterZoneInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsMasterZoneInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsMasterZoneInstance(elementP);
  	}
  };  
}
 
