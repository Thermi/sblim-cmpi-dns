// =======================================================================
// Linux_DnsElementSettingRepositoryInstance.h
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
#ifndef Linux_DnsElementSettingRepositoryInstance_h
#define Linux_DnsElementSettingRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsElementSettingInstanceName.h"


namespace genProvider {

  class Linux_DnsElementSettingRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsElementSettingRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsElementSettingInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsElementSettingRepositoryInstance();
    Linux_DnsElementSettingRepositoryInstance(
      const Linux_DnsElementSettingRepositoryInstance& anInstance);
    Linux_DnsElementSettingRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsElementSettingRepositoryInstance();
       
    Linux_DnsElementSettingRepositoryInstance& operator=(
      const Linux_DnsElementSettingRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsElementSettingInstanceName& anInstanceName);        
    const Linux_DnsElementSettingInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsElementSettingRepositoryInstanceEnumerationElement {

    Linux_DnsElementSettingRepositoryInstance* m_elementP;
    Linux_DnsElementSettingRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsElementSettingRepositoryInstanceEnumerationElement();
    ~Linux_DnsElementSettingRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsElementSettingRepositoryInstanceEnumeration {

    private:
    Linux_DnsElementSettingRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsElementSettingRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsElementSettingRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsElementSettingRepositoryInstanceEnumeration();
    Linux_DnsElementSettingRepositoryInstanceEnumeration(
      const Linux_DnsElementSettingRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsElementSettingRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsElementSettingRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsElementSettingRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsElementSettingRepositoryInstance& anInstance);

  };

}

#endif
