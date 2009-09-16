// =======================================================================
// Linux_DnsServiceManualInstance.cpp
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
#include "Linux_DnsServiceManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsServiceManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsServiceManualInstance::Linux_DnsServiceManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsServiceManualInstance::Linux_DnsServiceManualInstance(
    const Linux_DnsServiceManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsServiceManualInstance::Linux_DnsServiceManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsServiceInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("RunAsRoot");
    if ( ! cmpiData.isNullValue()){
      CMPIBoolean RunAsRoot = cmpiData;
      setRunAsRoot(RunAsRoot);
    }

    cmpiData = aCmpiInstance.getProperty("Started");
    if ( ! cmpiData.isNullValue()){
      CMPIBoolean Started = cmpiData;
      setStarted(Started);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsServiceManualInstance::
   ~Linux_DnsServiceManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsServiceManualInstance&
  Linux_DnsServiceManualInstance::operator=(
    const Linux_DnsServiceManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsServiceManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.RunAsRoot) {
  	  
  	  cmpiInstance.setProperty(
  	    "RunAsRoot",
  	    CmpiBooleanData(m_RunAsRoot));
  	}

  	if (isSet.Started) {
  	  
  	  cmpiInstance.setProperty(
  	    "Started",
  	    CmpiBooleanData(m_Started));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsServiceManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceInstanceName&
  Linux_DnsServiceManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsService");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceManualInstance::setInstanceName(
    const Linux_DnsServiceInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // RunAsRoot related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceManualInstance::isRunAsRootSet() const {
    return isSet.RunAsRoot;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceManualInstance::setRunAsRoot(
    const CMPIBoolean aValue) {
  
    m_RunAsRoot = aValue;
    isSet.RunAsRoot = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIBoolean
  Linux_DnsServiceManualInstance::getRunAsRoot() const {
    
    if ( ! isSet.RunAsRoot) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "RunAsRoot",
        "Linux_DnsService");
   	}


    return m_RunAsRoot;

  }
       
  //----------------------------------------------------------------------------
  // Started related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceManualInstance::isStartedSet() const {
    return isSet.Started;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceManualInstance::setStarted(
    const CMPIBoolean aValue) {
  
    m_Started = aValue;
    isSet.Started = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIBoolean
  Linux_DnsServiceManualInstance::getStarted() const {
    
    if ( ! isSet.Started) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Started",
        "Linux_DnsService");
   	}


    return m_Started;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.RunAsRoot = 0;
    isSet.Started = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsServiceManualInstance::init(
    const Linux_DnsServiceManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isRunAsRootSet()) {
      const CMPIBoolean RunAsRootOriginal = anOriginal.getRunAsRoot();
      setRunAsRoot(RunAsRootOriginal);
    }
   	
    if (anOriginal.isStartedSet()) {
      const CMPIBoolean StartedOriginal = anOriginal.getStarted();
      setStarted(StartedOriginal);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceManualInstance::reset() {
   	
  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsServiceManualInstanceEnumerationElement::Linux_DnsServiceManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceManualInstanceEnumerationElement::~Linux_DnsServiceManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsServiceManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsServiceManualInstanceEnumeration::Linux_DnsServiceManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceManualInstanceEnumeration::Linux_DnsServiceManualInstanceEnumeration(
    const Linux_DnsServiceManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceManualInstanceEnumeration::~Linux_DnsServiceManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsServiceManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsServiceManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsServiceManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceManualInstance&  
  Linux_DnsServiceManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsServiceManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceManualInstance&
  Linux_DnsServiceManualInstanceEnumeration::getNext() {
   	
    Linux_DnsServiceManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceManualInstanceEnumeration::addElement(
    const Linux_DnsServiceManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsServiceManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsServiceManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsServiceManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsServiceManualInstance(anInstance);
  	}

  }
  
}
