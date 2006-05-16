// =======================================================================
// Linux_DnsAddressMatchListManualInstance.cpp
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
#include "Linux_DnsAddressMatchListManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsAddressMatchListManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsAddressMatchListManualInstance::Linux_DnsAddressMatchListManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstance::Linux_DnsAddressMatchListManualInstance(
    const Linux_DnsAddressMatchListManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstance::Linux_DnsAddressMatchListManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsAddressMatchListInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("AddressListType");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 AddressListType = cmpiData;
      setAddressListType(AddressListType);
    }

    cmpiData = aCmpiInstance.getProperty("AddressList");
    if ( ! cmpiData.isNullValue()){
      CmpiArray AddressList = cmpiData;
    unsigned int AddressListSize;
    const char** AddressListArray;
    ArrayConverter::makeArray(
      AddressList, 
      (char***)&AddressListArray, 
      AddressListSize);
      setAddressList(AddressListArray, AddressListSize, 0);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstance::
   ~Linux_DnsAddressMatchListManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstance&
  Linux_DnsAddressMatchListManualInstance::operator=(
    const Linux_DnsAddressMatchListManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsAddressMatchListManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.AddressListType) {
  	  
  	  cmpiInstance.setProperty(
  	    "AddressListType",
  	    CmpiData(m_AddressListType));
  	}

  	if (isSet.AddressList) {
  	  
      unsigned int AddressListSize;
      const char** arrayAddressList = getAddressList(AddressListSize);
      CmpiArray cmpiArrayAddressList = CmpiArray(
        AddressListSize,
        CMPI_chars);
      for (unsigned int x=0; x < AddressListSize; ++x) {
        cmpiArrayAddressList[x] = CmpiData(arrayAddressList[x]);
      }
  	  cmpiInstance.setProperty(
  	    "AddressList",
  	    CmpiData(cmpiArrayAddressList));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsAddressMatchListManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListInstanceName&
  Linux_DnsAddressMatchListManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsAddressMatchList");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstance::setInstanceName(
    const Linux_DnsAddressMatchListInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // AddressListType related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListManualInstance::isAddressListTypeSet() const {
    return isSet.AddressListType;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListManualInstance::setAddressListType(
    const CMPIUint16 aValue) {
  
    m_AddressListType = aValue;
    isSet.AddressListType = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsAddressMatchListManualInstance::getAddressListType() const {
    
    if ( ! isSet.AddressListType) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "AddressListType",
        "Linux_DnsAddressMatchList");
   	}


    return m_AddressListType;

  }
       
  //----------------------------------------------------------------------------
  // AddressList related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListManualInstance::isAddressListSet() const {
    return isSet.AddressList;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsAddressMatchListManualInstance::setAddressList(
    const char** aValuePP, 
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.AddressList) {
      delete m_AddressList;
    }
    
    if (aCopyFlag && aValuePP) {
      m_AddressList = new const char*[aSize];
      for (unsigned int x=0; x < aSize; ++x) {
        char* stringP = new char[strlen(aValuePP[x])+1];
        strcpy(stringP,aValuePP[x]);
        m_AddressList[x] = stringP;
      }      
    } else {
      m_AddressList = aValuePP;
    }
    
    m_AddressListSize = aSize;
    
    isSet.AddressList = 1;
    
  }       

  //----------------------------------------------------------------------------
  const char**
  Linux_DnsAddressMatchListManualInstance::getAddressList(unsigned int& aSize) const {
    
    if ( ! isSet.AddressList) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "AddressList",
        "Linux_DnsAddressMatchList");
   	}

    aSize = m_AddressListSize;
    return m_AddressList;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.AddressListType = 0;
    isSet.AddressList = 0;
    m_AddressListSize = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsAddressMatchListManualInstance::init(
    const Linux_DnsAddressMatchListManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isAddressListTypeSet()) {
      const CMPIUint16 AddressListTypeOriginal = anOriginal.getAddressListType();
      setAddressListType(AddressListTypeOriginal);
    }
   	
    if (anOriginal.isAddressListSet()) {
      unsigned int sizeAddressList;
      const char** AddressListOriginal = anOriginal.getAddressList(sizeAddressList);
      setAddressList(AddressListOriginal, sizeAddressList,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstance::reset() {
   	
  	if (isSet.AddressList) {
  	  ArrayConverter::destructArray((char**)m_AddressList,m_AddressListSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumerationElement::Linux_DnsAddressMatchListManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumerationElement::~Linux_DnsAddressMatchListManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumeration::Linux_DnsAddressMatchListManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumeration::Linux_DnsAddressMatchListManualInstanceEnumeration(
    const Linux_DnsAddressMatchListManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumeration::~Linux_DnsAddressMatchListManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsAddressMatchListManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsAddressMatchListManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListManualInstance&  
  Linux_DnsAddressMatchListManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListManualInstance&
  Linux_DnsAddressMatchListManualInstanceEnumeration::getNext() {
   	
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstanceEnumeration::addElement(
    const Linux_DnsAddressMatchListManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsAddressMatchListManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsAddressMatchListManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsAddressMatchListManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsAddressMatchListManualInstance(anInstance);
  	}

  }
  
}
