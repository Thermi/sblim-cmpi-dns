// =======================================================================
// Linux_DnsResourceRecordsForZoneInstanceName.h
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
#ifndef Linux_DnsResourceRecordsForZoneInstanceName_h
#define Linux_DnsResourceRecordsForZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsZoneInstanceName.h"
#include "Linux_DnsResourceRecordInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordsForZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsZoneInstanceName m_GroupComponent;
    Linux_DnsResourceRecordInstanceName m_PartComponent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int GroupComponent:1;
      unsigned int PartComponent:1;

    } isSet;
  
    public:
    Linux_DnsResourceRecordsForZoneInstanceName();
  	
    Linux_DnsResourceRecordsForZoneInstanceName(const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);
  	   
    Linux_DnsResourceRecordsForZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsResourceRecordsForZoneInstanceName();
       
    Linux_DnsResourceRecordsForZoneInstanceName& operator=(const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isGroupComponentSet() const;
    void setGroupComponent(const Linux_DnsZoneInstanceName& aValue);
    const Linux_DnsZoneInstanceName& getGroupComponent() const;

    unsigned int isPartComponentSet() const;
    void setPartComponent(const Linux_DnsResourceRecordInstanceName& aValue);
    const Linux_DnsResourceRecordInstanceName& getPartComponent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsResourceRecordsForZoneInstanceNameEnumerationElement {
  	Linux_DnsResourceRecordsForZoneInstanceName* m_elementP;
  	Linux_DnsResourceRecordsForZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordsForZoneInstanceNameEnumerationElement();
  	~Linux_DnsResourceRecordsForZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsResourceRecordsForZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsResourceRecordsForZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsResourceRecordsForZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsResourceRecordsForZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsResourceRecordsForZoneInstanceNameEnumeration();
  	  
    Linux_DnsResourceRecordsForZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsResourceRecordsForZoneInstanceNameEnumeration(const Linux_DnsResourceRecordsForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsResourceRecordsForZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsResourceRecordsForZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsResourceRecordsForZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

