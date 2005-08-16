 /**
 * Linux_DnsMasterZoneManualInstance.h
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
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
  public:
       Linux_DnsMasterZoneManualInstance();
  	
       Linux_DnsMasterZoneManualInstance
  	    (const Linux_DnsMasterZoneManualInstance& original);
  	   
       Linux_DnsMasterZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsMasterZoneManualInstance();
       
       Linux_DnsMasterZoneManualInstance& operator=
  	    (const Linux_DnsMasterZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsMasterZoneInstanceName& val);        
       const Linux_DnsMasterZoneInstanceName&
        getInstanceName() const;

       unsigned int isContactSet() const;
       void setContact(const char* val, int makeCopy = 1);
       const char* getContact() const;

       unsigned int isExpireSet() const;
       void setExpire(const CMPIUint32 val);
       const CMPIUint32 getExpire() const;

       unsigned int isForwardSet() const;
       void setForward(const CMPIUint16 val);
       const CMPIUint16 getForward() const;

       unsigned int isForwardersSet() const;
       void setForwarders(const char** val, unsigned const int size, int makeCopy = 1);
       const char** getForwarders(unsigned int& size) const;

       unsigned int isNegativeCachingTTLSet() const;
       void setNegativeCachingTTL(const CMPIUint32 val);
       const CMPIUint32 getNegativeCachingTTL() const;

       unsigned int isRefreshSet() const;
       void setRefresh(const CMPIUint32 val);
       const CMPIUint32 getRefresh() const;

       unsigned int isResourceRecordFileSet() const;
       void setResourceRecordFile(const char* val, int makeCopy = 1);
       const char* getResourceRecordFile() const;

       unsigned int isRetrySet() const;
       void setRetry(const CMPIUint32 val);
       const CMPIUint32 getRetry() const;

       unsigned int isSerialNumberSet() const;
       void setSerialNumber(const char* val, int makeCopy = 1);
       const char* getSerialNumber() const;

       unsigned int isServerSet() const;
       void setServer(const char* val, int makeCopy = 1);
       const char* getServer() const;

       unsigned int isTypeSet() const;
       void setType(const CMPIUint16 val);
       const CMPIUint16 getType() const;
       
  private:
       void init();
       void init(const Linux_DnsMasterZoneManualInstance& original);
       void reset();
       
       Linux_DnsMasterZoneInstanceName m_instanceName;
       const char* m_Contact;
       CMPIUint32 m_Expire;
       CMPIUint16 m_Forward;
       const char** m_Forwarders;
        unsigned int ForwardersArraySize;
       CMPIUint32 m_NegativeCachingTTL;
       CMPIUint32 m_Refresh;
       const char* m_ResourceRecordFile;
       CMPIUint32 m_Retry;
       const char* m_SerialNumber;
       const char* m_Server;
       CMPIUint16 m_Type;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Contact:1;
         unsigned int Expire:1;
         unsigned int Forward:1;
         unsigned int Forwarders:1;
         unsigned int NegativeCachingTTL:1;
         unsigned int Refresh:1;
         unsigned int ResourceRecordFile:1;
         unsigned int Retry:1;
         unsigned int SerialNumber:1;
         unsigned int Server:1;
         unsigned int Type:1;
       } isSet;
  };
  
  
  struct Linux_DnsMasterZoneManualInstanceEnumerationElement{
  	Linux_DnsMasterZoneManualInstance* m_elementP;
  	Linux_DnsMasterZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsMasterZoneManualInstanceEnumerationElement();
  	~Linux_DnsMasterZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsMasterZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsMasterZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsMasterZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsMasterZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsMasterZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsMasterZoneManualInstanceEnumeration(
  	   const Linux_DnsMasterZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsMasterZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsMasterZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsMasterZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsMasterZoneManualInstance& elementP);
  };
}
#endif

