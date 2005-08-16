 /**
 * Linux_DnsServiceConfigurationManualInstance.h
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
#ifndef Linux_DnsServiceConfigurationManualInstance_h
#define Linux_DnsServiceConfigurationManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationInstanceName.h"

namespace genProvider {

  class Linux_DnsServiceConfigurationManualInstance {
  public:
       Linux_DnsServiceConfigurationManualInstance();
  	
       Linux_DnsServiceConfigurationManualInstance
  	    (const Linux_DnsServiceConfigurationManualInstance& original);
  	   
       Linux_DnsServiceConfigurationManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsServiceConfigurationManualInstance();
       
       Linux_DnsServiceConfigurationManualInstance& operator=
  	    (const Linux_DnsServiceConfigurationManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsServiceConfigurationInstanceName& val);        
       const Linux_DnsServiceConfigurationInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsServiceConfigurationManualInstance& original);
       void reset();
       
       Linux_DnsServiceConfigurationInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsServiceConfigurationManualInstanceEnumerationElement{
  	Linux_DnsServiceConfigurationManualInstance* m_elementP;
  	Linux_DnsServiceConfigurationManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceConfigurationManualInstanceEnumerationElement();
  	~Linux_DnsServiceConfigurationManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsServiceConfigurationManualInstanceEnumeration {
  	private:
  	  Linux_DnsServiceConfigurationManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsServiceConfigurationManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsServiceConfigurationManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsServiceConfigurationManualInstanceEnumeration();
  	  
  	  Linux_DnsServiceConfigurationManualInstanceEnumeration(
  	   const Linux_DnsServiceConfigurationManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsServiceConfigurationManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsServiceConfigurationManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsServiceConfigurationManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsServiceConfigurationManualInstance& elementP);
  };
}
#endif

