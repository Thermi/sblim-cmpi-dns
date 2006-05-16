// =======================================================================
// Linux_DnsConfigurationManualInstance.h
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
#ifndef Linux_DnsConfigurationManualInstance_h
#define Linux_DnsConfigurationManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsConfigurationManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsConfigurationManualInstance& anInstance);
    void reset();
       
    Linux_DnsConfigurationInstanceName m_instanceName;
    const char* m_ConfigurationFile;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int ConfigurationFile:1;

    } isSet;
    
    public:
    Linux_DnsConfigurationManualInstance();
    Linux_DnsConfigurationManualInstance(
      const Linux_DnsConfigurationManualInstance& anInstance);
    Linux_DnsConfigurationManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsConfigurationManualInstance();
       
    Linux_DnsConfigurationManualInstance& operator=(
      const Linux_DnsConfigurationManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsConfigurationInstanceName& anInstanceName);        
    const Linux_DnsConfigurationInstanceName& getInstanceName() const;

    unsigned int isConfigurationFileSet() const;
    void setConfigurationFile(const char* aValue, int aCopyFlag = 1);
    const char* getConfigurationFile() const;


  };
  
  struct Linux_DnsConfigurationManualInstanceEnumerationElement {

    Linux_DnsConfigurationManualInstance* m_elementP;
    Linux_DnsConfigurationManualInstanceEnumerationElement* m_nextP;

    Linux_DnsConfigurationManualInstanceEnumerationElement();
    ~Linux_DnsConfigurationManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsConfigurationManualInstanceEnumeration {

    private:
    Linux_DnsConfigurationManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsConfigurationManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsConfigurationManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsConfigurationManualInstanceEnumeration();
    Linux_DnsConfigurationManualInstanceEnumeration(
      const Linux_DnsConfigurationManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsConfigurationManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsConfigurationManualInstance& getNext();
    int getSize() const;
    const Linux_DnsConfigurationManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsConfigurationManualInstance& anInstance);

  };

}

#endif
