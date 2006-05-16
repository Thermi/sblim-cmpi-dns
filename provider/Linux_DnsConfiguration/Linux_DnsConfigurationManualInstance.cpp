// =======================================================================
// Linux_DnsConfigurationManualInstance.cpp
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
#include "Linux_DnsConfigurationManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsConfigurationManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsConfigurationManualInstance::Linux_DnsConfigurationManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsConfigurationManualInstance::Linux_DnsConfigurationManualInstance(
    const Linux_DnsConfigurationManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsConfigurationManualInstance::Linux_DnsConfigurationManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsConfigurationInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("ConfigurationFile");
    if ( ! cmpiData.isNullValue()){
      CmpiString ConfigurationFile = cmpiData;
      setConfigurationFile(ConfigurationFile.charPtr());
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsConfigurationManualInstance::
   ~Linux_DnsConfigurationManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsConfigurationManualInstance&
  Linux_DnsConfigurationManualInstance::operator=(
    const Linux_DnsConfigurationManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsConfigurationManualInstance::getCmpiInstance(
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
  Linux_DnsConfigurationManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsConfigurationInstanceName&
  Linux_DnsConfigurationManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsConfiguration");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsConfigurationManualInstance::setInstanceName(
    const Linux_DnsConfigurationInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // ConfigurationFile related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsConfigurationManualInstance::isConfigurationFileSet() const {
    return isSet.ConfigurationFile;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsConfigurationManualInstance::setConfigurationFile(
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
  Linux_DnsConfigurationManualInstance::getConfigurationFile() const {
    
    if ( ! isSet.ConfigurationFile) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ConfigurationFile",
        "Linux_DnsConfiguration");
   	}


    return m_ConfigurationFile;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsConfigurationManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.ConfigurationFile = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsConfigurationManualInstance::init(
    const Linux_DnsConfigurationManualInstance& anOriginal) {   	

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
  Linux_DnsConfigurationManualInstance::reset() {
   	
  	if (isSet.ConfigurationFile) {
  	  delete(m_ConfigurationFile);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsConfigurationManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsConfigurationManualInstanceEnumerationElement::Linux_DnsConfigurationManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsConfigurationManualInstanceEnumerationElement::~Linux_DnsConfigurationManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsConfigurationManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsConfigurationManualInstanceEnumeration::Linux_DnsConfigurationManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsConfigurationManualInstanceEnumeration::Linux_DnsConfigurationManualInstanceEnumeration(
    const Linux_DnsConfigurationManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsConfigurationManualInstanceEnumeration::~Linux_DnsConfigurationManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsConfigurationManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsConfigurationManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsConfigurationManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsConfigurationManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsConfigurationManualInstance&  
  Linux_DnsConfigurationManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsConfigurationManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsConfigurationManualInstance&
  Linux_DnsConfigurationManualInstanceEnumeration::getNext() {
   	
    Linux_DnsConfigurationManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsConfigurationManualInstanceEnumeration::addElement(
    const Linux_DnsConfigurationManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsConfigurationManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsConfigurationManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsConfigurationManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsConfigurationManualInstance(anInstance);
  	}

  }
  
}
