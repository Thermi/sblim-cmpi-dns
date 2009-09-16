// =======================================================================
// Linux_DnsBlackholeForServiceInstanceName.h
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
#ifndef Linux_DnsBlackholeForServiceInstanceName_h
#define Linux_DnsBlackholeForServiceInstanceName_h

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

  class Linux_DnsBlackholeForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);
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
    Linux_DnsBlackholeForServiceInstanceName();
  	
    Linux_DnsBlackholeForServiceInstanceName(const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsBlackholeForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsBlackholeForServiceInstanceName();
       
    Linux_DnsBlackholeForServiceInstanceName& operator=(const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);
       
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
  struct Linux_DnsBlackholeForServiceInstanceNameEnumerationElement {
  	Linux_DnsBlackholeForServiceInstanceName* m_elementP;
  	Linux_DnsBlackholeForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsBlackholeForServiceInstanceNameEnumerationElement();
  	~Linux_DnsBlackholeForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsBlackholeForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsBlackholeForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsBlackholeForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsBlackholeForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsBlackholeForServiceInstanceNameEnumeration();
  	  
    Linux_DnsBlackholeForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsBlackholeForServiceInstanceNameEnumeration(const Linux_DnsBlackholeForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsBlackholeForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsBlackholeForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsBlackholeForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

