// =======================================================================
// Linux_DnsSlaveZoneInstanceName.h
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
#ifndef Linux_DnsSlaveZoneInstanceName_h
#define Linux_DnsSlaveZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsSlaveZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsSlaveZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_Name;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Name:1;

    } isSet;
  
    public:
    Linux_DnsSlaveZoneInstanceName();
  	
    Linux_DnsSlaveZoneInstanceName(const Linux_DnsSlaveZoneInstanceName& anInstanceName);
  	   
    Linux_DnsSlaveZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsSlaveZoneInstanceName();
       
    Linux_DnsSlaveZoneInstanceName& operator=(const Linux_DnsSlaveZoneInstanceName& anInstanceName);
       
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
  struct Linux_DnsSlaveZoneInstanceNameEnumerationElement {
  	Linux_DnsSlaveZoneInstanceName* m_elementP;
  	Linux_DnsSlaveZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsSlaveZoneInstanceNameEnumerationElement();
  	~Linux_DnsSlaveZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsSlaveZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsSlaveZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsSlaveZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsSlaveZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsSlaveZoneInstanceNameEnumeration();
  	  
    Linux_DnsSlaveZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsSlaveZoneInstanceNameEnumeration(const Linux_DnsSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsSlaveZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsSlaveZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsSlaveZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsSlaveZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

