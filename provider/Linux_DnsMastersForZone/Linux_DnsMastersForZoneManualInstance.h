// =======================================================================
// Linux_DnsMastersForZoneManualInstance.h
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
#ifndef Linux_DnsMastersForZoneManualInstance_h
#define Linux_DnsMastersForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsMastersForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersForZoneManualInstance();
    Linux_DnsMastersForZoneManualInstance(
      const Linux_DnsMastersForZoneManualInstance& anInstance);
    Linux_DnsMastersForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersForZoneManualInstance();
       
    Linux_DnsMastersForZoneManualInstance& operator=(
      const Linux_DnsMastersForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersForZoneInstanceName& anInstanceName);        
    const Linux_DnsMastersForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersForZoneManualInstanceEnumerationElement {

    Linux_DnsMastersForZoneManualInstance* m_elementP;
    Linux_DnsMastersForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersForZoneManualInstanceEnumerationElement();
    ~Linux_DnsMastersForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersForZoneManualInstanceEnumeration {

    private:
    Linux_DnsMastersForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersForZoneManualInstanceEnumeration();
    Linux_DnsMastersForZoneManualInstanceEnumeration(
      const Linux_DnsMastersForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersForZoneManualInstance& anInstance);

  };

}

#endif
