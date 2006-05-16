// =======================================================================
// Linux_DnsMastersOfSlaveZoneInstance.h
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
#ifndef Linux_DnsMastersOfSlaveZoneInstance_h
#define Linux_DnsMastersOfSlaveZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersOfSlaveZoneInstance& anInstance);
    void reset();
       
    Linux_DnsMastersOfSlaveZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersOfSlaveZoneInstance();
    Linux_DnsMastersOfSlaveZoneInstance(
      const Linux_DnsMastersOfSlaveZoneInstance& anInstance);
    Linux_DnsMastersOfSlaveZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersOfSlaveZoneInstance();
       
    Linux_DnsMastersOfSlaveZoneInstance& operator=(
      const Linux_DnsMastersOfSlaveZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);        
    const Linux_DnsMastersOfSlaveZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement {

    Linux_DnsMastersOfSlaveZoneInstance* m_elementP;
    Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement();
    ~Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersOfSlaveZoneInstanceEnumeration {

    private:
    Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersOfSlaveZoneInstanceEnumeration();
    Linux_DnsMastersOfSlaveZoneInstanceEnumeration(
      const Linux_DnsMastersOfSlaveZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersOfSlaveZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersOfSlaveZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersOfSlaveZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersOfSlaveZoneInstance& anInstance);

  };

}

#endif
