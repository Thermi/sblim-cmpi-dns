// =======================================================================
// Linux_DnsMastersOfSlaveZoneInstanceName.h
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
#ifndef Linux_DnsMastersOfSlaveZoneInstanceName_h
#define Linux_DnsMastersOfSlaveZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsIPAddressInstanceName.h"
#include "Linux_DnsSlaveZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsIPAddressInstanceName m_Setting;
    Linux_DnsSlaveZoneInstanceName m_Element;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Setting:1;
      unsigned int Element:1;

    } isSet;
  
    public:
    Linux_DnsMastersOfSlaveZoneInstanceName();
  	
    Linux_DnsMastersOfSlaveZoneInstanceName(const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);
  	   
    Linux_DnsMastersOfSlaveZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsMastersOfSlaveZoneInstanceName();
       
    Linux_DnsMastersOfSlaveZoneInstanceName& operator=(const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isSettingSet() const;
    void setSetting(const Linux_DnsIPAddressInstanceName& aValue);
    const Linux_DnsIPAddressInstanceName& getSetting() const;

    unsigned int isElementSet() const;
    void setElement(const Linux_DnsSlaveZoneInstanceName& aValue);
    const Linux_DnsSlaveZoneInstanceName& getElement() const;


  };
  
  //****************************************************************************
  struct Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement {
  	Linux_DnsMastersOfSlaveZoneInstanceName* m_elementP;
  	Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement();
  	~Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration();
  	  
    Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(const Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsMastersOfSlaveZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsMastersOfSlaveZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

