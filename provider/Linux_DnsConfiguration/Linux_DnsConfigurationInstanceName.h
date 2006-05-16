// =======================================================================
// Linux_DnsConfigurationInstanceName.h
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
#ifndef Linux_DnsConfigurationInstanceName_h
#define Linux_DnsConfigurationInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsConfigurationInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsConfigurationInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_Name;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Name:1;

    } isSet;
  
    public:
    Linux_DnsConfigurationInstanceName();
  	
    Linux_DnsConfigurationInstanceName(const Linux_DnsConfigurationInstanceName& anInstanceName);
  	   
    Linux_DnsConfigurationInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsConfigurationInstanceName();
       
    Linux_DnsConfigurationInstanceName& operator=(const Linux_DnsConfigurationInstanceName& anInstanceName);
       
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
  struct Linux_DnsConfigurationInstanceNameEnumerationElement {
  	Linux_DnsConfigurationInstanceName* m_elementP;
  	Linux_DnsConfigurationInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsConfigurationInstanceNameEnumerationElement();
  	~Linux_DnsConfigurationInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsConfigurationInstanceNameEnumeration {
  
  	private:
    Linux_DnsConfigurationInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsConfigurationInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsConfigurationInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsConfigurationInstanceNameEnumeration();
  	  
    Linux_DnsConfigurationInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsConfigurationInstanceNameEnumeration(const Linux_DnsConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsConfigurationInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsConfigurationInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsConfigurationInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsConfigurationInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

