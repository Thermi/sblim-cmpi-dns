// =======================================================================
// Linux_DnsAllowTransferForServiceInstanceName.h
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
#ifndef Linux_DnsAllowTransferForServiceInstanceName_h
#define Linux_DnsAllowTransferForServiceInstanceName_h

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

  class Linux_DnsAllowTransferForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferForServiceInstanceName& anInstanceName);
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
    Linux_DnsAllowTransferForServiceInstanceName();
  	
    Linux_DnsAllowTransferForServiceInstanceName(const Linux_DnsAllowTransferForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsAllowTransferForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAllowTransferForServiceInstanceName();
       
    Linux_DnsAllowTransferForServiceInstanceName& operator=(const Linux_DnsAllowTransferForServiceInstanceName& anInstanceName);
       
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
  struct Linux_DnsAllowTransferForServiceInstanceNameEnumerationElement {
  	Linux_DnsAllowTransferForServiceInstanceName* m_elementP;
  	Linux_DnsAllowTransferForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowTransferForServiceInstanceNameEnumerationElement();
  	~Linux_DnsAllowTransferForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAllowTransferForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsAllowTransferForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAllowTransferForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAllowTransferForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAllowTransferForServiceInstanceNameEnumeration();
  	  
    Linux_DnsAllowTransferForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAllowTransferForServiceInstanceNameEnumeration(const Linux_DnsAllowTransferForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAllowTransferForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAllowTransferForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAllowTransferForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAllowTransferForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

