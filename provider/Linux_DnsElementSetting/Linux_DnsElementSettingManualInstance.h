// =======================================================================
// Linux_DnsElementSettingManualInstance.h
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
#ifndef Linux_DnsElementSettingManualInstance_h
#define Linux_DnsElementSettingManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsElementSettingInstanceName.h"


namespace genProvider {

  class Linux_DnsElementSettingManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsElementSettingManualInstance& anInstance);
    void reset();
       
    Linux_DnsElementSettingInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsElementSettingManualInstance();
    Linux_DnsElementSettingManualInstance(
      const Linux_DnsElementSettingManualInstance& anInstance);
    Linux_DnsElementSettingManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsElementSettingManualInstance();
       
    Linux_DnsElementSettingManualInstance& operator=(
      const Linux_DnsElementSettingManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsElementSettingInstanceName& anInstanceName);        
    const Linux_DnsElementSettingInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsElementSettingManualInstanceEnumerationElement {

    Linux_DnsElementSettingManualInstance* m_elementP;
    Linux_DnsElementSettingManualInstanceEnumerationElement* m_nextP;

    Linux_DnsElementSettingManualInstanceEnumerationElement();
    ~Linux_DnsElementSettingManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsElementSettingManualInstanceEnumeration {

    private:
    Linux_DnsElementSettingManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsElementSettingManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsElementSettingManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsElementSettingManualInstanceEnumeration();
    Linux_DnsElementSettingManualInstanceEnumeration(
      const Linux_DnsElementSettingManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsElementSettingManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsElementSettingManualInstance& getNext();
    int getSize() const;
    const Linux_DnsElementSettingManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsElementSettingManualInstance& anInstance);

  };

}

#endif
