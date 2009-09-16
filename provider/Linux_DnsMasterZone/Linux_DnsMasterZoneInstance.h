// =======================================================================
// Linux_DnsMasterZoneInstance.h
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
#ifndef Linux_DnsMasterZoneInstance_h
#define Linux_DnsMasterZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMasterZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMasterZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsMasterZoneInstance& anInstance);
    void reset();
       
    Linux_DnsMasterZoneInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Contact;
    const char* m_Description;
    const char* m_ElementName;
    CMPIUint32 m_Expire;
    CMPIUint8 m_Forward;
    CMPIUint32 m_NegativeCachingTTL;
    CMPIUint32 m_Refresh;
    CMPIUint32 m_Retry;
    const char* m_SerialNumber;
    const char* m_Server;
    CMPISint32 m_TTL;
    CMPIUint8 m_Type;
    const char* m_ZoneFile;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Contact:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int Expire:1;
      unsigned int Forward:1;
      unsigned int NegativeCachingTTL:1;
      unsigned int Refresh:1;
      unsigned int Retry:1;
      unsigned int SerialNumber:1;
      unsigned int Server:1;
      unsigned int TTL:1;
      unsigned int Type:1;
      unsigned int ZoneFile:1;

    } isSet;
    
    public:
    Linux_DnsMasterZoneInstance();
    Linux_DnsMasterZoneInstance(
      const Linux_DnsMasterZoneInstance& anInstance);
    Linux_DnsMasterZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMasterZoneInstance();
       
    Linux_DnsMasterZoneInstance& operator=(
      const Linux_DnsMasterZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMasterZoneInstanceName& anInstanceName);        
    const Linux_DnsMasterZoneInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isContactSet() const;
    void setContact(const char* aValue, int aCopyFlag = 1);
    const char* getContact() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isExpireSet() const;
    void setExpire(const CMPIUint32 aValue);
    const CMPIUint32 getExpire() const;

    unsigned int isForwardSet() const;
    void setForward(const CMPIUint8 aValue);
    const CMPIUint8 getForward() const;

    unsigned int isNegativeCachingTTLSet() const;
    void setNegativeCachingTTL(const CMPIUint32 aValue);
    const CMPIUint32 getNegativeCachingTTL() const;

    unsigned int isRefreshSet() const;
    void setRefresh(const CMPIUint32 aValue);
    const CMPIUint32 getRefresh() const;

    unsigned int isRetrySet() const;
    void setRetry(const CMPIUint32 aValue);
    const CMPIUint32 getRetry() const;

    unsigned int isSerialNumberSet() const;
    void setSerialNumber(const char* aValue, int aCopyFlag = 1);
    const char* getSerialNumber() const;

    unsigned int isServerSet() const;
    void setServer(const char* aValue, int aCopyFlag = 1);
    const char* getServer() const;

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
  
  struct Linux_DnsMasterZoneInstanceEnumerationElement {

    Linux_DnsMasterZoneInstance* m_elementP;
    Linux_DnsMasterZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsMasterZoneInstanceEnumerationElement();
    ~Linux_DnsMasterZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsMasterZoneInstanceEnumeration {

    private:
    Linux_DnsMasterZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMasterZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMasterZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMasterZoneInstanceEnumeration();
    Linux_DnsMasterZoneInstanceEnumeration(
      const Linux_DnsMasterZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMasterZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMasterZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsMasterZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMasterZoneInstance& anInstance);

  };

}

#endif
