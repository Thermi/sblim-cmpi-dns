// =======================================================================
// Linux_DnsHintZoneRepositoryInstance.h
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
#ifndef Linux_DnsHintZoneRepositoryInstance_h
#define Linux_DnsHintZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsHintZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsHintZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsHintZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsHintZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsHintZoneRepositoryInstance();
    Linux_DnsHintZoneRepositoryInstance(
      const Linux_DnsHintZoneRepositoryInstance& anInstance);
    Linux_DnsHintZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsHintZoneRepositoryInstance();
       
    Linux_DnsHintZoneRepositoryInstance& operator=(
      const Linux_DnsHintZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsHintZoneInstanceName& anInstanceName);        
    const Linux_DnsHintZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsHintZoneRepositoryInstanceEnumerationElement {

    Linux_DnsHintZoneRepositoryInstance* m_elementP;
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsHintZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsHintZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsHintZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsHintZoneRepositoryInstanceEnumeration();
    Linux_DnsHintZoneRepositoryInstanceEnumeration(
      const Linux_DnsHintZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsHintZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsHintZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsHintZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsHintZoneRepositoryInstance& anInstance);

  };

}

#endif
