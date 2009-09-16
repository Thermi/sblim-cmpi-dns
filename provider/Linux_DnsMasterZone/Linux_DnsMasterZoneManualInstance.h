// =======================================================================
// Linux_DnsMasterZoneManualInstance.h
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
#ifndef Linux_DnsMasterZoneManualInstance_h
#define Linux_DnsMasterZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMasterZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsMasterZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsMasterZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsMasterZoneInstanceName m_instanceName;
    const char* m_Contact;
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
      unsigned int Contact:1;
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
    Linux_DnsMasterZoneManualInstance();
    Linux_DnsMasterZoneManualInstance(
      const Linux_DnsMasterZoneManualInstance& anInstance);
    Linux_DnsMasterZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMasterZoneManualInstance();
       
    Linux_DnsMasterZoneManualInstance& operator=(
      const Linux_DnsMasterZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMasterZoneInstanceName& anInstanceName);        
    const Linux_DnsMasterZoneInstanceName& getInstanceName() const;

    unsigned int isContactSet() const;
    void setContact(const char* aValue, int aCopyFlag = 1);
    const char* getContact() const;

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
  
  struct Linux_DnsMasterZoneManualInstanceEnumerationElement {

    Linux_DnsMasterZoneManualInstance* m_elementP;
    Linux_DnsMasterZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsMasterZoneManualInstanceEnumerationElement();
    ~Linux_DnsMasterZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsMasterZoneManualInstanceEnumeration {

    private:
    Linux_DnsMasterZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMasterZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMasterZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMasterZoneManualInstanceEnumeration();
    Linux_DnsMasterZoneManualInstanceEnumeration(
      const Linux_DnsMasterZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMasterZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMasterZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsMasterZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMasterZoneManualInstance& anInstance);

  };

}

#endif
