// =======================================================================
// Linux_DnsMastersForServiceInstance.h
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
#ifndef Linux_DnsMastersForServiceInstance_h
#define Linux_DnsMastersForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsMastersForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersForServiceInstance();
    Linux_DnsMastersForServiceInstance(
      const Linux_DnsMastersForServiceInstance& anInstance);
    Linux_DnsMastersForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersForServiceInstance();
       
    Linux_DnsMastersForServiceInstance& operator=(
      const Linux_DnsMastersForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersForServiceInstanceName& anInstanceName);        
    const Linux_DnsMastersForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersForServiceInstanceEnumerationElement {

    Linux_DnsMastersForServiceInstance* m_elementP;
    Linux_DnsMastersForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersForServiceInstanceEnumerationElement();
    ~Linux_DnsMastersForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersForServiceInstanceEnumeration {

    private:
    Linux_DnsMastersForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersForServiceInstanceEnumeration();
    Linux_DnsMastersForServiceInstanceEnumeration(
      const Linux_DnsMastersForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersForServiceInstance& anInstance);

  };

}

#endif
