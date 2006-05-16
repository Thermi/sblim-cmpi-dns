// =======================================================================
// Linux_DnsIPAddressRepositoryInstance.h
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
#ifndef Linux_DnsIPAddressRepositoryInstance_h
#define Linux_DnsIPAddressRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsIPAddressInstanceName.h"


namespace genProvider {

  class Linux_DnsIPAddressRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsIPAddressRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsIPAddressInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsIPAddressRepositoryInstance();
    Linux_DnsIPAddressRepositoryInstance(
      const Linux_DnsIPAddressRepositoryInstance& anInstance);
    Linux_DnsIPAddressRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsIPAddressRepositoryInstance();
       
    Linux_DnsIPAddressRepositoryInstance& operator=(
      const Linux_DnsIPAddressRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsIPAddressInstanceName& anInstanceName);        
    const Linux_DnsIPAddressInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsIPAddressRepositoryInstanceEnumerationElement {

    Linux_DnsIPAddressRepositoryInstance* m_elementP;
    Linux_DnsIPAddressRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsIPAddressRepositoryInstanceEnumerationElement();
    ~Linux_DnsIPAddressRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsIPAddressRepositoryInstanceEnumeration {

    private:
    Linux_DnsIPAddressRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsIPAddressRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsIPAddressRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsIPAddressRepositoryInstanceEnumeration();
    Linux_DnsIPAddressRepositoryInstanceEnumeration(
      const Linux_DnsIPAddressRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsIPAddressRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsIPAddressRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsIPAddressRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsIPAddressRepositoryInstance& anInstance);

  };

}

#endif
