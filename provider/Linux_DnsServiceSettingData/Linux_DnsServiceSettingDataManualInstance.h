// =======================================================================
// Linux_DnsServiceSettingDataManualInstance.h
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
#ifndef Linux_DnsServiceSettingDataManualInstance_h
#define Linux_DnsServiceSettingDataManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceSettingDataInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceSettingDataManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceSettingDataManualInstance& anInstance);
    void reset();
       
    Linux_DnsServiceSettingDataInstanceName m_instanceName;
    const char* m_ConfigurationDirectory;
    CMPIUint8 m_Forward;
    CMPIUint8 m_XferFormat;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int ConfigurationDirectory:1;
      unsigned int Forward:1;
      unsigned int XferFormat:1;

    } isSet;
    
    public:
    Linux_DnsServiceSettingDataManualInstance();
    Linux_DnsServiceSettingDataManualInstance(
      const Linux_DnsServiceSettingDataManualInstance& anInstance);
    Linux_DnsServiceSettingDataManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceSettingDataManualInstance();
       
    Linux_DnsServiceSettingDataManualInstance& operator=(
      const Linux_DnsServiceSettingDataManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceSettingDataInstanceName& anInstanceName);        
    const Linux_DnsServiceSettingDataInstanceName& getInstanceName() const;

    unsigned int isConfigurationDirectorySet() const;
    void setConfigurationDirectory(const char* aValue, int aCopyFlag = 1);
    const char* getConfigurationDirectory() const;

    unsigned int isForwardSet() const;
    void setForward(const CMPIUint8 aValue);
    const CMPIUint8 getForward() const;

    unsigned int isXferFormatSet() const;
    void setXferFormat(const CMPIUint8 aValue);
    const CMPIUint8 getXferFormat() const;


  };
  
  struct Linux_DnsServiceSettingDataManualInstanceEnumerationElement {

    Linux_DnsServiceSettingDataManualInstance* m_elementP;
    Linux_DnsServiceSettingDataManualInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceSettingDataManualInstanceEnumerationElement();
    ~Linux_DnsServiceSettingDataManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceSettingDataManualInstanceEnumeration {

    private:
    Linux_DnsServiceSettingDataManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceSettingDataManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceSettingDataManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceSettingDataManualInstanceEnumeration();
    Linux_DnsServiceSettingDataManualInstanceEnumeration(
      const Linux_DnsServiceSettingDataManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceSettingDataManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceSettingDataManualInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceSettingDataManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceSettingDataManualInstance& anInstance);

  };

}

#endif
