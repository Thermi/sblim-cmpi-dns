// =======================================================================
// Linux_DnsServiceManualInstance.h
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
#ifndef Linux_DnsServiceManualInstance_h
#define Linux_DnsServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsServiceInstanceName m_instanceName;
    CMPIBoolean m_RunAsRoot;
    CMPIBoolean m_Started;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int RunAsRoot:1;
      unsigned int Started:1;

    } isSet;
    
    public:
    Linux_DnsServiceManualInstance();
    Linux_DnsServiceManualInstance(
      const Linux_DnsServiceManualInstance& anInstance);
    Linux_DnsServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceManualInstance();
       
    Linux_DnsServiceManualInstance& operator=(
      const Linux_DnsServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceInstanceName& anInstanceName);        
    const Linux_DnsServiceInstanceName& getInstanceName() const;

    unsigned int isRunAsRootSet() const;
    void setRunAsRoot(const CMPIBoolean aValue);
    const CMPIBoolean getRunAsRoot() const;

    unsigned int isStartedSet() const;
    void setStarted(const CMPIBoolean aValue);
    const CMPIBoolean getStarted() const;


  };
  
  struct Linux_DnsServiceManualInstanceEnumerationElement {

    Linux_DnsServiceManualInstance* m_elementP;
    Linux_DnsServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceManualInstanceEnumerationElement();
    ~Linux_DnsServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceManualInstanceEnumeration {

    private:
    Linux_DnsServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceManualInstanceEnumeration();
    Linux_DnsServiceManualInstanceEnumeration(
      const Linux_DnsServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceManualInstance& anInstance);

  };

}

#endif
