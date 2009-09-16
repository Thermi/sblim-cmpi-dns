// =======================================================================
// Linux_DnsAllowQueryForZoneInstance.h
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
#ifndef Linux_DnsAllowQueryForZoneInstance_h
#define Linux_DnsAllowQueryForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowQueryForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsAllowQueryForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowQueryForZoneInstance();
    Linux_DnsAllowQueryForZoneInstance(
      const Linux_DnsAllowQueryForZoneInstance& anInstance);
    Linux_DnsAllowQueryForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowQueryForZoneInstance();
       
    Linux_DnsAllowQueryForZoneInstance& operator=(
      const Linux_DnsAllowQueryForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowQueryForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowQueryForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowQueryForZoneInstanceEnumerationElement {

    Linux_DnsAllowQueryForZoneInstance* m_elementP;
    Linux_DnsAllowQueryForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowQueryForZoneInstanceEnumerationElement();
    ~Linux_DnsAllowQueryForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowQueryForZoneInstanceEnumeration {

    private:
    Linux_DnsAllowQueryForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowQueryForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowQueryForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowQueryForZoneInstanceEnumeration();
    Linux_DnsAllowQueryForZoneInstanceEnumeration(
      const Linux_DnsAllowQueryForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowQueryForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowQueryForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowQueryForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowQueryForZoneInstance& anInstance);

  };

}

#endif
