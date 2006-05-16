// =======================================================================
// Linux_DnsMastersOfSlaveZoneManualInstance.h
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
#ifndef Linux_DnsMastersOfSlaveZoneManualInstance_h
#define Linux_DnsMastersOfSlaveZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersOfSlaveZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsMastersOfSlaveZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsMastersOfSlaveZoneManualInstance();
    Linux_DnsMastersOfSlaveZoneManualInstance(
      const Linux_DnsMastersOfSlaveZoneManualInstance& anInstance);
    Linux_DnsMastersOfSlaveZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersOfSlaveZoneManualInstance();
       
    Linux_DnsMastersOfSlaveZoneManualInstance& operator=(
      const Linux_DnsMastersOfSlaveZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);        
    const Linux_DnsMastersOfSlaveZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement {

    Linux_DnsMastersOfSlaveZoneManualInstance* m_elementP;
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement();
    ~Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration {

    private:
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration();
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration(
      const Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersOfSlaveZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersOfSlaveZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersOfSlaveZoneManualInstance& anInstance);

  };

}

#endif
