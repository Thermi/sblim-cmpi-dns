 /**
 * Linux_DnsTransferACLForServiceInstanceName.cpp
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
#include "Linux_DnsTransferACLForServiceInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsTransferACLForServiceInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsTransferACLForServiceInstanceName::
   Linux_DnsTransferACLForServiceInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsTransferACLForServiceInstanceName::
   Linux_DnsTransferACLForServiceInstanceName
   (const Linux_DnsTransferACLForServiceInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsTransferACLForServiceInstanceName::
   Linux_DnsTransferACLForServiceInstanceName (const CmpiObjectPath& path){
    
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
  Linux_DnsTransferACLForServiceInstanceName::
   ~Linux_DnsTransferACLForServiceInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsTransferACLForServiceInstanceName&
   Linux_DnsTransferACLForServiceInstanceName::operator=
   (const Linux_DnsTransferACLForServiceInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsTransferACLForServiceInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Element",CmpiData(m_Element.getObjectPath()));

  	objectPath.setKey("Setting",CmpiData(m_Setting.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsTransferACLForServiceInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Element){
  	  cmpiInstance.setProperty("Element",CmpiData(m_Element.getObjectPath()));
  	}

  	if(isSet.Setting){
  	  cmpiInstance.setProperty("Setting",CmpiData(m_Setting.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsTransferACLForServiceInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsTransferACLForServiceInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsTransferACLForService instanceName");
  	return m_namespace;
  }

  void Linux_DnsTransferACLForServiceInstanceName::
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
  unsigned int Linux_DnsTransferACLForServiceInstanceName::isElementSet() const{
    return isSet.Element;
  }
  void Linux_DnsTransferACLForServiceInstanceName::
   setElement(const Linux_DnsServiceInstanceName& val){
    m_Element = val;
    isSet.Element=1;
  }       
  const Linux_DnsServiceInstanceName& Linux_DnsTransferACLForServiceInstanceName::
   getElement() const{
    
    if(!isSet.Element)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Element not set");
   	   	
    return m_Element;
  }
       
  //Setting related methods
  unsigned int Linux_DnsTransferACLForServiceInstanceName::isSettingSet() const{
    return isSet.Setting;
  }
  void Linux_DnsTransferACLForServiceInstanceName::
   setSetting(const Linux_DnsAddressMatchListInstanceName& val){
    m_Setting = val;
    isSet.Setting=1;
  }       
  const Linux_DnsAddressMatchListInstanceName& Linux_DnsTransferACLForServiceInstanceName::
   getSetting() const{
    
    if(!isSet.Setting)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Setting not set");
   	   	
    return m_Setting;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsTransferACLForServiceInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsTransferACLForService";
  	isSet.m_namespace=0;    	
    isSet.Element=0;   	
    isSet.Setting=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsTransferACLForServiceInstanceName::init
   (const Linux_DnsTransferACLForServiceInstanceName& original){
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
  void Linux_DnsTransferACLForServiceInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsTransferACLForServiceInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsTransferACLForServiceInstanceNameEnumerationElement::
   Linux_DnsTransferACLForServiceInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsTransferACLForServiceInstanceNameEnumerationElement::
   ~Linux_DnsTransferACLForServiceInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsTransferACLForServiceInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsTransferACLForServiceInstanceNameEnumeration::
   Linux_DnsTransferACLForServiceInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsTransferACLForServiceInstanceNameEnumeration::
   Linux_DnsTransferACLForServiceInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsTransferACLForServiceInstanceName(arr[i]));
    }
  }
  
  Linux_DnsTransferACLForServiceInstanceNameEnumeration::
   Linux_DnsTransferACLForServiceInstanceNameEnumeration(
   const Linux_DnsTransferACLForServiceInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsTransferACLForServiceInstanceNameEnumeration::
   ~Linux_DnsTransferACLForServiceInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsTransferACLForServiceInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsTransferACLForServiceInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsTransferACLForServiceInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsTransferACLForServiceInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsTransferACLForServiceInstanceName&  
   Linux_DnsTransferACLForServiceInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsTransferACLForServiceInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsTransferACLForServiceInstanceName&
   Linux_DnsTransferACLForServiceInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsTransferACLForServiceInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsTransferACLForServiceInstanceNameEnumeration::addElement
   (const Linux_DnsTransferACLForServiceInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsTransferACLForServiceInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsTransferACLForServiceInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsTransferACLForServiceInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsTransferACLForServiceInstanceName(elementP);
  	}
  };
  
  Linux_DnsTransferACLForServiceInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
