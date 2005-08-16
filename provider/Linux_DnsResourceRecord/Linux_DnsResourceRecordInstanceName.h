 /**
 * Linux_DnsResourceRecordInstanceName.h
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
#ifndef Linux_DnsResourceRecordInstanceName_h
#define Linux_DnsResourceRecordInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"

namespace genProvider {

  class Linux_DnsResourceRecordInstanceName {
  public:
       Linux_DnsResourceRecordInstanceName();
  	
       Linux_DnsResourceRecordInstanceName
  	    (const Linux_DnsResourceRecordInstanceName& original);
  	   
       Linux_DnsResourceRecordInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsResourceRecordInstanceName();
       
       Linux_DnsResourceRecordInstanceName& operator=
  	    (const Linux_DnsResourceRecordInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isNameSet() const;
       void setName(const char* val, int makeCopy = 1);
       const char* getName() const;

       unsigned int isTypeSet() const;
       void setType(const CMPIUint16 val);
       const CMPIUint16 getType() const;

       unsigned int isValueSet() const;
       void setValue(const char* val, int makeCopy = 1);
       const char* getValue() const;

       unsigned int isZoneNameSet() const;
       void setZoneName(const char* val, int makeCopy = 1);
       const char* getZoneName() const;
       
  private:
       void init();
       void init(const Linux_DnsResourceRecordInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_Name;
       CMPIUint16 m_Type;
       const char* m_Value;
       const char* m_ZoneName;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Name:1;
         unsigned int Type:1;
         unsigned int Value:1;
         unsigned int ZoneName:1;
       } isSet;
  };
  
  
  struct Linux_DnsResourceRecordInstanceNameEnumerationElement{
  	Linux_DnsResourceRecordInstanceName* m_elementP;
  	Linux_DnsResourceRecordInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordInstanceNameEnumerationElement();
  	~Linux_DnsResourceRecordInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsResourceRecordInstanceNameEnumeration {
  	private:
  	  Linux_DnsResourceRecordInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsResourceRecordInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsResourceRecordInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsResourceRecordInstanceNameEnumeration();
  	  
  	  Linux_DnsResourceRecordInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsResourceRecordInstanceNameEnumeration(
  	   const Linux_DnsResourceRecordInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsResourceRecordInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsResourceRecordInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsResourceRecordInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsResourceRecordInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

