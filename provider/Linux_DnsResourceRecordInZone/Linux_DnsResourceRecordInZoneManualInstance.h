// =======================================================================
// Linux_DnsResourceRecordInZoneManualInstance.h
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
#ifndef Linux_DnsResourceRecordInZoneManualInstance_h
#define Linux_DnsResourceRecordInZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordInZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordInZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsResourceRecordInZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsResourceRecordInZoneManualInstance();
    Linux_DnsResourceRecordInZoneManualInstance(
      const Linux_DnsResourceRecordInZoneManualInstance& anInstance);
    Linux_DnsResourceRecordInZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsResourceRecordInZoneManualInstance();
       
    Linux_DnsResourceRecordInZoneManualInstance& operator=(
      const Linux_DnsResourceRecordInZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);        
    const Linux_DnsResourceRecordInZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement {

    Linux_DnsResourceRecordInZoneManualInstance* m_elementP;
    Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement();
    ~Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsResourceRecordInZoneManualInstanceEnumeration {

    private:
    Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsResourceRecordInZoneManualInstanceEnumeration();
    Linux_DnsResourceRecordInZoneManualInstanceEnumeration(
      const Linux_DnsResourceRecordInZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsResourceRecordInZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsResourceRecordInZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsResourceRecordInZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsResourceRecordInZoneManualInstance& anInstance);

  };

}

#endif
