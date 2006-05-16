// =======================================================================
// Linux_DnsSlaveZoneRepositoryInstance.h
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
#ifndef Linux_DnsSlaveZoneRepositoryInstance_h
#define Linux_DnsSlaveZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSlaveZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsSlaveZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsSlaveZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsSlaveZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsSlaveZoneRepositoryInstance();
    Linux_DnsSlaveZoneRepositoryInstance(
      const Linux_DnsSlaveZoneRepositoryInstance& anInstance);
    Linux_DnsSlaveZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsSlaveZoneRepositoryInstance();
       
    Linux_DnsSlaveZoneRepositoryInstance& operator=(
      const Linux_DnsSlaveZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsSlaveZoneInstanceName& anInstanceName);        
    const Linux_DnsSlaveZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement {

    Linux_DnsSlaveZoneRepositoryInstance* m_elementP;
    Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsSlaveZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsSlaveZoneRepositoryInstanceEnumeration();
    Linux_DnsSlaveZoneRepositoryInstanceEnumeration(
      const Linux_DnsSlaveZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsSlaveZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsSlaveZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsSlaveZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsSlaveZoneRepositoryInstance& anInstance);

  };

}

#endif
