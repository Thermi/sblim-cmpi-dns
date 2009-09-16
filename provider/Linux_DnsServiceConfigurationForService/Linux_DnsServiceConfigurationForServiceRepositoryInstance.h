// =======================================================================
// Linux_DnsServiceConfigurationForServiceRepositoryInstance.h
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
#ifndef Linux_DnsServiceConfigurationForServiceRepositoryInstance_h
#define Linux_DnsServiceConfigurationForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsServiceConfigurationForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceConfigurationForServiceRepositoryInstance();
    Linux_DnsServiceConfigurationForServiceRepositoryInstance(
      const Linux_DnsServiceConfigurationForServiceRepositoryInstance& anInstance);
    Linux_DnsServiceConfigurationForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceConfigurationForServiceRepositoryInstance();
       
    Linux_DnsServiceConfigurationForServiceRepositoryInstance& operator=(
      const Linux_DnsServiceConfigurationForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);        
    const Linux_DnsServiceConfigurationForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsServiceConfigurationForServiceRepositoryInstance* m_elementP;
    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration();
    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration(
      const Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceConfigurationForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceConfigurationForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceConfigurationForServiceRepositoryInstance& anInstance);

  };

}

#endif
