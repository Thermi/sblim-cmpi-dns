 /**
 * Linux_DnsResourceRecordInZoneInstanceName.h
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
#ifndef Linux_DnsResourceRecordInZoneInstanceName_h
#define Linux_DnsResourceRecordInZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsZoneInstanceName.h"
#include "Linux_DnsResourceRecordInstanceName.h"

namespace genProvider {

  class Linux_DnsResourceRecordInZoneInstanceName {
  public:
       Linux_DnsResourceRecordInZoneInstanceName();
  	
       Linux_DnsResourceRecordInZoneInstanceName
  	    (const Linux_DnsResourceRecordInZoneInstanceName& original);
  	   
       Linux_DnsResourceRecordInZoneInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsResourceRecordInZoneInstanceName();
       
       Linux_DnsResourceRecordInZoneInstanceName& operator=
  	    (const Linux_DnsResourceRecordInZoneInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isGroupComponentSet() const;
       void setGroupComponent(const Linux_DnsZoneInstanceName& val);
       const Linux_DnsZoneInstanceName& getGroupComponent() const;

       unsigned int isPartComponentSet() const;
       void setPartComponent(const Linux_DnsResourceRecordInstanceName& val);
       const Linux_DnsResourceRecordInstanceName& getPartComponent() const;
       
  private:
       void init();
       void init(const Linux_DnsResourceRecordInZoneInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       Linux_DnsZoneInstanceName m_GroupComponent;
       Linux_DnsResourceRecordInstanceName m_PartComponent;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int GroupComponent:1;
         unsigned int PartComponent:1;
       } isSet;
  };
  
  
  struct Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement{
  	Linux_DnsResourceRecordInZoneInstanceName* m_elementP;
  	Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement();
  	~Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsResourceRecordInZoneInstanceNameEnumeration {
  	private:
  	  Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsResourceRecordInZoneInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsResourceRecordInZoneInstanceNameEnumeration();
  	  
  	  Linux_DnsResourceRecordInZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsResourceRecordInZoneInstanceNameEnumeration(
  	   const Linux_DnsResourceRecordInZoneInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsResourceRecordInZoneInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsResourceRecordInZoneInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsResourceRecordInZoneInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsResourceRecordInZoneInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

