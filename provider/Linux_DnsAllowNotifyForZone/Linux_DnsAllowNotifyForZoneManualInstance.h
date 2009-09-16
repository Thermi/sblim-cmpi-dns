// =======================================================================
// Linux_DnsAllowNotifyForZoneManualInstance.h
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
#ifndef Linux_DnsAllowNotifyForZoneManualInstance_h
#define Linux_DnsAllowNotifyForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowNotifyForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowNotifyForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowNotifyForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowNotifyForZoneManualInstance();
    Linux_DnsAllowNotifyForZoneManualInstance(
      const Linux_DnsAllowNotifyForZoneManualInstance& anInstance);
    Linux_DnsAllowNotifyForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowNotifyForZoneManualInstance();
       
    Linux_DnsAllowNotifyForZoneManualInstance& operator=(
      const Linux_DnsAllowNotifyForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowNotifyForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowNotifyForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowNotifyForZoneManualInstanceEnumerationElement {

    Linux_DnsAllowNotifyForZoneManualInstance* m_elementP;
    Linux_DnsAllowNotifyForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowNotifyForZoneManualInstanceEnumerationElement();
    ~Linux_DnsAllowNotifyForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowNotifyForZoneManualInstanceEnumeration {

    private:
    Linux_DnsAllowNotifyForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowNotifyForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowNotifyForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowNotifyForZoneManualInstanceEnumeration();
    Linux_DnsAllowNotifyForZoneManualInstanceEnumeration(
      const Linux_DnsAllowNotifyForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowNotifyForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowNotifyForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowNotifyForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowNotifyForZoneManualInstance& anInstance);

  };

}

#endif
