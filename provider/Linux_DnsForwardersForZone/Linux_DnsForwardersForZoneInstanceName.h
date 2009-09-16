// =======================================================================
// Linux_DnsForwardersForZoneInstanceName.h
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
#ifndef Linux_DnsForwardersForZoneInstanceName_h
#define Linux_DnsForwardersForZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsZoneInstanceName.h"
#include "Linux_DnsForwardersInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersForZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsForwardersForZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsZoneInstanceName m_GroupComponent;
    Linux_DnsForwardersInstanceName m_PartComponent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int GroupComponent:1;
      unsigned int PartComponent:1;

    } isSet;
  
    public:
    Linux_DnsForwardersForZoneInstanceName();
  	
    Linux_DnsForwardersForZoneInstanceName(const Linux_DnsForwardersForZoneInstanceName& anInstanceName);
  	   
    Linux_DnsForwardersForZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsForwardersForZoneInstanceName();
       
    Linux_DnsForwardersForZoneInstanceName& operator=(const Linux_DnsForwardersForZoneInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isGroupComponentSet() const;
    void setGroupComponent(const Linux_DnsZoneInstanceName& aValue);
    const Linux_DnsZoneInstanceName& getGroupComponent() const;

    unsigned int isPartComponentSet() const;
    void setPartComponent(const Linux_DnsForwardersInstanceName& aValue);
    const Linux_DnsForwardersInstanceName& getPartComponent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsForwardersForZoneInstanceNameEnumerationElement {
  	Linux_DnsForwardersForZoneInstanceName* m_elementP;
  	Linux_DnsForwardersForZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsForwardersForZoneInstanceNameEnumerationElement();
  	~Linux_DnsForwardersForZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsForwardersForZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsForwardersForZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsForwardersForZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsForwardersForZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsForwardersForZoneInstanceNameEnumeration();
  	  
    Linux_DnsForwardersForZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsForwardersForZoneInstanceNameEnumeration(const Linux_DnsForwardersForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsForwardersForZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsForwardersForZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsForwardersForZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsForwardersForZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

