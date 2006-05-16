// =======================================================================
// Linux_DnsQueryACLForServiceInstanceName.h
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
#ifndef Linux_DnsQueryACLForServiceInstanceName_h
#define Linux_DnsQueryACLForServiceInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsAddressMatchListInstanceName.h"
#include "Linux_DnsServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsQueryACLForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsQueryACLForServiceInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsAddressMatchListInstanceName m_Setting;
    Linux_DnsServiceInstanceName m_Element;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Setting:1;
      unsigned int Element:1;

    } isSet;
  
    public:
    Linux_DnsQueryACLForServiceInstanceName();
  	
    Linux_DnsQueryACLForServiceInstanceName(const Linux_DnsQueryACLForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsQueryACLForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsQueryACLForServiceInstanceName();
       
    Linux_DnsQueryACLForServiceInstanceName& operator=(const Linux_DnsQueryACLForServiceInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isSettingSet() const;
    void setSetting(const Linux_DnsAddressMatchListInstanceName& aValue);
    const Linux_DnsAddressMatchListInstanceName& getSetting() const;

    unsigned int isElementSet() const;
    void setElement(const Linux_DnsServiceInstanceName& aValue);
    const Linux_DnsServiceInstanceName& getElement() const;


  };
  
  //****************************************************************************
  struct Linux_DnsQueryACLForServiceInstanceNameEnumerationElement {
  	Linux_DnsQueryACLForServiceInstanceName* m_elementP;
  	Linux_DnsQueryACLForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsQueryACLForServiceInstanceNameEnumerationElement();
  	~Linux_DnsQueryACLForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsQueryACLForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsQueryACLForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsQueryACLForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsQueryACLForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsQueryACLForServiceInstanceNameEnumeration();
  	  
    Linux_DnsQueryACLForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsQueryACLForServiceInstanceNameEnumeration(const Linux_DnsQueryACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsQueryACLForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsQueryACLForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsQueryACLForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsQueryACLForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

