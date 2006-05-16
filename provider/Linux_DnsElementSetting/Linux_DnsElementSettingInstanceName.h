// =======================================================================
// Linux_DnsElementSettingInstanceName.h
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
#ifndef Linux_DnsElementSettingInstanceName_h
#define Linux_DnsElementSettingInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsSettingInstanceName.h"
#include "Linux_DnsServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsElementSettingInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsElementSettingInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsSettingInstanceName m_Setting;
    Linux_DnsServiceInstanceName m_Element;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Setting:1;
      unsigned int Element:1;

    } isSet;
  
    public:
    Linux_DnsElementSettingInstanceName();
  	
    Linux_DnsElementSettingInstanceName(const Linux_DnsElementSettingInstanceName& anInstanceName);
  	   
    Linux_DnsElementSettingInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsElementSettingInstanceName();
       
    Linux_DnsElementSettingInstanceName& operator=(const Linux_DnsElementSettingInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isSettingSet() const;
    void setSetting(const Linux_DnsSettingInstanceName& aValue);
    const Linux_DnsSettingInstanceName& getSetting() const;

    unsigned int isElementSet() const;
    void setElement(const Linux_DnsServiceInstanceName& aValue);
    const Linux_DnsServiceInstanceName& getElement() const;


  };
  
  //****************************************************************************
  struct Linux_DnsElementSettingInstanceNameEnumerationElement {
  	Linux_DnsElementSettingInstanceName* m_elementP;
  	Linux_DnsElementSettingInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsElementSettingInstanceNameEnumerationElement();
  	~Linux_DnsElementSettingInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsElementSettingInstanceNameEnumeration {
  
  	private:
    Linux_DnsElementSettingInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsElementSettingInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsElementSettingInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsElementSettingInstanceNameEnumeration();
  	  
    Linux_DnsElementSettingInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsElementSettingInstanceNameEnumeration(const Linux_DnsElementSettingInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsElementSettingInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsElementSettingInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsElementSettingInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsElementSettingInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

