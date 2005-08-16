 /**
 * Linux_DnsZoneManualInstance.cpp
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
#include "Linux_DnsZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsZoneManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsZoneManualInstance::
   Linux_DnsZoneManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsZoneManualInstance::
   Linux_DnsZoneManualInstance
   (const Linux_DnsZoneManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsZoneManualInstance::
   Linux_DnsZoneManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsZoneInstanceName(cop));
    
    cmpiData = inst.getProperty("Contact");
    if(!cmpiData.isNullValue()){
      CmpiString Contact = cmpiData;
      setContact(Contact.charPtr());
    }
    
    cmpiData = inst.getProperty("ResourceRecordFile");
    if(!cmpiData.isNullValue()){
      CmpiString ResourceRecordFile = cmpiData;
      setResourceRecordFile(ResourceRecordFile.charPtr());
    }
    
    cmpiData = inst.getProperty("Type");
    if(!cmpiData.isNullValue()){
      CMPIUint16 Type = cmpiData;
      setType(Type);
    }
    
  }
  
  
  //Destructor
  Linux_DnsZoneManualInstance::
   ~Linux_DnsZoneManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsZoneManualInstance&
   Linux_DnsZoneManualInstance::operator=
   (const Linux_DnsZoneManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsZoneManualInstance::
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

  	if(isSet.ResourceRecordFile){
  	  cmpiInstance.setProperty("ResourceRecordFile",CmpiData(m_ResourceRecordFile));
  	}

  	if(isSet.Type){
  	  cmpiInstance.setProperty("Type",CmpiData(m_Type));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsZoneManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsZoneInstanceName&
    Linux_DnsZoneManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsZone instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsZoneManualInstance::setInstanceName(
   const Linux_DnsZoneInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Contact related methods
  unsigned int Linux_DnsZoneManualInstance::isContactSet() const{
    return isSet.Contact;
  }
  void  Linux_DnsZoneManualInstance::
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
  const char* Linux_DnsZoneManualInstance::
   getContact() const{
    
    if(!isSet.Contact)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Contact not set");
   	   	
    return m_Contact;
  }
       
  //ResourceRecordFile related methods
  unsigned int Linux_DnsZoneManualInstance::isResourceRecordFileSet() const{
    return isSet.ResourceRecordFile;
  }
  void  Linux_DnsZoneManualInstance::
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
  const char* Linux_DnsZoneManualInstance::
   getResourceRecordFile() const{
    
    if(!isSet.ResourceRecordFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ResourceRecordFile not set");
   	   	
    return m_ResourceRecordFile;
  }
       
  //Type related methods
  unsigned int Linux_DnsZoneManualInstance::isTypeSet() const{
    return isSet.Type;
  }
  void Linux_DnsZoneManualInstance::
   setType(const CMPIUint16 val){
    m_Type = val;
    isSet.Type=1;
  }       
  const CMPIUint16 Linux_DnsZoneManualInstance::
   getType() const{
    
    if(!isSet.Type)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Type not set");
   	   	
    return m_Type;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsZoneManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Contact=0;   	
    isSet.ResourceRecordFile=0;   	
    isSet.Type=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsZoneManualInstance::init
   (const Linux_DnsZoneManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isContactSet()){
      const char* ContactOriginal=original.getContact();
      setContact(ContactOriginal, 1);
    }   	
    if(original.isResourceRecordFileSet()){
      const char* ResourceRecordFileOriginal=original.getResourceRecordFile();
      setResourceRecordFile(ResourceRecordFileOriginal, 1);
    }   	
    if(original.isTypeSet()){
      const CMPIUint16 TypeOriginal=original.getType();
      setType(TypeOriginal);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsZoneManualInstance::reset(){
   	

  	if (isSet.Contact)
  	  delete(m_Contact);

  	if (isSet.ResourceRecordFile)
  	  delete(m_ResourceRecordFile);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsZoneManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsZoneManualInstanceEnumerationElement::
   Linux_DnsZoneManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsZoneManualInstanceEnumerationElement::
   ~Linux_DnsZoneManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsZoneManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsZoneManualInstanceEnumeration::
   Linux_DnsZoneManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsZoneManualInstanceEnumeration::
   Linux_DnsZoneManualInstanceEnumeration(
   const Linux_DnsZoneManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsZoneManualInstanceEnumeration::
   ~Linux_DnsZoneManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsZoneManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsZoneManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsZoneManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsZoneManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsZoneManualInstance&  
   Linux_DnsZoneManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsZoneManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsZoneManualInstance&
   Linux_DnsZoneManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsZoneManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsZoneManualInstanceEnumeration::addElement
   (const Linux_DnsZoneManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsZoneManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsZoneManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsZoneManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsZoneManualInstance(elementP);
  	}
  };  
}
 
