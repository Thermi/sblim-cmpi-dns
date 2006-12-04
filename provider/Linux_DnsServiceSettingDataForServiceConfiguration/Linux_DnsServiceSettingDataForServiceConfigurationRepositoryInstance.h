// =======================================================================
// Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance.h
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
#ifndef Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance_h
#define Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceSettingDataForServiceConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance();
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance(
      const Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance& anInstance);
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance();
       
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance& operator=(
      const Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName);        
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumerationElement {

    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance* m_elementP;
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumerationElement();
    ~Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumeration {

    private:
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumeration();
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumeration(
      const Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance& anInstance);

  };

}

#endif
