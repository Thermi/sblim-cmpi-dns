 /**
 * Linux_DnsServiceInstanceName.cpp
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
#include "Linux_DnsServiceInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsServiceInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsServiceInstanceName::
   Linux_DnsServiceInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsServiceInstanceName::
   Linux_DnsServiceInstanceName
   (const Linux_DnsServiceInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsServiceInstanceName::
   Linux_DnsServiceInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiString CreationClassName = path.getKey("CreationClassName");
    setCreationClassName(CreationClassName.charPtr());
    
    CmpiString Name = path.getKey("Name");
    setName(Name.charPtr());
    
    CmpiString SystemCreationClassName = path.getKey("SystemCreationClassName");
    setSystemCreationClassName(SystemCreationClassName.charPtr());
    
    CmpiString SystemName = path.getKey("SystemName");
    setSystemName(SystemName.charPtr());
    
  }
  
  
  //destructor
  Linux_DnsServiceInstanceName::
   ~Linux_DnsServiceInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsServiceInstanceName&
   Linux_DnsServiceInstanceName::operator=
   (const Linux_DnsServiceInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsServiceInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("CreationClassName",CmpiData(m_CreationClassName));

  	objectPath.setKey("Name",CmpiData(m_Name));

  	objectPath.setKey("SystemCreationClassName",CmpiData(m_SystemCreationClassName));

  	objectPath.setKey("SystemName",CmpiData(m_SystemName));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsServiceInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.CreationClassName){
  	  cmpiInstance.setProperty("CreationClassName",CmpiData(m_CreationClassName));
  	}

  	if(isSet.Name){
  	  cmpiInstance.setProperty("Name",CmpiData(m_Name));
  	}

  	if(isSet.SystemCreationClassName){
  	  cmpiInstance.setProperty("SystemCreationClassName",CmpiData(m_SystemCreationClassName));
  	}

  	if(isSet.SystemName){
  	  cmpiInstance.setProperty("SystemName",CmpiData(m_SystemName));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsServiceInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsServiceInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsService instanceName");
  	return m_namespace;
  }

  void Linux_DnsServiceInstanceName::
   setNamespace(const char* val, int makeCopy){
    if (isSet.m_namespace) {
      delete m_namespace;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_namespace = tmpval;
    } else {
      m_namespace = val;
    }
    isSet.m_namespace=1;
  }
       
  //CreationClassName related methods
  unsigned int Linux_DnsServiceInstanceName::isCreationClassNameSet() const{
    return isSet.CreationClassName;
  }
  void  Linux_DnsServiceInstanceName::
   setCreationClassName(const char* val, int makeCopy){
    if (isSet.CreationClassName) {
      delete []m_CreationClassName;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_CreationClassName = tmpval;
    } else {
      m_CreationClassName = val;
    }
    isSet.CreationClassName=1;
  }       
  const char* Linux_DnsServiceInstanceName::
   getCreationClassName() const{
    
    if(!isSet.CreationClassName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "CreationClassName not set");
   	   	
    return m_CreationClassName;
  }
       
  //Name related methods
  unsigned int Linux_DnsServiceInstanceName::isNameSet() const{
    return isSet.Name;
  }
  void  Linux_DnsServiceInstanceName::
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
  const char* Linux_DnsServiceInstanceName::
   getName() const{
    
    if(!isSet.Name)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Name not set");
   	   	
    return m_Name;
  }
       
  //SystemCreationClassName related methods
  unsigned int Linux_DnsServiceInstanceName::isSystemCreationClassNameSet() const{
    return isSet.SystemCreationClassName;
  }
  void  Linux_DnsServiceInstanceName::
   setSystemCreationClassName(const char* val, int makeCopy){
    if (isSet.SystemCreationClassName) {
      delete []m_SystemCreationClassName;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_SystemCreationClassName = tmpval;
    } else {
      m_SystemCreationClassName = val;
    }
    isSet.SystemCreationClassName=1;
  }       
  const char* Linux_DnsServiceInstanceName::
   getSystemCreationClassName() const{
    
    if(!isSet.SystemCreationClassName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SystemCreationClassName not set");
   	   	
    return m_SystemCreationClassName;
  }
       
  //SystemName related methods
  unsigned int Linux_DnsServiceInstanceName::isSystemNameSet() const{
    return isSet.SystemName;
  }
  void  Linux_DnsServiceInstanceName::
   setSystemName(const char* val, int makeCopy){
    if (isSet.SystemName) {
      delete []m_SystemName;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_SystemName = tmpval;
    } else {
      m_SystemName = val;
    }
    isSet.SystemName=1;
  }       
  const char* Linux_DnsServiceInstanceName::
   getSystemName() const{
    
    if(!isSet.SystemName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "SystemName not set");
   	   	
    return m_SystemName;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsServiceInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsService";
  	isSet.m_namespace=0;    	
    isSet.CreationClassName=0;   	
    isSet.Name=0;   	
    isSet.SystemCreationClassName=0;   	
    isSet.SystemName=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsServiceInstanceName::init
   (const Linux_DnsServiceInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isCreationClassNameSet()){
      const char* CreationClassNameOriginal=original.getCreationClassName();
      setCreationClassName(CreationClassNameOriginal, 1);
    }   	
    if(original.isNameSet()){
      const char* NameOriginal=original.getName();
      setName(NameOriginal, 1);
    }   	
    if(original.isSystemCreationClassNameSet()){
      const char* SystemCreationClassNameOriginal=original.getSystemCreationClassName();
      setSystemCreationClassName(SystemCreationClassNameOriginal, 1);
    }   	
    if(original.isSystemNameSet()){
      const char* SystemNameOriginal=original.getSystemName();
      setSystemName(SystemNameOriginal, 1);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsServiceInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);

  	if (isSet.CreationClassName)
  	  delete(m_CreationClassName);

  	if (isSet.Name)
  	  delete(m_Name);

  	if (isSet.SystemCreationClassName)
  	  delete(m_SystemCreationClassName);

  	if (isSet.SystemName)
  	  delete(m_SystemName);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsServiceInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsServiceInstanceNameEnumerationElement::
   Linux_DnsServiceInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsServiceInstanceNameEnumerationElement::
   ~Linux_DnsServiceInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsServiceInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsServiceInstanceNameEnumeration::
   Linux_DnsServiceInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsServiceInstanceNameEnumeration::
   Linux_DnsServiceInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsServiceInstanceName(arr[i]));
    }
  }
  
  Linux_DnsServiceInstanceNameEnumeration::
   Linux_DnsServiceInstanceNameEnumeration(
   const Linux_DnsServiceInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsServiceInstanceNameEnumeration::
   ~Linux_DnsServiceInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsServiceInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsServiceInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsServiceInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsServiceInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsServiceInstanceName&  
   Linux_DnsServiceInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsServiceInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsServiceInstanceName&
   Linux_DnsServiceInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsServiceInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsServiceInstanceNameEnumeration::addElement
   (const Linux_DnsServiceInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsServiceInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsServiceInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsServiceInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsServiceInstanceName(elementP);
  	}
  };
  
  Linux_DnsServiceInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
