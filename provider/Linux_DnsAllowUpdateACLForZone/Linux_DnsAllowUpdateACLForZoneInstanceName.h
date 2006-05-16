// =======================================================================
// Linux_DnsAllowUpdateACLForZoneInstanceName.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneInstanceName_h
#define Linux_DnsAllowUpdateACLForZoneInstanceName_h

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

  class Linux_DnsAllowUpdateACLForZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAllowUpdateACLForZoneInstanceName& anInstanceName);
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
    Linux_DnsAllowUpdateACLForZoneInstanceName();
  	
    Linux_DnsAllowUpdateACLForZoneInstanceName(const Linux_DnsAllowUpdateACLForZoneInstanceName& anInstanceName);
  	   
    Linux_DnsAllowUpdateACLForZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAllowUpdateACLForZoneInstanceName();
       
    Linux_DnsAllowUpdateACLForZoneInstanceName& operator=(const Linux_DnsAllowUpdateACLForZoneInstanceName& anInstanceName);
       
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
  struct Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement {
  	Linux_DnsAllowUpdateACLForZoneInstanceName* m_elementP;
  	Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement();
  	~Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration();
  	  
    Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration(const Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAllowUpdateACLForZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAllowUpdateACLForZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAllowUpdateACLForZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

