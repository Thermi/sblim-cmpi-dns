// =======================================================================
// Linux_DnsConfigurationInstance.h
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
#ifndef Linux_DnsConfigurationInstance_h
#define Linux_DnsConfigurationInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsConfigurationInstance {
       
    private:
    void init();
    void init(const Linux_DnsConfigurationInstance& anInstance);
    void reset();
       
    Linux_DnsConfigurationInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_ConfigurationFile;
    const char* m_Description;
    const char* m_ElementName;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int ConfigurationFile:1;
      unsigned int Description:1;
      unsigned int ElementName:1;

    } isSet;
    
    public:
    Linux_DnsConfigurationInstance();
    Linux_DnsConfigurationInstance(
      const Linux_DnsConfigurationInstance& anInstance);
    Linux_DnsConfigurationInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsConfigurationInstance();
       
    Linux_DnsConfigurationInstance& operator=(
      const Linux_DnsConfigurationInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsConfigurationInstanceName& anInstanceName);        
    const Linux_DnsConfigurationInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isConfigurationFileSet() const;
    void setConfigurationFile(const char* aValue, int aCopyFlag = 1);
    const char* getConfigurationFile() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;


  };
  
  struct Linux_DnsConfigurationInstanceEnumerationElement {

    Linux_DnsConfigurationInstance* m_elementP;
    Linux_DnsConfigurationInstanceEnumerationElement* m_nextP;

    Linux_DnsConfigurationInstanceEnumerationElement();
    ~Linux_DnsConfigurationInstanceEnumerationElement();  

  };
  

  class Linux_DnsConfigurationInstanceEnumeration {

    private:
    Linux_DnsConfigurationInstanceEnumerationElement* m_firstElementP;
    Linux_DnsConfigurationInstanceEnumerationElement* m_currentElementP;
    Linux_DnsConfigurationInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsConfigurationInstanceEnumeration();
    Linux_DnsConfigurationInstanceEnumeration(
      const Linux_DnsConfigurationInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsConfigurationInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsConfigurationInstance& getNext();
    int getSize() const;
    const Linux_DnsConfigurationInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsConfigurationInstance& anInstance);

  };

}

#endif
