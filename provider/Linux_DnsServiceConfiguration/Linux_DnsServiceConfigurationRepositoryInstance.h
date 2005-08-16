 /**
 * Linux_DnsServiceConfigurationRepositoryInstance.h
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
#ifndef Linux_DnsServiceConfigurationRepositoryInstance_h
#define Linux_DnsServiceConfigurationRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationInstanceName.h"

namespace genProvider {

  class Linux_DnsServiceConfigurationRepositoryInstance {
  public:
       Linux_DnsServiceConfigurationRepositoryInstance();
  	
       Linux_DnsServiceConfigurationRepositoryInstance
  	    (const Linux_DnsServiceConfigurationRepositoryInstance& original);
  	   
       Linux_DnsServiceConfigurationRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsServiceConfigurationRepositoryInstance();
       
       Linux_DnsServiceConfigurationRepositoryInstance& operator=
  	    (const Linux_DnsServiceConfigurationRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsServiceConfigurationInstanceName& val);        
       const Linux_DnsServiceConfigurationInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsServiceConfigurationRepositoryInstance& original);
       void reset();
       
       Linux_DnsServiceConfigurationInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement{
  	Linux_DnsServiceConfigurationRepositoryInstance* m_elementP;
  	Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement();
  	~Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsServiceConfigurationRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsServiceConfigurationRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsServiceConfigurationRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsServiceConfigurationRepositoryInstanceEnumeration(
  	   const Linux_DnsServiceConfigurationRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsServiceConfigurationRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsServiceConfigurationRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsServiceConfigurationRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsServiceConfigurationRepositoryInstance& elementP);
  };
}
#endif

