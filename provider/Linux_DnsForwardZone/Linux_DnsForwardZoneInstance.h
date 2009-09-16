// =======================================================================
// Linux_DnsForwardZoneInstance.h
//     created on Wed, 29 Nov 2006 using ECUTE 2.2
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
#ifndef Linux_DnsForwardZoneInstance_h
#define Linux_DnsForwardZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardZoneInstance& anInstance);
    void reset();
       
    Linux_DnsForwardZoneInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    CMPIUint8 m_Forward;
    CMPIUint8 m_Type;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int Forward:1;
      unsigned int Type:1;

    } isSet;
    
    public:
    Linux_DnsForwardZoneInstance();
    Linux_DnsForwardZoneInstance(
      const Linux_DnsForwardZoneInstance& anInstance);
    Linux_DnsForwardZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardZoneInstance();
       
    Linux_DnsForwardZoneInstance& operator=(
      const Linux_DnsForwardZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardZoneInstanceName& anInstanceName);        
    const Linux_DnsForwardZoneInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isForwardSet() const;
    void setForward(const CMPIUint8 aValue);
    const CMPIUint8 getForward() const;

    unsigned int isTypeSet() const;
    void setType(const CMPIUint8 aValue);
    const CMPIUint8 getType() const;


  };
  
  struct Linux_DnsForwardZoneInstanceEnumerationElement {

    Linux_DnsForwardZoneInstance* m_elementP;
    Linux_DnsForwardZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardZoneInstanceEnumerationElement();
    ~Linux_DnsForwardZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardZoneInstanceEnumeration {

    private:
    Linux_DnsForwardZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardZoneInstanceEnumeration();
    Linux_DnsForwardZoneInstanceEnumeration(
      const Linux_DnsForwardZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardZoneInstance& anInstance);

  };

}

#endif
