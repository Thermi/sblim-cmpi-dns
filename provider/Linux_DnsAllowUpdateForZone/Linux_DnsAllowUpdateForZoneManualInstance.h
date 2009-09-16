// =======================================================================
// Linux_DnsAllowUpdateForZoneManualInstance.h
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
#ifndef Linux_DnsAllowUpdateForZoneManualInstance_h
#define Linux_DnsAllowUpdateForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowUpdateForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowUpdateForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowUpdateForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowUpdateForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowUpdateForZoneManualInstance();
    Linux_DnsAllowUpdateForZoneManualInstance(
      const Linux_DnsAllowUpdateForZoneManualInstance& anInstance);
    Linux_DnsAllowUpdateForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowUpdateForZoneManualInstance();
       
    Linux_DnsAllowUpdateForZoneManualInstance& operator=(
      const Linux_DnsAllowUpdateForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowUpdateForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowUpdateForZoneManualInstanceEnumerationElement {

    Linux_DnsAllowUpdateForZoneManualInstance* m_elementP;
    Linux_DnsAllowUpdateForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowUpdateForZoneManualInstanceEnumerationElement();
    ~Linux_DnsAllowUpdateForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowUpdateForZoneManualInstanceEnumeration {

    private:
    Linux_DnsAllowUpdateForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowUpdateForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowUpdateForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowUpdateForZoneManualInstanceEnumeration();
    Linux_DnsAllowUpdateForZoneManualInstanceEnumeration(
      const Linux_DnsAllowUpdateForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowUpdateForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowUpdateForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowUpdateForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowUpdateForZoneManualInstance& anInstance);

  };

}

#endif
