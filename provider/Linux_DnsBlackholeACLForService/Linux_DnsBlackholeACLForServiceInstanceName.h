// =======================================================================
// Linux_DnsBlackholeACLForServiceInstanceName.h
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
#ifndef Linux_DnsBlackholeACLForServiceInstanceName_h
#define Linux_DnsBlackholeACLForServiceInstanceName_h

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

  class Linux_DnsBlackholeACLForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName);
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
    Linux_DnsBlackholeACLForServiceInstanceName();
  	
    Linux_DnsBlackholeACLForServiceInstanceName(const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsBlackholeACLForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsBlackholeACLForServiceInstanceName();
       
    Linux_DnsBlackholeACLForServiceInstanceName& operator=(const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName);
       
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
  struct Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement {
  	Linux_DnsBlackholeACLForServiceInstanceName* m_elementP;
  	Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement();
  	~Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsBlackholeACLForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsBlackholeACLForServiceInstanceNameEnumeration();
  	  
    Linux_DnsBlackholeACLForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsBlackholeACLForServiceInstanceNameEnumeration(const Linux_DnsBlackholeACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsBlackholeACLForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsBlackholeACLForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsBlackholeACLForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

