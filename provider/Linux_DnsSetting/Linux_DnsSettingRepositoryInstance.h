// =======================================================================
// Linux_DnsSettingRepositoryInstance.h
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
#ifndef Linux_DnsSettingRepositoryInstance_h
#define Linux_DnsSettingRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingInstanceName.h"


namespace genProvider {

  class Linux_DnsSettingRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsSettingRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsSettingInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsSettingRepositoryInstance();
    Linux_DnsSettingRepositoryInstance(
      const Linux_DnsSettingRepositoryInstance& anInstance);
    Linux_DnsSettingRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsSettingRepositoryInstance();
       
    Linux_DnsSettingRepositoryInstance& operator=(
      const Linux_DnsSettingRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsSettingInstanceName& anInstanceName);        
    const Linux_DnsSettingInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsSettingRepositoryInstanceEnumerationElement {

    Linux_DnsSettingRepositoryInstance* m_elementP;
    Linux_DnsSettingRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsSettingRepositoryInstanceEnumerationElement();
    ~Linux_DnsSettingRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsSettingRepositoryInstanceEnumeration {

    private:
    Linux_DnsSettingRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsSettingRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsSettingRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsSettingRepositoryInstanceEnumeration();
    Linux_DnsSettingRepositoryInstanceEnumeration(
      const Linux_DnsSettingRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsSettingRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsSettingRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsSettingRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsSettingRepositoryInstance& anInstance);

  };

}

#endif
