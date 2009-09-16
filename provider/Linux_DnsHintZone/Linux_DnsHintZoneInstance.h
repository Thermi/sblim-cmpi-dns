// =======================================================================
// Linux_DnsHintZoneInstance.h
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
#ifndef Linux_DnsHintZoneInstance_h
#define Linux_DnsHintZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsHintZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsHintZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsHintZoneInstance& anInstance);
    void reset();
       
    Linux_DnsHintZoneInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    CMPISint32 m_TTL;
    CMPIUint8 m_Type;
    const char* m_ZoneFile;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int TTL:1;
      unsigned int Type:1;
      unsigned int ZoneFile:1;

    } isSet;
    
    public:
    Linux_DnsHintZoneInstance();
    Linux_DnsHintZoneInstance(
      const Linux_DnsHintZoneInstance& anInstance);
    Linux_DnsHintZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsHintZoneInstance();
       
    Linux_DnsHintZoneInstance& operator=(
      const Linux_DnsHintZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsHintZoneInstanceName& anInstanceName);        
    const Linux_DnsHintZoneInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

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
  
  struct Linux_DnsHintZoneInstanceEnumerationElement {

    Linux_DnsHintZoneInstance* m_elementP;
    Linux_DnsHintZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsHintZoneInstanceEnumerationElement();
    ~Linux_DnsHintZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsHintZoneInstanceEnumeration {

    private:
    Linux_DnsHintZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsHintZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsHintZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsHintZoneInstanceEnumeration();
    Linux_DnsHintZoneInstanceEnumeration(
      const Linux_DnsHintZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsHintZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsHintZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsHintZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsHintZoneInstance& anInstance);

  };

}

#endif
