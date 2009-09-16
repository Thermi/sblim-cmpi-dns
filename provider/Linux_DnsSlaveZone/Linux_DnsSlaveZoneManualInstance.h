// =======================================================================
// Linux_DnsSlaveZoneManualInstance.h
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
#ifndef Linux_DnsSlaveZoneManualInstance_h
#define Linux_DnsSlaveZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSlaveZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsSlaveZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsSlaveZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsSlaveZoneInstanceName m_instanceName;
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
    Linux_DnsSlaveZoneManualInstance();
    Linux_DnsSlaveZoneManualInstance(
      const Linux_DnsSlaveZoneManualInstance& anInstance);
    Linux_DnsSlaveZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsSlaveZoneManualInstance();
       
    Linux_DnsSlaveZoneManualInstance& operator=(
      const Linux_DnsSlaveZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsSlaveZoneInstanceName& anInstanceName);        
    const Linux_DnsSlaveZoneInstanceName& getInstanceName() const;

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
  
  struct Linux_DnsSlaveZoneManualInstanceEnumerationElement {

    Linux_DnsSlaveZoneManualInstance* m_elementP;
    Linux_DnsSlaveZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsSlaveZoneManualInstanceEnumerationElement();
    ~Linux_DnsSlaveZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsSlaveZoneManualInstanceEnumeration {

    private:
    Linux_DnsSlaveZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsSlaveZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsSlaveZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsSlaveZoneManualInstanceEnumeration();
    Linux_DnsSlaveZoneManualInstanceEnumeration(
      const Linux_DnsSlaveZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsSlaveZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsSlaveZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsSlaveZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsSlaveZoneManualInstance& anInstance);

  };

}

#endif
