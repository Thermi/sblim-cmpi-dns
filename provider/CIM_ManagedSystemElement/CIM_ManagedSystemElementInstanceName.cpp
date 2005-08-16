 /**
 * CIM_ManagedSystemElementInstanceName.cpp
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
#include "CIM_ManagedSystemElementInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //CIM_ManagedSystemElementInstanceName
  //*********************************************************
  
  //empty constructor
  CIM_ManagedSystemElementInstanceName::
   CIM_ManagedSystemElementInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  CIM_ManagedSystemElementInstanceName::
   CIM_ManagedSystemElementInstanceName
   (const CIM_ManagedSystemElementInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  CIM_ManagedSystemElementInstanceName::
   CIM_ManagedSystemElementInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
  }
  
  
  //destructor
  CIM_ManagedSystemElementInstanceName::
   ~CIM_ManagedSystemElementInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  CIM_ManagedSystemElementInstanceName&
   CIM_ManagedSystemElementInstanceName::operator=
   (const CIM_ManagedSystemElementInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath CIM_ManagedSystemElementInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void CIM_ManagedSystemElementInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	
  }
  
  
  //NameSpace related methods
  unsigned int CIM_ManagedSystemElementInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * CIM_ManagedSystemElementInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in CIM_ManagedSystemElement instanceName");
  	return m_namespace;
  }

  void CIM_ManagedSystemElementInstanceName::
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

  
  //set isSet variables to FALSE
  void CIM_ManagedSystemElementInstanceName::init(){
  	
  	m_CIMClassNameP="CIM_ManagedSystemElement";
  	isSet.m_namespace=0; 
  }
  
  
  //copies another instance properties in this
  void CIM_ManagedSystemElementInstanceName::init
   (const CIM_ManagedSystemElementInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }    
  }
  
  //reset the instanceName data
  void CIM_ManagedSystemElementInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //CIM_ManagedSystemElementInstanceNameEnumerationElement	
  //*********************************************************
  
  CIM_ManagedSystemElementInstanceNameEnumerationElement::
   CIM_ManagedSystemElementInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  CIM_ManagedSystemElementInstanceNameEnumerationElement::
   ~CIM_ManagedSystemElementInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //CIM_ManagedSystemElementInstanceNameEnumeration
  //*********************************************************
  
  CIM_ManagedSystemElementInstanceNameEnumeration::
   CIM_ManagedSystemElementInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  CIM_ManagedSystemElementInstanceNameEnumeration::
   CIM_ManagedSystemElementInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(CIM_ManagedSystemElementInstanceName(arr[i]));
    }
  }
  
  CIM_ManagedSystemElementInstanceNameEnumeration::
   CIM_ManagedSystemElementInstanceNameEnumeration(
   const CIM_ManagedSystemElementInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  CIM_ManagedSystemElementInstanceNameEnumeration::
   ~CIM_ManagedSystemElementInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void CIM_ManagedSystemElementInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool CIM_ManagedSystemElementInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int CIM_ManagedSystemElementInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    CIM_ManagedSystemElementInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const CIM_ManagedSystemElementInstanceName&  
   CIM_ManagedSystemElementInstanceNameEnumeration::getElement(int pos) const{
   
    CIM_ManagedSystemElementInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const CIM_ManagedSystemElementInstanceName&
   CIM_ManagedSystemElementInstanceNameEnumeration::getNext() {
   	
  	 CIM_ManagedSystemElementInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void CIM_ManagedSystemElementInstanceNameEnumeration::addElement
   (const CIM_ManagedSystemElementInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new CIM_ManagedSystemElementInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new CIM_ManagedSystemElementInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new CIM_ManagedSystemElementInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new CIM_ManagedSystemElementInstanceName(elementP);
  	}
  };
  
  CIM_ManagedSystemElementInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
