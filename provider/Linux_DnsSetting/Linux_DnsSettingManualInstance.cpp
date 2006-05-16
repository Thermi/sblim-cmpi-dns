// =======================================================================
// Linux_DnsSettingManualInstance.cpp
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
#include "Linux_DnsSettingManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsSettingManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsSettingManualInstance::Linux_DnsSettingManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsSettingManualInstance::Linux_DnsSettingManualInstance(
    const Linux_DnsSettingManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsSettingManualInstance::Linux_DnsSettingManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsSettingInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("ConfigurationDirectory");
    if ( ! cmpiData.isNullValue()){
      CmpiString ConfigurationDirectory = cmpiData;
      setConfigurationDirectory(ConfigurationDirectory.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Forward");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 Forward = cmpiData;
      setForward(Forward);
    }

    cmpiData = aCmpiInstance.getProperty("Forwarders");
    if ( ! cmpiData.isNullValue()){
      CmpiArray Forwarders = cmpiData;
    unsigned int ForwardersSize;
    const char** ForwardersArray;
    ArrayConverter::makeArray(
      Forwarders, 
      (char***)&ForwardersArray, 
      ForwardersSize);
      setForwarders(ForwardersArray, ForwardersSize, 0);
    }

    cmpiData = aCmpiInstance.getProperty("PortNumber");
    if ( ! cmpiData.isNullValue()){
      CMPIUint32 PortNumber = cmpiData;
      setPortNumber(PortNumber);
    }

    cmpiData = aCmpiInstance.getProperty("TSIG");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 TSIG = cmpiData;
      setTSIG(TSIG);
    }

    cmpiData = aCmpiInstance.getProperty("TTL");
    if ( ! cmpiData.isNullValue()){
      CMPIUint32 TTL = cmpiData;
      setTTL(TTL);
    }

    cmpiData = aCmpiInstance.getProperty("XferFormat");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 XferFormat = cmpiData;
      setXferFormat(XferFormat);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsSettingManualInstance::
   ~Linux_DnsSettingManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsSettingManualInstance&
  Linux_DnsSettingManualInstance::operator=(
    const Linux_DnsSettingManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsSettingManualInstance::getCmpiInstance(
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

  	if (isSet.Forwarders) {
  	  
      unsigned int ForwardersSize;
      const char** arrayForwarders = getForwarders(ForwardersSize);
      CmpiArray cmpiArrayForwarders = CmpiArray(
        ForwardersSize,
        CMPI_chars);
      for (unsigned int x=0; x < ForwardersSize; ++x) {
        cmpiArrayForwarders[x] = CmpiData(arrayForwarders[x]);
      }
  	  cmpiInstance.setProperty(
  	    "Forwarders",
  	    CmpiData(cmpiArrayForwarders));
  	}

  	if (isSet.PortNumber) {
  	  
  	  cmpiInstance.setProperty(
  	    "PortNumber",
  	    CmpiData(m_PortNumber));
  	}

  	if (isSet.TSIG) {
  	  
  	  cmpiInstance.setProperty(
  	    "TSIG",
  	    CmpiData(m_TSIG));
  	}

  	if (isSet.TTL) {
  	  
  	  cmpiInstance.setProperty(
  	    "TTL",
  	    CmpiData(m_TTL));
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
  Linux_DnsSettingManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsSettingInstanceName&
  Linux_DnsSettingManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsSetting");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsSettingManualInstance::setInstanceName(
    const Linux_DnsSettingInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // ConfigurationDirectory related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSettingManualInstance::isConfigurationDirectorySet() const {
    return isSet.ConfigurationDirectory;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsSettingManualInstance::setConfigurationDirectory(
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
  Linux_DnsSettingManualInstance::getConfigurationDirectory() const {
    
    if ( ! isSet.ConfigurationDirectory) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ConfigurationDirectory",
        "Linux_DnsSetting");
   	}


    return m_ConfigurationDirectory;

  }
       
  //----------------------------------------------------------------------------
  // Forward related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSettingManualInstance::isForwardSet() const {
    return isSet.Forward;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSettingManualInstance::setForward(
    const CMPIUint16 aValue) {
  
    m_Forward = aValue;
    isSet.Forward = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsSettingManualInstance::getForward() const {
    
    if ( ! isSet.Forward) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Forward",
        "Linux_DnsSetting");
   	}


    return m_Forward;

  }
       
  //----------------------------------------------------------------------------
  // Forwarders related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSettingManualInstance::isForwardersSet() const {
    return isSet.Forwarders;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsSettingManualInstance::setForwarders(
    const char** aValuePP, 
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.Forwarders) {
      delete m_Forwarders;
    }
    
    if (aCopyFlag && aValuePP) {
      m_Forwarders = new const char*[aSize];
      for (unsigned int x=0; x < aSize; ++x) {
        char* stringP = new char[strlen(aValuePP[x])+1];
        strcpy(stringP,aValuePP[x]);
        m_Forwarders[x] = stringP;
      }      
    } else {
      m_Forwarders = aValuePP;
    }
    
    m_ForwardersSize = aSize;
    
    isSet.Forwarders = 1;
    
  }       

  //----------------------------------------------------------------------------
  const char**
  Linux_DnsSettingManualInstance::getForwarders(unsigned int& aSize) const {
    
    if ( ! isSet.Forwarders) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Forwarders",
        "Linux_DnsSetting");
   	}

    aSize = m_ForwardersSize;
    return m_Forwarders;

  }
       
  //----------------------------------------------------------------------------
  // PortNumber related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSettingManualInstance::isPortNumberSet() const {
    return isSet.PortNumber;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSettingManualInstance::setPortNumber(
    const CMPIUint32 aValue) {
  
    m_PortNumber = aValue;
    isSet.PortNumber = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsSettingManualInstance::getPortNumber() const {
    
    if ( ! isSet.PortNumber) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "PortNumber",
        "Linux_DnsSetting");
   	}


    return m_PortNumber;

  }
       
  //----------------------------------------------------------------------------
  // TSIG related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSettingManualInstance::isTSIGSet() const {
    return isSet.TSIG;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSettingManualInstance::setTSIG(
    const CMPIUint16 aValue) {
  
    m_TSIG = aValue;
    isSet.TSIG = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsSettingManualInstance::getTSIG() const {
    
    if ( ! isSet.TSIG) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "TSIG",
        "Linux_DnsSetting");
   	}


    return m_TSIG;

  }
       
  //----------------------------------------------------------------------------
  // TTL related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSettingManualInstance::isTTLSet() const {
    return isSet.TTL;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSettingManualInstance::setTTL(
    const CMPIUint32 aValue) {
  
    m_TTL = aValue;
    isSet.TTL = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsSettingManualInstance::getTTL() const {
    
    if ( ! isSet.TTL) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "TTL",
        "Linux_DnsSetting");
   	}


    return m_TTL;

  }
       
  //----------------------------------------------------------------------------
  // XferFormat related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSettingManualInstance::isXferFormatSet() const {
    return isSet.XferFormat;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSettingManualInstance::setXferFormat(
    const CMPIUint16 aValue) {
  
    m_XferFormat = aValue;
    isSet.XferFormat = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsSettingManualInstance::getXferFormat() const {
    
    if ( ! isSet.XferFormat) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "XferFormat",
        "Linux_DnsSetting");
   	}


    return m_XferFormat;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsSettingManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.ConfigurationDirectory = 0;
    isSet.Forward = 0;
    isSet.Forwarders = 0;
    m_ForwardersSize = 0;
    isSet.PortNumber = 0;
    isSet.TSIG = 0;
    isSet.TTL = 0;
    isSet.XferFormat = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsSettingManualInstance::init(
    const Linux_DnsSettingManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isConfigurationDirectorySet()) {
      const char* ConfigurationDirectoryOriginal = anOriginal.getConfigurationDirectory();
      setConfigurationDirectory(ConfigurationDirectoryOriginal,1);
    }
   	
    if (anOriginal.isForwardSet()) {
      const CMPIUint16 ForwardOriginal = anOriginal.getForward();
      setForward(ForwardOriginal);
    }
   	
    if (anOriginal.isForwardersSet()) {
      unsigned int sizeForwarders;
      const char** ForwardersOriginal = anOriginal.getForwarders(sizeForwarders);
      setForwarders(ForwardersOriginal, sizeForwarders,1);
    }
   	
    if (anOriginal.isPortNumberSet()) {
      const CMPIUint32 PortNumberOriginal = anOriginal.getPortNumber();
      setPortNumber(PortNumberOriginal);
    }
   	
    if (anOriginal.isTSIGSet()) {
      const CMPIUint16 TSIGOriginal = anOriginal.getTSIG();
      setTSIG(TSIGOriginal);
    }
   	
    if (anOriginal.isTTLSet()) {
      const CMPIUint32 TTLOriginal = anOriginal.getTTL();
      setTTL(TTLOriginal);
    }
   	
    if (anOriginal.isXferFormatSet()) {
      const CMPIUint16 XferFormatOriginal = anOriginal.getXferFormat();
      setXferFormat(XferFormatOriginal);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsSettingManualInstance::reset() {
   	
  	if (isSet.ConfigurationDirectory) {
  	  delete(m_ConfigurationDirectory);
  	}

  	if (isSet.Forwarders) {
  	  ArrayConverter::destructArray((char**)m_Forwarders,m_ForwardersSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsSettingManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsSettingManualInstanceEnumerationElement::Linux_DnsSettingManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsSettingManualInstanceEnumerationElement::~Linux_DnsSettingManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsSettingManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsSettingManualInstanceEnumeration::Linux_DnsSettingManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsSettingManualInstanceEnumeration::Linux_DnsSettingManualInstanceEnumeration(
    const Linux_DnsSettingManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsSettingManualInstanceEnumeration::~Linux_DnsSettingManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsSettingManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsSettingManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsSettingManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsSettingManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsSettingManualInstance&  
  Linux_DnsSettingManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsSettingManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsSettingManualInstance&
  Linux_DnsSettingManualInstanceEnumeration::getNext() {
   	
    Linux_DnsSettingManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsSettingManualInstanceEnumeration::addElement(
    const Linux_DnsSettingManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsSettingManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsSettingManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsSettingManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsSettingManualInstance(anInstance);
  	}

  }
  
}
