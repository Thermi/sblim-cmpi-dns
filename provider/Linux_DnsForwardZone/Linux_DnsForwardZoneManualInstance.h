 /**
 * Linux_DnsForwardZoneManualInstance.h
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
#ifndef Linux_DnsForwardZoneManualInstance_h
#define Linux_DnsForwardZoneManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsForwardZoneManualInstance {
  public:
       Linux_DnsForwardZoneManualInstance();
  	
       Linux_DnsForwardZoneManualInstance
  	    (const Linux_DnsForwardZoneManualInstance& original);
  	   
       Linux_DnsForwardZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsForwardZoneManualInstance();
       
       Linux_DnsForwardZoneManualInstance& operator=
  	    (const Linux_DnsForwardZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsForwardZoneInstanceName& val);        
       const Linux_DnsForwardZoneInstanceName&
        getInstanceName() const;

       unsigned int isForwardSet() const;
       void setForward(const CMPIUint16 val);
       const CMPIUint16 getForward() const;

       unsigned int isForwardersSet() const;
       void setForwarders(const char** val, unsigned const int size, int makeCopy = 1);
       const char** getForwarders(unsigned int& size) const;

       unsigned int isResourceRecordFileSet() const;
       void setResourceRecordFile(const char* val, int makeCopy = 1);
       const char* getResourceRecordFile() const;

       unsigned int isTypeSet() const;
       void setType(const CMPIUint16 val);
       const CMPIUint16 getType() const;
       
  private:
       void init();
       void init(const Linux_DnsForwardZoneManualInstance& original);
       void reset();
       
       Linux_DnsForwardZoneInstanceName m_instanceName;
       CMPIUint16 m_Forward;
       const char** m_Forwarders;
        unsigned int ForwardersArraySize;
       const char* m_ResourceRecordFile;
       CMPIUint16 m_Type;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Forward:1;
         unsigned int Forwarders:1;
         unsigned int ResourceRecordFile:1;
         unsigned int Type:1;
       } isSet;
  };
  
  
  struct Linux_DnsForwardZoneManualInstanceEnumerationElement{
  	Linux_DnsForwardZoneManualInstance* m_elementP;
  	Linux_DnsForwardZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsForwardZoneManualInstanceEnumerationElement();
  	~Linux_DnsForwardZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsForwardZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsForwardZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsForwardZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsForwardZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsForwardZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsForwardZoneManualInstanceEnumeration(
  	   const Linux_DnsForwardZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsForwardZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsForwardZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsForwardZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsForwardZoneManualInstance& elementP);
  };
}
#endif
