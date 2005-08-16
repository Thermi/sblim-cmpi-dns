 /**
 * Linux_DnsConfigurationRepositoryInstance.h
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
#ifndef Linux_DnsConfigurationRepositoryInstance_h
#define Linux_DnsConfigurationRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsConfigurationInstanceName.h"

namespace genProvider {

  class Linux_DnsConfigurationRepositoryInstance {
  public:
       Linux_DnsConfigurationRepositoryInstance();
  	
       Linux_DnsConfigurationRepositoryInstance
  	    (const Linux_DnsConfigurationRepositoryInstance& original);
  	   
       Linux_DnsConfigurationRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsConfigurationRepositoryInstance();
       
       Linux_DnsConfigurationRepositoryInstance& operator=
  	    (const Linux_DnsConfigurationRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsConfigurationInstanceName& val);        
       const Linux_DnsConfigurationInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsConfigurationRepositoryInstance& original);
       void reset();
       
       Linux_DnsConfigurationInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsConfigurationRepositoryInstanceEnumerationElement{
  	Linux_DnsConfigurationRepositoryInstance* m_elementP;
  	Linux_DnsConfigurationRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsConfigurationRepositoryInstanceEnumerationElement();
  	~Linux_DnsConfigurationRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsConfigurationRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsConfigurationRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsConfigurationRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsConfigurationRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsConfigurationRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsConfigurationRepositoryInstanceEnumeration(
  	   const Linux_DnsConfigurationRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsConfigurationRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsConfigurationRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsConfigurationRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsConfigurationRepositoryInstance& elementP);
  };
}
#endif

