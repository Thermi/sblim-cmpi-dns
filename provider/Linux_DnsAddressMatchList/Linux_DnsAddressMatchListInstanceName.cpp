 /**
 * Linux_DnsAddressMatchListInstanceName.cpp
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
#include "Linux_DnsAddressMatchListInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsAddressMatchListInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsAddressMatchListInstanceName::
   Linux_DnsAddressMatchListInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsAddressMatchListInstanceName::
   Linux_DnsAddressMatchListInstanceName
   (const Linux_DnsAddressMatchListInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsAddressMatchListInstanceName::
   Linux_DnsAddressMatchListInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiString Name = path.getKey("Name");
    setName(Name.charPtr());
    
    CmpiString ServiceName = path.getKey("ServiceName");
    setServiceName(ServiceName.charPtr());
    
  }
  
  
  //destructor
  Linux_DnsAddressMatchListInstanceName::
   ~Linux_DnsAddressMatchListInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAddressMatchListInstanceName&
   Linux_DnsAddressMatchListInstanceName::operator=
   (const Linux_DnsAddressMatchListInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsAddressMatchListInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Name",CmpiData(m_Name));

  	objectPath.setKey("ServiceName",CmpiData(m_ServiceName));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsAddressMatchListInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Name){
  	  cmpiInstance.setProperty("Name",CmpiData(m_Name));
  	}

  	if(isSet.ServiceName){
  	  cmpiInstance.setProperty("ServiceName",CmpiData(m_ServiceName));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsAddressMatchListInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsAddressMatchListInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsAddressMatchList instanceName");
  	return m_namespace;
  }

  void Linux_DnsAddressMatchListInstanceName::
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
       
  //Name related methods
  unsigned int Linux_DnsAddressMatchListInstanceName::isNameSet() const{
    return isSet.Name;
  }
  void  Linux_DnsAddressMatchListInstanceName::
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
  const char* Linux_DnsAddressMatchListInstanceName::
   getName() const{
    
    if(!isSet.Name)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Name not set");
   	   	
    return m_Name;
  }
       
  //ServiceName related methods
  unsigned int Linux_DnsAddressMatchListInstanceName::isServiceNameSet() const{
    return isSet.ServiceName;
  }
  void  Linux_DnsAddressMatchListInstanceName::
   setServiceName(const char* val, int makeCopy){
    if (isSet.ServiceName) {
      delete []m_ServiceName;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ServiceName = tmpval;
    } else {
      m_ServiceName = val;
    }
    isSet.ServiceName=1;
  }       
  const char* Linux_DnsAddressMatchListInstanceName::
   getServiceName() const{
    
    if(!isSet.ServiceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ServiceName not set");
   	   	
    return m_ServiceName;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsAddressMatchListInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsAddressMatchList";
  	isSet.m_namespace=0;    	
    isSet.Name=0;   	
    isSet.ServiceName=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsAddressMatchListInstanceName::init
   (const Linux_DnsAddressMatchListInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isNameSet()){
      const char* NameOriginal=original.getName();
      setName(NameOriginal, 1);
    }   	
    if(original.isServiceNameSet()){
      const char* ServiceNameOriginal=original.getServiceName();
      setServiceName(ServiceNameOriginal, 1);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsAddressMatchListInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);

  	if (isSet.Name)
  	  delete(m_Name);

  	if (isSet.ServiceName)
  	  delete(m_ServiceName);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsAddressMatchListInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsAddressMatchListInstanceNameEnumerationElement::
   Linux_DnsAddressMatchListInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAddressMatchListInstanceNameEnumerationElement::
   ~Linux_DnsAddressMatchListInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAddressMatchListInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsAddressMatchListInstanceNameEnumeration::
   Linux_DnsAddressMatchListInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAddressMatchListInstanceNameEnumeration::
   Linux_DnsAddressMatchListInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsAddressMatchListInstanceName(arr[i]));
    }
  }
  
  Linux_DnsAddressMatchListInstanceNameEnumeration::
   Linux_DnsAddressMatchListInstanceNameEnumeration(
   const Linux_DnsAddressMatchListInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAddressMatchListInstanceNameEnumeration::
   ~Linux_DnsAddressMatchListInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAddressMatchListInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAddressMatchListInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAddressMatchListInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAddressMatchListInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsAddressMatchListInstanceName&  
   Linux_DnsAddressMatchListInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsAddressMatchListInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAddressMatchListInstanceName&
   Linux_DnsAddressMatchListInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsAddressMatchListInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAddressMatchListInstanceNameEnumeration::addElement
   (const Linux_DnsAddressMatchListInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAddressMatchListInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAddressMatchListInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAddressMatchListInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAddressMatchListInstanceName(elementP);
  	}
  };
  
  Linux_DnsAddressMatchListInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
