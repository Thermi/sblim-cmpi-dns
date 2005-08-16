 /**
 * Linux_DnsResourceRecordInZoneInstanceName.cpp
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
#include "Linux_DnsResourceRecordInZoneInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsResourceRecordInZoneInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsResourceRecordInZoneInstanceName::
   Linux_DnsResourceRecordInZoneInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsResourceRecordInZoneInstanceName::
   Linux_DnsResourceRecordInZoneInstanceName
   (const Linux_DnsResourceRecordInZoneInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsResourceRecordInZoneInstanceName::
   Linux_DnsResourceRecordInZoneInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiObjectPath GroupComponent = path.getKey("GroupComponent");
    setGroupComponent(Linux_DnsZoneInstanceName(GroupComponent));
    
    CmpiObjectPath PartComponent = path.getKey("PartComponent");
    setPartComponent(Linux_DnsResourceRecordInstanceName(PartComponent));
    
  }
  
  
  //destructor
  Linux_DnsResourceRecordInZoneInstanceName::
   ~Linux_DnsResourceRecordInZoneInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsResourceRecordInZoneInstanceName&
   Linux_DnsResourceRecordInZoneInstanceName::operator=
   (const Linux_DnsResourceRecordInZoneInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsResourceRecordInZoneInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("GroupComponent",CmpiData(m_GroupComponent.getObjectPath()));

  	objectPath.setKey("PartComponent",CmpiData(m_PartComponent.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsResourceRecordInZoneInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.GroupComponent){
  	  cmpiInstance.setProperty("GroupComponent",CmpiData(m_GroupComponent.getObjectPath()));
  	}

  	if(isSet.PartComponent){
  	  cmpiInstance.setProperty("PartComponent",CmpiData(m_PartComponent.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsResourceRecordInZoneInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsResourceRecordInZoneInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsResourceRecordInZone instanceName");
  	return m_namespace;
  }

  void Linux_DnsResourceRecordInZoneInstanceName::
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
       
  //GroupComponent related methods
  unsigned int Linux_DnsResourceRecordInZoneInstanceName::isGroupComponentSet() const{
    return isSet.GroupComponent;
  }
  void Linux_DnsResourceRecordInZoneInstanceName::
   setGroupComponent(const Linux_DnsZoneInstanceName& val){
    m_GroupComponent = val;
    isSet.GroupComponent=1;
  }       
  const Linux_DnsZoneInstanceName& Linux_DnsResourceRecordInZoneInstanceName::
   getGroupComponent() const{
    
    if(!isSet.GroupComponent)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "GroupComponent not set");
   	   	
    return m_GroupComponent;
  }
       
  //PartComponent related methods
  unsigned int Linux_DnsResourceRecordInZoneInstanceName::isPartComponentSet() const{
    return isSet.PartComponent;
  }
  void Linux_DnsResourceRecordInZoneInstanceName::
   setPartComponent(const Linux_DnsResourceRecordInstanceName& val){
    m_PartComponent = val;
    isSet.PartComponent=1;
  }       
  const Linux_DnsResourceRecordInstanceName& Linux_DnsResourceRecordInZoneInstanceName::
   getPartComponent() const{
    
    if(!isSet.PartComponent)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "PartComponent not set");
   	   	
    return m_PartComponent;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsResourceRecordInZoneInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsResourceRecordInZone";
  	isSet.m_namespace=0;    	
    isSet.GroupComponent=0;   	
    isSet.PartComponent=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsResourceRecordInZoneInstanceName::init
   (const Linux_DnsResourceRecordInZoneInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isGroupComponentSet()){
      const Linux_DnsZoneInstanceName& GroupComponentOriginal=original.getGroupComponent();
      setGroupComponent(GroupComponentOriginal);
    }   	
    if(original.isPartComponentSet()){
      const Linux_DnsResourceRecordInstanceName& PartComponentOriginal=original.getPartComponent();
      setPartComponent(PartComponentOriginal);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsResourceRecordInZoneInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement::
   Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement::
   ~Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsResourceRecordInZoneInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsResourceRecordInZoneInstanceNameEnumeration::
   Linux_DnsResourceRecordInZoneInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsResourceRecordInZoneInstanceNameEnumeration::
   Linux_DnsResourceRecordInZoneInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsResourceRecordInZoneInstanceName(arr[i]));
    }
  }
  
  Linux_DnsResourceRecordInZoneInstanceNameEnumeration::
   Linux_DnsResourceRecordInZoneInstanceNameEnumeration(
   const Linux_DnsResourceRecordInZoneInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsResourceRecordInZoneInstanceNameEnumeration::
   ~Linux_DnsResourceRecordInZoneInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsResourceRecordInZoneInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsResourceRecordInZoneInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsResourceRecordInZoneInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsResourceRecordInZoneInstanceName&  
   Linux_DnsResourceRecordInZoneInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsResourceRecordInZoneInstanceName&
   Linux_DnsResourceRecordInZoneInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsResourceRecordInZoneInstanceNameEnumeration::addElement
   (const Linux_DnsResourceRecordInZoneInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsResourceRecordInZoneInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsResourceRecordInZoneInstanceName(elementP);
  	}
  };
  
  Linux_DnsResourceRecordInZoneInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
