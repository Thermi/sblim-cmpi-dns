// =======================================================================
// Linux_DnsServiceInstanceName.h
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
#ifndef Linux_DnsServiceInstanceName_h
#define Linux_DnsServiceInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsServiceInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_CreationClassName;
    const char* m_Name;
    const char* m_SystemCreationClassName;
    const char* m_SystemName;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int CreationClassName:1;
      unsigned int Name:1;
      unsigned int SystemCreationClassName:1;
      unsigned int SystemName:1;

    } isSet;
  
    public:
    Linux_DnsServiceInstanceName();
  	
    Linux_DnsServiceInstanceName(const Linux_DnsServiceInstanceName& anInstanceName);
  	   
    Linux_DnsServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsServiceInstanceName();
       
    Linux_DnsServiceInstanceName& operator=(const Linux_DnsServiceInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isCreationClassNameSet() const;
    void setCreationClassName(const char* aValue, int aCopyFlag = 1);
    const char* getCreationClassName() const;

    unsigned int isNameSet() const;
    void setName(const char* aValue, int aCopyFlag = 1);
    const char* getName() const;

    unsigned int isSystemCreationClassNameSet() const;
    void setSystemCreationClassName(const char* aValue, int aCopyFlag = 1);
    const char* getSystemCreationClassName() const;

    unsigned int isSystemNameSet() const;
    void setSystemName(const char* aValue, int aCopyFlag = 1);
    const char* getSystemName() const;


  };
  
  //****************************************************************************
  struct Linux_DnsServiceInstanceNameEnumerationElement {
  	Linux_DnsServiceInstanceName* m_elementP;
  	Linux_DnsServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceInstanceNameEnumerationElement();
  	~Linux_DnsServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsServiceInstanceNameEnumeration();
  	  
    Linux_DnsServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsServiceInstanceNameEnumeration(const Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

