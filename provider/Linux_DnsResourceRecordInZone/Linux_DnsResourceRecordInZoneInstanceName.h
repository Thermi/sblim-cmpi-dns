// =======================================================================
// Linux_DnsResourceRecordInZoneInstanceName.h
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
#ifndef Linux_DnsResourceRecordInZoneInstanceName_h
#define Linux_DnsResourceRecordInZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsResourceRecordInstanceName.h"
#include "Linux_DnsZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordInZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsResourceRecordInstanceName m_PartComponent;
    Linux_DnsZoneInstanceName m_GroupComponent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int PartComponent:1;
      unsigned int GroupComponent:1;

    } isSet;
  
    public:
    Linux_DnsResourceRecordInZoneInstanceName();
  	
    Linux_DnsResourceRecordInZoneInstanceName(const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);
  	   
    Linux_DnsResourceRecordInZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsResourceRecordInZoneInstanceName();
       
    Linux_DnsResourceRecordInZoneInstanceName& operator=(const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isPartComponentSet() const;
    void setPartComponent(const Linux_DnsResourceRecordInstanceName& aValue);
    const Linux_DnsResourceRecordInstanceName& getPartComponent() const;

    unsigned int isGroupComponentSet() const;
    void setGroupComponent(const Linux_DnsZoneInstanceName& aValue);
    const Linux_DnsZoneInstanceName& getGroupComponent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement {
  	Linux_DnsResourceRecordInZoneInstanceName* m_elementP;
  	Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement();
  	~Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsResourceRecordInZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsResourceRecordInZoneInstanceNameEnumeration();
  	  
    Linux_DnsResourceRecordInZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsResourceRecordInZoneInstanceNameEnumeration(const Linux_DnsResourceRecordInZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsResourceRecordInZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsResourceRecordInZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsResourceRecordInZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

