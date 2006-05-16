// =======================================================================
// Linux_DnsManagedSystemElementForSettingInstanceName.h
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
#ifndef Linux_DnsManagedSystemElementForSettingInstanceName_h
#define Linux_DnsManagedSystemElementForSettingInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsAddressMatchListInstanceName.h"
#include "Linux_DnsZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsAddressMatchListInstanceName m_Setting;
    Linux_DnsZoneInstanceName m_Element;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Setting:1;
      unsigned int Element:1;

    } isSet;
  
    public:
    Linux_DnsManagedSystemElementForSettingInstanceName();
  	
    Linux_DnsManagedSystemElementForSettingInstanceName(const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);
  	   
    Linux_DnsManagedSystemElementForSettingInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsManagedSystemElementForSettingInstanceName();
       
    Linux_DnsManagedSystemElementForSettingInstanceName& operator=(const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isSettingSet() const;
    void setSetting(const Linux_DnsAddressMatchListInstanceName& aValue);
    const Linux_DnsAddressMatchListInstanceName& getSetting() const;

    unsigned int isElementSet() const;
    void setElement(const Linux_DnsZoneInstanceName& aValue);
    const Linux_DnsZoneInstanceName& getElement() const;


  };
  
  //****************************************************************************
  struct Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement {
  	Linux_DnsManagedSystemElementForSettingInstanceName* m_elementP;
  	Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement();
  	~Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration {
  
  	private:
    Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration();
  	  
    Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration(const Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsManagedSystemElementForSettingInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsManagedSystemElementForSettingInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

