// =======================================================================
// Linux_DnsSettingContextInstanceName.h
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
#ifndef Linux_DnsSettingContextInstanceName_h
#define Linux_DnsSettingContextInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsSettingInstanceName.h"
#include "Linux_DnsConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsSettingContextInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsSettingContextInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsSettingInstanceName m_Setting;
    Linux_DnsConfigurationInstanceName m_Context;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Setting:1;
      unsigned int Context:1;

    } isSet;
  
    public:
    Linux_DnsSettingContextInstanceName();
  	
    Linux_DnsSettingContextInstanceName(const Linux_DnsSettingContextInstanceName& anInstanceName);
  	   
    Linux_DnsSettingContextInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsSettingContextInstanceName();
       
    Linux_DnsSettingContextInstanceName& operator=(const Linux_DnsSettingContextInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isSettingSet() const;
    void setSetting(const Linux_DnsSettingInstanceName& aValue);
    const Linux_DnsSettingInstanceName& getSetting() const;

    unsigned int isContextSet() const;
    void setContext(const Linux_DnsConfigurationInstanceName& aValue);
    const Linux_DnsConfigurationInstanceName& getContext() const;


  };
  
  //****************************************************************************
  struct Linux_DnsSettingContextInstanceNameEnumerationElement {
  	Linux_DnsSettingContextInstanceName* m_elementP;
  	Linux_DnsSettingContextInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingContextInstanceNameEnumerationElement();
  	~Linux_DnsSettingContextInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsSettingContextInstanceNameEnumeration {
  
  	private:
    Linux_DnsSettingContextInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsSettingContextInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsSettingContextInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsSettingContextInstanceNameEnumeration();
  	  
    Linux_DnsSettingContextInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsSettingContextInstanceNameEnumeration(const Linux_DnsSettingContextInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsSettingContextInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsSettingContextInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsSettingContextInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsSettingContextInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

