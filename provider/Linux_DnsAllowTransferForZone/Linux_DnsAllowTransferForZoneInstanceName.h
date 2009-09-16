// =======================================================================
// Linux_DnsAllowTransferForZoneInstanceName.h
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
#ifndef Linux_DnsAllowTransferForZoneInstanceName_h
#define Linux_DnsAllowTransferForZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsZoneInstanceName.h"
#include "Linux_DnsAddressMatchListInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferForZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsZoneInstanceName m_GroupComponent;
    Linux_DnsAddressMatchListInstanceName m_PartComponent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int GroupComponent:1;
      unsigned int PartComponent:1;

    } isSet;
  
    public:
    Linux_DnsAllowTransferForZoneInstanceName();
  	
    Linux_DnsAllowTransferForZoneInstanceName(const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName);
  	   
    Linux_DnsAllowTransferForZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAllowTransferForZoneInstanceName();
       
    Linux_DnsAllowTransferForZoneInstanceName& operator=(const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isGroupComponentSet() const;
    void setGroupComponent(const Linux_DnsZoneInstanceName& aValue);
    const Linux_DnsZoneInstanceName& getGroupComponent() const;

    unsigned int isPartComponentSet() const;
    void setPartComponent(const Linux_DnsAddressMatchListInstanceName& aValue);
    const Linux_DnsAddressMatchListInstanceName& getPartComponent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement {
  	Linux_DnsAllowTransferForZoneInstanceName* m_elementP;
  	Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement();
  	~Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAllowTransferForZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAllowTransferForZoneInstanceNameEnumeration();
  	  
    Linux_DnsAllowTransferForZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAllowTransferForZoneInstanceNameEnumeration(const Linux_DnsAllowTransferForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAllowTransferForZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAllowTransferForZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAllowTransferForZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

