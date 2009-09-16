// =======================================================================
// Linux_DnsServiceSettingDataManualInstance.cpp
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
#include "Linux_DnsServiceSettingDataManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsServiceSettingDataManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsServiceSettingDataManualInstance::Linux_DnsServiceSettingDataManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataManualInstance::Linux_DnsServiceSettingDataManualInstance(
    const Linux_DnsServiceSettingDataManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataManualInstance::Linux_DnsServiceSettingDataManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsServiceSettingDataInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("ConfigurationDirectory");
    if ( ! cmpiData.isNullValue()){
      CmpiString ConfigurationDirectory = cmpiData;
      setConfigurationDirectory(ConfigurationDirectory.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Forward");
    if ( ! cmpiData.isNullValue()){
      CMPIUint8 Forward = cmpiData;
      setForward(Forward);
    }

    cmpiData = aCmpiInstance.getProperty("XferFormat");
    if ( ! cmpiData.isNullValue()){
      CMPIUint8 XferFormat = cmpiData;
      setXferFormat(XferFormat);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataManualInstance::
   ~Linux_DnsServiceSettingDataManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataManualInstance&
  Linux_DnsServiceSettingDataManualInstance::operator=(
    const Linux_DnsServiceSettingDataManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsServiceSettingDataManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.ConfigurationDirectory) {
  	  
  	  cmpiInstance.setProperty(
  	    "ConfigurationDirectory",
  	    CmpiData(m_ConfigurationDirectory));
  	}

  	if (isSet.Forward) {
  	  
  	  cmpiInstance.setProperty(
  	    "Forward",
  	    CmpiData(m_Forward));
  	}

  	if (isSet.XferFormat) {
  	  
  	  cmpiInstance.setProperty(
  	    "XferFormat",
  	    CmpiData(m_XferFormat));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsServiceSettingDataManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceSettingDataInstanceName&
  Linux_DnsServiceSettingDataManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsServiceSettingData");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataManualInstance::setInstanceName(
    const Linux_DnsServiceSettingDataInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // ConfigurationDirectory related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceSettingDataManualInstance::isConfigurationDirectorySet() const {
    return isSet.ConfigurationDirectory;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataManualInstance::setConfigurationDirectory(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ConfigurationDirectory) {
      delete [] m_ConfigurationDirectory;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ConfigurationDirectory = valueP;
    } else {
      m_ConfigurationDirectory = aValueP;
    }
    
    isSet.ConfigurationDirectory = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsServiceSettingDataManualInstance::getConfigurationDirectory() const {
    
    if ( ! isSet.ConfigurationDirectory) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ConfigurationDirectory",
        "Linux_DnsServiceSettingData");
   	}


    return m_ConfigurationDirectory;

  }
       
  //----------------------------------------------------------------------------
  // Forward related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceSettingDataManualInstance::isForwardSet() const {
    return isSet.Forward;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceSettingDataManualInstance::setForward(
    const CMPIUint8 aValue) {
  
    m_Forward = aValue;
    isSet.Forward = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  Linux_DnsServiceSettingDataManualInstance::getForward() const {
    
    if ( ! isSet.Forward) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Forward",
        "Linux_DnsServiceSettingData");
   	}


    return m_Forward;

  }
       
  //----------------------------------------------------------------------------
  // XferFormat related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceSettingDataManualInstance::isXferFormatSet() const {
    return isSet.XferFormat;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceSettingDataManualInstance::setXferFormat(
    const CMPIUint8 aValue) {
  
    m_XferFormat = aValue;
    isSet.XferFormat = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  Linux_DnsServiceSettingDataManualInstance::getXferFormat() const {
    
    if ( ! isSet.XferFormat) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "XferFormat",
        "Linux_DnsServiceSettingData");
   	}


    return m_XferFormat;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.ConfigurationDirectory = 0;
    isSet.Forward = 0;
    isSet.XferFormat = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsServiceSettingDataManualInstance::init(
    const Linux_DnsServiceSettingDataManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isConfigurationDirectorySet()) {
      const char* ConfigurationDirectoryOriginal = anOriginal.getConfigurationDirectory();
      setConfigurationDirectory(ConfigurationDirectoryOriginal,1);
    }
   	
    if (anOriginal.isForwardSet()) {
      const CMPIUint8 ForwardOriginal = anOriginal.getForward();
      setForward(ForwardOriginal);
    }
   	
    if (anOriginal.isXferFormatSet()) {
      const CMPIUint8 XferFormatOriginal = anOriginal.getXferFormat();
      setXferFormat(XferFormatOriginal);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataManualInstance::reset() {
   	
  	if (isSet.ConfigurationDirectory) {
  	  delete(m_ConfigurationDirectory);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceSettingDataManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataManualInstanceEnumerationElement::Linux_DnsServiceSettingDataManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataManualInstanceEnumerationElement::~Linux_DnsServiceSettingDataManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsServiceSettingDataManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataManualInstanceEnumeration::Linux_DnsServiceSettingDataManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataManualInstanceEnumeration::Linux_DnsServiceSettingDataManualInstanceEnumeration(
    const Linux_DnsServiceSettingDataManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataManualInstanceEnumeration::~Linux_DnsServiceSettingDataManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsServiceSettingDataManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsServiceSettingDataManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsServiceSettingDataManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceSettingDataManualInstance&  
  Linux_DnsServiceSettingDataManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsServiceSettingDataManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceSettingDataManualInstance&
  Linux_DnsServiceSettingDataManualInstanceEnumeration::getNext() {
   	
    Linux_DnsServiceSettingDataManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataManualInstanceEnumeration::addElement(
    const Linux_DnsServiceSettingDataManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsServiceSettingDataManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsServiceSettingDataManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsServiceSettingDataManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsServiceSettingDataManualInstance(anInstance);
  	}

  }
  
}
