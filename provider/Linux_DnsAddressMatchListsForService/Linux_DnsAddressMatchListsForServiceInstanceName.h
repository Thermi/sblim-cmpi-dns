// =======================================================================
// Linux_DnsAddressMatchListsForServiceInstanceName.h
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
#ifndef Linux_DnsAddressMatchListsForServiceInstanceName_h
#define Linux_DnsAddressMatchListsForServiceInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsAddressMatchListInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListsForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsServiceInstanceName m_GroupComponent;
    Linux_DnsAddressMatchListInstanceName m_PartComponent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int GroupComponent:1;
      unsigned int PartComponent:1;

    } isSet;
  
    public:
    Linux_DnsAddressMatchListsForServiceInstanceName();
  	
    Linux_DnsAddressMatchListsForServiceInstanceName(const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsAddressMatchListsForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAddressMatchListsForServiceInstanceName();
       
    Linux_DnsAddressMatchListsForServiceInstanceName& operator=(const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isGroupComponentSet() const;
    void setGroupComponent(const Linux_DnsServiceInstanceName& aValue);
    const Linux_DnsServiceInstanceName& getGroupComponent() const;

    unsigned int isPartComponentSet() const;
    void setPartComponent(const Linux_DnsAddressMatchListInstanceName& aValue);
    const Linux_DnsAddressMatchListInstanceName& getPartComponent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsAddressMatchListsForServiceInstanceNameEnumerationElement {
  	Linux_DnsAddressMatchListsForServiceInstanceName* m_elementP;
  	Linux_DnsAddressMatchListsForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListsForServiceInstanceNameEnumerationElement();
  	~Linux_DnsAddressMatchListsForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsAddressMatchListsForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAddressMatchListsForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAddressMatchListsForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration();
  	  
    Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration(const Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAddressMatchListsForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAddressMatchListsForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

