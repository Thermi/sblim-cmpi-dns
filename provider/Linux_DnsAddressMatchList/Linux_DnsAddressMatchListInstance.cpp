 /**
 * Linux_DnsAddressMatchListInstance.cpp
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
#include "Linux_DnsAddressMatchListInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAddressMatchListInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAddressMatchListInstance::
   Linux_DnsAddressMatchListInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAddressMatchListInstance::
   Linux_DnsAddressMatchListInstance
   (const Linux_DnsAddressMatchListInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAddressMatchListInstance::
   Linux_DnsAddressMatchListInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAddressMatchListInstanceName(cop));
    
    cmpiData = inst.getProperty("AddressListType");
    if(!cmpiData.isNullValue()){
      CMPIUint16 AddressListType = cmpiData;
      setAddressListType(AddressListType);
    }
    
    cmpiData = inst.getProperty("AddressList");
    if(!cmpiData.isNullValue()){
      CmpiArray AddressList = cmpiData;
      unsigned int AddressListSize;
      const char** AddressListArray;
      ArrayConverter::makeArray(AddressList, (char***)&AddressListArray, AddressListSize);
      setAddressList(AddressListArray, AddressListSize, 0);
    }
    
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
    
    cmpiData = inst.getProperty("SettingID");
    if(!cmpiData.isNullValue()){
      CmpiString SettingID = cmpiData;
      setSettingID(SettingID.charPtr());
    }
    
  }
  
  
  //Destructor
  Linux_DnsAddressMatchListInstance::
   ~Linux_DnsAddressMatchListInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAddressMatchListInstance&
   Linux_DnsAddressMatchListInstance::operator=
   (const Linux_DnsAddressMatchListInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAddressMatchListInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.AddressListType){
  	  cmpiInstance.setProperty("AddressListType",CmpiData(m_AddressListType));
  	}

  	if(isSet.AddressList){
  	  unsigned int AddressListSize;
      const char** arrayAddressList=getAddressList(AddressListSize);
      CmpiArray arrayCmpiAddressList=CmpiArray(AddressListSize,CMPI_chars);
      for(unsigned int i=0;i<AddressListSize;i++)
        arrayCmpiAddressList[i]=CmpiData(arrayAddressList[i]);
  	cmpiInstance.setProperty("AddressList",CmpiData(arrayCmpiAddressList));
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

  	if(isSet.SettingID){
  	  cmpiInstance.setProperty("SettingID",CmpiData(m_SettingID));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsAddressMatchListInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAddressMatchListInstanceName&
    Linux_DnsAddressMatchListInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAddressMatchList instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAddressMatchListInstance::setInstanceName(
   const Linux_DnsAddressMatchListInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //AddressListType related methods
  unsigned int Linux_DnsAddressMatchListInstance::isAddressListTypeSet() const{
    return isSet.AddressListType;
  }
  void Linux_DnsAddressMatchListInstance::
   setAddressListType(const CMPIUint16 val){
    m_AddressListType = val;
    isSet.AddressListType=1;
  }       
  const CMPIUint16 Linux_DnsAddressMatchListInstance::
   getAddressListType() const{
    
    if(!isSet.AddressListType)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "AddressListType not set");
   	   	
    return m_AddressListType;
  }
       
  //AddressList related methods
  unsigned int Linux_DnsAddressMatchListInstance::isAddressListSet() const{
    return isSet.AddressList;
  }
  void  Linux_DnsAddressMatchListInstance::
   setAddressList(const char** val, const unsigned int size, int makeCopy){
    AddressListArraySize=size;
    if (isSet.AddressList) {
      delete m_AddressList;
    }
    if (makeCopy&&val) {
      m_AddressList = new const char*[size];
      for(unsigned int i=0;i<size;i++){
        char* aString = new char[strlen(val[i])+1];
        strcpy(aString,val[i]);
        m_AddressList[i]=aString;
      }      
    } else {
      m_AddressList = val;
    }
    isSet.AddressList=1;
  }       
  const char** Linux_DnsAddressMatchListInstance::
   getAddressList(unsigned int& size) const{
    
    if(!isSet.AddressList)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "AddressList not set");
   	   	
    size=AddressListArraySize;
    return m_AddressList;
  }
       
  //Caption related methods
  unsigned int Linux_DnsAddressMatchListInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  Linux_DnsAddressMatchListInstance::
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
  const char* Linux_DnsAddressMatchListInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //Description related methods
  unsigned int Linux_DnsAddressMatchListInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  Linux_DnsAddressMatchListInstance::
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
  const char* Linux_DnsAddressMatchListInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int Linux_DnsAddressMatchListInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  Linux_DnsAddressMatchListInstance::
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
  const char* Linux_DnsAddressMatchListInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
       
  //SettingID related methods
  unsigned int Linux_DnsAddressMatchListInstance::isSettingIDSet() const{
    return isSet.SettingID;
  }
  void  Linux_DnsAddressMatchListInstance::
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
  const char* Linux_DnsAddressMatchListInstance::
   getSettingID() const{
    
    if(!isSet.SettingID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SettingID not set");
   	   	
    return m_SettingID;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAddressMatchListInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.AddressListType=0;   	
    isSet.AddressList=0;   	
    AddressListArraySize=0;   	
    isSet.Caption=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;   	
    isSet.SettingID=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAddressMatchListInstance::init
   (const Linux_DnsAddressMatchListInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isAddressListTypeSet()){
      const CMPIUint16 AddressListTypeOriginal=original.getAddressListType();
      setAddressListType(AddressListTypeOriginal);
    }   	
    if(original.isAddressListSet()){
      unsigned int sizeAddressList;
    const char** AddressListOriginal=original.getAddressList(sizeAddressList);
      setAddressList(AddressListOriginal, sizeAddressList, 1);
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
    if(original.isSettingIDSet()){
      const char* SettingIDOriginal=original.getSettingID();
      setSettingID(SettingIDOriginal, 1);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAddressMatchListInstance::reset(){
   	

  	if (isSet.AddressList){
  	  ArrayConverter::destructArray((char**)(char**)m_AddressList,AddressListArraySize);
  	}

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
  //Linux_DnsAddressMatchListInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAddressMatchListInstanceEnumerationElement::
   Linux_DnsAddressMatchListInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAddressMatchListInstanceEnumerationElement::
   ~Linux_DnsAddressMatchListInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAddressMatchListInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAddressMatchListInstanceEnumeration::
   Linux_DnsAddressMatchListInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAddressMatchListInstanceEnumeration::
   Linux_DnsAddressMatchListInstanceEnumeration(
   const Linux_DnsAddressMatchListInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAddressMatchListInstanceEnumeration::
   ~Linux_DnsAddressMatchListInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAddressMatchListInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAddressMatchListInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAddressMatchListInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAddressMatchListInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAddressMatchListInstance&  
   Linux_DnsAddressMatchListInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAddressMatchListInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAddressMatchListInstance&
   Linux_DnsAddressMatchListInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAddressMatchListInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAddressMatchListInstanceEnumeration::addElement
   (const Linux_DnsAddressMatchListInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAddressMatchListInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAddressMatchListInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAddressMatchListInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAddressMatchListInstance(elementP);
  	}
  };  
}
 
