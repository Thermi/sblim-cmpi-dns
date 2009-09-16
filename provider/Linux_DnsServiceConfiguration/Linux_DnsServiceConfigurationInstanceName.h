// =======================================================================
// Linux_DnsServiceConfigurationInstanceName.h
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


namespace genProvider {

  class Linux_DnsServiceConfigurationInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_Name;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Name:1;

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
    
    unsigned int isNameSet() const;
    void setName(const char* aValue, int aCopyFlag = 1);
    const char* getName() const;


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

