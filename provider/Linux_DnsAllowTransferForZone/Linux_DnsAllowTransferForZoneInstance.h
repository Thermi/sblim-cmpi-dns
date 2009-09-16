// =======================================================================
// Linux_DnsAllowTransferForZoneInstance.h
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
#ifndef Linux_DnsAllowTransferForZoneInstance_h
#define Linux_DnsAllowTransferForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsAllowTransferForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowTransferForZoneInstance();
    Linux_DnsAllowTransferForZoneInstance(
      const Linux_DnsAllowTransferForZoneInstance& anInstance);
    Linux_DnsAllowTransferForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowTransferForZoneInstance();
       
    Linux_DnsAllowTransferForZoneInstance& operator=(
      const Linux_DnsAllowTransferForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowTransferForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowTransferForZoneInstanceEnumerationElement {

    Linux_DnsAllowTransferForZoneInstance* m_elementP;
    Linux_DnsAllowTransferForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowTransferForZoneInstanceEnumerationElement();
    ~Linux_DnsAllowTransferForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowTransferForZoneInstanceEnumeration {

    private:
    Linux_DnsAllowTransferForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowTransferForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowTransferForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowTransferForZoneInstanceEnumeration();
    Linux_DnsAllowTransferForZoneInstanceEnumeration(
      const Linux_DnsAllowTransferForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowTransferForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowTransferForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowTransferForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowTransferForZoneInstance& anInstance);

  };

}

#endif
