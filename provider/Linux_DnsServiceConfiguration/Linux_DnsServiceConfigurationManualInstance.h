// =======================================================================
// Linux_DnsServiceConfigurationManualInstance.h
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
#ifndef Linux_DnsServiceConfigurationManualInstance_h
#define Linux_DnsServiceConfigurationManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationManualInstance& anInstance);
    void reset();
       
    Linux_DnsServiceConfigurationInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceConfigurationManualInstance();
    Linux_DnsServiceConfigurationManualInstance(
      const Linux_DnsServiceConfigurationManualInstance& anInstance);
    Linux_DnsServiceConfigurationManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceConfigurationManualInstance();
       
    Linux_DnsServiceConfigurationManualInstance& operator=(
      const Linux_DnsServiceConfigurationManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);        
    const Linux_DnsServiceConfigurationInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceConfigurationManualInstanceEnumerationElement {

    Linux_DnsServiceConfigurationManualInstance* m_elementP;
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceConfigurationManualInstanceEnumerationElement();
    ~Linux_DnsServiceConfigurationManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceConfigurationManualInstanceEnumeration {

    private:
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceConfigurationManualInstanceEnumeration();
    Linux_DnsServiceConfigurationManualInstanceEnumeration(
      const Linux_DnsServiceConfigurationManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceConfigurationManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceConfigurationManualInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceConfigurationManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceConfigurationManualInstance& anInstance);

  };

}

#endif
