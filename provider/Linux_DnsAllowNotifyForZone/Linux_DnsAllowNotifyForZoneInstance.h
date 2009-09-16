// =======================================================================
// Linux_DnsAllowNotifyForZoneInstance.h
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
#ifndef Linux_DnsAllowNotifyForZoneInstance_h
#define Linux_DnsAllowNotifyForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowNotifyForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowNotifyForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsAllowNotifyForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowNotifyForZoneInstance();
    Linux_DnsAllowNotifyForZoneInstance(
      const Linux_DnsAllowNotifyForZoneInstance& anInstance);
    Linux_DnsAllowNotifyForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowNotifyForZoneInstance();
       
    Linux_DnsAllowNotifyForZoneInstance& operator=(
      const Linux_DnsAllowNotifyForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowNotifyForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowNotifyForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowNotifyForZoneInstanceEnumerationElement {

    Linux_DnsAllowNotifyForZoneInstance* m_elementP;
    Linux_DnsAllowNotifyForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowNotifyForZoneInstanceEnumerationElement();
    ~Linux_DnsAllowNotifyForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowNotifyForZoneInstanceEnumeration {

    private:
    Linux_DnsAllowNotifyForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowNotifyForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowNotifyForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowNotifyForZoneInstanceEnumeration();
    Linux_DnsAllowNotifyForZoneInstanceEnumeration(
      const Linux_DnsAllowNotifyForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowNotifyForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowNotifyForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowNotifyForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowNotifyForZoneInstance& anInstance);

  };

}

#endif
