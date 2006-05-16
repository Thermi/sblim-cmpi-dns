// =======================================================================
// Linux_DnsZoneInstanceName.h
//     created on Tue, 7 Mar 2006 using ECUTE
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
//                Rodrigo Ceron    <rceron@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsZoneInstanceName_h
#define Linux_DnsZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_Name;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Name:1;

    } isSet;
  
    public:
    Linux_DnsZoneInstanceName();
  	
    Linux_DnsZoneInstanceName(const Linux_DnsZoneInstanceName& anInstanceName);
  	   
    Linux_DnsZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsZoneInstanceName();
       
    Linux_DnsZoneInstanceName& operator=(const Linux_DnsZoneInstanceName& anInstanceName);
       
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
  struct Linux_DnsZoneInstanceNameEnumerationElement {
  	Linux_DnsZoneInstanceName* m_elementP;
  	Linux_DnsZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsZoneInstanceNameEnumerationElement();
  	~Linux_DnsZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsZoneInstanceNameEnumeration();
  	  
    Linux_DnsZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsZoneInstanceNameEnumeration(const Linux_DnsZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

