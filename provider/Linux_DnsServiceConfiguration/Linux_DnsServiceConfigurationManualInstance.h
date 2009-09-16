// =======================================================================
// Linux_DnsServiceConfigurationManualInstance.h
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
#ifndef Linux_DnsServiceConfigurationManualInstance_h
#define Linux_DnsServiceConfigurationManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationManualInstance& anInstance);
    void reset();
       
    Linux_DnsServiceConfigurationInstanceName m_instanceName;
    const char* m_ConfigurationFile;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int ConfigurationFile:1;

    } isSet;
    
    public:
    Linux_DnsServiceConfigurationManualInstance();
    Linux_DnsServiceConfigurationManualInstance(
      const Linux_DnsServiceConfigurationManualInstance& anInstance);
    Linux_DnsServiceConfigurationManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceConfigurationManualInstance();
       
    Linux_DnsServiceConfigurationManualInstance& operator=(
      const Linux_DnsServiceConfigurationManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);        
    const Linux_DnsServiceConfigurationInstanceName& getInstanceName() const;

    unsigned int isConfigurationFileSet() const;
    void setConfigurationFile(const char* aValue, int aCopyFlag = 1);
    const char* getConfigurationFile() const;


  };
  
  struct Linux_DnsServiceConfigurationManualInstanceEnumerationElement {

    Linux_DnsServiceConfigurationManualInstance* m_elementP;
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceConfigurationManualInstanceEnumerationElement();
    ~Linux_DnsServiceConfigurationManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceConfigurationManualInstanceEnumeration {

    private:
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceConfigurationManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceConfigurationManualInstanceEnumeration();
    Linux_DnsServiceConfigurationManualInstanceEnumeration(
      const Linux_DnsServiceConfigurationManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceConfigurationManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceConfigurationManualInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceConfigurationManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceConfigurationManualInstance& anInstance);

  };

}

#endif
