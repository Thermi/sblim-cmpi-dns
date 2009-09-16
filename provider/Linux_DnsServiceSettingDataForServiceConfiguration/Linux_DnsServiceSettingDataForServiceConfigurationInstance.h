// =======================================================================
// Linux_DnsServiceSettingDataForServiceConfigurationInstance.h
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
#ifndef Linux_DnsServiceSettingDataForServiceConfigurationInstance_h
#define Linux_DnsServiceSettingDataForServiceConfigurationInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceSettingDataForServiceConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceSettingDataForServiceConfigurationInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceSettingDataForServiceConfigurationInstance& anInstance);
    void reset();
       
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceSettingDataForServiceConfigurationInstance();
    Linux_DnsServiceSettingDataForServiceConfigurationInstance(
      const Linux_DnsServiceSettingDataForServiceConfigurationInstance& anInstance);
    Linux_DnsServiceSettingDataForServiceConfigurationInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceSettingDataForServiceConfigurationInstance();
       
    Linux_DnsServiceSettingDataForServiceConfigurationInstance& operator=(
      const Linux_DnsServiceSettingDataForServiceConfigurationInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName);        
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumerationElement {

    Linux_DnsServiceSettingDataForServiceConfigurationInstance* m_elementP;
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumerationElement();
    ~Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumeration {

    private:
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumeration();
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumeration(
      const Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceSettingDataForServiceConfigurationInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceSettingDataForServiceConfigurationInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceSettingDataForServiceConfigurationInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceSettingDataForServiceConfigurationInstance& anInstance);

  };

}

#endif
