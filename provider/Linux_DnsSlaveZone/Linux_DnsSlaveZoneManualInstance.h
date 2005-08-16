 /**
 * Linux_DnsSlaveZoneManualInstance.h
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
#ifndef Linux_DnsSlaveZoneManualInstance_h
#define Linux_DnsSlaveZoneManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSlaveZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsSlaveZoneManualInstance {
  public:
       Linux_DnsSlaveZoneManualInstance();
  	
       Linux_DnsSlaveZoneManualInstance
  	    (const Linux_DnsSlaveZoneManualInstance& original);
  	   
       Linux_DnsSlaveZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsSlaveZoneManualInstance();
       
       Linux_DnsSlaveZoneManualInstance& operator=
  	    (const Linux_DnsSlaveZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsSlaveZoneInstanceName& val);        
       const Linux_DnsSlaveZoneInstanceName&
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
       void init(const Linux_DnsSlaveZoneManualInstance& original);
       void reset();
       
       Linux_DnsSlaveZoneInstanceName m_instanceName;
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
  
  
  struct Linux_DnsSlaveZoneManualInstanceEnumerationElement{
  	Linux_DnsSlaveZoneManualInstance* m_elementP;
  	Linux_DnsSlaveZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsSlaveZoneManualInstanceEnumerationElement();
  	~Linux_DnsSlaveZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsSlaveZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsSlaveZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsSlaveZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsSlaveZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSlaveZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsSlaveZoneManualInstanceEnumeration(
  	   const Linux_DnsSlaveZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsSlaveZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSlaveZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSlaveZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsSlaveZoneManualInstance& elementP);
  };
}
#endif

