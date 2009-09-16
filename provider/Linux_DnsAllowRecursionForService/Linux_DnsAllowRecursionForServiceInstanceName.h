// =======================================================================
// Linux_DnsAllowRecursionForServiceInstanceName.h
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
#ifndef Linux_DnsAllowRecursionForServiceInstanceName_h
#define Linux_DnsAllowRecursionForServiceInstanceName_h

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

  class Linux_DnsAllowRecursionForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName);
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
    Linux_DnsAllowRecursionForServiceInstanceName();
  	
    Linux_DnsAllowRecursionForServiceInstanceName(const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsAllowRecursionForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAllowRecursionForServiceInstanceName();
       
    Linux_DnsAllowRecursionForServiceInstanceName& operator=(const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName);
       
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
  struct Linux_DnsAllowRecursionForServiceInstanceNameEnumerationElement {
  	Linux_DnsAllowRecursionForServiceInstanceName* m_elementP;
  	Linux_DnsAllowRecursionForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowRecursionForServiceInstanceNameEnumerationElement();
  	~Linux_DnsAllowRecursionForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAllowRecursionForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsAllowRecursionForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAllowRecursionForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAllowRecursionForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAllowRecursionForServiceInstanceNameEnumeration();
  	  
    Linux_DnsAllowRecursionForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAllowRecursionForServiceInstanceNameEnumeration(const Linux_DnsAllowRecursionForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAllowRecursionForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAllowRecursionForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAllowRecursionForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

