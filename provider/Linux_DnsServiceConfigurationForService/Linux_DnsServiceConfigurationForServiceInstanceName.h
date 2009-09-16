// =======================================================================
// Linux_DnsServiceConfigurationForServiceInstanceName.h
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
#ifndef Linux_DnsServiceConfigurationForServiceInstanceName_h
#define Linux_DnsServiceConfigurationForServiceInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsServiceConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsServiceInstanceName m_Element;
    Linux_DnsServiceConfigurationInstanceName m_Configuration;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Element:1;
      unsigned int Configuration:1;

    } isSet;
  
    public:
    Linux_DnsServiceConfigurationForServiceInstanceName();
  	
    Linux_DnsServiceConfigurationForServiceInstanceName(const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsServiceConfigurationForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsServiceConfigurationForServiceInstanceName();
       
    Linux_DnsServiceConfigurationForServiceInstanceName& operator=(const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isElementSet() const;
    void setElement(const Linux_DnsServiceInstanceName& aValue);
    const Linux_DnsServiceInstanceName& getElement() const;

    unsigned int isConfigurationSet() const;
    void setConfiguration(const Linux_DnsServiceConfigurationInstanceName& aValue);
    const Linux_DnsServiceConfigurationInstanceName& getConfiguration() const;


  };
  
  //****************************************************************************
  struct Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement {
  	Linux_DnsServiceConfigurationForServiceInstanceName* m_elementP;
  	Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement();
  	~Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration();
  	  
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration(const Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsServiceConfigurationForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsServiceConfigurationForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

