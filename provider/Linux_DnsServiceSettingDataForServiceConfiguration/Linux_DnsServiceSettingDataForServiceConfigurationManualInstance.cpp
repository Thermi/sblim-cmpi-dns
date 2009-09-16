// =======================================================================
// Linux_DnsServiceSettingDataForServiceConfigurationManualInstance.cpp
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#include "Linux_DnsServiceSettingDataForServiceConfigurationManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsServiceSettingDataForServiceConfigurationManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::Linux_DnsServiceSettingDataForServiceConfigurationManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::Linux_DnsServiceSettingDataForServiceConfigurationManualInstance(
    const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::Linux_DnsServiceSettingDataForServiceConfigurationManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsServiceSettingDataForServiceConfigurationInstanceName(cop));

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::
   ~Linux_DnsServiceSettingDataForServiceConfigurationManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance&
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::operator=(
    const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::getCmpiInstance(
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
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName&
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsServiceSettingDataForServiceConfiguration");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::setInstanceName(
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::init() {
   	isSet.instanceName = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::init(
    const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
        
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance::reset() {
   	
  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement::Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement::~Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration::Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration::Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration(
    const Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration::~Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance&  
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance&
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration::getNext() {
   	
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration::addElement(
    const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsServiceSettingDataForServiceConfigurationManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsServiceSettingDataForServiceConfigurationManualInstance(anInstance);
  	}

  }
  
}
