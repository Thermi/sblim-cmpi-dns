// =======================================================================
// Linux_DnsForwardersForServiceInstanceName.h
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
#ifndef Linux_DnsForwardersForServiceInstanceName_h
#define Linux_DnsForwardersForServiceInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsForwardersInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsForwardersForServiceInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsServiceInstanceName m_GroupComponent;
    Linux_DnsForwardersInstanceName m_PartComponent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int GroupComponent:1;
      unsigned int PartComponent:1;

    } isSet;
  
    public:
    Linux_DnsForwardersForServiceInstanceName();
  	
    Linux_DnsForwardersForServiceInstanceName(const Linux_DnsForwardersForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsForwardersForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsForwardersForServiceInstanceName();
       
    Linux_DnsForwardersForServiceInstanceName& operator=(const Linux_DnsForwardersForServiceInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isGroupComponentSet() const;
    void setGroupComponent(const Linux_DnsServiceInstanceName& aValue);
    const Linux_DnsServiceInstanceName& getGroupComponent() const;

    unsigned int isPartComponentSet() const;
    void setPartComponent(const Linux_DnsForwardersInstanceName& aValue);
    const Linux_DnsForwardersInstanceName& getPartComponent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsForwardersForServiceInstanceNameEnumerationElement {
  	Linux_DnsForwardersForServiceInstanceName* m_elementP;
  	Linux_DnsForwardersForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsForwardersForServiceInstanceNameEnumerationElement();
  	~Linux_DnsForwardersForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsForwardersForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsForwardersForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsForwardersForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsForwardersForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsForwardersForServiceInstanceNameEnumeration();
  	  
    Linux_DnsForwardersForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsForwardersForServiceInstanceNameEnumeration(const Linux_DnsForwardersForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsForwardersForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsForwardersForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsForwardersForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsForwardersForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

