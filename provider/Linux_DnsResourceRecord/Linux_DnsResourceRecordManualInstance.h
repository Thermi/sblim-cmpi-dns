 /**
 * Linux_DnsResourceRecordManualInstance.h
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
#ifndef Linux_DnsResourceRecordManualInstance_h
#define Linux_DnsResourceRecordManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInstanceName.h"

namespace genProvider {

  class Linux_DnsResourceRecordManualInstance {
  public:
       Linux_DnsResourceRecordManualInstance();
  	
       Linux_DnsResourceRecordManualInstance
  	    (const Linux_DnsResourceRecordManualInstance& original);
  	   
       Linux_DnsResourceRecordManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsResourceRecordManualInstance();
       
       Linux_DnsResourceRecordManualInstance& operator=
  	    (const Linux_DnsResourceRecordManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsResourceRecordInstanceName& val);        
       const Linux_DnsResourceRecordInstanceName&
        getInstanceName() const;

       unsigned int isFamilySet() const;
       void setFamily(const CMPIUint16 val);
       const CMPIUint16 getFamily() const;

       unsigned int isTTLSet() const;
       void setTTL(const CMPIUint32 val);
       const CMPIUint32 getTTL() const;
       
  private:
       void init();
       void init(const Linux_DnsResourceRecordManualInstance& original);
       void reset();
       
       Linux_DnsResourceRecordInstanceName m_instanceName;
       CMPIUint16 m_Family;
       CMPIUint32 m_TTL;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Family:1;
         unsigned int TTL:1;
       } isSet;
  };
  
  
  struct Linux_DnsResourceRecordManualInstanceEnumerationElement{
  	Linux_DnsResourceRecordManualInstance* m_elementP;
  	Linux_DnsResourceRecordManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordManualInstanceEnumerationElement();
  	~Linux_DnsResourceRecordManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsResourceRecordManualInstanceEnumeration {
  	private:
  	  Linux_DnsResourceRecordManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsResourceRecordManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsResourceRecordManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsResourceRecordManualInstanceEnumeration();
  	  
  	  Linux_DnsResourceRecordManualInstanceEnumeration(
  	   const Linux_DnsResourceRecordManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsResourceRecordManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsResourceRecordManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsResourceRecordManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsResourceRecordManualInstance& elementP);
  };
}
#endif

