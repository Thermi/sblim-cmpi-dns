// =======================================================================
// Linux_DnsHintZoneManualInstance.h
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
#ifndef Linux_DnsHintZoneManualInstance_h
#define Linux_DnsHintZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsHintZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsHintZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsHintZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsHintZoneInstanceName m_instanceName;
    CMPISint32 m_TTL;
    CMPIUint8 m_Type;
    const char* m_ZoneFile;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int TTL:1;
      unsigned int Type:1;
      unsigned int ZoneFile:1;

    } isSet;
    
    public:
    Linux_DnsHintZoneManualInstance();
    Linux_DnsHintZoneManualInstance(
      const Linux_DnsHintZoneManualInstance& anInstance);
    Linux_DnsHintZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsHintZoneManualInstance();
       
    Linux_DnsHintZoneManualInstance& operator=(
      const Linux_DnsHintZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsHintZoneInstanceName& anInstanceName);        
    const Linux_DnsHintZoneInstanceName& getInstanceName() const;

    unsigned int isTTLSet() const;
    void setTTL(const CMPISint32 aValue);
    const CMPISint32 getTTL() const;

    unsigned int isTypeSet() const;
    void setType(const CMPIUint8 aValue);
    const CMPIUint8 getType() const;

    unsigned int isZoneFileSet() const;
    void setZoneFile(const char* aValue, int aCopyFlag = 1);
    const char* getZoneFile() const;


  };
  
  struct Linux_DnsHintZoneManualInstanceEnumerationElement {

    Linux_DnsHintZoneManualInstance* m_elementP;
    Linux_DnsHintZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsHintZoneManualInstanceEnumerationElement();
    ~Linux_DnsHintZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsHintZoneManualInstanceEnumeration {

    private:
    Linux_DnsHintZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsHintZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsHintZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsHintZoneManualInstanceEnumeration();
    Linux_DnsHintZoneManualInstanceEnumeration(
      const Linux_DnsHintZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsHintZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsHintZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsHintZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsHintZoneManualInstance& anInstance);

  };

}

#endif
