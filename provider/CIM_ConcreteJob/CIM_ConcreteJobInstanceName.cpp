 /**
 * CIM_ConcreteJobInstanceName.cpp
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
#include "CIM_ConcreteJobInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //CIM_ConcreteJobInstanceName
  //*********************************************************
  
  //empty constructor
  CIM_ConcreteJobInstanceName::
   CIM_ConcreteJobInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  CIM_ConcreteJobInstanceName::
   CIM_ConcreteJobInstanceName
   (const CIM_ConcreteJobInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  CIM_ConcreteJobInstanceName::
   CIM_ConcreteJobInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiString InstanceID = path.getKey("InstanceID");
    setInstanceID(InstanceID.charPtr());
    
  }
  
  
  //destructor
  CIM_ConcreteJobInstanceName::
   ~CIM_ConcreteJobInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  CIM_ConcreteJobInstanceName&
   CIM_ConcreteJobInstanceName::operator=
   (const CIM_ConcreteJobInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath CIM_ConcreteJobInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("InstanceID",CmpiData(m_InstanceID));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void CIM_ConcreteJobInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.InstanceID){
  	  cmpiInstance.setProperty("InstanceID",CmpiData(m_InstanceID));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int CIM_ConcreteJobInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * CIM_ConcreteJobInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in CIM_ConcreteJob instanceName");
  	return m_namespace;
  }

  void CIM_ConcreteJobInstanceName::
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
       
  //InstanceID related methods
  unsigned int CIM_ConcreteJobInstanceName::isInstanceIDSet() const{
    return isSet.InstanceID;
  }
  void  CIM_ConcreteJobInstanceName::
   setInstanceID(const char* val, int makeCopy){
    if (isSet.InstanceID) {
      delete []m_InstanceID;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_InstanceID = tmpval;
    } else {
      m_InstanceID = val;
    }
    isSet.InstanceID=1;
  }       
  const char* CIM_ConcreteJobInstanceName::
   getInstanceID() const{
    
    if(!isSet.InstanceID)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceID not set");
   	   	
    return m_InstanceID;
  }

  
  //set isSet variables to FALSE
  void CIM_ConcreteJobInstanceName::init(){
  	
  	m_CIMClassNameP="CIM_ConcreteJob";
  	isSet.m_namespace=0;    	
    isSet.InstanceID=0;
  }
  
  
  //copies another instance properties in this
  void CIM_ConcreteJobInstanceName::init
   (const CIM_ConcreteJobInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isInstanceIDSet()){
      const char* InstanceIDOriginal=original.getInstanceID();
      setInstanceID(InstanceIDOriginal, 1);
    }    
  }
  
  //reset the instanceName data
  void CIM_ConcreteJobInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);

  	if (isSet.InstanceID)
  	  delete(m_InstanceID);  	  
  };
  
  
  
  
  //*********************************************************
  //CIM_ConcreteJobInstanceNameEnumerationElement	
  //*********************************************************
  
  CIM_ConcreteJobInstanceNameEnumerationElement::
   CIM_ConcreteJobInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  CIM_ConcreteJobInstanceNameEnumerationElement::
   ~CIM_ConcreteJobInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //CIM_ConcreteJobInstanceNameEnumeration
  //*********************************************************
  
  CIM_ConcreteJobInstanceNameEnumeration::
   CIM_ConcreteJobInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  CIM_ConcreteJobInstanceNameEnumeration::
   CIM_ConcreteJobInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(CIM_ConcreteJobInstanceName(arr[i]));
    }
  }
  
  CIM_ConcreteJobInstanceNameEnumeration::
   CIM_ConcreteJobInstanceNameEnumeration(
   const CIM_ConcreteJobInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  CIM_ConcreteJobInstanceNameEnumeration::
   ~CIM_ConcreteJobInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void CIM_ConcreteJobInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool CIM_ConcreteJobInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int CIM_ConcreteJobInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    CIM_ConcreteJobInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const CIM_ConcreteJobInstanceName&  
   CIM_ConcreteJobInstanceNameEnumeration::getElement(int pos) const{
   
    CIM_ConcreteJobInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const CIM_ConcreteJobInstanceName&
   CIM_ConcreteJobInstanceNameEnumeration::getNext() {
   	
  	 CIM_ConcreteJobInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void CIM_ConcreteJobInstanceNameEnumeration::addElement
   (const CIM_ConcreteJobInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new CIM_ConcreteJobInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new CIM_ConcreteJobInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new CIM_ConcreteJobInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new CIM_ConcreteJobInstanceName(elementP);
  	}
  };
  
  CIM_ConcreteJobInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
