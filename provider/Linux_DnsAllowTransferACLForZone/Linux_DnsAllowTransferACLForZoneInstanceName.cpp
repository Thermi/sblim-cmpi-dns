 /**
 * Linux_DnsAllowTransferACLForZoneInstanceName.cpp
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
#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsAllowTransferACLForZoneInstanceName::
   Linux_DnsAllowTransferACLForZoneInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsAllowTransferACLForZoneInstanceName::
   Linux_DnsAllowTransferACLForZoneInstanceName
   (const Linux_DnsAllowTransferACLForZoneInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsAllowTransferACLForZoneInstanceName::
   Linux_DnsAllowTransferACLForZoneInstanceName (const CmpiObjectPath& path){
    
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
  Linux_DnsAllowTransferACLForZoneInstanceName::
   ~Linux_DnsAllowTransferACLForZoneInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAllowTransferACLForZoneInstanceName&
   Linux_DnsAllowTransferACLForZoneInstanceName::operator=
   (const Linux_DnsAllowTransferACLForZoneInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsAllowTransferACLForZoneInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Element",CmpiData(m_Element.getObjectPath()));

  	objectPath.setKey("Setting",CmpiData(m_Setting.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsAllowTransferACLForZoneInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Element){
  	  cmpiInstance.setProperty("Element",CmpiData(m_Element.getObjectPath()));
  	}

  	if(isSet.Setting){
  	  cmpiInstance.setProperty("Setting",CmpiData(m_Setting.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsAllowTransferACLForZoneInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsAllowTransferACLForZoneInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsAllowTransferACLForZone instanceName");
  	return m_namespace;
  }

  void Linux_DnsAllowTransferACLForZoneInstanceName::
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
  unsigned int Linux_DnsAllowTransferACLForZoneInstanceName::isElementSet() const{
    return isSet.Element;
  }
  void Linux_DnsAllowTransferACLForZoneInstanceName::
   setElement(const Linux_DnsZoneInstanceName& val){
    m_Element = val;
    isSet.Element=1;
  }       
  const Linux_DnsZoneInstanceName& Linux_DnsAllowTransferACLForZoneInstanceName::
   getElement() const{
    
    if(!isSet.Element)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Element not set");
   	   	
    return m_Element;
  }
       
  //Setting related methods
  unsigned int Linux_DnsAllowTransferACLForZoneInstanceName::isSettingSet() const{
    return isSet.Setting;
  }
  void Linux_DnsAllowTransferACLForZoneInstanceName::
   setSetting(const Linux_DnsAddressMatchListInstanceName& val){
    m_Setting = val;
    isSet.Setting=1;
  }       
  const Linux_DnsAddressMatchListInstanceName& Linux_DnsAllowTransferACLForZoneInstanceName::
   getSetting() const{
    
    if(!isSet.Setting)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Setting not set");
   	   	
    return m_Setting;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsAllowTransferACLForZoneInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsAllowTransferACLForZone";
  	isSet.m_namespace=0;    	
    isSet.Element=0;   	
    isSet.Setting=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsAllowTransferACLForZoneInstanceName::init
   (const Linux_DnsAllowTransferACLForZoneInstanceName& original){
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
  void Linux_DnsAllowTransferACLForZoneInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement::
   Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement::
   ~Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::
   Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::
   Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsAllowTransferACLForZoneInstanceName(arr[i]));
    }
  }
  
  Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::
   Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration(
   const Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::
   ~Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsAllowTransferACLForZoneInstanceName&  
   Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAllowTransferACLForZoneInstanceName&
   Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::addElement
   (const Linux_DnsAllowTransferACLForZoneInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAllowTransferACLForZoneInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAllowTransferACLForZoneInstanceName(elementP);
  	}
  };
  
  Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
