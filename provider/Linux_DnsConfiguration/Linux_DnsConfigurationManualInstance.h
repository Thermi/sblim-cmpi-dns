 /**
 * Linux_DnsConfigurationManualInstance.h
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
#ifndef Linux_DnsConfigurationManualInstance_h
#define Linux_DnsConfigurationManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsConfigurationInstanceName.h"

namespace genProvider {

  class Linux_DnsConfigurationManualInstance {
  public:
       Linux_DnsConfigurationManualInstance();
  	
       Linux_DnsConfigurationManualInstance
  	    (const Linux_DnsConfigurationManualInstance& original);
  	   
       Linux_DnsConfigurationManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsConfigurationManualInstance();
       
       Linux_DnsConfigurationManualInstance& operator=
  	    (const Linux_DnsConfigurationManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsConfigurationInstanceName& val);        
       const Linux_DnsConfigurationInstanceName&
        getInstanceName() const;

       unsigned int isConfigurationFileSet() const;
       void setConfigurationFile(const char* val, int makeCopy = 1);
       const char* getConfigurationFile() const;
       
  private:
       void init();
       void init(const Linux_DnsConfigurationManualInstance& original);
       void reset();
       
       Linux_DnsConfigurationInstanceName m_instanceName;
       const char* m_ConfigurationFile;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int ConfigurationFile:1;
       } isSet;
  };
  
  
  struct Linux_DnsConfigurationManualInstanceEnumerationElement{
  	Linux_DnsConfigurationManualInstance* m_elementP;
  	Linux_DnsConfigurationManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsConfigurationManualInstanceEnumerationElement();
  	~Linux_DnsConfigurationManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsConfigurationManualInstanceEnumeration {
  	private:
  	  Linux_DnsConfigurationManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsConfigurationManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsConfigurationManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsConfigurationManualInstanceEnumeration();
  	  
  	  Linux_DnsConfigurationManualInstanceEnumeration(
  	   const Linux_DnsConfigurationManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsConfigurationManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsConfigurationManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsConfigurationManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsConfigurationManualInstance& elementP);
  };
}
#endif

