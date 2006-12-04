// =======================================================================
// Linux_DnsServiceConfigurationForServiceInstance.h
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
#ifndef Linux_DnsServiceConfigurationForServiceInstance_h
#define Linux_DnsServiceConfigurationForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsServiceConfigurationForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceConfigurationForServiceInstance();
    Linux_DnsServiceConfigurationForServiceInstance(
      const Linux_DnsServiceConfigurationForServiceInstance& anInstance);
    Linux_DnsServiceConfigurationForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceConfigurationForServiceInstance();
       
    Linux_DnsServiceConfigurationForServiceInstance& operator=(
      const Linux_DnsServiceConfigurationForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);        
    const Linux_DnsServiceConfigurationForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceConfigurationForServiceInstanceEnumerationElement {

    Linux_DnsServiceConfigurationForServiceInstance* m_elementP;
    Linux_DnsServiceConfigurationForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceConfigurationForServiceInstanceEnumerationElement();
    ~Linux_DnsServiceConfigurationForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceConfigurationForServiceInstanceEnumeration {

    private:
    Linux_DnsServiceConfigurationForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceConfigurationForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceConfigurationForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceConfigurationForServiceInstanceEnumeration();
    Linux_DnsServiceConfigurationForServiceInstanceEnumeration(
      const Linux_DnsServiceConfigurationForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceConfigurationForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceConfigurationForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceConfigurationForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceConfigurationForServiceInstance& anInstance);

  };

}

#endif