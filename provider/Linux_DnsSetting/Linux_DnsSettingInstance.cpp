 /**
 * Linux_DnsSettingInstance.cpp
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
#include "Linux_DnsSettingInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsSettingInstance
  //*********************************************************

  //empty constructor
  Linux_DnsSettingInstance::
   Linux_DnsSettingInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsSettingInstance::
   Linux_DnsSettingInstance
   (const Linux_DnsSettingInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsSettingInstance::
   Linux_DnsSettingInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsSettingInstanceName(cop));
    
    cmpiData = inst.getProperty("Caption");
    if(!cmpiData.isNullValue()){
      CmpiString Caption = cmpiData;
      setCaption(Caption.charPtr());
    }
    
    cmpiData = inst.getProperty("ConfigurationDirectory");
    if(!cmpiData.isNullValue()){
      CmpiString ConfigurationDirectory = cmpiData;
      setConfigurationDirectory(ConfigurationDirectory.charPtr());
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
    
    cmpiData = inst.getProperty("PortNumber");
    if(!cmpiData.isNullValue()){
      CMPIUint32 PortNumber = cmpiData;
      setPortNumber(PortNumber);
    }
    
    cmpiData = inst.getProperty("SettingID");
    if(!cmpiData.isNullValue()){
      CmpiString SettingID = cmpiData;
      setSettingID(SettingID.charPtr());
    }
    
    cmpiData = inst.getProperty("TSIG");
    if(!cmpiData.isNullValue()){
      CMPIUint16 TSIG = cmpiData;
      setTSIG(TSIG);
    }
    
    cmpiData = inst.getProperty("TTL");
    if(!cmpiData.isNullValue()){
      CMPIUint32 TTL = cmpiData;
      setTTL(TTL);
    }
    
    cmpiData = inst.getProperty("XferFormat");
    if(!cmpiData.isNullValue()){
      CMPIUint16 XferFormat = cmpiData;
      setXferFormat(XferFormat);
    }
    
  }
  
  
  //Destructor
  Linux_DnsSettingInstance::
   ~Linux_DnsSettingInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSettingInstance&
   Linux_DnsSettingInstance::operator=
   (const Linux_DnsSettingInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsSettingInstance::
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

  	if(isSet.ConfigurationDirectory){
  	  cmpiInstance.setProperty("ConfigurationDirectory",CmpiData(m_ConfigurationDirectory));
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

  	if(isSet.PortNumber){
  	  cmpiInstance.setProperty("PortNumber",CmpiData(m_PortNumber));
  	}

  	if(isSet.SettingID){
  	  cmpiInstance.setProperty("SettingID",CmpiData(m_SettingID));
  	}

  	if(isSet.TSIG){
  	  cmpiInstance.setProperty("TSIG",CmpiData(m_TSIG));
  	}

  	if(isSet.TTL){
  	  cmpiInstance.setProperty("TTL",CmpiData(m_TTL));
  	}

  	if(isSet.XferFormat){
  	  cmpiInstance.setProperty("XferFormat",CmpiData(m_XferFormat));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsSettingInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsSettingInstanceName&
    Linux_DnsSettingInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsSetting instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsSettingInstance::setInstanceName(
   const Linux_DnsSettingInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int Linux_DnsSettingInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  Linux_DnsSettingInstance::
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
  const char* Linux_DnsSettingInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //ConfigurationDirectory related methods
  unsigned int Linux_DnsSettingInstance::isConfigurationDirectorySet() const{
    return isSet.ConfigurationDirectory;
  }
  void  Linux_DnsSettingInstance::
   setConfigurationDirectory(const char* val, int makeCopy){
    if (isSet.ConfigurationDirectory) {
      delete []m_ConfigurationDirectory;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ConfigurationDirectory = tmpval;
    } else {
      m_ConfigurationDirectory = val;
    }
    isSet.ConfigurationDirectory=1;
  }       
  const char* Linux_DnsSettingInstance::
   getConfigurationDirectory() const{
    
    if(!isSet.ConfigurationDirectory)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ConfigurationDirectory not set");
   	   	
    return m_ConfigurationDirectory;
  }
       
  //Description related methods
  unsigned int Linux_DnsSettingInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  Linux_DnsSettingInstance::
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
  const char* Linux_DnsSettingInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int Linux_DnsSettingInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  Linux_DnsSettingInstance::
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
  const char* Linux_DnsSettingInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
       
  //Forward related methods
  unsigned int Linux_DnsSettingInstance::isForwardSet() const{
    return isSet.Forward;
  }
  void Linux_DnsSettingInstance::
   setForward(const CMPIUint16 val){
    m_Forward = val;
    isSet.Forward=1;
  }       
  const CMPIUint16 Linux_DnsSettingInstance::
   getForward() const{
    
    if(!isSet.Forward)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forward not set");
   	   	
    return m_Forward;
  }
       
  //Forwarders related methods
  unsigned int Linux_DnsSettingInstance::isForwardersSet() const{
    return isSet.Forwarders;
  }
  void  Linux_DnsSettingInstance::
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
  const char** Linux_DnsSettingInstance::
   getForwarders(unsigned int& size) const{
    
    if(!isSet.Forwarders)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forwarders not set");
   	   	
    size=ForwardersArraySize;
    return m_Forwarders;
  }
       
  //PortNumber related methods
  unsigned int Linux_DnsSettingInstance::isPortNumberSet() const{
    return isSet.PortNumber;
  }
  void Linux_DnsSettingInstance::
   setPortNumber(const CMPIUint32 val){
    m_PortNumber = val;
    isSet.PortNumber=1;
  }       
  const CMPIUint32 Linux_DnsSettingInstance::
   getPortNumber() const{
    
    if(!isSet.PortNumber)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "PortNumber not set");
   	   	
    return m_PortNumber;
  }
       
  //SettingID related methods
  unsigned int Linux_DnsSettingInstance::isSettingIDSet() const{
    return isSet.SettingID;
  }
  void  Linux_DnsSettingInstance::
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
  const char* Linux_DnsSettingInstance::
   getSettingID() const{
    
    if(!isSet.SettingID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SettingID not set");
   	   	
    return m_SettingID;
  }
       
  //TSIG related methods
  unsigned int Linux_DnsSettingInstance::isTSIGSet() const{
    return isSet.TSIG;
  }
  void Linux_DnsSettingInstance::
   setTSIG(const CMPIUint16 val){
    m_TSIG = val;
    isSet.TSIG=1;
  }       
  const CMPIUint16 Linux_DnsSettingInstance::
   getTSIG() const{
    
    if(!isSet.TSIG)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "TSIG not set");
   	   	
    return m_TSIG;
  }
       
  //TTL related methods
  unsigned int Linux_DnsSettingInstance::isTTLSet() const{
    return isSet.TTL;
  }
  void Linux_DnsSettingInstance::
   setTTL(const CMPIUint32 val){
    m_TTL = val;
    isSet.TTL=1;
  }       
  const CMPIUint32 Linux_DnsSettingInstance::
   getTTL() const{
    
    if(!isSet.TTL)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "TTL not set");
   	   	
    return m_TTL;
  }
       
  //XferFormat related methods
  unsigned int Linux_DnsSettingInstance::isXferFormatSet() const{
    return isSet.XferFormat;
  }
  void Linux_DnsSettingInstance::
   setXferFormat(const CMPIUint16 val){
    m_XferFormat = val;
    isSet.XferFormat=1;
  }       
  const CMPIUint16 Linux_DnsSettingInstance::
   getXferFormat() const{
    
    if(!isSet.XferFormat)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "XferFormat not set");
   	   	
    return m_XferFormat;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsSettingInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.ConfigurationDirectory=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;   	
    isSet.Forward=0;   	
    isSet.Forwarders=0;   	
    ForwardersArraySize=0;   	
    isSet.PortNumber=0;   	
    isSet.SettingID=0;   	
    isSet.TSIG=0;   	
    isSet.TTL=0;   	
    isSet.XferFormat=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsSettingInstance::init
   (const Linux_DnsSettingInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isCaptionSet()){
      const char* CaptionOriginal=original.getCaption();
      setCaption(CaptionOriginal, 1);
    }   	
    if(original.isConfigurationDirectorySet()){
      const char* ConfigurationDirectoryOriginal=original.getConfigurationDirectory();
      setConfigurationDirectory(ConfigurationDirectoryOriginal, 1);
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
    if(original.isPortNumberSet()){
      const CMPIUint32 PortNumberOriginal=original.getPortNumber();
      setPortNumber(PortNumberOriginal);
    }   	
    if(original.isSettingIDSet()){
      const char* SettingIDOriginal=original.getSettingID();
      setSettingID(SettingIDOriginal, 1);
    }   	
    if(original.isTSIGSet()){
      const CMPIUint16 TSIGOriginal=original.getTSIG();
      setTSIG(TSIGOriginal);
    }   	
    if(original.isTTLSet()){
      const CMPIUint32 TTLOriginal=original.getTTL();
      setTTL(TTLOriginal);
    }   	
    if(original.isXferFormatSet()){
      const CMPIUint16 XferFormatOriginal=original.getXferFormat();
      setXferFormat(XferFormatOriginal);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsSettingInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.ConfigurationDirectory)
  	  delete(m_ConfigurationDirectory);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);

  	if (isSet.Forwarders){
  	  ArrayConverter::destructArray((char**)(char**)m_Forwarders,ForwardersArraySize);
  	}

  	if (isSet.SettingID)
  	  delete(m_SettingID);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsSettingInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsSettingInstanceEnumerationElement::
   Linux_DnsSettingInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSettingInstanceEnumerationElement::
   ~Linux_DnsSettingInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSettingInstanceNameEnumeration
  //*********************************************************

  Linux_DnsSettingInstanceEnumeration::
   Linux_DnsSettingInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSettingInstanceEnumeration::
   Linux_DnsSettingInstanceEnumeration(
   const Linux_DnsSettingInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSettingInstanceEnumeration::
   ~Linux_DnsSettingInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSettingInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSettingInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSettingInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSettingInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsSettingInstance&  
   Linux_DnsSettingInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsSettingInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSettingInstance&
   Linux_DnsSettingInstanceEnumeration::getNext() {
   	
  	 Linux_DnsSettingInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSettingInstanceEnumeration::addElement
   (const Linux_DnsSettingInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSettingInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSettingInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSettingInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSettingInstance(elementP);
  	}
  };  
}
 
