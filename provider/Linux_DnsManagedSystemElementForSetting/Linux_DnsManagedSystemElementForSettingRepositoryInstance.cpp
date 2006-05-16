// =======================================================================
// Linux_DnsManagedSystemElementForSettingRepositoryInstance.cpp
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#include "Linux_DnsManagedSystemElementForSettingRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsManagedSystemElementForSettingRepositoryInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::Linux_DnsManagedSystemElementForSettingRepositoryInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::Linux_DnsManagedSystemElementForSettingRepositoryInstance(
    const Linux_DnsManagedSystemElementForSettingRepositoryInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::Linux_DnsManagedSystemElementForSettingRepositoryInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsManagedSystemElementForSettingInstanceName(cop));

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::
   ~Linux_DnsManagedSystemElementForSettingRepositoryInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingRepositoryInstance&
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::operator=(
    const Linux_DnsManagedSystemElementForSettingRepositoryInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsManagedSystemElementForSettingInstanceName&
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsManagedSystemElementForSetting");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::setInstanceName(
    const Linux_DnsManagedSystemElementForSettingInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::init() {
   	isSet.instanceName = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::init(
    const Linux_DnsManagedSystemElementForSettingRepositoryInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
        
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingRepositoryInstance::reset() {
   	
  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement::Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement::~Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsManagedSystemElementForSettingRepositoryInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration(
    const Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::~Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsManagedSystemElementForSettingRepositoryInstance&  
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsManagedSystemElementForSettingRepositoryInstance&
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::getNext() {
   	
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration::addElement(
    const Linux_DnsManagedSystemElementForSettingRepositoryInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsManagedSystemElementForSettingRepositoryInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsManagedSystemElementForSettingRepositoryInstance(anInstance);
  	}

  }
  
}
