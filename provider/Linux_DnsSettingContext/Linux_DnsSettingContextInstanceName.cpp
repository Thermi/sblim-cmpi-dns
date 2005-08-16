 /**
 * Linux_DnsSettingContextInstanceName.cpp
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
#include "Linux_DnsSettingContextInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsSettingContextInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsSettingContextInstanceName::
   Linux_DnsSettingContextInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsSettingContextInstanceName::
   Linux_DnsSettingContextInstanceName
   (const Linux_DnsSettingContextInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsSettingContextInstanceName::
   Linux_DnsSettingContextInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiObjectPath Context = path.getKey("Context");
    setContext(Linux_DnsConfigurationInstanceName(Context));
    
    CmpiObjectPath Setting = path.getKey("Setting");
    setSetting(Linux_DnsSettingInstanceName(Setting));
    
  }
  
  
  //destructor
  Linux_DnsSettingContextInstanceName::
   ~Linux_DnsSettingContextInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSettingContextInstanceName&
   Linux_DnsSettingContextInstanceName::operator=
   (const Linux_DnsSettingContextInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsSettingContextInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Context",CmpiData(m_Context.getObjectPath()));

  	objectPath.setKey("Setting",CmpiData(m_Setting.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsSettingContextInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Context){
  	  cmpiInstance.setProperty("Context",CmpiData(m_Context.getObjectPath()));
  	}

  	if(isSet.Setting){
  	  cmpiInstance.setProperty("Setting",CmpiData(m_Setting.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsSettingContextInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsSettingContextInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsSettingContext instanceName");
  	return m_namespace;
  }

  void Linux_DnsSettingContextInstanceName::
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
       
  //Context related methods
  unsigned int Linux_DnsSettingContextInstanceName::isContextSet() const{
    return isSet.Context;
  }
  void Linux_DnsSettingContextInstanceName::
   setContext(const Linux_DnsConfigurationInstanceName& val){
    m_Context = val;
    isSet.Context=1;
  }       
  const Linux_DnsConfigurationInstanceName& Linux_DnsSettingContextInstanceName::
   getContext() const{
    
    if(!isSet.Context)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Context not set");
   	   	
    return m_Context;
  }
       
  //Setting related methods
  unsigned int Linux_DnsSettingContextInstanceName::isSettingSet() const{
    return isSet.Setting;
  }
  void Linux_DnsSettingContextInstanceName::
   setSetting(const Linux_DnsSettingInstanceName& val){
    m_Setting = val;
    isSet.Setting=1;
  }       
  const Linux_DnsSettingInstanceName& Linux_DnsSettingContextInstanceName::
   getSetting() const{
    
    if(!isSet.Setting)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Setting not set");
   	   	
    return m_Setting;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsSettingContextInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsSettingContext";
  	isSet.m_namespace=0;    	
    isSet.Context=0;   	
    isSet.Setting=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsSettingContextInstanceName::init
   (const Linux_DnsSettingContextInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isContextSet()){
      const Linux_DnsConfigurationInstanceName& ContextOriginal=original.getContext();
      setContext(ContextOriginal);
    }   	
    if(original.isSettingSet()){
      const Linux_DnsSettingInstanceName& SettingOriginal=original.getSetting();
      setSetting(SettingOriginal);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsSettingContextInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsSettingContextInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsSettingContextInstanceNameEnumerationElement::
   Linux_DnsSettingContextInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSettingContextInstanceNameEnumerationElement::
   ~Linux_DnsSettingContextInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSettingContextInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsSettingContextInstanceNameEnumeration::
   Linux_DnsSettingContextInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSettingContextInstanceNameEnumeration::
   Linux_DnsSettingContextInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsSettingContextInstanceName(arr[i]));
    }
  }
  
  Linux_DnsSettingContextInstanceNameEnumeration::
   Linux_DnsSettingContextInstanceNameEnumeration(
   const Linux_DnsSettingContextInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSettingContextInstanceNameEnumeration::
   ~Linux_DnsSettingContextInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSettingContextInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSettingContextInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSettingContextInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSettingContextInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsSettingContextInstanceName&  
   Linux_DnsSettingContextInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsSettingContextInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSettingContextInstanceName&
   Linux_DnsSettingContextInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsSettingContextInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSettingContextInstanceNameEnumeration::addElement
   (const Linux_DnsSettingContextInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSettingContextInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSettingContextInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSettingContextInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSettingContextInstanceName(elementP);
  	}
  };
  
  Linux_DnsSettingContextInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
