// =======================================================================
// Linux_DnsMastersRepositoryInstance.h
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
#ifndef Linux_DnsMastersRepositoryInstance_h
#define Linux_DnsMastersRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsMastersInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersRepositoryInstance();
    Linux_DnsMastersRepositoryInstance(
      const Linux_DnsMastersRepositoryInstance& anInstance);
    Linux_DnsMastersRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersRepositoryInstance();
       
    Linux_DnsMastersRepositoryInstance& operator=(
      const Linux_DnsMastersRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersInstanceName& anInstanceName);        
    const Linux_DnsMastersInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersRepositoryInstanceEnumerationElement {

    Linux_DnsMastersRepositoryInstance* m_elementP;
    Linux_DnsMastersRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersRepositoryInstanceEnumerationElement();
    ~Linux_DnsMastersRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersRepositoryInstanceEnumeration {

    private:
    Linux_DnsMastersRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersRepositoryInstanceEnumeration();
    Linux_DnsMastersRepositoryInstanceEnumeration(
      const Linux_DnsMastersRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersRepositoryInstance& anInstance);

  };

}

#endif
