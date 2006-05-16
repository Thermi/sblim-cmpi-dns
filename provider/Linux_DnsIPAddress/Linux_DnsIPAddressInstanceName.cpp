// =======================================================================
// Linux_DnsIPAddressInstanceName.cpp
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
#include "Linux_DnsIPAddressInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsIPAddressInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceName::Linux_DnsIPAddressInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceName::Linux_DnsIPAddressInstanceName(
    const Linux_DnsIPAddressInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceName::Linux_DnsIPAddressInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiString IPAddress = path.getKey("IPAddress");
    setIPAddress(IPAddress.charPtr());
    
    CmpiString ZoneName = path.getKey("ZoneName");
    setZoneName(ZoneName.charPtr());

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceName::~Linux_DnsIPAddressInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceName&
  Linux_DnsIPAddressInstanceName::operator=(
    const Linux_DnsIPAddressInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsIPAddressInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "IPAddress",
  	  CmpiData(m_IPAddress));
  	objectPath.setKey(
  	  "ZoneName",
  	  CmpiData(m_ZoneName));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsIPAddressInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.IPAddress) {
  	  
  	  cmpiInstance.setProperty(
  	    "IPAddress",
  	    CmpiData(m_IPAddress));
  	}

  	if (isSet.ZoneName) {
  	  
  	  cmpiInstance.setProperty(
  	    "ZoneName",
  	    CmpiData(m_ZoneName));
  	}

  }
  
  
  //---------------------------------------------------------------------------- 
  // NameSpace related methods
  //---------------------------------------------------------------------------- 
  unsigned int 
  Linux_DnsIPAddressInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsIPAddressInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsIPAddress");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsIPAddressInstanceName::setNamespace(
    const char* aNameSpaceP,
    int aCopyFlag) {
  
    if (isSet.m_nameSpaceP) {
      delete m_nameSpaceP;
    }
    
    if (aCopyFlag && aNameSpaceP) {
      char* nameSpaceP = new char[strlen(aNameSpaceP) + 1];
      strcpy(nameSpaceP,aNameSpaceP);
      m_nameSpaceP = nameSpaceP;
    } else {
      m_nameSpaceP = aNameSpaceP;
    }
    
    isSet.m_nameSpaceP = 1;
  }
         
  //----------------------------------------------------------------------------
  // IPAddress related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsIPAddressInstanceName::isIPAddressSet() const {
    return isSet.IPAddress;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsIPAddressInstanceName::setIPAddress(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.IPAddress) {
      delete [] m_IPAddress;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_IPAddress = valueP;
    } else {
      m_IPAddress = aValueP;
    }
    
    isSet.IPAddress = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsIPAddressInstanceName::getIPAddress() const {
    
    if ( ! isSet.IPAddress) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "IPAddress",
        "Linux_DnsIPAddress");
   	}


    return m_IPAddress;

  }
       
  //----------------------------------------------------------------------------
  // ZoneName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsIPAddressInstanceName::isZoneNameSet() const {
    return isSet.ZoneName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsIPAddressInstanceName::setZoneName(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ZoneName) {
      delete [] m_ZoneName;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ZoneName = valueP;
    } else {
      m_ZoneName = aValueP;
    }
    
    isSet.ZoneName = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsIPAddressInstanceName::getZoneName() const {
    
    if ( ! isSet.ZoneName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ZoneName",
        "Linux_DnsIPAddress");
   	}


    return m_ZoneName;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsIPAddressInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsIPAddress";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.IPAddress = 0;
    isSet.ZoneName = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsIPAddressInstanceName::init(
    const Linux_DnsIPAddressInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isIPAddressSet()) {
      const char* IPAddressOriginal = anOriginal.getIPAddress();
      setIPAddress(IPAddressOriginal,1);
    }
   	
    if (anOriginal.isZoneNameSet()) {
      const char* ZoneNameOriginal = anOriginal.getZoneName();
      setZoneName(ZoneNameOriginal,1);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsIPAddressInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	
  	if (isSet.IPAddress) {
  	  delete(m_IPAddress);
  	}

  	if (isSet.ZoneName) {
  	  delete(m_ZoneName);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceNameEnumerationElement::Linux_DnsIPAddressInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceNameEnumerationElement::~Linux_DnsIPAddressInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceNameEnumeration::Linux_DnsIPAddressInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceNameEnumeration::Linux_DnsIPAddressInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsIPAddressInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceNameEnumeration::Linux_DnsIPAddressInstanceNameEnumeration(
    const Linux_DnsIPAddressInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceNameEnumeration::~Linux_DnsIPAddressInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsIPAddressInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsIPAddressInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsIPAddressInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsIPAddressInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsIPAddressInstanceName&  
   Linux_DnsIPAddressInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsIPAddressInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsIPAddressInstanceName&
  Linux_DnsIPAddressInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsIPAddressInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsIPAddressInstanceNameEnumeration::addElement
   (const Linux_DnsIPAddressInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsIPAddressInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsIPAddressInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsIPAddressInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsIPAddressInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsIPAddressInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
