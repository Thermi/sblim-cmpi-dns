 /**
 * Linux_DnsResourceRecordInZoneInstance.h
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
#ifndef Linux_DnsResourceRecordInZoneInstance_h
#define Linux_DnsResourceRecordInZoneInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsResourceRecordInZoneInstance {
  public:
       Linux_DnsResourceRecordInZoneInstance();
  	
       Linux_DnsResourceRecordInZoneInstance
  	    (const Linux_DnsResourceRecordInZoneInstance& original);
  	   
       Linux_DnsResourceRecordInZoneInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsResourceRecordInZoneInstance();
       
       Linux_DnsResourceRecordInZoneInstance& operator=
  	    (const Linux_DnsResourceRecordInZoneInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsResourceRecordInZoneInstanceName& val);        
       const Linux_DnsResourceRecordInZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsResourceRecordInZoneInstance& original);
       void reset();
       
       Linux_DnsResourceRecordInZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsResourceRecordInZoneInstanceEnumerationElement{
  	Linux_DnsResourceRecordInZoneInstance* m_elementP;
  	Linux_DnsResourceRecordInZoneInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordInZoneInstanceEnumerationElement();
  	~Linux_DnsResourceRecordInZoneInstanceEnumerationElement();  	
  };
  

  class Linux_DnsResourceRecordInZoneInstanceEnumeration {
  	private:
  	  Linux_DnsResourceRecordInZoneInstanceEnumerationElement* firstElementP;
  	  Linux_DnsResourceRecordInZoneInstanceEnumerationElement* currentElementP;
  	  Linux_DnsResourceRecordInZoneInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsResourceRecordInZoneInstanceEnumeration();
  	  
  	  Linux_DnsResourceRecordInZoneInstanceEnumeration(
  	   const Linux_DnsResourceRecordInZoneInstanceEnumeration& original);
  	  
  	  ~Linux_DnsResourceRecordInZoneInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsResourceRecordInZoneInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsResourceRecordInZoneInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsResourceRecordInZoneInstance& elementP);
  };
}
#endif

