// =======================================================================
// Linux_DnsAllowQueryForZoneInstanceName.h
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
#ifndef Linux_DnsAllowQueryForZoneInstanceName_h
#define Linux_DnsAllowQueryForZoneInstanceName_h

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

  class Linux_DnsAllowQueryForZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryForZoneInstanceName& anInstanceName);
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
    Linux_DnsAllowQueryForZoneInstanceName();
  	
    Linux_DnsAllowQueryForZoneInstanceName(const Linux_DnsAllowQueryForZoneInstanceName& anInstanceName);
  	   
    Linux_DnsAllowQueryForZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAllowQueryForZoneInstanceName();
       
    Linux_DnsAllowQueryForZoneInstanceName& operator=(const Linux_DnsAllowQueryForZoneInstanceName& anInstanceName);
       
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
  struct Linux_DnsAllowQueryForZoneInstanceNameEnumerationElement {
  	Linux_DnsAllowQueryForZoneInstanceName* m_elementP;
  	Linux_DnsAllowQueryForZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowQueryForZoneInstanceNameEnumerationElement();
  	~Linux_DnsAllowQueryForZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAllowQueryForZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsAllowQueryForZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAllowQueryForZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAllowQueryForZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAllowQueryForZoneInstanceNameEnumeration();
  	  
    Linux_DnsAllowQueryForZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAllowQueryForZoneInstanceNameEnumeration(const Linux_DnsAllowQueryForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAllowQueryForZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAllowQueryForZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAllowQueryForZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAllowQueryForZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

