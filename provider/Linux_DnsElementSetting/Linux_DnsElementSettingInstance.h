// =======================================================================
// Linux_DnsElementSettingInstance.h
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
#ifndef Linux_DnsElementSettingInstance_h
#define Linux_DnsElementSettingInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsElementSettingInstanceName.h"


namespace genProvider {

  class Linux_DnsElementSettingInstance {
       
    private:
    void init();
    void init(const Linux_DnsElementSettingInstance& anInstance);
    void reset();
       
    Linux_DnsElementSettingInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsElementSettingInstance();
    Linux_DnsElementSettingInstance(
      const Linux_DnsElementSettingInstance& anInstance);
    Linux_DnsElementSettingInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsElementSettingInstance();
       
    Linux_DnsElementSettingInstance& operator=(
      const Linux_DnsElementSettingInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsElementSettingInstanceName& anInstanceName);        
    const Linux_DnsElementSettingInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsElementSettingInstanceEnumerationElement {

    Linux_DnsElementSettingInstance* m_elementP;
    Linux_DnsElementSettingInstanceEnumerationElement* m_nextP;

    Linux_DnsElementSettingInstanceEnumerationElement();
    ~Linux_DnsElementSettingInstanceEnumerationElement();  

  };
  

  class Linux_DnsElementSettingInstanceEnumeration {

    private:
    Linux_DnsElementSettingInstanceEnumerationElement* m_firstElementP;
    Linux_DnsElementSettingInstanceEnumerationElement* m_currentElementP;
    Linux_DnsElementSettingInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsElementSettingInstanceEnumeration();
    Linux_DnsElementSettingInstanceEnumeration(
      const Linux_DnsElementSettingInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsElementSettingInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsElementSettingInstance& getNext();
    int getSize() const;
    const Linux_DnsElementSettingInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsElementSettingInstance& anInstance);

  };

}

#endif
