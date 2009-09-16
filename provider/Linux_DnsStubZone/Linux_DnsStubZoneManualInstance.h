// =======================================================================
// Linux_DnsStubZoneManualInstance.h
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
#ifndef Linux_DnsStubZoneManualInstance_h
#define Linux_DnsStubZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsStubZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsStubZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsStubZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsStubZoneInstanceName m_instanceName;
    CMPIUint8 m_Forward;
    CMPISint32 m_TTL;
    CMPIUint8 m_Type;
    const char* m_ZoneFile;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Forward:1;
      unsigned int TTL:1;
      unsigned int Type:1;
      unsigned int ZoneFile:1;

    } isSet;
    
    public:
    Linux_DnsStubZoneManualInstance();
    Linux_DnsStubZoneManualInstance(
      const Linux_DnsStubZoneManualInstance& anInstance);
    Linux_DnsStubZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsStubZoneManualInstance();
       
    Linux_DnsStubZoneManualInstance& operator=(
      const Linux_DnsStubZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsStubZoneInstanceName& anInstanceName);        
    const Linux_DnsStubZoneInstanceName& getInstanceName() const;

    unsigned int isForwardSet() const;
    void setForward(const CMPIUint8 aValue);
    const CMPIUint8 getForward() const;

    unsigned int isTTLSet() const;
    void setTTL(const CMPISint32 aValue);
    const CMPISint32 getTTL() const;

    unsigned int isTypeSet() const;
    void setType(const CMPIUint8 aValue);
    const CMPIUint8 getType() const;

    unsigned int isZoneFileSet() const;
    void setZoneFile(const char* aValue, int aCopyFlag = 1);
    const char* getZoneFile() const;


  };
  
  struct Linux_DnsStubZoneManualInstanceEnumerationElement {

    Linux_DnsStubZoneManualInstance* m_elementP;
    Linux_DnsStubZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsStubZoneManualInstanceEnumerationElement();
    ~Linux_DnsStubZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsStubZoneManualInstanceEnumeration {

    private:
    Linux_DnsStubZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsStubZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsStubZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsStubZoneManualInstanceEnumeration();
    Linux_DnsStubZoneManualInstanceEnumeration(
      const Linux_DnsStubZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsStubZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsStubZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsStubZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsStubZoneManualInstance& anInstance);

  };

}

#endif
