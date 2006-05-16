// =======================================================================
// Linux_DnsManagedSystemElementForSettingInstance.h
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
#ifndef Linux_DnsManagedSystemElementForSettingInstance_h
#define Linux_DnsManagedSystemElementForSettingInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsManagedSystemElementForSettingInstanceName.h"


namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingInstance {
       
    private:
    void init();
    void init(const Linux_DnsManagedSystemElementForSettingInstance& anInstance);
    void reset();
       
    Linux_DnsManagedSystemElementForSettingInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsManagedSystemElementForSettingInstance();
    Linux_DnsManagedSystemElementForSettingInstance(
      const Linux_DnsManagedSystemElementForSettingInstance& anInstance);
    Linux_DnsManagedSystemElementForSettingInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsManagedSystemElementForSettingInstance();
       
    Linux_DnsManagedSystemElementForSettingInstance& operator=(
      const Linux_DnsManagedSystemElementForSettingInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);        
    const Linux_DnsManagedSystemElementForSettingInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement {

    Linux_DnsManagedSystemElementForSettingInstance* m_elementP;
    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* m_nextP;

    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement();
    ~Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement();  

  };
  

  class Linux_DnsManagedSystemElementForSettingInstanceEnumeration {

    private:
    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* m_firstElementP;
    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* m_currentElementP;
    Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsManagedSystemElementForSettingInstanceEnumeration();
    Linux_DnsManagedSystemElementForSettingInstanceEnumeration(
      const Linux_DnsManagedSystemElementForSettingInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsManagedSystemElementForSettingInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsManagedSystemElementForSettingInstance& getNext();
    int getSize() const;
    const Linux_DnsManagedSystemElementForSettingInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsManagedSystemElementForSettingInstance& anInstance);

  };

}

#endif
