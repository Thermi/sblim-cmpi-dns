// =======================================================================
// Linux_DnsMastersForZoneInstance.h
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
#ifndef Linux_DnsMastersForZoneInstance_h
#define Linux_DnsMastersForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsMastersForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersForZoneInstance();
    Linux_DnsMastersForZoneInstance(
      const Linux_DnsMastersForZoneInstance& anInstance);
    Linux_DnsMastersForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersForZoneInstance();
       
    Linux_DnsMastersForZoneInstance& operator=(
      const Linux_DnsMastersForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersForZoneInstanceName& anInstanceName);        
    const Linux_DnsMastersForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersForZoneInstanceEnumerationElement {

    Linux_DnsMastersForZoneInstance* m_elementP;
    Linux_DnsMastersForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersForZoneInstanceEnumerationElement();
    ~Linux_DnsMastersForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersForZoneInstanceEnumeration {

    private:
    Linux_DnsMastersForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersForZoneInstanceEnumeration();
    Linux_DnsMastersForZoneInstanceEnumeration(
      const Linux_DnsMastersForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersForZoneInstance& anInstance);

  };

}

#endif
