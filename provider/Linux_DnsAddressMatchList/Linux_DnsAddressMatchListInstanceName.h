// =======================================================================
// Linux_DnsAddressMatchListInstanceName.h
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
#ifndef Linux_DnsAddressMatchListInstanceName_h
#define Linux_DnsAddressMatchListInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsAddressMatchListInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_Name;
    const char* m_ServiceName;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Name:1;
      unsigned int ServiceName:1;

    } isSet;
  
    public:
    Linux_DnsAddressMatchListInstanceName();
  	
    Linux_DnsAddressMatchListInstanceName(const Linux_DnsAddressMatchListInstanceName& anInstanceName);
  	   
    Linux_DnsAddressMatchListInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAddressMatchListInstanceName();
       
    Linux_DnsAddressMatchListInstanceName& operator=(const Linux_DnsAddressMatchListInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isNameSet() const;
    void setName(const char* aValue, int aCopyFlag = 1);
    const char* getName() const;

    unsigned int isServiceNameSet() const;
    void setServiceName(const char* aValue, int aCopyFlag = 1);
    const char* getServiceName() const;


  };
  
  //****************************************************************************
  struct Linux_DnsAddressMatchListInstanceNameEnumerationElement {
  	Linux_DnsAddressMatchListInstanceName* m_elementP;
  	Linux_DnsAddressMatchListInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListInstanceNameEnumerationElement();
  	~Linux_DnsAddressMatchListInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAddressMatchListInstanceNameEnumeration {
  
  	private:
    Linux_DnsAddressMatchListInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAddressMatchListInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAddressMatchListInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAddressMatchListInstanceNameEnumeration();
  	  
    Linux_DnsAddressMatchListInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAddressMatchListInstanceNameEnumeration(const Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAddressMatchListInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAddressMatchListInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAddressMatchListInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAddressMatchListInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

