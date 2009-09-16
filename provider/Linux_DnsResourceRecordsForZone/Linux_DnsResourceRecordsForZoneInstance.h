// =======================================================================
// Linux_DnsResourceRecordsForZoneInstance.h
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
#ifndef Linux_DnsResourceRecordsForZoneInstance_h
#define Linux_DnsResourceRecordsForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordsForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordsForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordsForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsResourceRecordsForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsResourceRecordsForZoneInstance();
    Linux_DnsResourceRecordsForZoneInstance(
      const Linux_DnsResourceRecordsForZoneInstance& anInstance);
    Linux_DnsResourceRecordsForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsResourceRecordsForZoneInstance();
       
    Linux_DnsResourceRecordsForZoneInstance& operator=(
      const Linux_DnsResourceRecordsForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);        
    const Linux_DnsResourceRecordsForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsResourceRecordsForZoneInstanceEnumerationElement {

    Linux_DnsResourceRecordsForZoneInstance* m_elementP;
    Linux_DnsResourceRecordsForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsResourceRecordsForZoneInstanceEnumerationElement();
    ~Linux_DnsResourceRecordsForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsResourceRecordsForZoneInstanceEnumeration {

    private:
    Linux_DnsResourceRecordsForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsResourceRecordsForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsResourceRecordsForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsResourceRecordsForZoneInstanceEnumeration();
    Linux_DnsResourceRecordsForZoneInstanceEnumeration(
      const Linux_DnsResourceRecordsForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsResourceRecordsForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsResourceRecordsForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsResourceRecordsForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsResourceRecordsForZoneInstance& anInstance);

  };

}

#endif
