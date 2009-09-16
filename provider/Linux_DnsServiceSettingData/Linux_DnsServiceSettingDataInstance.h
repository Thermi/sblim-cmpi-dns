// =======================================================================
// Linux_DnsServiceSettingDataInstance.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsServiceSettingDataInstance_h
#define Linux_DnsServiceSettingDataInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceSettingDataInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceSettingDataInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceSettingDataInstance& anInstance);
    void reset();
       
    Linux_DnsServiceSettingDataInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_ConfigurationDirectory;
    const char* m_Description;
    const char* m_ElementName;
    CMPIUint8 m_Forward;
    CMPIUint8 m_XferFormat;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int ConfigurationDirectory:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int Forward:1;
      unsigned int XferFormat:1;

    } isSet;
    
    public:
    Linux_DnsServiceSettingDataInstance();
    Linux_DnsServiceSettingDataInstance(
      const Linux_DnsServiceSettingDataInstance& anInstance);
    Linux_DnsServiceSettingDataInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceSettingDataInstance();
       
    Linux_DnsServiceSettingDataInstance& operator=(
      const Linux_DnsServiceSettingDataInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceSettingDataInstanceName& anInstanceName);        
    const Linux_DnsServiceSettingDataInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isConfigurationDirectorySet() const;
    void setConfigurationDirectory(const char* aValue, int aCopyFlag = 1);
    const char* getConfigurationDirectory() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isForwardSet() const;
    void setForward(const CMPIUint8 aValue);
    const CMPIUint8 getForward() const;

    unsigned int isXferFormatSet() const;
    void setXferFormat(const CMPIUint8 aValue);
    const CMPIUint8 getXferFormat() const;


  };
  
  struct Linux_DnsServiceSettingDataInstanceEnumerationElement {

    Linux_DnsServiceSettingDataInstance* m_elementP;
    Linux_DnsServiceSettingDataInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceSettingDataInstanceEnumerationElement();
    ~Linux_DnsServiceSettingDataInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceSettingDataInstanceEnumeration {

    private:
    Linux_DnsServiceSettingDataInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceSettingDataInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceSettingDataInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceSettingDataInstanceEnumeration();
    Linux_DnsServiceSettingDataInstanceEnumeration(
      const Linux_DnsServiceSettingDataInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceSettingDataInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceSettingDataInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceSettingDataInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceSettingDataInstance& anInstance);

  };

}

#endif
