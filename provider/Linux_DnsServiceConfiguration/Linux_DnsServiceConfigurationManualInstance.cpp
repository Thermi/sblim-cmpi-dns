// =======================================================================
// Linux_DnsServiceConfigurationManualInstance.cpp
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
#include "Linux_DnsServiceConfigurationManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsServiceConfigurationManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsServiceConfigurationManualInstance::Linux_DnsServiceConfigurationManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationManualInstance::Linux_DnsServiceConfigurationManualInstance(
    const Linux_DnsServiceConfigurationManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationManualInstance::Linux_DnsServiceConfigurationManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsServiceConfigurationInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("ConfigurationFile");
    if ( ! cmpiData.isNullValue()){
      CmpiString ConfigurationFile = cmpiData;
      setConfigurationFile(ConfigurationFile.charPtr());
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationManualInstance::
   ~Linux_DnsServiceConfigurationManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationManualInstance&
  Linux_DnsServiceConfigurationManualInstance::operator=(
    const Linux_DnsServiceConfigurationManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsServiceConfigurationManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.ConfigurationFile) {
  	  
  	  cmpiInstance.setProperty(
  	    "ConfigurationFile",
  	    CmpiData(m_ConfigurationFile));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsServiceConfigurationManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceConfigurationInstanceName&
  Linux_DnsServiceConfigurationManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsServiceConfiguration");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationManualInstance::setInstanceName(
    const Linux_DnsServiceConfigurationInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // ConfigurationFile related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceConfigurationManualInstance::isConfigurationFileSet() const {
    return isSet.ConfigurationFile;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationManualInstance::setConfigurationFile(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ConfigurationFile) {
      delete [] m_ConfigurationFile;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ConfigurationFile = valueP;
    } else {
      m_ConfigurationFile = aValueP;
    }
    
    isSet.ConfigurationFile = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsServiceConfigurationManualInstance::getConfigurationFile() const {
    
    if ( ! isSet.ConfigurationFile) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ConfigurationFile",
        "Linux_DnsServiceConfiguration");
   	}


    return m_ConfigurationFile;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.ConfigurationFile = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsServiceConfigurationManualInstance::init(
    const Linux_DnsServiceConfigurationManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isConfigurationFileSet()) {
      const char* ConfigurationFileOriginal = anOriginal.getConfigurationFile();
      setConfigurationFile(ConfigurationFileOriginal,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationManualInstance::reset() {
   	
  	if (isSet.ConfigurationFile) {
  	  delete(m_ConfigurationFile);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceConfigurationManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationManualInstanceEnumerationElement::Linux_DnsServiceConfigurationManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationManualInstanceEnumerationElement::~Linux_DnsServiceConfigurationManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsServiceConfigurationManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationManualInstanceEnumeration::Linux_DnsServiceConfigurationManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationManualInstanceEnumeration::Linux_DnsServiceConfigurationManualInstanceEnumeration(
    const Linux_DnsServiceConfigurationManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationManualInstanceEnumeration::~Linux_DnsServiceConfigurationManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsServiceConfigurationManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsServiceConfigurationManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceConfigurationManualInstance&  
  Linux_DnsServiceConfigurationManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceConfigurationManualInstance&
  Linux_DnsServiceConfigurationManualInstanceEnumeration::getNext() {
   	
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationManualInstanceEnumeration::addElement(
    const Linux_DnsServiceConfigurationManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsServiceConfigurationManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsServiceConfigurationManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsServiceConfigurationManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsServiceConfigurationManualInstance(anInstance);
  	}

  }
  
}
