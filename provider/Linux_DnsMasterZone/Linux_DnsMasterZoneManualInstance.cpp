 /**
 * Linux_DnsMasterZoneManualInstance.cpp
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
#include "Linux_DnsMasterZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsMasterZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsMasterZoneManualInstance::
   Linux_DnsMasterZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsMasterZoneManualInstance::
   Linux_DnsMasterZoneManualInstance
   (const Linux_DnsMasterZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsMasterZoneManualInstance::
   Linux_DnsMasterZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsMasterZoneInstanceName(cop));
    
    cmpiData = inst.getProperty("Contact");
    if(!cmpiData.isNullValue()){
      CmpiString Contact = cmpiData;
      setContact(Contact.charPtr());
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
    
    cmpiData = inst.getProperty("Type");
    if(!cmpiData.isNullValue()){
      CMPIUint16 Type = cmpiData;
      setType(Type);
    }
    
  }
  
  
  //Destructor
  Linux_DnsMasterZoneManualInstance::
   ~Linux_DnsMasterZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsMasterZoneManualInstance&
   Linux_DnsMasterZoneManualInstance::operator=
   (const Linux_DnsMasterZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsMasterZoneManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.Contact){
  	  cmpiInstance.setProperty("Contact",CmpiData(m_Contact));
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

  	if(isSet.Type){
  	  cmpiInstance.setProperty("Type",CmpiData(m_Type));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsMasterZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsMasterZoneInstanceName&
    Linux_DnsMasterZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsMasterZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsMasterZoneManualInstance::setInstanceName(
   const Linux_DnsMasterZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Contact related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isContactSet() const{
    return isSet.Contact;
  }
  void  Linux_DnsMasterZoneManualInstance::
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
  const char* Linux_DnsMasterZoneManualInstance::
   getContact() const{
    
    if(!isSet.Contact)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Contact not set");
   	   	
    return m_Contact;
  }
       
  //Expire related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isExpireSet() const{
    return isSet.Expire;
  }
  void Linux_DnsMasterZoneManualInstance::
   setExpire(const CMPIUint32 val){
    m_Expire = val;
    isSet.Expire=1;
  }       
  const CMPIUint32 Linux_DnsMasterZoneManualInstance::
   getExpire() const{
    
    if(!isSet.Expire)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Expire not set");
   	   	
    return m_Expire;
  }
       
  //Forward related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isForwardSet() const{
    return isSet.Forward;
  }
  void Linux_DnsMasterZoneManualInstance::
   setForward(const CMPIUint16 val){
    m_Forward = val;
    isSet.Forward=1;
  }       
  const CMPIUint16 Linux_DnsMasterZoneManualInstance::
   getForward() const{
    
    if(!isSet.Forward)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forward not set");
   	   	
    return m_Forward;
  }
       
  //Forwarders related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isForwardersSet() const{
    return isSet.Forwarders;
  }
  void  Linux_DnsMasterZoneManualInstance::
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
  const char** Linux_DnsMasterZoneManualInstance::
   getForwarders(unsigned int& size) const{
    
    if(!isSet.Forwarders)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Forwarders not set");
   	   	
    size=ForwardersArraySize;
    return m_Forwarders;
  }
       
  //NegativeCachingTTL related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isNegativeCachingTTLSet() const{
    return isSet.NegativeCachingTTL;
  }
  void Linux_DnsMasterZoneManualInstance::
   setNegativeCachingTTL(const CMPIUint32 val){
    m_NegativeCachingTTL = val;
    isSet.NegativeCachingTTL=1;
  }       
  const CMPIUint32 Linux_DnsMasterZoneManualInstance::
   getNegativeCachingTTL() const{
    
    if(!isSet.NegativeCachingTTL)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NegativeCachingTTL not set");
   	   	
    return m_NegativeCachingTTL;
  }
       
  //Refresh related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isRefreshSet() const{
    return isSet.Refresh;
  }
  void Linux_DnsMasterZoneManualInstance::
   setRefresh(const CMPIUint32 val){
    m_Refresh = val;
    isSet.Refresh=1;
  }       
  const CMPIUint32 Linux_DnsMasterZoneManualInstance::
   getRefresh() const{
    
    if(!isSet.Refresh)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Refresh not set");
   	   	
    return m_Refresh;
  }
       
  //ResourceRecordFile related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isResourceRecordFileSet() const{
    return isSet.ResourceRecordFile;
  }
  void  Linux_DnsMasterZoneManualInstance::
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
  const char* Linux_DnsMasterZoneManualInstance::
   getResourceRecordFile() const{
    
    if(!isSet.ResourceRecordFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ResourceRecordFile not set");
   	   	
    return m_ResourceRecordFile;
  }
       
  //Retry related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isRetrySet() const{
    return isSet.Retry;
  }
  void Linux_DnsMasterZoneManualInstance::
   setRetry(const CMPIUint32 val){
    m_Retry = val;
    isSet.Retry=1;
  }       
  const CMPIUint32 Linux_DnsMasterZoneManualInstance::
   getRetry() const{
    
    if(!isSet.Retry)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Retry not set");
   	   	
    return m_Retry;
  }
       
  //SerialNumber related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isSerialNumberSet() const{
    return isSet.SerialNumber;
  }
  void  Linux_DnsMasterZoneManualInstance::
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
  const char* Linux_DnsMasterZoneManualInstance::
   getSerialNumber() const{
    
    if(!isSet.SerialNumber)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SerialNumber not set");
   	   	
    return m_SerialNumber;
  }
       
  //Server related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isServerSet() const{
    return isSet.Server;
  }
  void  Linux_DnsMasterZoneManualInstance::
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
  const char* Linux_DnsMasterZoneManualInstance::
   getServer() const{
    
    if(!isSet.Server)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Server not set");
   	   	
    return m_Server;
  }
       
  //Type related methods
  unsigned int Linux_DnsMasterZoneManualInstance::isTypeSet() const{
    return isSet.Type;
  }
  void Linux_DnsMasterZoneManualInstance::
   setType(const CMPIUint16 val){
    m_Type = val;
    isSet.Type=1;
  }       
  const CMPIUint16 Linux_DnsMasterZoneManualInstance::
   getType() const{
    
    if(!isSet.Type)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Type not set");
   	   	
    return m_Type;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsMasterZoneManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Contact=0;   	
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
    isSet.Type=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsMasterZoneManualInstance::init
   (const Linux_DnsMasterZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isContactSet()){
      const char* ContactOriginal=original.getContact();
      setContact(ContactOriginal, 1);
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
    if(original.isTypeSet()){
      const CMPIUint16 TypeOriginal=original.getType();
      setType(TypeOriginal);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsMasterZoneManualInstance::reset(){
   	

  	if (isSet.Contact)
  	  delete(m_Contact);

  	if (isSet.Forwarders){
  	  ArrayConverter::destructArray((char**)(char**)m_Forwarders,ForwardersArraySize);
  	}

  	if (isSet.ResourceRecordFile)
  	  delete(m_ResourceRecordFile);

  	if (isSet.SerialNumber)
  	  delete(m_SerialNumber);

  	if (isSet.Server)
  	  delete(m_Server);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsMasterZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsMasterZoneManualInstanceEnumerationElement::
   Linux_DnsMasterZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsMasterZoneManualInstanceEnumerationElement::
   ~Linux_DnsMasterZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsMasterZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsMasterZoneManualInstanceEnumeration::
   Linux_DnsMasterZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsMasterZoneManualInstanceEnumeration::
   Linux_DnsMasterZoneManualInstanceEnumeration(
   const Linux_DnsMasterZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsMasterZoneManualInstanceEnumeration::
   ~Linux_DnsMasterZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsMasterZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsMasterZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsMasterZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsMasterZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsMasterZoneManualInstance&  
   Linux_DnsMasterZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsMasterZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsMasterZoneManualInstance&
   Linux_DnsMasterZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsMasterZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsMasterZoneManualInstanceEnumeration::addElement
   (const Linux_DnsMasterZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsMasterZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsMasterZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsMasterZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsMasterZoneManualInstance(elementP);
  	}
  };  
}
 
