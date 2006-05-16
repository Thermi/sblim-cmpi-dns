// =======================================================================
// Linux_DnsIPAddressManualInstance.cpp
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
#include "Linux_DnsIPAddressManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsIPAddressManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsIPAddressManualInstance::Linux_DnsIPAddressManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsIPAddressManualInstance::Linux_DnsIPAddressManualInstance(
    const Linux_DnsIPAddressManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsIPAddressManualInstance::Linux_DnsIPAddressManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsIPAddressInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("Port");
    if ( ! cmpiData.isNullValue()){
      CMPIUint32 Port = cmpiData;
      setPort(Port);
    }

    cmpiData = aCmpiInstance.getProperty("SecurityKey");
    if ( ! cmpiData.isNullValue()){
      CmpiString SecurityKey = cmpiData;
      setSecurityKey(SecurityKey.charPtr());
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsIPAddressManualInstance::
   ~Linux_DnsIPAddressManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsIPAddressManualInstance&
  Linux_DnsIPAddressManualInstance::operator=(
    const Linux_DnsIPAddressManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsIPAddressManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.Port) {
  	  
  	  cmpiInstance.setProperty(
  	    "Port",
  	    CmpiData(m_Port));
  	}

  	if (isSet.SecurityKey) {
  	  
  	  cmpiInstance.setProperty(
  	    "SecurityKey",
  	    CmpiData(m_SecurityKey));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsIPAddressManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsIPAddressInstanceName&
  Linux_DnsIPAddressManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsIPAddress");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsIPAddressManualInstance::setInstanceName(
    const Linux_DnsIPAddressInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Port related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsIPAddressManualInstance::isPortSet() const {
    return isSet.Port;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsIPAddressManualInstance::setPort(
    const CMPIUint32 aValue) {
  
    m_Port = aValue;
    isSet.Port = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsIPAddressManualInstance::getPort() const {
    
    if ( ! isSet.Port) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Port",
        "Linux_DnsIPAddress");
   	}


    return m_Port;

  }
       
  //----------------------------------------------------------------------------
  // SecurityKey related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsIPAddressManualInstance::isSecurityKeySet() const {
    return isSet.SecurityKey;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsIPAddressManualInstance::setSecurityKey(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.SecurityKey) {
      delete [] m_SecurityKey;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_SecurityKey = valueP;
    } else {
      m_SecurityKey = aValueP;
    }
    
    isSet.SecurityKey = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsIPAddressManualInstance::getSecurityKey() const {
    
    if ( ! isSet.SecurityKey) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "SecurityKey",
        "Linux_DnsIPAddress");
   	}


    return m_SecurityKey;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsIPAddressManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.Port = 0;
    isSet.SecurityKey = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsIPAddressManualInstance::init(
    const Linux_DnsIPAddressManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isPortSet()) {
      const CMPIUint32 PortOriginal = anOriginal.getPort();
      setPort(PortOriginal);
    }
   	
    if (anOriginal.isSecurityKeySet()) {
      const char* SecurityKeyOriginal = anOriginal.getSecurityKey();
      setSecurityKey(SecurityKeyOriginal,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsIPAddressManualInstance::reset() {
   	
  	if (isSet.SecurityKey) {
  	  delete(m_SecurityKey);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsIPAddressManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsIPAddressManualInstanceEnumerationElement::Linux_DnsIPAddressManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsIPAddressManualInstanceEnumerationElement::~Linux_DnsIPAddressManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsIPAddressManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsIPAddressManualInstanceEnumeration::Linux_DnsIPAddressManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsIPAddressManualInstanceEnumeration::Linux_DnsIPAddressManualInstanceEnumeration(
    const Linux_DnsIPAddressManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsIPAddressManualInstanceEnumeration::~Linux_DnsIPAddressManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsIPAddressManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsIPAddressManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsIPAddressManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsIPAddressManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsIPAddressManualInstance&  
  Linux_DnsIPAddressManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsIPAddressManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsIPAddressManualInstance&
  Linux_DnsIPAddressManualInstanceEnumeration::getNext() {
   	
    Linux_DnsIPAddressManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsIPAddressManualInstanceEnumeration::addElement(
    const Linux_DnsIPAddressManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsIPAddressManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsIPAddressManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsIPAddressManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsIPAddressManualInstance(anInstance);
  	}

  }
  
}
