// =======================================================================
// Linux_DnsMastersForServiceManualInstance.h
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
#ifndef Linux_DnsMastersForServiceManualInstance_h
#define Linux_DnsMastersForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsMastersForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersForServiceManualInstance();
    Linux_DnsMastersForServiceManualInstance(
      const Linux_DnsMastersForServiceManualInstance& anInstance);
    Linux_DnsMastersForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersForServiceManualInstance();
       
    Linux_DnsMastersForServiceManualInstance& operator=(
      const Linux_DnsMastersForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersForServiceInstanceName& anInstanceName);        
    const Linux_DnsMastersForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersForServiceManualInstanceEnumerationElement {

    Linux_DnsMastersForServiceManualInstance* m_elementP;
    Linux_DnsMastersForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersForServiceManualInstanceEnumerationElement();
    ~Linux_DnsMastersForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersForServiceManualInstanceEnumeration {

    private:
    Linux_DnsMastersForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersForServiceManualInstanceEnumeration();
    Linux_DnsMastersForServiceManualInstanceEnumeration(
      const Linux_DnsMastersForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersForServiceManualInstance& anInstance);

  };

}

#endif
