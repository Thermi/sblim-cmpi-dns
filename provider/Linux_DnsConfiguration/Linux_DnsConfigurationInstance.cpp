 /**
 * Linux_DnsConfigurationInstance.cpp
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
#include "Linux_DnsConfigurationInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsConfigurationInstance
  //*********************************************************

  //empty constructor
  Linux_DnsConfigurationInstance::
   Linux_DnsConfigurationInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsConfigurationInstance::
   Linux_DnsConfigurationInstance
   (const Linux_DnsConfigurationInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsConfigurationInstance::
   Linux_DnsConfigurationInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsConfigurationInstanceName(cop));
    
    cmpiData = inst.getProperty("Caption");
    if(!cmpiData.isNullValue()){
      CmpiString Caption = cmpiData;
      setCaption(Caption.charPtr());
    }
    
    cmpiData = inst.getProperty("ConfigurationFile");
    if(!cmpiData.isNullValue()){
      CmpiString ConfigurationFile = cmpiData;
      setConfigurationFile(ConfigurationFile.charPtr());
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
    
  }
  
  
  //Destructor
  Linux_DnsConfigurationInstance::
   ~Linux_DnsConfigurationInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsConfigurationInstance&
   Linux_DnsConfigurationInstance::operator=
   (const Linux_DnsConfigurationInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsConfigurationInstance::
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

  	if(isSet.ConfigurationFile){
  	  cmpiInstance.setProperty("ConfigurationFile",CmpiData(m_ConfigurationFile));
  	}

  	if(isSet.Description){
  	  cmpiInstance.setProperty("Description",CmpiData(m_Description));
  	}

  	if(isSet.ElementName){
  	  cmpiInstance.setProperty("ElementName",CmpiData(m_ElementName));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsConfigurationInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsConfigurationInstanceName&
    Linux_DnsConfigurationInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsConfiguration instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsConfigurationInstance::setInstanceName(
   const Linux_DnsConfigurationInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int Linux_DnsConfigurationInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  Linux_DnsConfigurationInstance::
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
  const char* Linux_DnsConfigurationInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //ConfigurationFile related methods
  unsigned int Linux_DnsConfigurationInstance::isConfigurationFileSet() const{
    return isSet.ConfigurationFile;
  }
  void  Linux_DnsConfigurationInstance::
   setConfigurationFile(const char* val, int makeCopy){
    if (isSet.ConfigurationFile) {
      delete []m_ConfigurationFile;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ConfigurationFile = tmpval;
    } else {
      m_ConfigurationFile = val;
    }
    isSet.ConfigurationFile=1;
  }       
  const char* Linux_DnsConfigurationInstance::
   getConfigurationFile() const{
    
    if(!isSet.ConfigurationFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ConfigurationFile not set");
   	   	
    return m_ConfigurationFile;
  }
       
  //Description related methods
  unsigned int Linux_DnsConfigurationInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  Linux_DnsConfigurationInstance::
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
  const char* Linux_DnsConfigurationInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int Linux_DnsConfigurationInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  Linux_DnsConfigurationInstance::
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
  const char* Linux_DnsConfigurationInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsConfigurationInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.ConfigurationFile=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsConfigurationInstance::init
   (const Linux_DnsConfigurationInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isCaptionSet()){
      const char* CaptionOriginal=original.getCaption();
      setCaption(CaptionOriginal, 1);
    }   	
    if(original.isConfigurationFileSet()){
      const char* ConfigurationFileOriginal=original.getConfigurationFile();
      setConfigurationFile(ConfigurationFileOriginal, 1);
    }   	
    if(original.isDescriptionSet()){
      const char* DescriptionOriginal=original.getDescription();
      setDescription(DescriptionOriginal, 1);
    }   	
    if(original.isElementNameSet()){
      const char* ElementNameOriginal=original.getElementName();
      setElementName(ElementNameOriginal, 1);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsConfigurationInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.ConfigurationFile)
  	  delete(m_ConfigurationFile);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsConfigurationInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsConfigurationInstanceEnumerationElement::
   Linux_DnsConfigurationInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsConfigurationInstanceEnumerationElement::
   ~Linux_DnsConfigurationInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsConfigurationInstanceNameEnumeration
  //*********************************************************

  Linux_DnsConfigurationInstanceEnumeration::
   Linux_DnsConfigurationInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsConfigurationInstanceEnumeration::
   Linux_DnsConfigurationInstanceEnumeration(
   const Linux_DnsConfigurationInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsConfigurationInstanceEnumeration::
   ~Linux_DnsConfigurationInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsConfigurationInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsConfigurationInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsConfigurationInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsConfigurationInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsConfigurationInstance&  
   Linux_DnsConfigurationInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsConfigurationInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsConfigurationInstance&
   Linux_DnsConfigurationInstanceEnumeration::getNext() {
   	
  	 Linux_DnsConfigurationInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsConfigurationInstanceEnumeration::addElement
   (const Linux_DnsConfigurationInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsConfigurationInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsConfigurationInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsConfigurationInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsConfigurationInstance(elementP);
  	}
  };  
}
 
