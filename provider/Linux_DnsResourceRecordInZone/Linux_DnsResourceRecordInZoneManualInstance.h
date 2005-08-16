 /**
 * Linux_DnsResourceRecordInZoneManualInstance.h
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
#ifndef Linux_DnsResourceRecordInZoneManualInstance_h
#define Linux_DnsResourceRecordInZoneManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsResourceRecordInZoneManualInstance {
  public:
       Linux_DnsResourceRecordInZoneManualInstance();
  	
       Linux_DnsResourceRecordInZoneManualInstance
  	    (const Linux_DnsResourceRecordInZoneManualInstance& original);
  	   
       Linux_DnsResourceRecordInZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsResourceRecordInZoneManualInstance();
       
       Linux_DnsResourceRecordInZoneManualInstance& operator=
  	    (const Linux_DnsResourceRecordInZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsResourceRecordInZoneInstanceName& val);        
       const Linux_DnsResourceRecordInZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsResourceRecordInZoneManualInstance& original);
       void reset();
       
       Linux_DnsResourceRecordInZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement{
  	Linux_DnsResourceRecordInZoneManualInstance* m_elementP;
  	Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement();
  	~Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsResourceRecordInZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsResourceRecordInZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsResourceRecordInZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsResourceRecordInZoneManualInstanceEnumeration(
  	   const Linux_DnsResourceRecordInZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsResourceRecordInZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsResourceRecordInZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsResourceRecordInZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsResourceRecordInZoneManualInstance& elementP);
  };
}
#endif

