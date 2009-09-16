// =======================================================================
// Linux_DnsForwardersForZoneInstance.h
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
#ifndef Linux_DnsForwardersForZoneInstance_h
#define Linux_DnsForwardersForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardersForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardersForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsForwardersForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsForwardersForZoneInstance();
    Linux_DnsForwardersForZoneInstance(
      const Linux_DnsForwardersForZoneInstance& anInstance);
    Linux_DnsForwardersForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardersForZoneInstance();
       
    Linux_DnsForwardersForZoneInstance& operator=(
      const Linux_DnsForwardersForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardersForZoneInstanceName& anInstanceName);        
    const Linux_DnsForwardersForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsForwardersForZoneInstanceEnumerationElement {

    Linux_DnsForwardersForZoneInstance* m_elementP;
    Linux_DnsForwardersForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardersForZoneInstanceEnumerationElement();
    ~Linux_DnsForwardersForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardersForZoneInstanceEnumeration {

    private:
    Linux_DnsForwardersForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardersForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardersForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardersForZoneInstanceEnumeration();
    Linux_DnsForwardersForZoneInstanceEnumeration(
      const Linux_DnsForwardersForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardersForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardersForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardersForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardersForZoneInstance& anInstance);

  };

}

#endif
