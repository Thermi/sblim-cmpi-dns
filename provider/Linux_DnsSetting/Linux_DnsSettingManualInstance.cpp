 /**
 * Linux_DnsSettingManualInstance.cpp
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
#include "Linux_DnsSettingManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsSettingManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsSettingManualInstance::
   Linux_DnsSettingManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsSettingManualInstance::
   Linux_DnsSettingManualInstance
   (const Linux_DnsSettingManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsSettingManualInstance::
   Linux_DnsSettingManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsSettingInstanceName(cop));
    
    cmpiData = inst.getProperty("ConfigurationDirectory");
    if(!cmpiData.isNullValue()){
      CmpiString ConfigurationDirectory = cmpiData;
      setConfigurationDirectory(ConfigurationDirectory.charPtr());
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
  Linux_DnsSettingManualInstance::
   ~Linux_DnsSettingManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSettingManualInstance&
   Linux_DnsSettingManualInstance::operator=
   (const Linux_DnsSettingManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsSettingManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.ConfigurationDirectory){
  	  cmpiInstance.setProperty("ConfigurationDirectory",CmpiData(m_ConfigurationDirectory));
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
  unsigned int Linux_DnsSettingManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsSettingInstanceName&
    Linux_DnsSettingManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsSetting instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsSettingManualInstance::setInstanceName(
   const Linux_DnsSettingInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //ConfigurationDirectory related methods
  unsigned int Linux_DnsSettingManualInstance::isConfigurationDirectorySet() const{
    return isSet.ConfigurationDirectory;
  }
  void  Linux_DnsSettingManualInstance::
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
  const char* Linux_DnsSettingManualInstance::
   getConfigurationDirectory() const{
    
    if(!isSet.ConfigurationDirectory)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ConfigurationDirectory not set");
   	   	
    return m_ConfigurationDirectory;
  }
       
  //Forward related methods
  unsigned int Linux_DnsSettingManualInstance::isForwardSet() const{
    return isSet.Forward;
  }
  void Linux_DnsSettingManualInstance::
   setForward(const CMPIUint16 val){
    m_Forward = val;
    isSet.Forward=1;
  }       
  const CMPIUint16 Linux_DnsSettingManualInstance::
   getForward() const{
    
    if(!isSet.Forward)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forward not set");
   	   	
    return m_Forward;
  }
       
  //Forwarders related methods
  unsigned int Linux_DnsSettingManualInstance::isForwardersSet() const{
    return isSet.Forwarders;
  }
  void  Linux_DnsSettingManualInstance::
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
  const char** Linux_DnsSettingManualInstance::
   getForwarders(unsigned int& size) const{
    
    if(!isSet.Forwarders)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forwarders not set");
   	   	
    size=ForwardersArraySize;
    return m_Forwarders;
  }
       
  //PortNumber related methods
  unsigned int Linux_DnsSettingManualInstance::isPortNumberSet() const{
    return isSet.PortNumber;
  }
  void Linux_DnsSettingManualInstance::
   setPortNumber(const CMPIUint32 val){
    m_PortNumber = val;
    isSet.PortNumber=1;
  }       
  const CMPIUint32 Linux_DnsSettingManualInstance::
   getPortNumber() const{
    
    if(!isSet.PortNumber)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "PortNumber not set");
   	   	
    return m_PortNumber;
  }
       
  //TSIG related methods
  unsigned int Linux_DnsSettingManualInstance::isTSIGSet() const{
    return isSet.TSIG;
  }
  void Linux_DnsSettingManualInstance::
   setTSIG(const CMPIUint16 val){
    m_TSIG = val;
    isSet.TSIG=1;
  }       
  const CMPIUint16 Linux_DnsSettingManualInstance::
   getTSIG() const{
    
    if(!isSet.TSIG)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "TSIG not set");
   	   	
    return m_TSIG;
  }
       
  //TTL related methods
  unsigned int Linux_DnsSettingManualInstance::isTTLSet() const{
    return isSet.TTL;
  }
  void Linux_DnsSettingManualInstance::
   setTTL(const CMPIUint32 val){
    m_TTL = val;
    isSet.TTL=1;
  }       
  const CMPIUint32 Linux_DnsSettingManualInstance::
   getTTL() const{
    
    if(!isSet.TTL)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "TTL not set");
   	   	
    return m_TTL;
  }
       
  //XferFormat related methods
  unsigned int Linux_DnsSettingManualInstance::isXferFormatSet() const{
    return isSet.XferFormat;
  }
  void Linux_DnsSettingManualInstance::
   setXferFormat(const CMPIUint16 val){
    m_XferFormat = val;
    isSet.XferFormat=1;
  }       
  const CMPIUint16 Linux_DnsSettingManualInstance::
   getXferFormat() const{
    
    if(!isSet.XferFormat)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "XferFormat not set");
   	   	
    return m_XferFormat;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsSettingManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.ConfigurationDirectory=0;   	
    isSet.Forward=0;   	
    isSet.Forwarders=0;   	
    ForwardersArraySize=0;   	
    isSet.PortNumber=0;   	
    isSet.TSIG=0;   	
    isSet.TTL=0;   	
    isSet.XferFormat=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsSettingManualInstance::init
   (const Linux_DnsSettingManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isConfigurationDirectorySet()){
      const char* ConfigurationDirectoryOriginal=original.getConfigurationDirectory();
      setConfigurationDirectory(ConfigurationDirectoryOriginal, 1);
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
  void Linux_DnsSettingManualInstance::reset(){
   	

  	if (isSet.ConfigurationDirectory)
  	  delete(m_ConfigurationDirectory);

  	if (isSet.Forwarders){
  	  ArrayConverter::destructArray((char**)(char**)m_Forwarders,ForwardersArraySize);
  	}
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsSettingManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsSettingManualInstanceEnumerationElement::
   Linux_DnsSettingManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSettingManualInstanceEnumerationElement::
   ~Linux_DnsSettingManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSettingManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsSettingManualInstanceEnumeration::
   Linux_DnsSettingManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSettingManualInstanceEnumeration::
   Linux_DnsSettingManualInstanceEnumeration(
   const Linux_DnsSettingManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSettingManualInstanceEnumeration::
   ~Linux_DnsSettingManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSettingManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSettingManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSettingManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSettingManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsSettingManualInstance&  
   Linux_DnsSettingManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsSettingManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSettingManualInstance&
   Linux_DnsSettingManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsSettingManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSettingManualInstanceEnumeration::addElement
   (const Linux_DnsSettingManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSettingManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSettingManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSettingManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSettingManualInstance(elementP);
  	}
  };  
}
 
