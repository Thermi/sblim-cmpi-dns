 /**
 * Linux_DnsMastersOfSlaveZoneInstanceName.cpp
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
#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsMastersOfSlaveZoneInstanceName::
   Linux_DnsMastersOfSlaveZoneInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsMastersOfSlaveZoneInstanceName::
   Linux_DnsMastersOfSlaveZoneInstanceName
   (const Linux_DnsMastersOfSlaveZoneInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsMastersOfSlaveZoneInstanceName::
   Linux_DnsMastersOfSlaveZoneInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiObjectPath Element = path.getKey("Element");
    setElement(Linux_DnsSlaveZoneInstanceName(Element));
    
    CmpiObjectPath Setting = path.getKey("Setting");
    setSetting(Linux_DnsIPAddressInstanceName(Setting));
    
  }
  
  
  //destructor
  Linux_DnsMastersOfSlaveZoneInstanceName::
   ~Linux_DnsMastersOfSlaveZoneInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsMastersOfSlaveZoneInstanceName&
   Linux_DnsMastersOfSlaveZoneInstanceName::operator=
   (const Linux_DnsMastersOfSlaveZoneInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsMastersOfSlaveZoneInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Element",CmpiData(m_Element.getObjectPath()));

  	objectPath.setKey("Setting",CmpiData(m_Setting.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsMastersOfSlaveZoneInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Element){
  	  cmpiInstance.setProperty("Element",CmpiData(m_Element.getObjectPath()));
  	}

  	if(isSet.Setting){
  	  cmpiInstance.setProperty("Setting",CmpiData(m_Setting.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsMastersOfSlaveZoneInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsMastersOfSlaveZoneInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsMastersOfSlaveZone instanceName");
  	return m_namespace;
  }

  void Linux_DnsMastersOfSlaveZoneInstanceName::
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
  unsigned int Linux_DnsMastersOfSlaveZoneInstanceName::isElementSet() const{
    return isSet.Element;
  }
  void Linux_DnsMastersOfSlaveZoneInstanceName::
   setElement(const Linux_DnsSlaveZoneInstanceName& val){
    m_Element = val;
    isSet.Element=1;
  }       
  const Linux_DnsSlaveZoneInstanceName& Linux_DnsMastersOfSlaveZoneInstanceName::
   getElement() const{
    
    if(!isSet.Element)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Element not set");
   	   	
    return m_Element;
  }
       
  //Setting related methods
  unsigned int Linux_DnsMastersOfSlaveZoneInstanceName::isSettingSet() const{
    return isSet.Setting;
  }
  void Linux_DnsMastersOfSlaveZoneInstanceName::
   setSetting(const Linux_DnsIPAddressInstanceName& val){
    m_Setting = val;
    isSet.Setting=1;
  }       
  const Linux_DnsIPAddressInstanceName& Linux_DnsMastersOfSlaveZoneInstanceName::
   getSetting() const{
    
    if(!isSet.Setting)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Setting not set");
   	   	
    return m_Setting;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsMastersOfSlaveZoneInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsMastersOfSlaveZone";
  	isSet.m_namespace=0;    	
    isSet.Element=0;   	
    isSet.Setting=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsMastersOfSlaveZoneInstanceName::init
   (const Linux_DnsMastersOfSlaveZoneInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isElementSet()){
      const Linux_DnsSlaveZoneInstanceName& ElementOriginal=original.getElement();
      setElement(ElementOriginal);
    }   	
    if(original.isSettingSet()){
      const Linux_DnsIPAddressInstanceName& SettingOriginal=original.getSetting();
      setSetting(SettingOriginal);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsMastersOfSlaveZoneInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement::
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement::
   ~Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsMastersOfSlaveZoneInstanceName(arr[i]));
    }
  }
  
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(
   const Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::
   ~Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsMastersOfSlaveZoneInstanceName&  
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsMastersOfSlaveZoneInstanceName&
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::addElement
   (const Linux_DnsMastersOfSlaveZoneInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsMastersOfSlaveZoneInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsMastersOfSlaveZoneInstanceName(elementP);
  	}
  };
  
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
