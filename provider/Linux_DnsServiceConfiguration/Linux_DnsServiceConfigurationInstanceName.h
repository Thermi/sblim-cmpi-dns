 /**
 * Linux_DnsServiceConfigurationInstanceName.h
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
#ifndef Linux_DnsServiceConfigurationInstanceName_h
#define Linux_DnsServiceConfigurationInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsConfigurationInstanceName.h"

namespace genProvider {

  class Linux_DnsServiceConfigurationInstanceName {
  public:
       Linux_DnsServiceConfigurationInstanceName();
  	
       Linux_DnsServiceConfigurationInstanceName
  	    (const Linux_DnsServiceConfigurationInstanceName& original);
  	   
       Linux_DnsServiceConfigurationInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsServiceConfigurationInstanceName();
       
       Linux_DnsServiceConfigurationInstanceName& operator=
  	    (const Linux_DnsServiceConfigurationInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isElementSet() const;
       void setElement(const Linux_DnsServiceInstanceName& val);
       const Linux_DnsServiceInstanceName& getElement() const;

       unsigned int isConfigurationSet() const;
       void setConfiguration(const Linux_DnsConfigurationInstanceName& val);
       const Linux_DnsConfigurationInstanceName& getConfiguration() const;
       
  private:
       void init();
       void init(const Linux_DnsServiceConfigurationInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       Linux_DnsServiceInstanceName m_Element;
       Linux_DnsConfigurationInstanceName m_Configuration;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Element:1;
         unsigned int Configuration:1;
       } isSet;
  };
  
  
  struct Linux_DnsServiceConfigurationInstanceNameEnumerationElement{
  	Linux_DnsServiceConfigurationInstanceName* m_elementP;
  	Linux_DnsServiceConfigurationInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceConfigurationInstanceNameEnumerationElement();
  	~Linux_DnsServiceConfigurationInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsServiceConfigurationInstanceNameEnumeration {
  	private:
  	  Linux_DnsServiceConfigurationInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsServiceConfigurationInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsServiceConfigurationInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsServiceConfigurationInstanceNameEnumeration();
  	  
  	  Linux_DnsServiceConfigurationInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsServiceConfigurationInstanceNameEnumeration(
  	   const Linux_DnsServiceConfigurationInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsServiceConfigurationInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsServiceConfigurationInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsServiceConfigurationInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsServiceConfigurationInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

