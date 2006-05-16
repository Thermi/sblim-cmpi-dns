// =======================================================================
// Linux_DnsSettingContextRepositoryInstance.h
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
#ifndef Linux_DnsSettingContextRepositoryInstance_h
#define Linux_DnsSettingContextRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingContextInstanceName.h"


namespace genProvider {

  class Linux_DnsSettingContextRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsSettingContextRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsSettingContextInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsSettingContextRepositoryInstance();
    Linux_DnsSettingContextRepositoryInstance(
      const Linux_DnsSettingContextRepositoryInstance& anInstance);
    Linux_DnsSettingContextRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsSettingContextRepositoryInstance();
       
    Linux_DnsSettingContextRepositoryInstance& operator=(
      const Linux_DnsSettingContextRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsSettingContextInstanceName& anInstanceName);        
    const Linux_DnsSettingContextInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsSettingContextRepositoryInstanceEnumerationElement {

    Linux_DnsSettingContextRepositoryInstance* m_elementP;
    Linux_DnsSettingContextRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsSettingContextRepositoryInstanceEnumerationElement();
    ~Linux_DnsSettingContextRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsSettingContextRepositoryInstanceEnumeration {

    private:
    Linux_DnsSettingContextRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsSettingContextRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsSettingContextRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsSettingContextRepositoryInstanceEnumeration();
    Linux_DnsSettingContextRepositoryInstanceEnumeration(
      const Linux_DnsSettingContextRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsSettingContextRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsSettingContextRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsSettingContextRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsSettingContextRepositoryInstance& anInstance);

  };

}

#endif
