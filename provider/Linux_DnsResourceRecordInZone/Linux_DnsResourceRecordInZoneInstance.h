// =======================================================================
// Linux_DnsResourceRecordInZoneInstance.h
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
#ifndef Linux_DnsResourceRecordInZoneInstance_h
#define Linux_DnsResourceRecordInZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordInZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordInZoneInstance& anInstance);
    void reset();
       
    Linux_DnsResourceRecordInZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsResourceRecordInZoneInstance();
    Linux_DnsResourceRecordInZoneInstance(
      const Linux_DnsResourceRecordInZoneInstance& anInstance);
    Linux_DnsResourceRecordInZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsResourceRecordInZoneInstance();
       
    Linux_DnsResourceRecordInZoneInstance& operator=(
      const Linux_DnsResourceRecordInZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);        
    const Linux_DnsResourceRecordInZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsResourceRecordInZoneInstanceEnumerationElement {

    Linux_DnsResourceRecordInZoneInstance* m_elementP;
    Linux_DnsResourceRecordInZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsResourceRecordInZoneInstanceEnumerationElement();
    ~Linux_DnsResourceRecordInZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsResourceRecordInZoneInstanceEnumeration {

    private:
    Linux_DnsResourceRecordInZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsResourceRecordInZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsResourceRecordInZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsResourceRecordInZoneInstanceEnumeration();
    Linux_DnsResourceRecordInZoneInstanceEnumeration(
      const Linux_DnsResourceRecordInZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsResourceRecordInZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsResourceRecordInZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsResourceRecordInZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsResourceRecordInZoneInstance& anInstance);

  };

}

#endif
