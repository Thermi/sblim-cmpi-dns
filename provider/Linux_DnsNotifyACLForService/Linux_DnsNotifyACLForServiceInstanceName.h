// =======================================================================
// Linux_DnsNotifyACLForServiceInstanceName.h
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
#ifndef Linux_DnsNotifyACLForServiceInstanceName_h
#define Linux_DnsNotifyACLForServiceInstanceName_h

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

  class Linux_DnsNotifyACLForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName);
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
    Linux_DnsNotifyACLForServiceInstanceName();
  	
    Linux_DnsNotifyACLForServiceInstanceName(const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsNotifyACLForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsNotifyACLForServiceInstanceName();
       
    Linux_DnsNotifyACLForServiceInstanceName& operator=(const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName);
       
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
  struct Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement {
  	Linux_DnsNotifyACLForServiceInstanceName* m_elementP;
  	Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement();
  	~Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsNotifyACLForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsNotifyACLForServiceInstanceNameEnumeration();
  	  
    Linux_DnsNotifyACLForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsNotifyACLForServiceInstanceNameEnumeration(const Linux_DnsNotifyACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsNotifyACLForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsNotifyACLForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsNotifyACLForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

