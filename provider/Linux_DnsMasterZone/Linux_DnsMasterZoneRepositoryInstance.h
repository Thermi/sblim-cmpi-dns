// =======================================================================
// Linux_DnsMasterZoneRepositoryInstance.h
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
#ifndef Linux_DnsMasterZoneRepositoryInstance_h
#define Linux_DnsMasterZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMasterZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMasterZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsMasterZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsMasterZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMasterZoneRepositoryInstance();
    Linux_DnsMasterZoneRepositoryInstance(
      const Linux_DnsMasterZoneRepositoryInstance& anInstance);
    Linux_DnsMasterZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMasterZoneRepositoryInstance();
       
    Linux_DnsMasterZoneRepositoryInstance& operator=(
      const Linux_DnsMasterZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMasterZoneInstanceName& anInstanceName);        
    const Linux_DnsMasterZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMasterZoneRepositoryInstanceEnumerationElement {

    Linux_DnsMasterZoneRepositoryInstance* m_elementP;
    Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsMasterZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsMasterZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsMasterZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMasterZoneRepositoryInstanceEnumeration();
    Linux_DnsMasterZoneRepositoryInstanceEnumeration(
      const Linux_DnsMasterZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMasterZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMasterZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsMasterZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMasterZoneRepositoryInstance& anInstance);

  };

}

#endif
