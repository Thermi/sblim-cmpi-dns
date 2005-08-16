 /**
 * Linux_DnsZoneManualInstance.h
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
#ifndef Linux_DnsZoneManualInstance_h
#define Linux_DnsZoneManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsZoneManualInstance {
  public:
       Linux_DnsZoneManualInstance();
  	
       Linux_DnsZoneManualInstance
  	    (const Linux_DnsZoneManualInstance& original);
  	   
       Linux_DnsZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsZoneManualInstance();
       
       Linux_DnsZoneManualInstance& operator=
  	    (const Linux_DnsZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsZoneInstanceName& val);        
       const Linux_DnsZoneInstanceName&
        getInstanceName() const;

       unsigned int isContactSet() const;
       void setContact(const char* val, int makeCopy = 1);
       const char* getContact() const;

       unsigned int isResourceRecordFileSet() const;
       void setResourceRecordFile(const char* val, int makeCopy = 1);
       const char* getResourceRecordFile() const;

       unsigned int isTypeSet() const;
       void setType(const CMPIUint16 val);
       const CMPIUint16 getType() const;
       
  private:
       void init();
       void init(const Linux_DnsZoneManualInstance& original);
       void reset();
       
       Linux_DnsZoneInstanceName m_instanceName;
       const char* m_Contact;
       const char* m_ResourceRecordFile;
       CMPIUint16 m_Type;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Contact:1;
         unsigned int ResourceRecordFile:1;
         unsigned int Type:1;
       } isSet;
  };
  
  
  struct Linux_DnsZoneManualInstanceEnumerationElement{
  	Linux_DnsZoneManualInstance* m_elementP;
  	Linux_DnsZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsZoneManualInstanceEnumerationElement();
  	~Linux_DnsZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsZoneManualInstanceEnumeration(
  	   const Linux_DnsZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsZoneManualInstance& elementP);
  };
}
#endif

