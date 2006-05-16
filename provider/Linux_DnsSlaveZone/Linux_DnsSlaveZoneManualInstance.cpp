// =======================================================================
// Linux_DnsSlaveZoneManualInstance.cpp
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
#include "Linux_DnsSlaveZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsSlaveZoneManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsSlaveZoneManualInstance::Linux_DnsSlaveZoneManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneManualInstance::Linux_DnsSlaveZoneManualInstance(
    const Linux_DnsSlaveZoneManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneManualInstance::Linux_DnsSlaveZoneManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsSlaveZoneInstanceName(cop));

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

    cmpiData = aCmpiInstance.getProperty("ResourceRecordFile");
    if ( ! cmpiData.isNullValue()){
      CmpiString ResourceRecordFile = cmpiData;
      setResourceRecordFile(ResourceRecordFile.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Type");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 Type = cmpiData;
      setType(Type);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneManualInstance::
   ~Linux_DnsSlaveZoneManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneManualInstance&
  Linux_DnsSlaveZoneManualInstance::operator=(
    const Linux_DnsSlaveZoneManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsSlaveZoneManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
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

  	if (isSet.ResourceRecordFile) {
  	  
  	  cmpiInstance.setProperty(
  	    "ResourceRecordFile",
  	    CmpiData(m_ResourceRecordFile));
  	}

  	if (isSet.Type) {
  	  
  	  cmpiInstance.setProperty(
  	    "Type",
  	    CmpiData(m_Type));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsSlaveZoneManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsSlaveZoneInstanceName&
  Linux_DnsSlaveZoneManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsSlaveZone");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneManualInstance::setInstanceName(
    const Linux_DnsSlaveZoneInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Forward related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSlaveZoneManualInstance::isForwardSet() const {
    return isSet.Forward;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSlaveZoneManualInstance::setForward(
    const CMPIUint16 aValue) {
  
    m_Forward = aValue;
    isSet.Forward = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsSlaveZoneManualInstance::getForward() const {
    
    if ( ! isSet.Forward) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Forward",
        "Linux_DnsSlaveZone");
   	}


    return m_Forward;

  }
       
  //----------------------------------------------------------------------------
  // Forwarders related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSlaveZoneManualInstance::isForwardersSet() const {
    return isSet.Forwarders;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsSlaveZoneManualInstance::setForwarders(
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
  Linux_DnsSlaveZoneManualInstance::getForwarders(unsigned int& aSize) const {
    
    if ( ! isSet.Forwarders) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Forwarders",
        "Linux_DnsSlaveZone");
   	}

    aSize = m_ForwardersSize;
    return m_Forwarders;

  }
       
  //----------------------------------------------------------------------------
  // ResourceRecordFile related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSlaveZoneManualInstance::isResourceRecordFileSet() const {
    return isSet.ResourceRecordFile;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneManualInstance::setResourceRecordFile(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ResourceRecordFile) {
      delete [] m_ResourceRecordFile;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ResourceRecordFile = valueP;
    } else {
      m_ResourceRecordFile = aValueP;
    }
    
    isSet.ResourceRecordFile = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsSlaveZoneManualInstance::getResourceRecordFile() const {
    
    if ( ! isSet.ResourceRecordFile) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ResourceRecordFile",
        "Linux_DnsSlaveZone");
   	}


    return m_ResourceRecordFile;

  }
       
  //----------------------------------------------------------------------------
  // Type related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSlaveZoneManualInstance::isTypeSet() const {
    return isSet.Type;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSlaveZoneManualInstance::setType(
    const CMPIUint16 aValue) {
  
    m_Type = aValue;
    isSet.Type = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsSlaveZoneManualInstance::getType() const {
    
    if ( ! isSet.Type) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Type",
        "Linux_DnsSlaveZone");
   	}


    return m_Type;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.Forward = 0;
    isSet.Forwarders = 0;
    m_ForwardersSize = 0;
    isSet.ResourceRecordFile = 0;
    isSet.Type = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsSlaveZoneManualInstance::init(
    const Linux_DnsSlaveZoneManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
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
   	
    if (anOriginal.isResourceRecordFileSet()) {
      const char* ResourceRecordFileOriginal = anOriginal.getResourceRecordFile();
      setResourceRecordFile(ResourceRecordFileOriginal,1);
    }
   	
    if (anOriginal.isTypeSet()) {
      const CMPIUint16 TypeOriginal = anOriginal.getType();
      setType(TypeOriginal);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneManualInstance::reset() {
   	
  	if (isSet.Forwarders) {
  	  ArrayConverter::destructArray((char**)m_Forwarders,m_ForwardersSize);
  	}

  	if (isSet.ResourceRecordFile) {
  	  delete(m_ResourceRecordFile);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsSlaveZoneManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneManualInstanceEnumerationElement::Linux_DnsSlaveZoneManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneManualInstanceEnumerationElement::~Linux_DnsSlaveZoneManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsSlaveZoneManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneManualInstanceEnumeration::Linux_DnsSlaveZoneManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneManualInstanceEnumeration::Linux_DnsSlaveZoneManualInstanceEnumeration(
    const Linux_DnsSlaveZoneManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneManualInstanceEnumeration::~Linux_DnsSlaveZoneManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsSlaveZoneManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsSlaveZoneManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsSlaveZoneManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsSlaveZoneManualInstance&  
  Linux_DnsSlaveZoneManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsSlaveZoneManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsSlaveZoneManualInstance&
  Linux_DnsSlaveZoneManualInstanceEnumeration::getNext() {
   	
    Linux_DnsSlaveZoneManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneManualInstanceEnumeration::addElement(
    const Linux_DnsSlaveZoneManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsSlaveZoneManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsSlaveZoneManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsSlaveZoneManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsSlaveZoneManualInstance(anInstance);
  	}

  }
  
}
