 /**
 * CIM_CollectionOfMSEsInstance.cpp
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
#include "CIM_CollectionOfMSEsInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //CIM_CollectionOfMSEsInstance
  //*********************************************************

  //empty constructor
  CIM_CollectionOfMSEsInstance::
   CIM_CollectionOfMSEsInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  CIM_CollectionOfMSEsInstance::
   CIM_CollectionOfMSEsInstance
   (const CIM_CollectionOfMSEsInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  CIM_CollectionOfMSEsInstance::
   CIM_CollectionOfMSEsInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(CIM_CollectionOfMSEsInstanceName(cop));
    
    cmpiData = inst.getProperty("Caption");
    if(!cmpiData.isNullValue()){
      CmpiString Caption = cmpiData;
      setCaption(Caption.charPtr());
    }
    
    cmpiData = inst.getProperty("CollectionID");
    if(!cmpiData.isNullValue()){
      CmpiString CollectionID = cmpiData;
      setCollectionID(CollectionID.charPtr());
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
  CIM_CollectionOfMSEsInstance::
   ~CIM_CollectionOfMSEsInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  CIM_CollectionOfMSEsInstance&
   CIM_CollectionOfMSEsInstance::operator=
   (const CIM_CollectionOfMSEsInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance CIM_CollectionOfMSEsInstance::
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

  	if(isSet.CollectionID){
  	  cmpiInstance.setProperty("CollectionID",CmpiData(m_CollectionID));
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
  unsigned int CIM_CollectionOfMSEsInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const CIM_CollectionOfMSEsInstanceName&
    CIM_CollectionOfMSEsInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in CIM_CollectionOfMSEs instance");
  		
   	return m_instanceName;
  }

  void CIM_CollectionOfMSEsInstance::setInstanceName(
   const CIM_CollectionOfMSEsInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int CIM_CollectionOfMSEsInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  CIM_CollectionOfMSEsInstance::
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
  const char* CIM_CollectionOfMSEsInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //CollectionID related methods
  unsigned int CIM_CollectionOfMSEsInstance::isCollectionIDSet() const{
    return isSet.CollectionID;
  }
  void  CIM_CollectionOfMSEsInstance::
   setCollectionID(const char* val, int makeCopy){
    if (isSet.CollectionID) {
      delete []m_CollectionID;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_CollectionID = tmpval;
    } else {
      m_CollectionID = val;
    }
    isSet.CollectionID=1;
  }       
  const char* CIM_CollectionOfMSEsInstance::
   getCollectionID() const{
    
    if(!isSet.CollectionID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "CollectionID not set");
   	   	
    return m_CollectionID;
  }
       
  //Description related methods
  unsigned int CIM_CollectionOfMSEsInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  CIM_CollectionOfMSEsInstance::
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
  const char* CIM_CollectionOfMSEsInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElementName related methods
  unsigned int CIM_CollectionOfMSEsInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  CIM_CollectionOfMSEsInstance::
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
  const char* CIM_CollectionOfMSEsInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }


  
  //set isSet attributes to FALSE
  void CIM_CollectionOfMSEsInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.CollectionID=0;   	
    isSet.Description=0;   	
    isSet.ElementName=0;  	
  };
  
  
  //copies another instance properties in this
  void CIM_CollectionOfMSEsInstance::init
   (const CIM_CollectionOfMSEsInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isCaptionSet()){
      const char* CaptionOriginal=original.getCaption();
      setCaption(CaptionOriginal, 1);
    }   	
    if(original.isCollectionIDSet()){
      const char* CollectionIDOriginal=original.getCollectionID();
      setCollectionID(CollectionIDOriginal, 1);
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
  void CIM_CollectionOfMSEsInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.CollectionID)
  	  delete(m_CollectionID);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);
  	  
  };
  
  
  //*********************************************************
  //CIM_CollectionOfMSEsInstanceEnumerationElement	
  //*********************************************************
  
  CIM_CollectionOfMSEsInstanceEnumerationElement::
   CIM_CollectionOfMSEsInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  CIM_CollectionOfMSEsInstanceEnumerationElement::
   ~CIM_CollectionOfMSEsInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //CIM_CollectionOfMSEsInstanceNameEnumeration
  //*********************************************************

  CIM_CollectionOfMSEsInstanceEnumeration::
   CIM_CollectionOfMSEsInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  CIM_CollectionOfMSEsInstanceEnumeration::
   CIM_CollectionOfMSEsInstanceEnumeration(
   const CIM_CollectionOfMSEsInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  CIM_CollectionOfMSEsInstanceEnumeration::
   ~CIM_CollectionOfMSEsInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void CIM_CollectionOfMSEsInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool CIM_CollectionOfMSEsInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int CIM_CollectionOfMSEsInstanceEnumeration::getSize() const{
  	
    int size=0;
    CIM_CollectionOfMSEsInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const CIM_CollectionOfMSEsInstance&  
   CIM_CollectionOfMSEsInstanceEnumeration::getElement(int pos) const{
   
    CIM_CollectionOfMSEsInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const CIM_CollectionOfMSEsInstance&
   CIM_CollectionOfMSEsInstanceEnumeration::getNext() {
   	
  	 CIM_CollectionOfMSEsInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void CIM_CollectionOfMSEsInstanceEnumeration::addElement
   (const CIM_CollectionOfMSEsInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new CIM_CollectionOfMSEsInstanceEnumerationElement();
  	  firstElementP->m_elementP=new CIM_CollectionOfMSEsInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new CIM_CollectionOfMSEsInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new CIM_CollectionOfMSEsInstance(elementP);
  	}
  };  
}
 
