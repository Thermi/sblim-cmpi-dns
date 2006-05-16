// =======================================================================
// Linux_DnsAllowTransferACLForZoneInstanceName.h
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
#ifndef Linux_DnsAllowTransferACLForZoneInstanceName_h
#define Linux_DnsAllowTransferACLForZoneInstanceName_h

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

  class Linux_DnsAllowTransferACLForZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferACLForZoneInstanceName& anInstanceName);
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
    Linux_DnsAllowTransferACLForZoneInstanceName();
  	
    Linux_DnsAllowTransferACLForZoneInstanceName(const Linux_DnsAllowTransferACLForZoneInstanceName& anInstanceName);
  	   
    Linux_DnsAllowTransferACLForZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAllowTransferACLForZoneInstanceName();
       
    Linux_DnsAllowTransferACLForZoneInstanceName& operator=(const Linux_DnsAllowTransferACLForZoneInstanceName& anInstanceName);
       
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
  struct Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement {
  	Linux_DnsAllowTransferACLForZoneInstanceName* m_elementP;
  	Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement();
  	~Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAllowTransferACLForZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration();
  	  
    Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration(const Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAllowTransferACLForZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAllowTransferACLForZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAllowTransferACLForZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

