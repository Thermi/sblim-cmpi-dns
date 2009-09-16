// =======================================================================
// Linux_DnsStubZoneInstanceName.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsStubZoneInstanceName_h
#define Linux_DnsStubZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsStubZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsStubZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_InstanceID;
    const char* m_Name;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int InstanceID:1;
      unsigned int Name:1;

    } isSet;
  
    public:
    Linux_DnsStubZoneInstanceName();
  	
    Linux_DnsStubZoneInstanceName(const Linux_DnsStubZoneInstanceName& anInstanceName);
  	   
    Linux_DnsStubZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsStubZoneInstanceName();
       
    Linux_DnsStubZoneInstanceName& operator=(const Linux_DnsStubZoneInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isInstanceIDSet() const;
    void setInstanceID(const char* aValue, int aCopyFlag = 1);
    const char* getInstanceID() const;

    unsigned int isNameSet() const;
    void setName(const char* aValue, int aCopyFlag = 1);
    const char* getName() const;


  };
  
  //****************************************************************************
  struct Linux_DnsStubZoneInstanceNameEnumerationElement {
  	Linux_DnsStubZoneInstanceName* m_elementP;
  	Linux_DnsStubZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsStubZoneInstanceNameEnumerationElement();
  	~Linux_DnsStubZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsStubZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsStubZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsStubZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsStubZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsStubZoneInstanceNameEnumeration();
  	  
    Linux_DnsStubZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsStubZoneInstanceNameEnumeration(const Linux_DnsStubZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsStubZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsStubZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsStubZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsStubZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

