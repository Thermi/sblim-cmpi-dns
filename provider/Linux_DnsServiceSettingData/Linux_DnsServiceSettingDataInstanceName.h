// =======================================================================
// Linux_DnsServiceSettingDataInstanceName.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
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
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsServiceSettingDataInstanceName_h
#define Linux_DnsServiceSettingDataInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsServiceSettingDataInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsServiceSettingDataInstanceName& anInstanceName);
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
    Linux_DnsServiceSettingDataInstanceName();
  	
    Linux_DnsServiceSettingDataInstanceName(const Linux_DnsServiceSettingDataInstanceName& anInstanceName);
  	   
    Linux_DnsServiceSettingDataInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsServiceSettingDataInstanceName();
       
    Linux_DnsServiceSettingDataInstanceName& operator=(const Linux_DnsServiceSettingDataInstanceName& anInstanceName);
       
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
  struct Linux_DnsServiceSettingDataInstanceNameEnumerationElement {
  	Linux_DnsServiceSettingDataInstanceName* m_elementP;
  	Linux_DnsServiceSettingDataInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceSettingDataInstanceNameEnumerationElement();
  	~Linux_DnsServiceSettingDataInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsServiceSettingDataInstanceNameEnumeration {
  
  	private:
    Linux_DnsServiceSettingDataInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsServiceSettingDataInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsServiceSettingDataInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsServiceSettingDataInstanceNameEnumeration();
  	  
    Linux_DnsServiceSettingDataInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsServiceSettingDataInstanceNameEnumeration(const Linux_DnsServiceSettingDataInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsServiceSettingDataInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsServiceSettingDataInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsServiceSettingDataInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsServiceSettingDataInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif
