 /**
 * Linux_DnsResourceRecordInstanceName.cpp
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
#include "Linux_DnsResourceRecordInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsResourceRecordInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsResourceRecordInstanceName::
   Linux_DnsResourceRecordInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsResourceRecordInstanceName::
   Linux_DnsResourceRecordInstanceName
   (const Linux_DnsResourceRecordInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsResourceRecordInstanceName::
   Linux_DnsResourceRecordInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
   
    CmpiInstance inst = CmpiInstance( path );
 
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiString Name = path.getKey("Name");
    setName(Name.charPtr());
    
    //CMPIUint16 Type = path.getKey("Type");
    CMPIUint16 Type = inst.getProperty("Type");
    setType(Type);
    
    CmpiString Value = path.getKey("Value");
    setValue(Value.charPtr());
    
    CmpiString ZoneName = path.getKey("ZoneName");
    setZoneName(ZoneName.charPtr());
    
  }
  
  
  //destructor
  Linux_DnsResourceRecordInstanceName::
   ~Linux_DnsResourceRecordInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsResourceRecordInstanceName&
   Linux_DnsResourceRecordInstanceName::operator=
   (const Linux_DnsResourceRecordInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsResourceRecordInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Name",CmpiData(m_Name));

  	objectPath.setKey("Type",CmpiData(m_Type));

  	objectPath.setKey("Value",CmpiData(m_Value));

  	objectPath.setKey("ZoneName",CmpiData(m_ZoneName));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsResourceRecordInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Name){
  	  cmpiInstance.setProperty("Name",CmpiData(m_Name));
  	}

  	if(isSet.Type){
  	  cmpiInstance.setProperty("Type",CmpiData(m_Type));
  	}

  	if(isSet.Value){
  	  cmpiInstance.setProperty("Value",CmpiData(m_Value));
  	}

  	if(isSet.ZoneName){
  	  cmpiInstance.setProperty("ZoneName",CmpiData(m_ZoneName));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsResourceRecordInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsResourceRecordInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsResourceRecord instanceName");
  	return m_namespace;
  }

  void Linux_DnsResourceRecordInstanceName::
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
  unsigned int Linux_DnsResourceRecordInstanceName::isNameSet() const{
    return isSet.Name;
  }
  void  Linux_DnsResourceRecordInstanceName::
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
  const char* Linux_DnsResourceRecordInstanceName::
   getName() const{
    
    if(!isSet.Name)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Name not set");
   	   	
    return m_Name;
  }
       
  //Type related methods
  unsigned int Linux_DnsResourceRecordInstanceName::isTypeSet() const{
    return isSet.Type;
  }
  void Linux_DnsResourceRecordInstanceName::
   setType(const CMPIUint16 val){
    m_Type = val;
    isSet.Type=1;
  }       
  const CMPIUint16 Linux_DnsResourceRecordInstanceName::
   getType() const{
    
    if(!isSet.Type)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Type not set");
   	   	
    return m_Type;
  }
       
  //Value related methods
  unsigned int Linux_DnsResourceRecordInstanceName::isValueSet() const{
    return isSet.Value;
  }
  void  Linux_DnsResourceRecordInstanceName::
   setValue(const char* val, int makeCopy){
    if (isSet.Value) {
      delete []m_Value;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Value = tmpval;
    } else {
      m_Value = val;
    }
    isSet.Value=1;
  }       
  const char* Linux_DnsResourceRecordInstanceName::
   getValue() const{
    
    if(!isSet.Value)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Value not set");
   	   	
    return m_Value;
  }
       
  //ZoneName related methods
  unsigned int Linux_DnsResourceRecordInstanceName::isZoneNameSet() const{
    return isSet.ZoneName;
  }
  void  Linux_DnsResourceRecordInstanceName::
   setZoneName(const char* val, int makeCopy){
    if (isSet.ZoneName) {
      delete []m_ZoneName;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ZoneName = tmpval;
    } else {
      m_ZoneName = val;
    }
    isSet.ZoneName=1;
  }       
  const char* Linux_DnsResourceRecordInstanceName::
   getZoneName() const{
    
    if(!isSet.ZoneName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ZoneName not set");
   	   	
    return m_ZoneName;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsResourceRecordInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsResourceRecord";
  	isSet.m_namespace=0;    	
    isSet.Name=0;   	
    isSet.Type=0;   	
    isSet.Value=0;   	
    isSet.ZoneName=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsResourceRecordInstanceName::init
   (const Linux_DnsResourceRecordInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isNameSet()){
      const char* NameOriginal=original.getName();
      setName(NameOriginal, 1);
    }   	
    if(original.isTypeSet()){
      const CMPIUint16 TypeOriginal=original.getType();
      setType(TypeOriginal);
    }   	
    if(original.isValueSet()){
      const char* ValueOriginal=original.getValue();
      setValue(ValueOriginal, 1);
    }   	
    if(original.isZoneNameSet()){
      const char* ZoneNameOriginal=original.getZoneName();
      setZoneName(ZoneNameOriginal, 1);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsResourceRecordInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);

  	if (isSet.Name)
  	  delete(m_Name);

  	if (isSet.Value)
  	  delete(m_Value);

  	if (isSet.ZoneName)
  	  delete(m_ZoneName);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsResourceRecordInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsResourceRecordInstanceNameEnumerationElement::
   Linux_DnsResourceRecordInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsResourceRecordInstanceNameEnumerationElement::
   ~Linux_DnsResourceRecordInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsResourceRecordInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsResourceRecordInstanceNameEnumeration::
   Linux_DnsResourceRecordInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsResourceRecordInstanceNameEnumeration::
   Linux_DnsResourceRecordInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsResourceRecordInstanceName(arr[i]));
    }
  }
  
  Linux_DnsResourceRecordInstanceNameEnumeration::
   Linux_DnsResourceRecordInstanceNameEnumeration(
   const Linux_DnsResourceRecordInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsResourceRecordInstanceNameEnumeration::
   ~Linux_DnsResourceRecordInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsResourceRecordInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsResourceRecordInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsResourceRecordInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsResourceRecordInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsResourceRecordInstanceName&  
   Linux_DnsResourceRecordInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsResourceRecordInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsResourceRecordInstanceName&
   Linux_DnsResourceRecordInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsResourceRecordInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsResourceRecordInstanceNameEnumeration::addElement
   (const Linux_DnsResourceRecordInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsResourceRecordInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsResourceRecordInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsResourceRecordInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsResourceRecordInstanceName(elementP);
  	}
  };
  
  Linux_DnsResourceRecordInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
