// =======================================================================
// Linux_DnsMasterZoneRepositoryInstance.h
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
