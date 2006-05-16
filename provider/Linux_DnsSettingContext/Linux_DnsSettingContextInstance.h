// =======================================================================
// Linux_DnsSettingContextInstance.h
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
#ifndef Linux_DnsSettingContextInstance_h
#define Linux_DnsSettingContextInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingContextInstanceName.h"


namespace genProvider {

  class Linux_DnsSettingContextInstance {
       
    private:
    void init();
    void init(const Linux_DnsSettingContextInstance& anInstance);
    void reset();
       
    Linux_DnsSettingContextInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsSettingContextInstance();
    Linux_DnsSettingContextInstance(
      const Linux_DnsSettingContextInstance& anInstance);
    Linux_DnsSettingContextInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsSettingContextInstance();
       
    Linux_DnsSettingContextInstance& operator=(
      const Linux_DnsSettingContextInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsSettingContextInstanceName& anInstanceName);        
    const Linux_DnsSettingContextInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsSettingContextInstanceEnumerationElement {

    Linux_DnsSettingContextInstance* m_elementP;
    Linux_DnsSettingContextInstanceEnumerationElement* m_nextP;

    Linux_DnsSettingContextInstanceEnumerationElement();
    ~Linux_DnsSettingContextInstanceEnumerationElement();  

  };
  

  class Linux_DnsSettingContextInstanceEnumeration {

    private:
    Linux_DnsSettingContextInstanceEnumerationElement* m_firstElementP;
    Linux_DnsSettingContextInstanceEnumerationElement* m_currentElementP;
    Linux_DnsSettingContextInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsSettingContextInstanceEnumeration();
    Linux_DnsSettingContextInstanceEnumeration(
      const Linux_DnsSettingContextInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsSettingContextInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsSettingContextInstance& getNext();
    int getSize() const;
    const Linux_DnsSettingContextInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsSettingContextInstance& anInstance);

  };

}

#endif
