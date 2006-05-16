// =======================================================================
// Linux_DnsIPAddressManualInstance.h
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
#ifndef Linux_DnsIPAddressManualInstance_h
#define Linux_DnsIPAddressManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsIPAddressInstanceName.h"


namespace genProvider {

  class Linux_DnsIPAddressManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsIPAddressManualInstance& anInstance);
    void reset();
       
    Linux_DnsIPAddressInstanceName m_instanceName;
    CMPIUint32 m_Port;
    const char* m_SecurityKey;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Port:1;
      unsigned int SecurityKey:1;

    } isSet;
    
    public:
    Linux_DnsIPAddressManualInstance();
    Linux_DnsIPAddressManualInstance(
      const Linux_DnsIPAddressManualInstance& anInstance);
    Linux_DnsIPAddressManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsIPAddressManualInstance();
       
    Linux_DnsIPAddressManualInstance& operator=(
      const Linux_DnsIPAddressManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsIPAddressInstanceName& anInstanceName);        
    const Linux_DnsIPAddressInstanceName& getInstanceName() const;

    unsigned int isPortSet() const;
    void setPort(const CMPIUint32 aValue);
    const CMPIUint32 getPort() const;

    unsigned int isSecurityKeySet() const;
    void setSecurityKey(const char* aValue, int aCopyFlag = 1);
    const char* getSecurityKey() const;


  };
  
  struct Linux_DnsIPAddressManualInstanceEnumerationElement {

    Linux_DnsIPAddressManualInstance* m_elementP;
    Linux_DnsIPAddressManualInstanceEnumerationElement* m_nextP;

    Linux_DnsIPAddressManualInstanceEnumerationElement();
    ~Linux_DnsIPAddressManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsIPAddressManualInstanceEnumeration {

    private:
    Linux_DnsIPAddressManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsIPAddressManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsIPAddressManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsIPAddressManualInstanceEnumeration();
    Linux_DnsIPAddressManualInstanceEnumeration(
      const Linux_DnsIPAddressManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsIPAddressManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsIPAddressManualInstance& getNext();
    int getSize() const;
    const Linux_DnsIPAddressManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsIPAddressManualInstance& anInstance);

  };

}

#endif
