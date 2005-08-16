 /**
 * Linux_DnsSlaveZoneInstanceName.h
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
#ifndef Linux_DnsSlaveZoneInstanceName_h
#define Linux_DnsSlaveZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"

namespace genProvider {

  class Linux_DnsSlaveZoneInstanceName {
  public:
       Linux_DnsSlaveZoneInstanceName();
  	
       Linux_DnsSlaveZoneInstanceName
  	    (const Linux_DnsSlaveZoneInstanceName& original);
  	   
       Linux_DnsSlaveZoneInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsSlaveZoneInstanceName();
       
       Linux_DnsSlaveZoneInstanceName& operator=
  	    (const Linux_DnsSlaveZoneInstanceName& original);
       
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
       void init(const Linux_DnsSlaveZoneInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_Name;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Name:1;
       } isSet;
  };
  
  
  struct Linux_DnsSlaveZoneInstanceNameEnumerationElement{
  	Linux_DnsSlaveZoneInstanceName* m_elementP;
  	Linux_DnsSlaveZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsSlaveZoneInstanceNameEnumerationElement();
  	~Linux_DnsSlaveZoneInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsSlaveZoneInstanceNameEnumeration {
  	private:
  	  Linux_DnsSlaveZoneInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsSlaveZoneInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsSlaveZoneInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSlaveZoneInstanceNameEnumeration();
  	  
  	  Linux_DnsSlaveZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsSlaveZoneInstanceNameEnumeration(
  	   const Linux_DnsSlaveZoneInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsSlaveZoneInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSlaveZoneInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSlaveZoneInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsSlaveZoneInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

