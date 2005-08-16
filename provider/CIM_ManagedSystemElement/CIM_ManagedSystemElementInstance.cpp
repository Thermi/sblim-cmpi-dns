 /**
 * CIM_ManagedSystemElementInstance.cpp
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
#include "CIM_ManagedSystemElementInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //CIM_ManagedSystemElementInstance
  //*********************************************************

  //empty constructor
  CIM_ManagedSystemElementInstance::
   CIM_ManagedSystemElementInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  CIM_ManagedSystemElementInstance::
   CIM_ManagedSystemElementInstance
   (const CIM_ManagedSystemElementInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  CIM_ManagedSystemElementInstance::
   CIM_ManagedSystemElementInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(CIM_ManagedSystemElementInstanceName(cop));
    
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
    
    cmpiData = inst.getProperty("InstallDate");
    if(!cmpiData.isNullValue()){
      CmpiDateTime InstallDate = cmpiData;
      setInstallDate(InstallDate);
    }
    
    cmpiData = inst.getProperty("Name");
    if(!cmpiData.isNullValue()){
      CmpiString Name = cmpiData;
      setName(Name.charPtr());
    }
    
    cmpiData = inst.getProperty("OperationalStatus");
    if(!cmpiData.isNullValue()){
      CmpiArray OperationalStatus = cmpiData;
      unsigned int OperationalStatusSize;
      const CMPIUint16* OperationalStatusArray;
      ArrayConverter::makeArray(OperationalStatus, (CMPIUint16**)&OperationalStatusArray, OperationalStatusSize);
      setOperationalStatus(OperationalStatusArray, OperationalStatusSize, 0);
    }
    
    cmpiData = inst.getProperty("Status");
    if(!cmpiData.isNullValue()){
      CmpiString Status = cmpiData;
      setStatus(Status.charPtr());
    }
    
    cmpiData = inst.getProperty("StatusDescriptions");
    if(!cmpiData.isNullValue()){
      CmpiArray StatusDescriptions = cmpiData;
      unsigned int StatusDescriptionsSize;
      const char** StatusDescriptionsArray;
      ArrayConverter::makeArray(StatusDescriptions, (char***)&StatusDescriptionsArray, StatusDescriptionsSize);
      setStatusDescriptions(StatusDescriptionsArray, StatusDescriptionsSize, 0);
    }
    
  }
  
  
  //Destructor
  CIM_ManagedSystemElementInstance::
   ~CIM_ManagedSystemElementInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  CIM_ManagedSystemElementInstance&
   CIM_ManagedSystemElementInstance::operator=
   (const CIM_ManagedSystemElementInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance CIM_ManagedSystemElementInstance::
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

  	if(isSet.InstallDate){
  	  cmpiInstance.setProperty("InstallDate",CmpiData(m_InstallDate));
  	}

  	if(isSet.Name){
  	  cmpiInstance.setProperty("Name",CmpiData(m_Name));
  	}

  	if(isSet.OperationalStatus){
  	  unsigned int OperationalStatusSize;
      const CMPIUint16* arrayOperationalStatus=getOperationalStatus(OperationalStatusSize);
      CmpiArray arrayCmpiOperationalStatus=CmpiArray(OperationalStatusSize,CMPI_uint16);
      for(unsigned int i=0;i<OperationalStatusSize;i++)
        arrayCmpiOperationalStatus[i]=CmpiData(arrayOperationalStatus[i]);
  	cmpiInstance.setProperty("OperationalStatus",CmpiData(arrayCmpiOperationalStatus));
  	}

  	if(isSet.Status){
  	  cmpiInstance.setProperty("Status",CmpiData(m_Status));
  	}

  	if(isSet.StatusDescriptions){
  	  unsigned int StatusDescriptionsSize;
      const char** arrayStatusDescriptions=getStatusDescriptions(StatusDescriptionsSize);
      CmpiArray arrayCmpiStatusDescriptions=CmpiArray(StatusDescriptionsSize,CMPI_chars);
      for(unsigned int i=0;i<StatusDescriptionsSize;i++)
        arrayCmpiStatusDescriptions[i]=CmpiData(arrayStatusDescriptions[i]);
  	cmpiInstance.setProperty("StatusDescriptions",CmpiData(arrayCmpiStatusDescriptions));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int CIM_ManagedSystemElementInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const CIM_ManagedSystemElementInstanceName&
    CIM_ManagedSystemElementInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in CIM_ManagedSystemElement instance");
  		
   	return m_instanceName;
  }

  void CIM_ManagedSystemElementInstance::setInstanceName(
   const CIM_ManagedSystemElementInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int CIM_ManagedSystemElementInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  CIM_ManagedSystemElementInstance::
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
  const char* CIM_ManagedSystemElementInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //Description related methods
  unsigned int CIM_ManagedSystemElementInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  CIM_ManagedSystemElementInstance::
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
  const char* CIM_ManagedSystemElementInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int CIM_ManagedSystemElementInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  CIM_ManagedSystemElementInstance::
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
  const char* CIM_ManagedSystemElementInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
       
  //InstallDate related methods
  unsigned int CIM_ManagedSystemElementInstance::isInstallDateSet() const{
    return isSet.InstallDate;
  }
  void CIM_ManagedSystemElementInstance::
   setInstallDate(const CmpiDateTime& val){
    m_InstallDate = val;
    isSet.InstallDate=1;
  }       
  const CmpiDateTime& CIM_ManagedSystemElementInstance::
   getInstallDate() const{
    
    if(!isSet.InstallDate)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstallDate not set");
   	   	
    return m_InstallDate;
  }
       
  //Name related methods
  unsigned int CIM_ManagedSystemElementInstance::isNameSet() const{
    return isSet.Name;
  }
  void  CIM_ManagedSystemElementInstance::
   setName(const char* val, int makeCopy){
    if (isSet.Name) {
      delete []m_Name;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Name = tmpval;
    } else {
      m_Name = val;
    }
    isSet.Name=1;
  }       
  const char* CIM_ManagedSystemElementInstance::
   getName() const{
    
    if(!isSet.Name)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Name not set");
   	   	
    return m_Name;
  }
       
  //OperationalStatus related methods
  unsigned int CIM_ManagedSystemElementInstance::isOperationalStatusSet() const{
    return isSet.OperationalStatus;
  }
  void CIM_ManagedSystemElementInstance::
   setOperationalStatus(const CMPIUint16* val, const unsigned int size, int makeCopy){
    OperationalStatusArraySize=size;
    if (isSet.OperationalStatus) {
      delete []m_OperationalStatus;
    }
    if (makeCopy&&val) {
      CMPIUint16* AnArray = new CMPIUint16[size];
      for(unsigned int i=0;i<size;i++)
        AnArray[i] = val[i];
      m_OperationalStatus=AnArray;
    } else {
      m_OperationalStatus = val;
    }
    isSet.OperationalStatus=1;
  }       
  const CMPIUint16* CIM_ManagedSystemElementInstance::
   getOperationalStatus(unsigned int& size) const{
    
    if(!isSet.OperationalStatus)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "OperationalStatus not set");
   	   	
    size=OperationalStatusArraySize;
    return m_OperationalStatus;
  }
       
  //Status related methods
  unsigned int CIM_ManagedSystemElementInstance::isStatusSet() const{
    return isSet.Status;
  }
  void  CIM_ManagedSystemElementInstance::
   setStatus(const char* val, int makeCopy){
    if (isSet.Status) {
      delete []m_Status;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Status = tmpval;
    } else {
      m_Status = val;
    }
    isSet.Status=1;
  }       
  const char* CIM_ManagedSystemElementInstance::
   getStatus() const{
    
    if(!isSet.Status)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Status not set");
   	   	
    return m_Status;
  }
       
  //StatusDescriptions related methods
  unsigned int CIM_ManagedSystemElementInstance::isStatusDescriptionsSet() const{
    return isSet.StatusDescriptions;
  }
  void  CIM_ManagedSystemElementInstance::
   setStatusDescriptions(const char** val, const unsigned int size, int makeCopy){
    StatusDescriptionsArraySize=size;
    if (isSet.StatusDescriptions) {
      delete m_StatusDescriptions;
    }
    if (makeCopy&&val) {
      m_StatusDescriptions = new const char*[size];
      for(unsigned int i=0;i<size;i++){
        char* aString = new char[strlen(val[i])+1];
        strcpy(aString,val[i]);
        m_StatusDescriptions[i]=aString;
      }      
    } else {
      m_StatusDescriptions = val;
    }
    isSet.StatusDescriptions=1;
  }       
  const char** CIM_ManagedSystemElementInstance::
   getStatusDescriptions(unsigned int& size) const{
    
    if(!isSet.StatusDescriptions)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "StatusDescriptions not set");
   	   	
    size=StatusDescriptionsArraySize;
    return m_StatusDescriptions;
  }


  
  //set isSet attributes to FALSE
  void CIM_ManagedSystemElementInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;   	
    isSet.InstallDate=0;   	
    isSet.Name=0;   	
    isSet.OperationalStatus=0;   	
    OperationalStatusArraySize=0;   	
    isSet.Status=0;   	
    isSet.StatusDescriptions=0;   	
    StatusDescriptionsArraySize=0;  	
  };
  
  
  //copies another instance properties in this
  void CIM_ManagedSystemElementInstance::init
   (const CIM_ManagedSystemElementInstance& original){   	
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
    if(original.isInstallDateSet()){
      const CmpiDateTime& InstallDateOriginal=original.getInstallDate();
      setInstallDate(InstallDateOriginal);
    }   	
    if(original.isNameSet()){
      const char* NameOriginal=original.getName();
      setName(NameOriginal, 1);
    }   	
    if(original.isOperationalStatusSet()){
      unsigned int sizeOperationalStatus;
    const CMPIUint16* OperationalStatusOriginal=original.getOperationalStatus(sizeOperationalStatus);
      setOperationalStatus(OperationalStatusOriginal, sizeOperationalStatus, 1);
    }   	
    if(original.isStatusSet()){
      const char* StatusOriginal=original.getStatus();
      setStatus(StatusOriginal, 1);
    }   	
    if(original.isStatusDescriptionsSet()){
      unsigned int sizeStatusDescriptions;
    const char** StatusDescriptionsOriginal=original.getStatusDescriptions(sizeStatusDescriptions);
      setStatusDescriptions(StatusDescriptionsOriginal, sizeStatusDescriptions, 1);
    }    
   }
  
  
  //reset the instance data
  void CIM_ManagedSystemElementInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);

  	if (isSet.Name)
  	  delete(m_Name);

  	if (isSet.OperationalStatus){
  	  ArrayConverter::destructArray((CMPIUint16*)m_OperationalStatus);
  	}

  	if (isSet.Status)
  	  delete(m_Status);

  	if (isSet.StatusDescriptions){
  	  ArrayConverter::destructArray((char**)(char**)m_StatusDescriptions,StatusDescriptionsArraySize);
  	}
  	  
  };
  
  
  //*********************************************************
  //CIM_ManagedSystemElementInstanceEnumerationElement	
  //*********************************************************
  
  CIM_ManagedSystemElementInstanceEnumerationElement::
   CIM_ManagedSystemElementInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  CIM_ManagedSystemElementInstanceEnumerationElement::
   ~CIM_ManagedSystemElementInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //CIM_ManagedSystemElementInstanceNameEnumeration
  //*********************************************************

  CIM_ManagedSystemElementInstanceEnumeration::
   CIM_ManagedSystemElementInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  CIM_ManagedSystemElementInstanceEnumeration::
   CIM_ManagedSystemElementInstanceEnumeration(
   const CIM_ManagedSystemElementInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  CIM_ManagedSystemElementInstanceEnumeration::
   ~CIM_ManagedSystemElementInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void CIM_ManagedSystemElementInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool CIM_ManagedSystemElementInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int CIM_ManagedSystemElementInstanceEnumeration::getSize() const{
  	
    int size=0;
    CIM_ManagedSystemElementInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const CIM_ManagedSystemElementInstance&  
   CIM_ManagedSystemElementInstanceEnumeration::getElement(int pos) const{
   
    CIM_ManagedSystemElementInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const CIM_ManagedSystemElementInstance&
   CIM_ManagedSystemElementInstanceEnumeration::getNext() {
   	
  	 CIM_ManagedSystemElementInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void CIM_ManagedSystemElementInstanceEnumeration::addElement
   (const CIM_ManagedSystemElementInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new CIM_ManagedSystemElementInstanceEnumerationElement();
  	  firstElementP->m_elementP=new CIM_ManagedSystemElementInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new CIM_ManagedSystemElementInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new CIM_ManagedSystemElementInstance(elementP);
  	}
  };  
}
 
