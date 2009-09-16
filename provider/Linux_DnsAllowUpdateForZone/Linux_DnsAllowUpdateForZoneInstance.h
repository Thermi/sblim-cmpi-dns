// =======================================================================
// Linux_DnsAllowUpdateForZoneInstance.h
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
#ifndef Linux_DnsAllowUpdateForZoneInstance_h
#define Linux_DnsAllowUpdateForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowUpdateForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowUpdateForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowUpdateForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsAllowUpdateForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowUpdateForZoneInstance();
    Linux_DnsAllowUpdateForZoneInstance(
      const Linux_DnsAllowUpdateForZoneInstance& anInstance);
    Linux_DnsAllowUpdateForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowUpdateForZoneInstance();
       
    Linux_DnsAllowUpdateForZoneInstance& operator=(
      const Linux_DnsAllowUpdateForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowUpdateForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowUpdateForZoneInstanceEnumerationElement {

    Linux_DnsAllowUpdateForZoneInstance* m_elementP;
    Linux_DnsAllowUpdateForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowUpdateForZoneInstanceEnumerationElement();
    ~Linux_DnsAllowUpdateForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowUpdateForZoneInstanceEnumeration {

    private:
    Linux_DnsAllowUpdateForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowUpdateForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowUpdateForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowUpdateForZoneInstanceEnumeration();
    Linux_DnsAllowUpdateForZoneInstanceEnumeration(
      const Linux_DnsAllowUpdateForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowUpdateForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowUpdateForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowUpdateForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowUpdateForZoneInstance& anInstance);

  };

}

#endif
