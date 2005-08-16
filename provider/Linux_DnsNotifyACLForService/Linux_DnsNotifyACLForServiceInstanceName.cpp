 /**
 * Linux_DnsNotifyACLForServiceInstanceName.cpp
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
#include "Linux_DnsNotifyACLForServiceInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsNotifyACLForServiceInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsNotifyACLForServiceInstanceName::
   Linux_DnsNotifyACLForServiceInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsNotifyACLForServiceInstanceName::
   Linux_DnsNotifyACLForServiceInstanceName
   (const Linux_DnsNotifyACLForServiceInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsNotifyACLForServiceInstanceName::
   Linux_DnsNotifyACLForServiceInstanceName (const CmpiObjectPath& path){
    
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
  Linux_DnsNotifyACLForServiceInstanceName::
   ~Linux_DnsNotifyACLForServiceInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsNotifyACLForServiceInstanceName&
   Linux_DnsNotifyACLForServiceInstanceName::operator=
   (const Linux_DnsNotifyACLForServiceInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsNotifyACLForServiceInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Element",CmpiData(m_Element.getObjectPath()));

  	objectPath.setKey("Setting",CmpiData(m_Setting.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsNotifyACLForServiceInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Element){
  	  cmpiInstance.setProperty("Element",CmpiData(m_Element.getObjectPath()));
  	}

  	if(isSet.Setting){
  	  cmpiInstance.setProperty("Setting",CmpiData(m_Setting.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsNotifyACLForServiceInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsNotifyACLForServiceInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsNotifyACLForService instanceName");
  	return m_namespace;
  }

  void Linux_DnsNotifyACLForServiceInstanceName::
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
  unsigned int Linux_DnsNotifyACLForServiceInstanceName::isElementSet() const{
    return isSet.Element;
  }
  void Linux_DnsNotifyACLForServiceInstanceName::
   setElement(const Linux_DnsServiceInstanceName& val){
    m_Element = val;
    isSet.Element=1;
  }       
  const Linux_DnsServiceInstanceName& Linux_DnsNotifyACLForServiceInstanceName::
   getElement() const{
    
    if(!isSet.Element)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Element not set");
   	   	
    return m_Element;
  }
       
  //Setting related methods
  unsigned int Linux_DnsNotifyACLForServiceInstanceName::isSettingSet() const{
    return isSet.Setting;
  }
  void Linux_DnsNotifyACLForServiceInstanceName::
   setSetting(const Linux_DnsAddressMatchListInstanceName& val){
    m_Setting = val;
    isSet.Setting=1;
  }       
  const Linux_DnsAddressMatchListInstanceName& Linux_DnsNotifyACLForServiceInstanceName::
   getSetting() const{
    
    if(!isSet.Setting)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Setting not set");
   	   	
    return m_Setting;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsNotifyACLForServiceInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsNotifyACLForService";
  	isSet.m_namespace=0;    	
    isSet.Element=0;   	
    isSet.Setting=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsNotifyACLForServiceInstanceName::init
   (const Linux_DnsNotifyACLForServiceInstanceName& original){
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
  void Linux_DnsNotifyACLForServiceInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement::
   Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement::
   ~Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsNotifyACLForServiceInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsNotifyACLForServiceInstanceNameEnumeration::
   Linux_DnsNotifyACLForServiceInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsNotifyACLForServiceInstanceNameEnumeration::
   Linux_DnsNotifyACLForServiceInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsNotifyACLForServiceInstanceName(arr[i]));
    }
  }
  
  Linux_DnsNotifyACLForServiceInstanceNameEnumeration::
   Linux_DnsNotifyACLForServiceInstanceNameEnumeration(
   const Linux_DnsNotifyACLForServiceInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsNotifyACLForServiceInstanceNameEnumeration::
   ~Linux_DnsNotifyACLForServiceInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsNotifyACLForServiceInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsNotifyACLForServiceInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsNotifyACLForServiceInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsNotifyACLForServiceInstanceName&  
   Linux_DnsNotifyACLForServiceInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsNotifyACLForServiceInstanceName&
   Linux_DnsNotifyACLForServiceInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsNotifyACLForServiceInstanceNameEnumeration::addElement
   (const Linux_DnsNotifyACLForServiceInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsNotifyACLForServiceInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsNotifyACLForServiceInstanceName(elementP);
  	}
  };
  
  Linux_DnsNotifyACLForServiceInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
