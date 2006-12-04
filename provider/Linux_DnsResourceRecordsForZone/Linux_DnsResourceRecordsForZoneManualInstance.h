// =======================================================================
// Linux_DnsResourceRecordsForZoneManualInstance.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
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
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsResourceRecordsForZoneManualInstance_h
#define Linux_DnsResourceRecordsForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordsForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordsForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordsForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsResourceRecordsForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsResourceRecordsForZoneManualInstance();
    Linux_DnsResourceRecordsForZoneManualInstance(
      const Linux_DnsResourceRecordsForZoneManualInstance& anInstance);
    Linux_DnsResourceRecordsForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsResourceRecordsForZoneManualInstance();
       
    Linux_DnsResourceRecordsForZoneManualInstance& operator=(
      const Linux_DnsResourceRecordsForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);        
    const Linux_DnsResourceRecordsForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsResourceRecordsForZoneManualInstanceEnumerationElement {

    Linux_DnsResourceRecordsForZoneManualInstance* m_elementP;
    Linux_DnsResourceRecordsForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsResourceRecordsForZoneManualInstanceEnumerationElement();
    ~Linux_DnsResourceRecordsForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsResourceRecordsForZoneManualInstanceEnumeration {

    private:
    Linux_DnsResourceRecordsForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsResourceRecordsForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsResourceRecordsForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsResourceRecordsForZoneManualInstanceEnumeration();
    Linux_DnsResourceRecordsForZoneManualInstanceEnumeration(
      const Linux_DnsResourceRecordsForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsResourceRecordsForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsResourceRecordsForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsResourceRecordsForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsResourceRecordsForZoneManualInstance& anInstance);

  };

}

#endif
