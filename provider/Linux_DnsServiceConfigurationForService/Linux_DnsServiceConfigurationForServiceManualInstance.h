// =======================================================================
// Linux_DnsServiceConfigurationForServiceManualInstance.h
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
#ifndef Linux_DnsServiceConfigurationForServiceManualInstance_h
#define Linux_DnsServiceConfigurationForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsServiceConfigurationForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceConfigurationForServiceManualInstance();
    Linux_DnsServiceConfigurationForServiceManualInstance(
      const Linux_DnsServiceConfigurationForServiceManualInstance& anInstance);
    Linux_DnsServiceConfigurationForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceConfigurationForServiceManualInstance();
       
    Linux_DnsServiceConfigurationForServiceManualInstance& operator=(
      const Linux_DnsServiceConfigurationForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);        
    const Linux_DnsServiceConfigurationForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceConfigurationForServiceManualInstanceEnumerationElement {

    Linux_DnsServiceConfigurationForServiceManualInstance* m_elementP;
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceConfigurationForServiceManualInstanceEnumerationElement();
    ~Linux_DnsServiceConfigurationForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration {

    private:
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration();
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration(
      const Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceConfigurationForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceConfigurationForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceConfigurationForServiceManualInstance& anInstance);

  };

}

#endif
