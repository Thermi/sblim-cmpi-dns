 /**
 * Linux_DnsRecursionACLForServiceInstanceName.cpp
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
#include "Linux_DnsRecursionACLForServiceInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsRecursionACLForServiceInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsRecursionACLForServiceInstanceName::
   Linux_DnsRecursionACLForServiceInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsRecursionACLForServiceInstanceName::
   Linux_DnsRecursionACLForServiceInstanceName
   (const Linux_DnsRecursionACLForServiceInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsRecursionACLForServiceInstanceName::
   Linux_DnsRecursionACLForServiceInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiObjectPath Element = path.getKey("Element");
    setElement(Linux_DnsServiceInstanceName(Element));
    
    CmpiObjectPath Setting = path.getKey("Setting");
    setSetting(Linux_DnsAddressMatchListInstanceName(Setting));
    
  }
  
  
  //destructor
  Linux_DnsRecursionACLForServiceInstanceName::
   ~Linux_DnsRecursionACLForServiceInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsRecursionACLForServiceInstanceName&
   Linux_DnsRecursionACLForServiceInstanceName::operator=
   (const Linux_DnsRecursionACLForServiceInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsRecursionACLForServiceInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Element",CmpiData(m_Element.getObjectPath()));

  	objectPath.setKey("Setting",CmpiData(m_Setting.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsRecursionACLForServiceInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Element){
  	  cmpiInstance.setProperty("Element",CmpiData(m_Element.getObjectPath()));
  	}

  	if(isSet.Setting){
  	  cmpiInstance.setProperty("Setting",CmpiData(m_Setting.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsRecursionACLForServiceInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsRecursionACLForServiceInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsRecursionACLForService instanceName");
  	return m_namespace;
  }

  void Linux_DnsRecursionACLForServiceInstanceName::
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
  unsigned int Linux_DnsRecursionACLForServiceInstanceName::isElementSet() const{
    return isSet.Element;
  }
  void Linux_DnsRecursionACLForServiceInstanceName::
   setElement(const Linux_DnsServiceInstanceName& val){
    m_Element = val;
    isSet.Element=1;
  }       
  const Linux_DnsServiceInstanceName& Linux_DnsRecursionACLForServiceInstanceName::
   getElement() const{
    
    if(!isSet.Element)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Element not set");
   	   	
    return m_Element;
  }
       
  //Setting related methods
  unsigned int Linux_DnsRecursionACLForServiceInstanceName::isSettingSet() const{
    return isSet.Setting;
  }
  void Linux_DnsRecursionACLForServiceInstanceName::
   setSetting(const Linux_DnsAddressMatchListInstanceName& val){
    m_Setting = val;
    isSet.Setting=1;
  }       
  const Linux_DnsAddressMatchListInstanceName& Linux_DnsRecursionACLForServiceInstanceName::
   getSetting() const{
    
    if(!isSet.Setting)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Setting not set");
   	   	
    return m_Setting;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsRecursionACLForServiceInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsRecursionACLForService";
  	isSet.m_namespace=0;    	
    isSet.Element=0;   	
    isSet.Setting=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsRecursionACLForServiceInstanceName::init
   (const Linux_DnsRecursionACLForServiceInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isElementSet()){
      const Linux_DnsServiceInstanceName& ElementOriginal=original.getElement();
      setElement(ElementOriginal);
    }   	
    if(original.isSettingSet()){
      const Linux_DnsAddressMatchListInstanceName& SettingOriginal=original.getSetting();
      setSetting(SettingOriginal);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsRecursionACLForServiceInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement::
   Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement::
   ~Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsRecursionACLForServiceInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsRecursionACLForServiceInstanceNameEnumeration::
   Linux_DnsRecursionACLForServiceInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsRecursionACLForServiceInstanceNameEnumeration::
   Linux_DnsRecursionACLForServiceInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsRecursionACLForServiceInstanceName(arr[i]));
    }
  }
  
  Linux_DnsRecursionACLForServiceInstanceNameEnumeration::
   Linux_DnsRecursionACLForServiceInstanceNameEnumeration(
   const Linux_DnsRecursionACLForServiceInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsRecursionACLForServiceInstanceNameEnumeration::
   ~Linux_DnsRecursionACLForServiceInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsRecursionACLForServiceInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsRecursionACLForServiceInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsRecursionACLForServiceInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsRecursionACLForServiceInstanceName&  
   Linux_DnsRecursionACLForServiceInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsRecursionACLForServiceInstanceName&
   Linux_DnsRecursionACLForServiceInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsRecursionACLForServiceInstanceNameEnumeration::addElement
   (const Linux_DnsRecursionACLForServiceInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsRecursionACLForServiceInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsRecursionACLForServiceInstanceName(elementP);
  	}
  };
  
  Linux_DnsRecursionACLForServiceInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
