// =======================================================================
// Linux_DnsMasterZoneInstance.cpp
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
#include "Linux_DnsMasterZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsMasterZoneInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsMasterZoneInstance::Linux_DnsMasterZoneInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneInstance::Linux_DnsMasterZoneInstance(
    const Linux_DnsMasterZoneInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneInstance::Linux_DnsMasterZoneInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsMasterZoneInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("Caption");
    if ( ! cmpiData.isNullValue()){
      CmpiString Caption = cmpiData;
      setCaption(Caption.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Contact");
    if ( ! cmpiData.isNullValue()){
      CmpiString Contact = cmpiData;
      setContact(Contact.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Description");
    if ( ! cmpiData.isNullValue()){
      CmpiString Description = cmpiData;
      setDescription(Description.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("ElementName");
    if ( ! cmpiData.isNullValue()){
      CmpiString ElementName = cmpiData;
      setElementName(ElementName.charPtr());
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
  Linux_DnsMasterZoneInstance::
   ~Linux_DnsMasterZoneInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneInstance&
  Linux_DnsMasterZoneInstance::operator=(
    const Linux_DnsMasterZoneInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsMasterZoneInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.Caption) {
  	  
  	  cmpiInstance.setProperty(
  	    "Caption",
  	    CmpiData(m_Caption));
  	}

  	if (isSet.Contact) {
  	  
  	  cmpiInstance.setProperty(
  	    "Contact",
  	    CmpiData(m_Contact));
  	}

  	if (isSet.Description) {
  	  
  	  cmpiInstance.setProperty(
  	    "Description",
  	    CmpiData(m_Description));
  	}

  	if (isSet.ElementName) {
  	  
  	  cmpiInstance.setProperty(
  	    "ElementName",
  	    CmpiData(m_ElementName));
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
  Linux_DnsMasterZoneInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMasterZoneInstanceName&
  Linux_DnsMasterZoneInstance::getInstanceName() const {

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
  Linux_DnsMasterZoneInstance::setInstanceName(
    const Linux_DnsMasterZoneInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Caption related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneInstance::isCaptionSet() const {
    return isSet.Caption;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstance::setCaption(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Caption) {
      delete [] m_Caption;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Caption = valueP;
    } else {
      m_Caption = aValueP;
    }
    
    isSet.Caption = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsMasterZoneInstance::getCaption() const {
    
    if ( ! isSet.Caption) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Caption",
        "Linux_DnsMasterZone");
   	}


    return m_Caption;

  }
       
  //----------------------------------------------------------------------------
  // Contact related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneInstance::isContactSet() const {
    return isSet.Contact;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstance::setContact(
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
  Linux_DnsMasterZoneInstance::getContact() const {
    
    if ( ! isSet.Contact) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Contact",
        "Linux_DnsMasterZone");
   	}


    return m_Contact;

  }
       
  //----------------------------------------------------------------------------
  // Description related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneInstance::isDescriptionSet() const {
    return isSet.Description;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstance::setDescription(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Description) {
      delete [] m_Description;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Description = valueP;
    } else {
      m_Description = aValueP;
    }
    
    isSet.Description = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsMasterZoneInstance::getDescription() const {
    
    if ( ! isSet.Description) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Description",
        "Linux_DnsMasterZone");
   	}


    return m_Description;

  }
       
  //----------------------------------------------------------------------------
  // ElementName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneInstance::isElementNameSet() const {
    return isSet.ElementName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstance::setElementName(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ElementName) {
      delete [] m_ElementName;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ElementName = valueP;
    } else {
      m_ElementName = aValueP;
    }
    
    isSet.ElementName = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsMasterZoneInstance::getElementName() const {
    
    if ( ! isSet.ElementName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElementName",
        "Linux_DnsMasterZone");
   	}


    return m_ElementName;

  }
       
  //----------------------------------------------------------------------------
  // Expire related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneInstance::isExpireSet() const {
    return isSet.Expire;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneInstance::setExpire(
    const CMPIUint32 aValue) {
  
    m_Expire = aValue;
    isSet.Expire = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsMasterZoneInstance::getExpire() const {
    
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
  Linux_DnsMasterZoneInstance::isForwardSet() const {
    return isSet.Forward;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneInstance::setForward(
    const CMPIUint8 aValue) {
  
    m_Forward = aValue;
    isSet.Forward = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  Linux_DnsMasterZoneInstance::getForward() const {
    
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
  Linux_DnsMasterZoneInstance::isNegativeCachingTTLSet() const {
    return isSet.NegativeCachingTTL;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneInstance::setNegativeCachingTTL(
    const CMPIUint32 aValue) {
  
    m_NegativeCachingTTL = aValue;
    isSet.NegativeCachingTTL = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsMasterZoneInstance::getNegativeCachingTTL() const {
    
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
  Linux_DnsMasterZoneInstance::isRefreshSet() const {
    return isSet.Refresh;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneInstance::setRefresh(
    const CMPIUint32 aValue) {
  
    m_Refresh = aValue;
    isSet.Refresh = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsMasterZoneInstance::getRefresh() const {
    
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
  Linux_DnsMasterZoneInstance::isRetrySet() const {
    return isSet.Retry;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneInstance::setRetry(
    const CMPIUint32 aValue) {
  
    m_Retry = aValue;
    isSet.Retry = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  Linux_DnsMasterZoneInstance::getRetry() const {
    
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
  Linux_DnsMasterZoneInstance::isSerialNumberSet() const {
    return isSet.SerialNumber;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstance::setSerialNumber(
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
  Linux_DnsMasterZoneInstance::getSerialNumber() const {
    
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
  Linux_DnsMasterZoneInstance::isServerSet() const {
    return isSet.Server;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstance::setServer(
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
  Linux_DnsMasterZoneInstance::getServer() const {
    
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
  Linux_DnsMasterZoneInstance::isTTLSet() const {
    return isSet.TTL;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneInstance::setTTL(
    const CMPISint32 aValue) {
  
    m_TTL = aValue;
    isSet.TTL = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPISint32
  Linux_DnsMasterZoneInstance::getTTL() const {
    
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
  Linux_DnsMasterZoneInstance::isTypeSet() const {
    return isSet.Type;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMasterZoneInstance::setType(
    const CMPIUint8 aValue) {
  
    m_Type = aValue;
    isSet.Type = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  Linux_DnsMasterZoneInstance::getType() const {
    
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
  Linux_DnsMasterZoneInstance::isZoneFileSet() const {
    return isSet.ZoneFile;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstance::setZoneFile(
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
  Linux_DnsMasterZoneInstance::getZoneFile() const {
    
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
  Linux_DnsMasterZoneInstance::init() {
   	isSet.instanceName = 0;
    isSet.Caption = 0;
    isSet.Contact = 0;
    isSet.Description = 0;
    isSet.ElementName = 0;
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
  Linux_DnsMasterZoneInstance::init(
    const Linux_DnsMasterZoneInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isCaptionSet()) {
      const char* CaptionOriginal = anOriginal.getCaption();
      setCaption(CaptionOriginal,1);
    }
   	
    if (anOriginal.isContactSet()) {
      const char* ContactOriginal = anOriginal.getContact();
      setContact(ContactOriginal,1);
    }
   	
    if (anOriginal.isDescriptionSet()) {
      const char* DescriptionOriginal = anOriginal.getDescription();
      setDescription(DescriptionOriginal,1);
    }
   	
    if (anOriginal.isElementNameSet()) {
      const char* ElementNameOriginal = anOriginal.getElementName();
      setElementName(ElementNameOriginal,1);
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
  Linux_DnsMasterZoneInstance::reset() {
   	
  	if (isSet.Caption) {
  	  delete(m_Caption);
  	}

  	if (isSet.Contact) {
  	  delete(m_Contact);
  	}

  	if (isSet.Description) {
  	  delete(m_Description);
  	}

  	if (isSet.ElementName) {
  	  delete(m_ElementName);
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
  //Linux_DnsMasterZoneInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneInstanceEnumerationElement::Linux_DnsMasterZoneInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneInstanceEnumerationElement::~Linux_DnsMasterZoneInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsMasterZoneInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneInstanceEnumeration::Linux_DnsMasterZoneInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneInstanceEnumeration::Linux_DnsMasterZoneInstanceEnumeration(
    const Linux_DnsMasterZoneInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneInstanceEnumeration::~Linux_DnsMasterZoneInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsMasterZoneInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsMasterZoneInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsMasterZoneInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMasterZoneInstance&  
  Linux_DnsMasterZoneInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsMasterZoneInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMasterZoneInstance&
  Linux_DnsMasterZoneInstanceEnumeration::getNext() {
   	
    Linux_DnsMasterZoneInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstanceEnumeration::addElement(
    const Linux_DnsMasterZoneInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsMasterZoneInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsMasterZoneInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsMasterZoneInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsMasterZoneInstance(anInstance);
  	}

  }
  
}
