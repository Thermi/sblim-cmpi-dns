 /**
 * Linux_DnsAllowQueryACLForZoneInstanceName.cpp
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
#include "Linux_DnsAllowQueryACLForZoneInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsAllowQueryACLForZoneInstanceName::
   Linux_DnsAllowQueryACLForZoneInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsAllowQueryACLForZoneInstanceName::
   Linux_DnsAllowQueryACLForZoneInstanceName
   (const Linux_DnsAllowQueryACLForZoneInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsAllowQueryACLForZoneInstanceName::
   Linux_DnsAllowQueryACLForZoneInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiObjectPath Element = path.getKey("Element");
    setElement(Linux_DnsZoneInstanceName(Element));
    
    CmpiObjectPath Setting = path.getKey("Setting");
    setSetting(Linux_DnsAddressMatchListInstanceName(Setting));
    
  }
  
  
  //destructor
  Linux_DnsAllowQueryACLForZoneInstanceName::
   ~Linux_DnsAllowQueryACLForZoneInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowQueryACLForZoneInstanceName&
   Linux_DnsAllowQueryACLForZoneInstanceName::operator=
   (const Linux_DnsAllowQueryACLForZoneInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsAllowQueryACLForZoneInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Element",CmpiData(m_Element.getObjectPath()));

  	objectPath.setKey("Setting",CmpiData(m_Setting.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsAllowQueryACLForZoneInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Element){
  	  cmpiInstance.setProperty("Element",CmpiData(m_Element.getObjectPath()));
  	}

  	if(isSet.Setting){
  	  cmpiInstance.setProperty("Setting",CmpiData(m_Setting.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsAllowQueryACLForZoneInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsAllowQueryACLForZoneInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsAllowQueryACLForZone instanceName");
  	return m_namespace;
  }

  void Linux_DnsAllowQueryACLForZoneInstanceName::
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
  unsigned int Linux_DnsAllowQueryACLForZoneInstanceName::isElementSet() const{
    return isSet.Element;
  }
  void Linux_DnsAllowQueryACLForZoneInstanceName::
   setElement(const Linux_DnsZoneInstanceName& val){
    m_Element = val;
    isSet.Element=1;
  }       
  const Linux_DnsZoneInstanceName& Linux_DnsAllowQueryACLForZoneInstanceName::
   getElement() const{
    
    if(!isSet.Element)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Element not set");
   	   	
    return m_Element;
  }
       
  //Setting related methods
  unsigned int Linux_DnsAllowQueryACLForZoneInstanceName::isSettingSet() const{
    return isSet.Setting;
  }
  void Linux_DnsAllowQueryACLForZoneInstanceName::
   setSetting(const Linux_DnsAddressMatchListInstanceName& val){
    m_Setting = val;
    isSet.Setting=1;
  }       
  const Linux_DnsAddressMatchListInstanceName& Linux_DnsAllowQueryACLForZoneInstanceName::
   getSetting() const{
    
    if(!isSet.Setting)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Setting not set");
   	   	
    return m_Setting;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsAllowQueryACLForZoneInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsAllowQueryACLForZone";
  	isSet.m_namespace=0;    	
    isSet.Element=0;   	
    isSet.Setting=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsAllowQueryACLForZoneInstanceName::init
   (const Linux_DnsAllowQueryACLForZoneInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isElementSet()){
      const Linux_DnsZoneInstanceName& ElementOriginal=original.getElement();
      setElement(ElementOriginal);
    }   	
    if(original.isSettingSet()){
      const Linux_DnsAddressMatchListInstanceName& SettingOriginal=original.getSetting();
      setSetting(SettingOriginal);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsAllowQueryACLForZoneInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement::
   Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement::
   ~Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::
   Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::
   Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsAllowQueryACLForZoneInstanceName(arr[i]));
    }
  }
  
  Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::
   Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration(
   const Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::
   ~Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsAllowQueryACLForZoneInstanceName&  
   Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowQueryACLForZoneInstanceName&
   Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::addElement
   (const Linux_DnsAllowQueryACLForZoneInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowQueryACLForZoneInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowQueryACLForZoneInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowQueryACLForZoneInstanceName(elementP);
  	}
  };
  
  Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
