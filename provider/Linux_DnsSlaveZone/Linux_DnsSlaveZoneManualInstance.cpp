// =======================================================================
// Linux_DnsSlaveZoneManualInstance.cpp
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
      CMPIUint8 Forward = cmpiData;
      setForward(Forward);
    }

    cmpiData = aCmpiInstance.getProperty("TTL");
    if ( ! cmpiData.isNullValue()){
      CMPISint32 TTL = cmpiData;
      setTTL(TTL);
    }

    cmpiData = aCmpiInstance.getProperty("Type");
    if ( ! cmpiData.isNullValue()){
      CMPIUint8 Type = cmpiData;
      setType(Type);
    }

    cmpiData = aCmpiInstance.getProperty("ZoneFile");
    if ( ! cmpiData.isNullValue()){
      CmpiString ZoneFile = cmpiData;
      setZoneFile(ZoneFile.charPtr());
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

  	if (isSet.TTL) {
  	  
  	  cmpiInstance.setProperty(
  	    "TTL",
  	    CmpiData(m_TTL));
  	}

  	if (isSet.Type) {
  	  
  	  cmpiInstance.setProperty(
  	    "Type",
  	    CmpiData(m_Type));
  	}

  	if (isSet.ZoneFile) {
  	  
  	  cmpiInstance.setProperty(
  	    "ZoneFile",
  	    CmpiData(m_ZoneFile));
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
    const CMPIUint8 aValue) {
  
    m_Forward = aValue;
    isSet.Forward = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
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
  // TTL related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSlaveZoneManualInstance::isTTLSet() const {
    return isSet.TTL;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSlaveZoneManualInstance::setTTL(
    const CMPISint32 aValue) {
  
    m_TTL = aValue;
    isSet.TTL = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPISint32
  Linux_DnsSlaveZoneManualInstance::getTTL() const {
    
    if ( ! isSet.TTL) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "TTL",
        "Linux_DnsSlaveZone");
   	}


    return m_TTL;

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
    const CMPIUint8 aValue) {
  
    m_Type = aValue;
    isSet.Type = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
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
  // ZoneFile related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSlaveZoneManualInstance::isZoneFileSet() const {
    return isSet.ZoneFile;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneManualInstance::setZoneFile(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ZoneFile) {
      delete [] m_ZoneFile;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ZoneFile = valueP;
    } else {
      m_ZoneFile = aValueP;
    }
    
    isSet.ZoneFile = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsSlaveZoneManualInstance::getZoneFile() const {
    
    if ( ! isSet.ZoneFile) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ZoneFile",
        "Linux_DnsSlaveZone");
   	}


    return m_ZoneFile;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.Forward = 0;
    isSet.TTL = 0;
    isSet.Type = 0;
    isSet.ZoneFile = 0;
  	
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
      const CMPIUint8 ForwardOriginal = anOriginal.getForward();
      setForward(ForwardOriginal);
    }
   	
    if (anOriginal.isTTLSet()) {
      const CMPISint32 TTLOriginal = anOriginal.getTTL();
      setTTL(TTLOriginal);
    }
   	
    if (anOriginal.isTypeSet()) {
      const CMPIUint8 TypeOriginal = anOriginal.getType();
      setType(TypeOriginal);
    }
   	
    if (anOriginal.isZoneFileSet()) {
      const char* ZoneFileOriginal = anOriginal.getZoneFile();
      setZoneFile(ZoneFileOriginal,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneManualInstance::reset() {
   	
  	if (isSet.ZoneFile) {
  	  delete(m_ZoneFile);
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
