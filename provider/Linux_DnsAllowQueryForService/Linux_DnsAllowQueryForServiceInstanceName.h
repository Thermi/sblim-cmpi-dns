// =======================================================================
// Linux_DnsAllowQueryForServiceInstanceName.h
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
#ifndef Linux_DnsAllowQueryForServiceInstanceName_h
#define Linux_DnsAllowQueryForServiceInstanceName_h

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

  class Linux_DnsAllowQueryForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);
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
    Linux_DnsAllowQueryForServiceInstanceName();
  	
    Linux_DnsAllowQueryForServiceInstanceName(const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsAllowQueryForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAllowQueryForServiceInstanceName();
       
    Linux_DnsAllowQueryForServiceInstanceName& operator=(const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);
       
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
  struct Linux_DnsAllowQueryForServiceInstanceNameEnumerationElement {
  	Linux_DnsAllowQueryForServiceInstanceName* m_elementP;
  	Linux_DnsAllowQueryForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowQueryForServiceInstanceNameEnumerationElement();
  	~Linux_DnsAllowQueryForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAllowQueryForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsAllowQueryForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAllowQueryForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAllowQueryForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAllowQueryForServiceInstanceNameEnumeration();
  	  
    Linux_DnsAllowQueryForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAllowQueryForServiceInstanceNameEnumeration(const Linux_DnsAllowQueryForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAllowQueryForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAllowQueryForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAllowQueryForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

