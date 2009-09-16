// =======================================================================
// Linux_DnsResourceRecordInstanceName.h
//     created on Fri, 1 Dec 2006 using ECUTE 2.2
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
#ifndef Linux_DnsResourceRecordInstanceName_h
#define Linux_DnsResourceRecordInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsResourceRecordInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_InstanceID;
    const char* m_Name;
    const char* m_Type;
    const char* m_Value;
    const char* m_ZoneName;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int InstanceID:1;
      unsigned int Name:1;
      unsigned int Type:1;
      unsigned int Value:1;
      unsigned int ZoneName:1;

    } isSet;
  
    public:
    Linux_DnsResourceRecordInstanceName();
  	
    Linux_DnsResourceRecordInstanceName(const Linux_DnsResourceRecordInstanceName& anInstanceName);
  	   
    Linux_DnsResourceRecordInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsResourceRecordInstanceName();
       
    Linux_DnsResourceRecordInstanceName& operator=(const Linux_DnsResourceRecordInstanceName& anInstanceName);
       
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

    unsigned int isTypeSet() const;
    void setType(const char* aValue, int aCopyFlag = 1);
    const char* getType() const;

    unsigned int isValueSet() const;
    void setValue(const char* aValue, int aCopyFlag = 1);
    const char* getValue() const;

    unsigned int isZoneNameSet() const;
    void setZoneName(const char* aValue, int aCopyFlag = 1);
    const char* getZoneName() const;


  };
  
  //****************************************************************************
  struct Linux_DnsResourceRecordInstanceNameEnumerationElement {
  	Linux_DnsResourceRecordInstanceName* m_elementP;
  	Linux_DnsResourceRecordInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordInstanceNameEnumerationElement();
  	~Linux_DnsResourceRecordInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsResourceRecordInstanceNameEnumeration {
  
  	private:
    Linux_DnsResourceRecordInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsResourceRecordInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsResourceRecordInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsResourceRecordInstanceNameEnumeration();
  	  
    Linux_DnsResourceRecordInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsResourceRecordInstanceNameEnumeration(const Linux_DnsResourceRecordInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsResourceRecordInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsResourceRecordInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsResourceRecordInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsResourceRecordInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

