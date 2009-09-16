// =======================================================================
// Linux_DnsBlackholeForServiceManualInstance.h
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
#ifndef Linux_DnsBlackholeForServiceManualInstance_h
#define Linux_DnsBlackholeForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsBlackholeForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsBlackholeForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsBlackholeForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsBlackholeForServiceManualInstance();
    Linux_DnsBlackholeForServiceManualInstance(
      const Linux_DnsBlackholeForServiceManualInstance& anInstance);
    Linux_DnsBlackholeForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsBlackholeForServiceManualInstance();
       
    Linux_DnsBlackholeForServiceManualInstance& operator=(
      const Linux_DnsBlackholeForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);        
    const Linux_DnsBlackholeForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsBlackholeForServiceManualInstanceEnumerationElement {

    Linux_DnsBlackholeForServiceManualInstance* m_elementP;
    Linux_DnsBlackholeForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsBlackholeForServiceManualInstanceEnumerationElement();
    ~Linux_DnsBlackholeForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsBlackholeForServiceManualInstanceEnumeration {

    private:
    Linux_DnsBlackholeForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsBlackholeForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsBlackholeForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsBlackholeForServiceManualInstanceEnumeration();
    Linux_DnsBlackholeForServiceManualInstanceEnumeration(
      const Linux_DnsBlackholeForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsBlackholeForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsBlackholeForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsBlackholeForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsBlackholeForServiceManualInstance& anInstance);

  };

}

#endif
