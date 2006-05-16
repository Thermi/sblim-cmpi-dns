// =======================================================================
// Linux_DnsSettingContextManualInstance.h
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
#ifndef Linux_DnsSettingContextManualInstance_h
#define Linux_DnsSettingContextManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingContextInstanceName.h"


namespace genProvider {

  class Linux_DnsSettingContextManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsSettingContextManualInstance& anInstance);
    void reset();
       
    Linux_DnsSettingContextInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsSettingContextManualInstance();
    Linux_DnsSettingContextManualInstance(
      const Linux_DnsSettingContextManualInstance& anInstance);
    Linux_DnsSettingContextManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsSettingContextManualInstance();
       
    Linux_DnsSettingContextManualInstance& operator=(
      const Linux_DnsSettingContextManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsSettingContextInstanceName& anInstanceName);        
    const Linux_DnsSettingContextInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsSettingContextManualInstanceEnumerationElement {

    Linux_DnsSettingContextManualInstance* m_elementP;
    Linux_DnsSettingContextManualInstanceEnumerationElement* m_nextP;

    Linux_DnsSettingContextManualInstanceEnumerationElement();
    ~Linux_DnsSettingContextManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsSettingContextManualInstanceEnumeration {

    private:
    Linux_DnsSettingContextManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsSettingContextManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsSettingContextManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsSettingContextManualInstanceEnumeration();
    Linux_DnsSettingContextManualInstanceEnumeration(
      const Linux_DnsSettingContextManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsSettingContextManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsSettingContextManualInstance& getNext();
    int getSize() const;
    const Linux_DnsSettingContextManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsSettingContextManualInstance& anInstance);

  };

}

#endif
