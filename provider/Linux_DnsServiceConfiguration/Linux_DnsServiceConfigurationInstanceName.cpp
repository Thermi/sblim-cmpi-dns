 /**
 * Linux_DnsServiceConfigurationInstanceName.cpp
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
#include "Linux_DnsServiceConfigurationInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsServiceConfigurationInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsServiceConfigurationInstanceName::
   Linux_DnsServiceConfigurationInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsServiceConfigurationInstanceName::
   Linux_DnsServiceConfigurationInstanceName
   (const Linux_DnsServiceConfigurationInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsServiceConfigurationInstanceName::
   Linux_DnsServiceConfigurationInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiObjectPath Element = path.getKey("Element");
    setElement(Linux_DnsServiceInstanceName(Element));
    
    CmpiObjectPath Configuration = path.getKey("Configuration");
    setConfiguration(Linux_DnsConfigurationInstanceName(Configuration));
    
  }
  
  
  //destructor
  Linux_DnsServiceConfigurationInstanceName::
   ~Linux_DnsServiceConfigurationInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsServiceConfigurationInstanceName&
   Linux_DnsServiceConfigurationInstanceName::operator=
   (const Linux_DnsServiceConfigurationInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsServiceConfigurationInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Element",CmpiData(m_Element.getObjectPath()));

  	objectPath.setKey("Configuration",CmpiData(m_Configuration.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsServiceConfigurationInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Element){
  	  cmpiInstance.setProperty("Element",CmpiData(m_Element.getObjectPath()));
  	}

  	if(isSet.Configuration){
  	  cmpiInstance.setProperty("Configuration",CmpiData(m_Configuration.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsServiceConfigurationInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsServiceConfigurationInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsServiceConfiguration instanceName");
  	return m_namespace;
  }

  void Linux_DnsServiceConfigurationInstanceName::
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
       
  //Element related methods
  unsigned int Linux_DnsServiceConfigurationInstanceName::isElementSet() const{
    return isSet.Element;
  }
  void Linux_DnsServiceConfigurationInstanceName::
   setElement(const Linux_DnsServiceInstanceName& val){
    m_Element = val;
    isSet.Element=1;
  }       
  const Linux_DnsServiceInstanceName& Linux_DnsServiceConfigurationInstanceName::
   getElement() const{
    
    if(!isSet.Element)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Element not set");
   	   	
    return m_Element;
  }
       
  //Configuration related methods
  unsigned int Linux_DnsServiceConfigurationInstanceName::isConfigurationSet() const{
    return isSet.Configuration;
  }
  void Linux_DnsServiceConfigurationInstanceName::
   setConfiguration(const Linux_DnsConfigurationInstanceName& val){
    m_Configuration = val;
    isSet.Configuration=1;
  }       
  const Linux_DnsConfigurationInstanceName& Linux_DnsServiceConfigurationInstanceName::
   getConfiguration() const{
    
    if(!isSet.Configuration)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Configuration not set");
   	   	
    return m_Configuration;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsServiceConfigurationInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsServiceConfiguration";
  	isSet.m_namespace=0;    	
    isSet.Element=0;   	
    isSet.Configuration=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsServiceConfigurationInstanceName::init
   (const Linux_DnsServiceConfigurationInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isElementSet()){
      const Linux_DnsServiceInstanceName& ElementOriginal=original.getElement();
      setElement(ElementOriginal);
    }   	
    if(original.isConfigurationSet()){
      const Linux_DnsConfigurationInstanceName& ConfigurationOriginal=original.getConfiguration();
      setConfiguration(ConfigurationOriginal);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsServiceConfigurationInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsServiceConfigurationInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsServiceConfigurationInstanceNameEnumerationElement::
   Linux_DnsServiceConfigurationInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsServiceConfigurationInstanceNameEnumerationElement::
   ~Linux_DnsServiceConfigurationInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsServiceConfigurationInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsServiceConfigurationInstanceNameEnumeration::
   Linux_DnsServiceConfigurationInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsServiceConfigurationInstanceNameEnumeration::
   Linux_DnsServiceConfigurationInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsServiceConfigurationInstanceName(arr[i]));
    }
  }
  
  Linux_DnsServiceConfigurationInstanceNameEnumeration::
   Linux_DnsServiceConfigurationInstanceNameEnumeration(
   const Linux_DnsServiceConfigurationInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsServiceConfigurationInstanceNameEnumeration::
   ~Linux_DnsServiceConfigurationInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsServiceConfigurationInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsServiceConfigurationInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsServiceConfigurationInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsServiceConfigurationInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsServiceConfigurationInstanceName&  
   Linux_DnsServiceConfigurationInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsServiceConfigurationInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsServiceConfigurationInstanceName&
   Linux_DnsServiceConfigurationInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsServiceConfigurationInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsServiceConfigurationInstanceNameEnumeration::addElement
   (const Linux_DnsServiceConfigurationInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsServiceConfigurationInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsServiceConfigurationInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsServiceConfigurationInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsServiceConfigurationInstanceName(elementP);
  	}
  };
  
  Linux_DnsServiceConfigurationInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
