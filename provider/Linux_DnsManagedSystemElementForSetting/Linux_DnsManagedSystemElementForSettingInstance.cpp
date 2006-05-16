// =======================================================================
// Linux_DnsManagedSystemElementForSettingInstance.cpp
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
#include "Linux_DnsManagedSystemElementForSettingInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsManagedSystemElementForSettingInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsManagedSystemElementForSettingInstance::Linux_DnsManagedSystemElementForSettingInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingInstance::Linux_DnsManagedSystemElementForSettingInstance(
    const Linux_DnsManagedSystemElementForSettingInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingInstance::Linux_DnsManagedSystemElementForSettingInstance(
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
  Linux_DnsManagedSystemElementForSettingInstance::
   ~Linux_DnsManagedSystemElementForSettingInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingInstance&
  Linux_DnsManagedSystemElementForSettingInstance::operator=(
    const Linux_DnsManagedSystemElementForSettingInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsManagedSystemElementForSettingInstance::getCmpiInstance(
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
  Linux_DnsManagedSystemElementForSettingInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsManagedSystemElementForSettingInstanceName&
  Linux_DnsManagedSystemElementForSettingInstance::getInstanceName() const {

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
  Linux_DnsManagedSystemElementForSettingInstance::setInstanceName(
    const Linux_DnsManagedSystemElementForSettingInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingInstance::init() {
   	isSet.instanceName = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsManagedSystemElementForSettingInstance::init(
    const Linux_DnsManagedSystemElementForSettingInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
        
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingInstance::reset() {
   	
  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement::Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement::~Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::Linux_DnsManagedSystemElementForSettingInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::Linux_DnsManagedSystemElementForSettingInstanceEnumeration(
    const Linux_DnsManagedSystemElementForSettingInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::~Linux_DnsManagedSystemElementForSettingInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsManagedSystemElementForSettingInstance&  
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsManagedSystemElementForSettingInstance&
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::getNext() {
   	
    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingInstanceEnumeration::addElement(
    const Linux_DnsManagedSystemElementForSettingInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsManagedSystemElementForSettingInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsManagedSystemElementForSettingInstance(anInstance);
  	}

  }
  
}
