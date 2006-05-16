// =======================================================================
// Linux_DnsMastersOfSlaveZoneRepositoryInstance.h
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
#ifndef Linux_DnsMastersOfSlaveZoneRepositoryInstance_h
#define Linux_DnsMastersOfSlaveZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersOfSlaveZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsMastersOfSlaveZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersOfSlaveZoneRepositoryInstance();
    Linux_DnsMastersOfSlaveZoneRepositoryInstance(
      const Linux_DnsMastersOfSlaveZoneRepositoryInstance& anInstance);
    Linux_DnsMastersOfSlaveZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersOfSlaveZoneRepositoryInstance();
       
    Linux_DnsMastersOfSlaveZoneRepositoryInstance& operator=(
      const Linux_DnsMastersOfSlaveZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);        
    const Linux_DnsMastersOfSlaveZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement {

    Linux_DnsMastersOfSlaveZoneRepositoryInstance* m_elementP;
    Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration();
    Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration(
      const Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersOfSlaveZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersOfSlaveZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersOfSlaveZoneRepositoryInstance& anInstance);

  };

}

#endif
