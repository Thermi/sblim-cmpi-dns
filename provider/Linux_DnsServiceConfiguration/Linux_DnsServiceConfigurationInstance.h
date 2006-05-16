// =======================================================================
// Linux_DnsServiceConfigurationInstance.h
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsServiceConfigurationInstance_h
#define Linux_DnsServiceConfigurationInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationInstance& anInstance);
    void reset();
       
    Linux_DnsServiceConfigurationInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceConfigurationInstance();
    Linux_DnsServiceConfigurationInstance(
      const Linux_DnsServiceConfigurationInstance& anInstance);
    Linux_DnsServiceConfigurationInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceConfigurationInstance();
       
    Linux_DnsServiceConfigurationInstance& operator=(
      const Linux_DnsServiceConfigurationInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);        
    const Linux_DnsServiceConfigurationInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceConfigurationInstanceEnumerationElement {

    Linux_DnsServiceConfigurationInstance* m_elementP;
    Linux_DnsServiceConfigurationInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceConfigurationInstanceEnumerationElement();
    ~Linux_DnsServiceConfigurationInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceConfigurationInstanceEnumeration {

    private:
    Linux_DnsServiceConfigurationInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceConfigurationInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceConfigurationInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceConfigurationInstanceEnumeration();
    Linux_DnsServiceConfigurationInstanceEnumeration(
      const Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceConfigurationInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceConfigurationInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceConfigurationInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceConfigurationInstance& anInstance);

  };

}

#endif
