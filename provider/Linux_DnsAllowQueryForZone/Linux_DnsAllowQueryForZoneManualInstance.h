// =======================================================================
// Linux_DnsAllowQueryForZoneManualInstance.h
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
#ifndef Linux_DnsAllowQueryForZoneManualInstance_h
#define Linux_DnsAllowQueryForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowQueryForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowQueryForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowQueryForZoneManualInstance();
    Linux_DnsAllowQueryForZoneManualInstance(
      const Linux_DnsAllowQueryForZoneManualInstance& anInstance);
    Linux_DnsAllowQueryForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowQueryForZoneManualInstance();
       
    Linux_DnsAllowQueryForZoneManualInstance& operator=(
      const Linux_DnsAllowQueryForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowQueryForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowQueryForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowQueryForZoneManualInstanceEnumerationElement {

    Linux_DnsAllowQueryForZoneManualInstance* m_elementP;
    Linux_DnsAllowQueryForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowQueryForZoneManualInstanceEnumerationElement();
    ~Linux_DnsAllowQueryForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowQueryForZoneManualInstanceEnumeration {

    private:
    Linux_DnsAllowQueryForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowQueryForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowQueryForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowQueryForZoneManualInstanceEnumeration();
    Linux_DnsAllowQueryForZoneManualInstanceEnumeration(
      const Linux_DnsAllowQueryForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowQueryForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowQueryForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowQueryForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowQueryForZoneManualInstance& anInstance);

  };

}

#endif
