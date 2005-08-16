 /**
 * Linux_DnsHintZoneManualInstance.h
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
  public:
       Linux_DnsHintZoneManualInstance();
  	
       Linux_DnsHintZoneManualInstance
  	    (const Linux_DnsHintZoneManualInstance& original);
  	   
       Linux_DnsHintZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsHintZoneManualInstance();
       
       Linux_DnsHintZoneManualInstance& operator=
  	    (const Linux_DnsHintZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsHintZoneInstanceName& val);        
       const Linux_DnsHintZoneInstanceName&
        getInstanceName() const;

       unsigned int isResourceRecordFileSet() const;
       void setResourceRecordFile(const char* val, int makeCopy = 1);
       const char* getResourceRecordFile() const;

       unsigned int isTypeSet() const;
       void setType(const CMPIUint16 val);
       const CMPIUint16 getType() const;
       
  private:
       void init();
       void init(const Linux_DnsHintZoneManualInstance& original);
       void reset();
       
       Linux_DnsHintZoneInstanceName m_instanceName;
       const char* m_ResourceRecordFile;
       CMPIUint16 m_Type;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int ResourceRecordFile:1;
         unsigned int Type:1;
       } isSet;
  };
  
  
  struct Linux_DnsHintZoneManualInstanceEnumerationElement{
  	Linux_DnsHintZoneManualInstance* m_elementP;
  	Linux_DnsHintZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsHintZoneManualInstanceEnumerationElement();
  	~Linux_DnsHintZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsHintZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsHintZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsHintZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsHintZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsHintZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsHintZoneManualInstanceEnumeration(
  	   const Linux_DnsHintZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsHintZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsHintZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsHintZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsHintZoneManualInstance& elementP);
  };
}
#endif

