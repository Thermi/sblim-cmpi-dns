 /**
 * Linux_DnsForwardZoneInstanceName.h
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
#ifndef Linux_DnsForwardZoneInstanceName_h
#define Linux_DnsForwardZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"

namespace genProvider {

  class Linux_DnsForwardZoneInstanceName {
  public:
       Linux_DnsForwardZoneInstanceName();
  	
       Linux_DnsForwardZoneInstanceName
  	    (const Linux_DnsForwardZoneInstanceName& original);
  	   
       Linux_DnsForwardZoneInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsForwardZoneInstanceName();
       
       Linux_DnsForwardZoneInstanceName& operator=
  	    (const Linux_DnsForwardZoneInstanceName& original);
       
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
       void init(const Linux_DnsForwardZoneInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_Name;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Name:1;
       } isSet;
  };
  
  
  struct Linux_DnsForwardZoneInstanceNameEnumerationElement{
  	Linux_DnsForwardZoneInstanceName* m_elementP;
  	Linux_DnsForwardZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsForwardZoneInstanceNameEnumerationElement();
  	~Linux_DnsForwardZoneInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsForwardZoneInstanceNameEnumeration {
  	private:
  	  Linux_DnsForwardZoneInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsForwardZoneInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsForwardZoneInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsForwardZoneInstanceNameEnumeration();
  	  
  	  Linux_DnsForwardZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsForwardZoneInstanceNameEnumeration(
  	   const Linux_DnsForwardZoneInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsForwardZoneInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsForwardZoneInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsForwardZoneInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsForwardZoneInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

