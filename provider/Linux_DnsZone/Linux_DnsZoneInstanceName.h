 /**
 * Linux_DnsZoneInstanceName.h
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
#ifndef Linux_DnsZoneInstanceName_h
#define Linux_DnsZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"

namespace genProvider {

  class Linux_DnsZoneInstanceName {
  public:
       Linux_DnsZoneInstanceName();
  	
       Linux_DnsZoneInstanceName
  	    (const Linux_DnsZoneInstanceName& original);
  	   
       Linux_DnsZoneInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsZoneInstanceName();
       
       Linux_DnsZoneInstanceName& operator=
  	    (const Linux_DnsZoneInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isNameSet() const;
       void setName(const char* val, int makeCopy = 1);
       const char* getName() const;
       
  private:
       void init();
       void init(const Linux_DnsZoneInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_Name;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Name:1;
       } isSet;
  };
  
  
  struct Linux_DnsZoneInstanceNameEnumerationElement{
  	Linux_DnsZoneInstanceName* m_elementP;
  	Linux_DnsZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsZoneInstanceNameEnumerationElement();
  	~Linux_DnsZoneInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsZoneInstanceNameEnumeration {
  	private:
  	  Linux_DnsZoneInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsZoneInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsZoneInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsZoneInstanceNameEnumeration();
  	  
  	  Linux_DnsZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsZoneInstanceNameEnumeration(
  	   const Linux_DnsZoneInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsZoneInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsZoneInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsZoneInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsZoneInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

