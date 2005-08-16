 /**
 * Linux_DnsServiceConfigurationInstance.h
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
#ifndef Linux_DnsServiceConfigurationInstance_h
#define Linux_DnsServiceConfigurationInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationInstanceName.h"

namespace genProvider {

  class Linux_DnsServiceConfigurationInstance {
  public:
       Linux_DnsServiceConfigurationInstance();
  	
       Linux_DnsServiceConfigurationInstance
  	    (const Linux_DnsServiceConfigurationInstance& original);
  	   
       Linux_DnsServiceConfigurationInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsServiceConfigurationInstance();
       
       Linux_DnsServiceConfigurationInstance& operator=
  	    (const Linux_DnsServiceConfigurationInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsServiceConfigurationInstanceName& val);        
       const Linux_DnsServiceConfigurationInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsServiceConfigurationInstance& original);
       void reset();
       
       Linux_DnsServiceConfigurationInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsServiceConfigurationInstanceEnumerationElement{
  	Linux_DnsServiceConfigurationInstance* m_elementP;
  	Linux_DnsServiceConfigurationInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceConfigurationInstanceEnumerationElement();
  	~Linux_DnsServiceConfigurationInstanceEnumerationElement();  	
  };
  

  class Linux_DnsServiceConfigurationInstanceEnumeration {
  	private:
  	  Linux_DnsServiceConfigurationInstanceEnumerationElement* firstElementP;
  	  Linux_DnsServiceConfigurationInstanceEnumerationElement* currentElementP;
  	  Linux_DnsServiceConfigurationInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsServiceConfigurationInstanceEnumeration();
  	  
  	  Linux_DnsServiceConfigurationInstanceEnumeration(
  	   const Linux_DnsServiceConfigurationInstanceEnumeration& original);
  	  
  	  ~Linux_DnsServiceConfigurationInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsServiceConfigurationInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsServiceConfigurationInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsServiceConfigurationInstance& elementP);
  };
}
#endif

