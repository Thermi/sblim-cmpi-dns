// =======================================================================
// Linux_DnsMasterZoneManualInstance.cpp
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
#include "Linux_DnsMasterZoneManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsMasterZoneManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsMasterZoneManualInstance::Linux_DnsMasterZoneManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneManualInstance::Linux_DnsMasterZoneManualInstance(
    const Linux_DnsMasterZoneManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneManualInstance::Linux_DnsMasterZoneManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsMasterZoneInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("Contact");
    if ( ! cmpiData.isNullValue()){
      CmpiString Contact = cmpiData;
      setContact(Contact.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Expire");
    if ( ! cmpiData.isNullValue()){
      CMPIUint32 Expire = cmpiData;
      setExpire(Expire);
    }

    cmpiData = aCmpiInstance.getProperty("Forward");
    if ( ! cmpiData.isNullValue()){
      CMPIUint8 Forward = cmpiData;
      setForward(Forward);
    }

    cmpiData = aCmpiInstance.getProperty("NegativeCachingTTL");
    if ( ! cmpiData.isNullValue()){
      CMPIUint32 NegativeCachingTTL = cmpiData;
      setNegativeCachingTTL(NegativeCachingTTL);
    }

    cmpiData = aCmpiInstance.getProperty("Refresh");
    if ( ! cmpiData.isNullValue()){
      CMPIUint32 Refresh = cmpiData;
      setRefresh(Refresh);
    }

    cmpiData = aCmpiInstance.getProperty("Retry");
    if ( ! cmpiData.isNullValue()){
      CMPIUint32 Retry = cmpiData;
      setRetry(Retry);
    }

    cmpiData = aCmpiInstance.getProperty("SerialNumber");
    if ( ! cmpiData.isNullValue()){
      CmpiString SerialNumber = cmpiData;
      setSerialNumber(SerialNumber.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Server");
    if ( ! cmpiData.isNullValue()){
      CmpiString Server = cmpiData;
      setServer(Server.charPtr());
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
  Linux_DnsMasterZoneManualInstance::
   ~Linux_DnsMasterZoneManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneManualInstance&
  Linux_DnsMasterZoneManualInstance::operator=(
    const Linux_DnsMasterZoneManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsMasterZoneManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.Contact) {
  	  
  	  cmpiInstance.setProperty(
  	    "Contact",
  	    CmpiData(m_Contact));
  	}

  	if (isSet.Expire) {
  	  
  	  cmpiInstance.setProperty(
  	    "Expire",
  	    CmpiData(m_Expire));
  	}

  	if (isSet.Forward) {
  	  
  	  cmpiInstance.setProperty(
  	    "Forward",
  	    CmpiData(m_Forward));
  	}

  	if (isSet.NegativeCachingTTL) {
  	  
  	  cmpiInstance.setProperty(
  	    "NegativeCachingTTL",
  	    CmpiData(m_NegativeCachingTTL));
  	}

  	if (isSet.Refresh) {
  	  
  	  cmpiInstance.setProperty(
  	    "Refresh",
  	    CmpiData(m_Refresh));
  	}

  	if (isSet.Retry) {
  	  
  	  cmpiInstance.setProperty(
  	    "Retry",
  	    CmpiData(m_Retry));
  	}

  	if (isSet.SerialNumber) {
  	  
  	  cmpiInstance.setProperty(
  	    "SerialNumber",
  	    CmpiData(m_SerialNumber));
  	}

  	if (isSet.Server) {
  	  
  	  cmpiInstance.setProperty(
  	    "Server",
  	    CmpiData(m_Server));
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
  Linux_DnsMasterZoneManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMasterZoneInstanceName&
  Linux_DnsMasterZoneManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsMasterZone");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneManualInstance::setInstanceName(
    const Linux_DnsMasterZoneInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Contact related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isContactSet() const {
    return isSet.Contact;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneManualInstance::setContact(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Contact) {
      delete [] m_Contact;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Contact = valueP;
    } else {
      m_Contact = aValueP;
    }
    
    isSet.Contact = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsMasterZoneManualInstance::getContact() const {
    
    if ( ! isSet.Contact) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Contact",
        "Linux_DnsMasterZone");
   	}


    return m_Contact;

  }
       
  //----------------------------------------------------------------------------
  // Expire related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isExpireSet() const {
    return isSet.Expire;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneManualInstance::setExpire(
    const CMPIUint32 aValue) {
  
    m_Expire = aValue;
    isSet.Expire = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsMasterZoneManualInstance::getExpire() const {
    
    if ( ! isSet.Expire) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Expire",
        "Linux_DnsMasterZone");
   	}


    return m_Expire;

  }
       
  //----------------------------------------------------------------------------
  // Forward related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isForwardSet() const {
    return isSet.Forward;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneManualInstance::setForward(
    const CMPIUint8 aValue) {
  
    m_Forward = aValue;
    isSet.Forward = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  Linux_DnsMasterZoneManualInstance::getForward() const {
    
    if ( ! isSet.Forward) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Forward",
        "Linux_DnsMasterZone");
   	}


    return m_Forward;

  }
       
  //----------------------------------------------------------------------------
  // NegativeCachingTTL related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isNegativeCachingTTLSet() const {
    return isSet.NegativeCachingTTL;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneManualInstance::setNegativeCachingTTL(
    const CMPIUint32 aValue) {
  
    m_NegativeCachingTTL = aValue;
    isSet.NegativeCachingTTL = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsMasterZoneManualInstance::getNegativeCachingTTL() const {
    
    if ( ! isSet.NegativeCachingTTL) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "NegativeCachingTTL",
        "Linux_DnsMasterZone");
   	}


    return m_NegativeCachingTTL;

  }
       
  //----------------------------------------------------------------------------
  // Refresh related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isRefreshSet() const {
    return isSet.Refresh;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneManualInstance::setRefresh(
    const CMPIUint32 aValue) {
  
    m_Refresh = aValue;
    isSet.Refresh = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsMasterZoneManualInstance::getRefresh() const {
    
    if ( ! isSet.Refresh) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Refresh",
        "Linux_DnsMasterZone");
   	}


    return m_Refresh;

  }
       
  //----------------------------------------------------------------------------
  // Retry related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isRetrySet() const {
    return isSet.Retry;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneManualInstance::setRetry(
    const CMPIUint32 aValue) {
  
    m_Retry = aValue;
    isSet.Retry = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsMasterZoneManualInstance::getRetry() const {
    
    if ( ! isSet.Retry) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Retry",
        "Linux_DnsMasterZone");
   	}


    return m_Retry;

  }
       
  //----------------------------------------------------------------------------
  // SerialNumber related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isSerialNumberSet() const {
    return isSet.SerialNumber;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneManualInstance::setSerialNumber(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.SerialNumber) {
      delete [] m_SerialNumber;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_SerialNumber = valueP;
    } else {
      m_SerialNumber = aValueP;
    }
    
    isSet.SerialNumber = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsMasterZoneManualInstance::getSerialNumber() const {
    
    if ( ! isSet.SerialNumber) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "SerialNumber",
        "Linux_DnsMasterZone");
   	}


    return m_SerialNumber;

  }
       
  //----------------------------------------------------------------------------
  // Server related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isServerSet() const {
    return isSet.Server;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneManualInstance::setServer(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Server) {
      delete [] m_Server;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Server = valueP;
    } else {
      m_Server = aValueP;
    }
    
    isSet.Server = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsMasterZoneManualInstance::getServer() const {
    
    if ( ! isSet.Server) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Server",
        "Linux_DnsMasterZone");
   	}


    return m_Server;

  }
       
  //----------------------------------------------------------------------------
  // TTL related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isTTLSet() const {
    return isSet.TTL;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneManualInstance::setTTL(
    const CMPISint32 aValue) {
  
    m_TTL = aValue;
    isSet.TTL = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPISint32
  Linux_DnsMasterZoneManualInstance::getTTL() const {
    
    if ( ! isSet.TTL) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "TTL",
        "Linux_DnsMasterZone");
   	}


    return m_TTL;

  }
       
  //----------------------------------------------------------------------------
  // Type related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isTypeSet() const {
    return isSet.Type;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneManualInstance::setType(
    const CMPIUint8 aValue) {
  
    m_Type = aValue;
    isSet.Type = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  Linux_DnsMasterZoneManualInstance::getType() const {
    
    if ( ! isSet.Type) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Type",
        "Linux_DnsMasterZone");
   	}


    return m_Type;

  }
       
  //----------------------------------------------------------------------------
  // ZoneFile related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneManualInstance::isZoneFileSet() const {
    return isSet.ZoneFile;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneManualInstance::setZoneFile(
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
  Linux_DnsMasterZoneManualInstance::getZoneFile() const {
    
    if ( ! isSet.ZoneFile) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ZoneFile",
        "Linux_DnsMasterZone");
   	}


    return m_ZoneFile;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.Contact = 0;
    isSet.Expire = 0;
    isSet.Forward = 0;
    isSet.NegativeCachingTTL = 0;
    isSet.Refresh = 0;
    isSet.Retry = 0;
    isSet.SerialNumber = 0;
    isSet.Server = 0;
    isSet.TTL = 0;
    isSet.Type = 0;
    isSet.ZoneFile = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsMasterZoneManualInstance::init(
    const Linux_DnsMasterZoneManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isContactSet()) {
      const char* ContactOriginal = anOriginal.getContact();
      setContact(ContactOriginal,1);
    }
   	
    if (anOriginal.isExpireSet()) {
      const CMPIUint32 ExpireOriginal = anOriginal.getExpire();
      setExpire(ExpireOriginal);
    }
   	
    if (anOriginal.isForwardSet()) {
      const CMPIUint8 ForwardOriginal = anOriginal.getForward();
      setForward(ForwardOriginal);
    }
   	
    if (anOriginal.isNegativeCachingTTLSet()) {
      const CMPIUint32 NegativeCachingTTLOriginal = anOriginal.getNegativeCachingTTL();
      setNegativeCachingTTL(NegativeCachingTTLOriginal);
    }
   	
    if (anOriginal.isRefreshSet()) {
      const CMPIUint32 RefreshOriginal = anOriginal.getRefresh();
      setRefresh(RefreshOriginal);
    }
   	
    if (anOriginal.isRetrySet()) {
      const CMPIUint32 RetryOriginal = anOriginal.getRetry();
      setRetry(RetryOriginal);
    }
   	
    if (anOriginal.isSerialNumberSet()) {
      const char* SerialNumberOriginal = anOriginal.getSerialNumber();
      setSerialNumber(SerialNumberOriginal,1);
    }
   	
    if (anOriginal.isServerSet()) {
      const char* ServerOriginal = anOriginal.getServer();
      setServer(ServerOriginal,1);
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
  Linux_DnsMasterZoneManualInstance::reset() {
   	
  	if (isSet.Contact) {
  	  delete(m_Contact);
  	}

  	if (isSet.SerialNumber) {
  	  delete(m_SerialNumber);
  	}

  	if (isSet.Server) {
  	  delete(m_Server);
  	}

  	if (isSet.ZoneFile) {
  	  delete(m_ZoneFile);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsMasterZoneManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneManualInstanceEnumerationElement::Linux_DnsMasterZoneManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneManualInstanceEnumerationElement::~Linux_DnsMasterZoneManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsMasterZoneManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneManualInstanceEnumeration::Linux_DnsMasterZoneManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneManualInstanceEnumeration::Linux_DnsMasterZoneManualInstanceEnumeration(
    const Linux_DnsMasterZoneManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneManualInstanceEnumeration::~Linux_DnsMasterZoneManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsMasterZoneManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsMasterZoneManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsMasterZoneManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMasterZoneManualInstance&  
  Linux_DnsMasterZoneManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsMasterZoneManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMasterZoneManualInstance&
  Linux_DnsMasterZoneManualInstanceEnumeration::getNext() {
   	
    Linux_DnsMasterZoneManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneManualInstanceEnumeration::addElement(
    const Linux_DnsMasterZoneManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsMasterZoneManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsMasterZoneManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsMasterZoneManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsMasterZoneManualInstance(anInstance);
  	}

  }
  
}
