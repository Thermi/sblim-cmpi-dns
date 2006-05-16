// =======================================================================
// Linux_DnsIPAddressInstance.h
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
#ifndef Linux_DnsIPAddressInstance_h
#define Linux_DnsIPAddressInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsIPAddressInstanceName.h"


namespace genProvider {

  class Linux_DnsIPAddressInstance {
       
    private:
    void init();
    void init(const Linux_DnsIPAddressInstance& anInstance);
    void reset();
       
    Linux_DnsIPAddressInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    CMPIUint32 m_Port;
    const char* m_SecurityKey;
    const char* m_SettingID;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int Port:1;
      unsigned int SecurityKey:1;
      unsigned int SettingID:1;

    } isSet;
    
    public:
    Linux_DnsIPAddressInstance();
    Linux_DnsIPAddressInstance(
      const Linux_DnsIPAddressInstance& anInstance);
    Linux_DnsIPAddressInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsIPAddressInstance();
       
    Linux_DnsIPAddressInstance& operator=(
      const Linux_DnsIPAddressInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsIPAddressInstanceName& anInstanceName);        
    const Linux_DnsIPAddressInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isPortSet() const;
    void setPort(const CMPIUint32 aValue);
    const CMPIUint32 getPort() const;

    unsigned int isSecurityKeySet() const;
    void setSecurityKey(const char* aValue, int aCopyFlag = 1);
    const char* getSecurityKey() const;

    unsigned int isSettingIDSet() const;
    void setSettingID(const char* aValue, int aCopyFlag = 1);
    const char* getSettingID() const;


  };
  
  struct Linux_DnsIPAddressInstanceEnumerationElement {

    Linux_DnsIPAddressInstance* m_elementP;
    Linux_DnsIPAddressInstanceEnumerationElement* m_nextP;

    Linux_DnsIPAddressInstanceEnumerationElement();
    ~Linux_DnsIPAddressInstanceEnumerationElement();  

  };
  

  class Linux_DnsIPAddressInstanceEnumeration {

    private:
    Linux_DnsIPAddressInstanceEnumerationElement* m_firstElementP;
    Linux_DnsIPAddressInstanceEnumerationElement* m_currentElementP;
    Linux_DnsIPAddressInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsIPAddressInstanceEnumeration();
    Linux_DnsIPAddressInstanceEnumeration(
      const Linux_DnsIPAddressInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsIPAddressInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsIPAddressInstance& getNext();
    int getSize() const;
    const Linux_DnsIPAddressInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsIPAddressInstance& anInstance);

  };

}

#endif
