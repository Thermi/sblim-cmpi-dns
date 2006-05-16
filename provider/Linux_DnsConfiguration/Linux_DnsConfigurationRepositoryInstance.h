// =======================================================================
// Linux_DnsConfigurationRepositoryInstance.h
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
#ifndef Linux_DnsConfigurationRepositoryInstance_h
#define Linux_DnsConfigurationRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsConfigurationRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsConfigurationRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsConfigurationInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsConfigurationRepositoryInstance();
    Linux_DnsConfigurationRepositoryInstance(
      const Linux_DnsConfigurationRepositoryInstance& anInstance);
    Linux_DnsConfigurationRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsConfigurationRepositoryInstance();
       
    Linux_DnsConfigurationRepositoryInstance& operator=(
      const Linux_DnsConfigurationRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsConfigurationInstanceName& anInstanceName);        
    const Linux_DnsConfigurationInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsConfigurationRepositoryInstanceEnumerationElement {

    Linux_DnsConfigurationRepositoryInstance* m_elementP;
    Linux_DnsConfigurationRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsConfigurationRepositoryInstanceEnumerationElement();
    ~Linux_DnsConfigurationRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsConfigurationRepositoryInstanceEnumeration {

    private:
    Linux_DnsConfigurationRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsConfigurationRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsConfigurationRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsConfigurationRepositoryInstanceEnumeration();
    Linux_DnsConfigurationRepositoryInstanceEnumeration(
      const Linux_DnsConfigurationRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsConfigurationRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsConfigurationRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsConfigurationRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsConfigurationRepositoryInstance& anInstance);

  };

}

#endif
