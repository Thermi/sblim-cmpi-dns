// =======================================================================
// Linux_DnsMastersForServiceRepositoryInstance.h
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
#ifndef Linux_DnsMastersForServiceRepositoryInstance_h
#define Linux_DnsMastersForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsMastersForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersForServiceRepositoryInstance();
    Linux_DnsMastersForServiceRepositoryInstance(
      const Linux_DnsMastersForServiceRepositoryInstance& anInstance);
    Linux_DnsMastersForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersForServiceRepositoryInstance();
       
    Linux_DnsMastersForServiceRepositoryInstance& operator=(
      const Linux_DnsMastersForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersForServiceInstanceName& anInstanceName);        
    const Linux_DnsMastersForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsMastersForServiceRepositoryInstance* m_elementP;
    Linux_DnsMastersForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsMastersForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsMastersForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersForServiceRepositoryInstanceEnumeration();
    Linux_DnsMastersForServiceRepositoryInstanceEnumeration(
      const Linux_DnsMastersForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersForServiceRepositoryInstance& anInstance);

  };

}

#endif
