// =======================================================================
// Linux_DnsForwardZoneInstanceName.h
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
#ifndef Linux_DnsForwardZoneInstanceName_h
#define Linux_DnsForwardZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsForwardZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsForwardZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_Name;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Name:1;

    } isSet;
  
    public:
    Linux_DnsForwardZoneInstanceName();
  	
    Linux_DnsForwardZoneInstanceName(const Linux_DnsForwardZoneInstanceName& anInstanceName);
  	   
    Linux_DnsForwardZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsForwardZoneInstanceName();
       
    Linux_DnsForwardZoneInstanceName& operator=(const Linux_DnsForwardZoneInstanceName& anInstanceName);
       
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
  struct Linux_DnsForwardZoneInstanceNameEnumerationElement {
  	Linux_DnsForwardZoneInstanceName* m_elementP;
  	Linux_DnsForwardZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsForwardZoneInstanceNameEnumerationElement();
  	~Linux_DnsForwardZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsForwardZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsForwardZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsForwardZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsForwardZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsForwardZoneInstanceNameEnumeration();
  	  
    Linux_DnsForwardZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsForwardZoneInstanceNameEnumeration(const Linux_DnsForwardZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsForwardZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsForwardZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsForwardZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsForwardZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

