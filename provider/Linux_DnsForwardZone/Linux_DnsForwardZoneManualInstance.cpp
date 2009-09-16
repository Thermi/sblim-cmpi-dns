// =======================================================================
// Linux_DnsForwardZoneManualInstance.cpp
//     created on Wed, 29 Nov 2006 using ECUTE 2.2
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
#include "Linux_DnsForwardZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsForwardZoneManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsForwardZoneManualInstance::Linux_DnsForwardZoneManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneManualInstance::Linux_DnsForwardZoneManualInstance(
    const Linux_DnsForwardZoneManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneManualInstance::Linux_DnsForwardZoneManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsForwardZoneInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("Forward");
    if ( ! cmpiData.isNullValue()){
      CMPIUint8 Forward = cmpiData;
      setForward(Forward);
    }

    cmpiData = aCmpiInstance.getProperty("Type");
    if ( ! cmpiData.isNullValue()){
      CMPIUint8 Type = cmpiData;
      setType(Type);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneManualInstance::
   ~Linux_DnsForwardZoneManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneManualInstance&
  Linux_DnsForwardZoneManualInstance::operator=(
    const Linux_DnsForwardZoneManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsForwardZoneManualInstance::getCmpiInstance(
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
  Linux_DnsForwardZoneManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardZoneInstanceName&
  Linux_DnsForwardZoneManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsForwardZone");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneManualInstance::setInstanceName(
    const Linux_DnsForwardZoneInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Forward related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneManualInstance::isForwardSet() const {
    return isSet.Forward;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsForwardZoneManualInstance::setForward(
    const CMPIUint8 aValue) {
  
    m_Forward = aValue;
    isSet.Forward = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  Linux_DnsForwardZoneManualInstance::getForward() const {
    
    if ( ! isSet.Forward) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Forward",
        "Linux_DnsForwardZone");
   	}


    return m_Forward;

  }
       
  //----------------------------------------------------------------------------
  // Type related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneManualInstance::isTypeSet() const {
    return isSet.Type;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsForwardZoneManualInstance::setType(
    const CMPIUint8 aValue) {
  
    m_Type = aValue;
    isSet.Type = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  Linux_DnsForwardZoneManualInstance::getType() const {
    
    if ( ! isSet.Type) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Type",
        "Linux_DnsForwardZone");
   	}


    return m_Type;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.Forward = 0;
    isSet.Type = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsForwardZoneManualInstance::init(
    const Linux_DnsForwardZoneManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isForwardSet()) {
      const CMPIUint8 ForwardOriginal = anOriginal.getForward();
      setForward(ForwardOriginal);
    }
   	
    if (anOriginal.isTypeSet()) {
      const CMPIUint8 TypeOriginal = anOriginal.getType();
      setType(TypeOriginal);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneManualInstance::reset() {
   	
  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsForwardZoneManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneManualInstanceEnumerationElement::Linux_DnsForwardZoneManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneManualInstanceEnumerationElement::~Linux_DnsForwardZoneManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsForwardZoneManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneManualInstanceEnumeration::Linux_DnsForwardZoneManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneManualInstanceEnumeration::Linux_DnsForwardZoneManualInstanceEnumeration(
    const Linux_DnsForwardZoneManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneManualInstanceEnumeration::~Linux_DnsForwardZoneManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsForwardZoneManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsForwardZoneManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsForwardZoneManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardZoneManualInstance&  
  Linux_DnsForwardZoneManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsForwardZoneManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardZoneManualInstance&
  Linux_DnsForwardZoneManualInstanceEnumeration::getNext() {
   	
    Linux_DnsForwardZoneManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneManualInstanceEnumeration::addElement(
    const Linux_DnsForwardZoneManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsForwardZoneManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsForwardZoneManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsForwardZoneManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsForwardZoneManualInstance(anInstance);
  	}

  }
  
}
