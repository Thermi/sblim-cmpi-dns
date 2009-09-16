// =======================================================================
// Linux_DnsServiceSettingDataRepositoryInstance.h
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
#ifndef Linux_DnsServiceSettingDataRepositoryInstance_h
#define Linux_DnsServiceSettingDataRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceSettingDataInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceSettingDataRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceSettingDataRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsServiceSettingDataInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceSettingDataRepositoryInstance();
    Linux_DnsServiceSettingDataRepositoryInstance(
      const Linux_DnsServiceSettingDataRepositoryInstance& anInstance);
    Linux_DnsServiceSettingDataRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceSettingDataRepositoryInstance();
       
    Linux_DnsServiceSettingDataRepositoryInstance& operator=(
      const Linux_DnsServiceSettingDataRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceSettingDataInstanceName& anInstanceName);        
    const Linux_DnsServiceSettingDataInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceSettingDataRepositoryInstanceEnumerationElement {

    Linux_DnsServiceSettingDataRepositoryInstance* m_elementP;
    Linux_DnsServiceSettingDataRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceSettingDataRepositoryInstanceEnumerationElement();
    ~Linux_DnsServiceSettingDataRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceSettingDataRepositoryInstanceEnumeration {

    private:
    Linux_DnsServiceSettingDataRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceSettingDataRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceSettingDataRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceSettingDataRepositoryInstanceEnumeration();
    Linux_DnsServiceSettingDataRepositoryInstanceEnumeration(
      const Linux_DnsServiceSettingDataRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceSettingDataRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceSettingDataRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceSettingDataRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceSettingDataRepositoryInstance& anInstance);

  };

}

#endif
