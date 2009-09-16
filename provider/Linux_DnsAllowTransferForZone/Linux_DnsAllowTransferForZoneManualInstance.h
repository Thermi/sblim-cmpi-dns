// =======================================================================
// Linux_DnsAllowTransferForZoneManualInstance.h
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
#ifndef Linux_DnsAllowTransferForZoneManualInstance_h
#define Linux_DnsAllowTransferForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowTransferForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowTransferForZoneManualInstance();
    Linux_DnsAllowTransferForZoneManualInstance(
      const Linux_DnsAllowTransferForZoneManualInstance& anInstance);
    Linux_DnsAllowTransferForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowTransferForZoneManualInstance();
       
    Linux_DnsAllowTransferForZoneManualInstance& operator=(
      const Linux_DnsAllowTransferForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowTransferForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowTransferForZoneManualInstanceEnumerationElement {

    Linux_DnsAllowTransferForZoneManualInstance* m_elementP;
    Linux_DnsAllowTransferForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowTransferForZoneManualInstanceEnumerationElement();
    ~Linux_DnsAllowTransferForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowTransferForZoneManualInstanceEnumeration {

    private:
    Linux_DnsAllowTransferForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowTransferForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowTransferForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowTransferForZoneManualInstanceEnumeration();
    Linux_DnsAllowTransferForZoneManualInstanceEnumeration(
      const Linux_DnsAllowTransferForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowTransferForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowTransferForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowTransferForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowTransferForZoneManualInstance& anInstance);

  };

}

#endif
