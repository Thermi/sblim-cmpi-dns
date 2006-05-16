// =======================================================================
// Linux_DnsSettingManualInstance.h
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
#ifndef Linux_DnsSettingManualInstance_h
#define Linux_DnsSettingManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingInstanceName.h"


namespace genProvider {

  class Linux_DnsSettingManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsSettingManualInstance& anInstance);
    void reset();
       
    Linux_DnsSettingInstanceName m_instanceName;
    const char* m_ConfigurationDirectory;
    CMPIUint16 m_Forward;
    const char** m_Forwarders;
    unsigned int m_ForwardersSize;
    CMPIUint32 m_PortNumber;
    CMPIUint16 m_TSIG;
    CMPIUint32 m_TTL;
    CMPIUint16 m_XferFormat;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int ConfigurationDirectory:1;
      unsigned int Forward:1;
      unsigned int Forwarders:1;
      unsigned int PortNumber:1;
      unsigned int TSIG:1;
      unsigned int TTL:1;
      unsigned int XferFormat:1;

    } isSet;
    
    public:
    Linux_DnsSettingManualInstance();
    Linux_DnsSettingManualInstance(
      const Linux_DnsSettingManualInstance& anInstance);
    Linux_DnsSettingManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsSettingManualInstance();
       
    Linux_DnsSettingManualInstance& operator=(
      const Linux_DnsSettingManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsSettingInstanceName& anInstanceName);        
    const Linux_DnsSettingInstanceName& getInstanceName() const;

    unsigned int isConfigurationDirectorySet() const;
    void setConfigurationDirectory(const char* aValue, int aCopyFlag = 1);
    const char* getConfigurationDirectory() const;

    unsigned int isForwardSet() const;
    void setForward(const CMPIUint16 aValue);
    const CMPIUint16 getForward() const;

    unsigned int isForwardersSet() const;
    void setForwarders(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getForwarders(unsigned int& aSize) const;

    unsigned int isPortNumberSet() const;
    void setPortNumber(const CMPIUint32 aValue);
    const CMPIUint32 getPortNumber() const;

    unsigned int isTSIGSet() const;
    void setTSIG(const CMPIUint16 aValue);
    const CMPIUint16 getTSIG() const;

    unsigned int isTTLSet() const;
    void setTTL(const CMPIUint32 aValue);
    const CMPIUint32 getTTL() const;

    unsigned int isXferFormatSet() const;
    void setXferFormat(const CMPIUint16 aValue);
    const CMPIUint16 getXferFormat() const;


  };
  
  struct Linux_DnsSettingManualInstanceEnumerationElement {

    Linux_DnsSettingManualInstance* m_elementP;
    Linux_DnsSettingManualInstanceEnumerationElement* m_nextP;

    Linux_DnsSettingManualInstanceEnumerationElement();
    ~Linux_DnsSettingManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsSettingManualInstanceEnumeration {

    private:
    Linux_DnsSettingManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsSettingManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsSettingManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsSettingManualInstanceEnumeration();
    Linux_DnsSettingManualInstanceEnumeration(
      const Linux_DnsSettingManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsSettingManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsSettingManualInstance& getNext();
    int getSize() const;
    const Linux_DnsSettingManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsSettingManualInstance& anInstance);

  };

}

#endif
