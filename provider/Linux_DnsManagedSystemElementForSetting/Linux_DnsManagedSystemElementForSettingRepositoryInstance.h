// =======================================================================
// Linux_DnsManagedSystemElementForSettingRepositoryInstance.h
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
#ifndef Linux_DnsManagedSystemElementForSettingRepositoryInstance_h
#define Linux_DnsManagedSystemElementForSettingRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsManagedSystemElementForSettingInstanceName.h"


namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsManagedSystemElementForSettingRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsManagedSystemElementForSettingInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsManagedSystemElementForSettingRepositoryInstance();
    Linux_DnsManagedSystemElementForSettingRepositoryInstance(
      const Linux_DnsManagedSystemElementForSettingRepositoryInstance& anInstance);
    Linux_DnsManagedSystemElementForSettingRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsManagedSystemElementForSettingRepositoryInstance();
       
    Linux_DnsManagedSystemElementForSettingRepositoryInstance& operator=(
      const Linux_DnsManagedSystemElementForSettingRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);        
    const Linux_DnsManagedSystemElementForSettingInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement {

    Linux_DnsManagedSystemElementForSettingRepositoryInstance* m_elementP;
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement();
    ~Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration {

    private:
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration();
    Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration(
      const Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsManagedSystemElementForSettingRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsManagedSystemElementForSettingRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsManagedSystemElementForSettingRepositoryInstance& anInstance);

  };

}

#endif
