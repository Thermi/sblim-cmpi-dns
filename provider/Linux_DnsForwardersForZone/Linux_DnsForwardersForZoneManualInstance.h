// =======================================================================
// Linux_DnsForwardersForZoneManualInstance.h
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
#ifndef Linux_DnsForwardersForZoneManualInstance_h
#define Linux_DnsForwardersForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardersForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardersForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsForwardersForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsForwardersForZoneManualInstance();
    Linux_DnsForwardersForZoneManualInstance(
      const Linux_DnsForwardersForZoneManualInstance& anInstance);
    Linux_DnsForwardersForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardersForZoneManualInstance();
       
    Linux_DnsForwardersForZoneManualInstance& operator=(
      const Linux_DnsForwardersForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardersForZoneInstanceName& anInstanceName);        
    const Linux_DnsForwardersForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsForwardersForZoneManualInstanceEnumerationElement {

    Linux_DnsForwardersForZoneManualInstance* m_elementP;
    Linux_DnsForwardersForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardersForZoneManualInstanceEnumerationElement();
    ~Linux_DnsForwardersForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardersForZoneManualInstanceEnumeration {

    private:
    Linux_DnsForwardersForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardersForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardersForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardersForZoneManualInstanceEnumeration();
    Linux_DnsForwardersForZoneManualInstanceEnumeration(
      const Linux_DnsForwardersForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardersForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardersForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardersForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardersForZoneManualInstance& anInstance);

  };

}

#endif
