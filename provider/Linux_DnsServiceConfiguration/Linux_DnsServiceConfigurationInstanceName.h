// =======================================================================
// Linux_DnsServiceConfigurationInstanceName.h
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsServiceConfigurationInstanceName_h
#define Linux_DnsServiceConfigurationInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsConfigurationInstanceName.h"
#include "Linux_DnsServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsConfigurationInstanceName m_Configuration;
    Linux_DnsServiceInstanceName m_Element;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Configuration:1;
      unsigned int Element:1;

    } isSet;
  
    public:
    Linux_DnsServiceConfigurationInstanceName();
  	
    Linux_DnsServiceConfigurationInstanceName(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);
  	   
    Linux_DnsServiceConfigurationInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsServiceConfigurationInstanceName();
       
    Linux_DnsServiceConfigurationInstanceName& operator=(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isConfigurationSet() const;
    void setConfiguration(const Linux_DnsConfigurationInstanceName& aValue);
    const Linux_DnsConfigurationInstanceName& getConfiguration() const;

    unsigned int isElementSet() const;
    void setElement(const Linux_DnsServiceInstanceName& aValue);
    const Linux_DnsServiceInstanceName& getElement() const;


  };
  
  //****************************************************************************
  struct Linux_DnsServiceConfigurationInstanceNameEnumerationElement {
  	Linux_DnsServiceConfigurationInstanceName* m_elementP;
  	Linux_DnsServiceConfigurationInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceConfigurationInstanceNameEnumerationElement();
  	~Linux_DnsServiceConfigurationInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsServiceConfigurationInstanceNameEnumeration {
  
  	private:
    Linux_DnsServiceConfigurationInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsServiceConfigurationInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsServiceConfigurationInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsServiceConfigurationInstanceNameEnumeration();
  	  
    Linux_DnsServiceConfigurationInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsServiceConfigurationInstanceNameEnumeration(const Linux_DnsServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsServiceConfigurationInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsServiceConfigurationInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsServiceConfigurationInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

