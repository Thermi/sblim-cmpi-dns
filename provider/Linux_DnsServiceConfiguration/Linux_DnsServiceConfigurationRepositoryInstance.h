// =======================================================================
// Linux_DnsServiceConfigurationRepositoryInstance.h
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
#ifndef Linux_DnsServiceConfigurationRepositoryInstance_h
#define Linux_DnsServiceConfigurationRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsServiceConfigurationInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceConfigurationRepositoryInstance();
    Linux_DnsServiceConfigurationRepositoryInstance(
      const Linux_DnsServiceConfigurationRepositoryInstance& anInstance);
    Linux_DnsServiceConfigurationRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceConfigurationRepositoryInstance();
       
    Linux_DnsServiceConfigurationRepositoryInstance& operator=(
      const Linux_DnsServiceConfigurationRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);        
    const Linux_DnsServiceConfigurationInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement {

    Linux_DnsServiceConfigurationRepositoryInstance* m_elementP;
    Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement();
    ~Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceConfigurationRepositoryInstanceEnumeration {

    private:
    Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceConfigurationRepositoryInstanceEnumeration();
    Linux_DnsServiceConfigurationRepositoryInstanceEnumeration(
      const Linux_DnsServiceConfigurationRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceConfigurationRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceConfigurationRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceConfigurationRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceConfigurationRepositoryInstance& anInstance);

  };

}

#endif
