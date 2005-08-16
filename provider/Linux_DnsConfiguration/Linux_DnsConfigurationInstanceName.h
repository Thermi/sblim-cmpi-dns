 /**
 * Linux_DnsConfigurationInstanceName.h
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
#ifndef Linux_DnsConfigurationInstanceName_h
#define Linux_DnsConfigurationInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"

namespace genProvider {

  class Linux_DnsConfigurationInstanceName {
  public:
       Linux_DnsConfigurationInstanceName();
  	
       Linux_DnsConfigurationInstanceName
  	    (const Linux_DnsConfigurationInstanceName& original);
  	   
       Linux_DnsConfigurationInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsConfigurationInstanceName();
       
       Linux_DnsConfigurationInstanceName& operator=
  	    (const Linux_DnsConfigurationInstanceName& original);
       
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
       void init(const Linux_DnsConfigurationInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_Name;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Name:1;
       } isSet;
  };
  
  
  struct Linux_DnsConfigurationInstanceNameEnumerationElement{
  	Linux_DnsConfigurationInstanceName* m_elementP;
  	Linux_DnsConfigurationInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsConfigurationInstanceNameEnumerationElement();
  	~Linux_DnsConfigurationInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsConfigurationInstanceNameEnumeration {
  	private:
  	  Linux_DnsConfigurationInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsConfigurationInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsConfigurationInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsConfigurationInstanceNameEnumeration();
  	  
  	  Linux_DnsConfigurationInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsConfigurationInstanceNameEnumeration(
  	   const Linux_DnsConfigurationInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsConfigurationInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsConfigurationInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsConfigurationInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsConfigurationInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

