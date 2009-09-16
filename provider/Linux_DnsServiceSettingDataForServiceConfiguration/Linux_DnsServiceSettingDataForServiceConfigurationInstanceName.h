// =======================================================================
// Linux_DnsServiceSettingDataForServiceConfigurationInstanceName.h
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
#ifndef Linux_DnsServiceSettingDataForServiceConfigurationInstanceName_h
#define Linux_DnsServiceSettingDataForServiceConfigurationInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsServiceConfigurationInstanceName.h"
#include "Linux_DnsServiceSettingDataInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceSettingDataForServiceConfigurationInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsServiceConfigurationInstanceName m_GroupComponent;
    Linux_DnsServiceSettingDataInstanceName m_PartComponent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int GroupComponent:1;
      unsigned int PartComponent:1;

    } isSet;
  
    public:
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceName();
  	
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceName(const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName);
  	   
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsServiceSettingDataForServiceConfigurationInstanceName();
       
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& operator=(const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isGroupComponentSet() const;
    void setGroupComponent(const Linux_DnsServiceConfigurationInstanceName& aValue);
    const Linux_DnsServiceConfigurationInstanceName& getGroupComponent() const;

    unsigned int isPartComponentSet() const;
    void setPartComponent(const Linux_DnsServiceSettingDataInstanceName& aValue);
    const Linux_DnsServiceSettingDataInstanceName& getPartComponent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement {
  	Linux_DnsServiceSettingDataForServiceConfigurationInstanceName* m_elementP;
  	Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement();
  	~Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration {
  
  	private:
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration();
  	  
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration(const Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

