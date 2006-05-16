// =======================================================================
// Linux_DnsManagedSystemElementForSettingManualInstance.h
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
#ifndef Linux_DnsManagedSystemElementForSettingManualInstance_h
#define Linux_DnsManagedSystemElementForSettingManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsManagedSystemElementForSettingInstanceName.h"


namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsManagedSystemElementForSettingManualInstance& anInstance);
    void reset();
       
    Linux_DnsManagedSystemElementForSettingInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsManagedSystemElementForSettingManualInstance();
    Linux_DnsManagedSystemElementForSettingManualInstance(
      const Linux_DnsManagedSystemElementForSettingManualInstance& anInstance);
    Linux_DnsManagedSystemElementForSettingManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsManagedSystemElementForSettingManualInstance();
       
    Linux_DnsManagedSystemElementForSettingManualInstance& operator=(
      const Linux_DnsManagedSystemElementForSettingManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName);        
    const Linux_DnsManagedSystemElementForSettingInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement {

    Linux_DnsManagedSystemElementForSettingManualInstance* m_elementP;
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* m_nextP;

    Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement();
    ~Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration {

    private:
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration();
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration(
      const Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsManagedSystemElementForSettingManualInstance& getNext();
    int getSize() const;
    const Linux_DnsManagedSystemElementForSettingManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsManagedSystemElementForSettingManualInstance& anInstance);

  };

}

#endif
