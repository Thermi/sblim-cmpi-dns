 /**
 * Linux_DnsSettingInstanceName.cpp
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
#include "Linux_DnsSettingInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsSettingInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsSettingInstanceName::
   Linux_DnsSettingInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsSettingInstanceName::
   Linux_DnsSettingInstanceName
   (const Linux_DnsSettingInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsSettingInstanceName::
   Linux_DnsSettingInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiString Name = path.getKey("Name");
    setName(Name.charPtr());
    
  }
  
  
  //destructor
  Linux_DnsSettingInstanceName::
   ~Linux_DnsSettingInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsSettingInstanceName&
   Linux_DnsSettingInstanceName::operator=
   (const Linux_DnsSettingInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsSettingInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Name",CmpiData(m_Name));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsSettingInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Name){
  	  cmpiInstance.setProperty("Name",CmpiData(m_Name));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsSettingInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsSettingInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsSetting instanceName");
  	return m_namespace;
  }

  void Linux_DnsSettingInstanceName::
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
  unsigned int Linux_DnsSettingInstanceName::isNameSet() const{
    return isSet.Name;
  }
  void  Linux_DnsSettingInstanceName::
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
  const char* Linux_DnsSettingInstanceName::
   getName() const{
    
    if(!isSet.Name)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Name not set");
   	   	
    return m_Name;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsSettingInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsSetting";
  	isSet.m_namespace=0;    	
    isSet.Name=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsSettingInstanceName::init
   (const Linux_DnsSettingInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isNameSet()){
      const char* NameOriginal=original.getName();
      setName(NameOriginal, 1);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsSettingInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);

  	if (isSet.Name)
  	  delete(m_Name);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsSettingInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsSettingInstanceNameEnumerationElement::
   Linux_DnsSettingInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsSettingInstanceNameEnumerationElement::
   ~Linux_DnsSettingInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsSettingInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsSettingInstanceNameEnumeration::
   Linux_DnsSettingInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsSettingInstanceNameEnumeration::
   Linux_DnsSettingInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsSettingInstanceName(arr[i]));
    }
  }
  
  Linux_DnsSettingInstanceNameEnumeration::
   Linux_DnsSettingInstanceNameEnumeration(
   const Linux_DnsSettingInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsSettingInstanceNameEnumeration::
   ~Linux_DnsSettingInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsSettingInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsSettingInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsSettingInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsSettingInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsSettingInstanceName&  
   Linux_DnsSettingInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsSettingInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsSettingInstanceName&
   Linux_DnsSettingInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsSettingInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsSettingInstanceNameEnumeration::addElement
   (const Linux_DnsSettingInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsSettingInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsSettingInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsSettingInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsSettingInstanceName(elementP);
  	}
  };
  
  Linux_DnsSettingInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
