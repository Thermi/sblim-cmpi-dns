// =======================================================================
// Linux_DnsAddressMatchListOfServiceInstanceName.h
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
#ifndef Linux_DnsAddressMatchListOfServiceInstanceName_h
#define Linux_DnsAddressMatchListOfServiceInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsAddressMatchListInstanceName.h"
#include "Linux_DnsServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsAddressMatchListInstanceName m_Dependent;
    Linux_DnsServiceInstanceName m_Antecedent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Dependent:1;
      unsigned int Antecedent:1;

    } isSet;
  
    public:
    Linux_DnsAddressMatchListOfServiceInstanceName();
  	
    Linux_DnsAddressMatchListOfServiceInstanceName(const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName);
  	   
    Linux_DnsAddressMatchListOfServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsAddressMatchListOfServiceInstanceName();
       
    Linux_DnsAddressMatchListOfServiceInstanceName& operator=(const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isDependentSet() const;
    void setDependent(const Linux_DnsAddressMatchListInstanceName& aValue);
    const Linux_DnsAddressMatchListInstanceName& getDependent() const;

    unsigned int isAntecedentSet() const;
    void setAntecedent(const Linux_DnsServiceInstanceName& aValue);
    const Linux_DnsServiceInstanceName& getAntecedent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement {
  	Linux_DnsAddressMatchListOfServiceInstanceName* m_elementP;
  	Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement();
  	~Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration();
  	  
    Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(const Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsAddressMatchListOfServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsAddressMatchListOfServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

