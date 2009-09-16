// =======================================================================
// Linux_DnsMastersForZoneRepositoryInstance.h
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
#ifndef Linux_DnsMastersForZoneRepositoryInstance_h
#define Linux_DnsMastersForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsMastersForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersForZoneRepositoryInstance();
    Linux_DnsMastersForZoneRepositoryInstance(
      const Linux_DnsMastersForZoneRepositoryInstance& anInstance);
    Linux_DnsMastersForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersForZoneRepositoryInstance();
       
    Linux_DnsMastersForZoneRepositoryInstance& operator=(
      const Linux_DnsMastersForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersForZoneInstanceName& anInstanceName);        
    const Linux_DnsMastersForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsMastersForZoneRepositoryInstance* m_elementP;
    Linux_DnsMastersForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsMastersForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsMastersForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersForZoneRepositoryInstanceEnumeration();
    Linux_DnsMastersForZoneRepositoryInstanceEnumeration(
      const Linux_DnsMastersForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersForZoneRepositoryInstance& anInstance);

  };

}

#endif
