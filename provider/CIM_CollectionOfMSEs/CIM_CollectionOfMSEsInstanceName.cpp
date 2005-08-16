 /**
 * CIM_CollectionOfMSEsInstanceName.cpp
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
#include "CIM_CollectionOfMSEsInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //CIM_CollectionOfMSEsInstanceName
  //*********************************************************
  
  //empty constructor
  CIM_CollectionOfMSEsInstanceName::
   CIM_CollectionOfMSEsInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  CIM_CollectionOfMSEsInstanceName::
   CIM_CollectionOfMSEsInstanceName
   (const CIM_CollectionOfMSEsInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  CIM_CollectionOfMSEsInstanceName::
   CIM_CollectionOfMSEsInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
  }
  
  
  //destructor
  CIM_CollectionOfMSEsInstanceName::
   ~CIM_CollectionOfMSEsInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  CIM_CollectionOfMSEsInstanceName&
   CIM_CollectionOfMSEsInstanceName::operator=
   (const CIM_CollectionOfMSEsInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath CIM_CollectionOfMSEsInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void CIM_CollectionOfMSEsInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	
  }
  
  
  //NameSpace related methods
  unsigned int CIM_CollectionOfMSEsInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * CIM_CollectionOfMSEsInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in CIM_CollectionOfMSEs instanceName");
  	return m_namespace;
  }

  void CIM_CollectionOfMSEsInstanceName::
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
  void CIM_CollectionOfMSEsInstanceName::init(){
  	
  	m_CIMClassNameP="CIM_CollectionOfMSEs";
  	isSet.m_namespace=0; 
  }
  
  
  //copies another instance properties in this
  void CIM_CollectionOfMSEsInstanceName::init
   (const CIM_CollectionOfMSEsInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }    
  }
  
  //reset the instanceName data
  void CIM_CollectionOfMSEsInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //CIM_CollectionOfMSEsInstanceNameEnumerationElement	
  //*********************************************************
  
  CIM_CollectionOfMSEsInstanceNameEnumerationElement::
   CIM_CollectionOfMSEsInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  CIM_CollectionOfMSEsInstanceNameEnumerationElement::
   ~CIM_CollectionOfMSEsInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //CIM_CollectionOfMSEsInstanceNameEnumeration
  //*********************************************************
  
  CIM_CollectionOfMSEsInstanceNameEnumeration::
   CIM_CollectionOfMSEsInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  CIM_CollectionOfMSEsInstanceNameEnumeration::
   CIM_CollectionOfMSEsInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(CIM_CollectionOfMSEsInstanceName(arr[i]));
    }
  }
  
  CIM_CollectionOfMSEsInstanceNameEnumeration::
   CIM_CollectionOfMSEsInstanceNameEnumeration(
   const CIM_CollectionOfMSEsInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  CIM_CollectionOfMSEsInstanceNameEnumeration::
   ~CIM_CollectionOfMSEsInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void CIM_CollectionOfMSEsInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool CIM_CollectionOfMSEsInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int CIM_CollectionOfMSEsInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    CIM_CollectionOfMSEsInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const CIM_CollectionOfMSEsInstanceName&  
   CIM_CollectionOfMSEsInstanceNameEnumeration::getElement(int pos) const{
   
    CIM_CollectionOfMSEsInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const CIM_CollectionOfMSEsInstanceName&
   CIM_CollectionOfMSEsInstanceNameEnumeration::getNext() {
   	
  	 CIM_CollectionOfMSEsInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void CIM_CollectionOfMSEsInstanceNameEnumeration::addElement
   (const CIM_CollectionOfMSEsInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new CIM_CollectionOfMSEsInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new CIM_CollectionOfMSEsInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new CIM_CollectionOfMSEsInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new CIM_CollectionOfMSEsInstanceName(elementP);
  	}
  };
  
  CIM_CollectionOfMSEsInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
