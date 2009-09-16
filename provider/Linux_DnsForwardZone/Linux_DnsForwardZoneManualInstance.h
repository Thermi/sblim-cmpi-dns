// =======================================================================
// Linux_DnsForwardZoneManualInstance.h
//     created on Wed, 29 Nov 2006 using ECUTE 2.2
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
#ifndef Linux_DnsForwardZoneManualInstance_h
#define Linux_DnsForwardZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsForwardZoneInstanceName m_instanceName;
    CMPIUint8 m_Forward;
    CMPIUint8 m_Type;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Forward:1;
      unsigned int Type:1;

    } isSet;
    
    public:
    Linux_DnsForwardZoneManualInstance();
    Linux_DnsForwardZoneManualInstance(
      const Linux_DnsForwardZoneManualInstance& anInstance);
    Linux_DnsForwardZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardZoneManualInstance();
       
    Linux_DnsForwardZoneManualInstance& operator=(
      const Linux_DnsForwardZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardZoneInstanceName& anInstanceName);        
    const Linux_DnsForwardZoneInstanceName& getInstanceName() const;

    unsigned int isForwardSet() const;
    void setForward(const CMPIUint8 aValue);
    const CMPIUint8 getForward() const;

    unsigned int isTypeSet() const;
    void setType(const CMPIUint8 aValue);
    const CMPIUint8 getType() const;


  };
  
  struct Linux_DnsForwardZoneManualInstanceEnumerationElement {

    Linux_DnsForwardZoneManualInstance* m_elementP;
    Linux_DnsForwardZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardZoneManualInstanceEnumerationElement();
    ~Linux_DnsForwardZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardZoneManualInstanceEnumeration {

    private:
    Linux_DnsForwardZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardZoneManualInstanceEnumeration();
    Linux_DnsForwardZoneManualInstanceEnumeration(
      const Linux_DnsForwardZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardZoneManualInstance& anInstance);

  };

}

#endif
