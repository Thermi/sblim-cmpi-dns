 /**
 * Linux_DnsElementSettingRepositoryInstance.h
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
#ifndef Linux_DnsElementSettingRepositoryInstance_h
#define Linux_DnsElementSettingRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsElementSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsElementSettingRepositoryInstance {
  public:
       Linux_DnsElementSettingRepositoryInstance();
  	
       Linux_DnsElementSettingRepositoryInstance
  	    (const Linux_DnsElementSettingRepositoryInstance& original);
  	   
       Linux_DnsElementSettingRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsElementSettingRepositoryInstance();
       
       Linux_DnsElementSettingRepositoryInstance& operator=
  	    (const Linux_DnsElementSettingRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsElementSettingInstanceName& val);        
       const Linux_DnsElementSettingInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsElementSettingRepositoryInstance& original);
       void reset();
       
       Linux_DnsElementSettingInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsElementSettingRepositoryInstanceEnumerationElement{
  	Linux_DnsElementSettingRepositoryInstance* m_elementP;
  	Linux_DnsElementSettingRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsElementSettingRepositoryInstanceEnumerationElement();
  	~Linux_DnsElementSettingRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsElementSettingRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsElementSettingRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsElementSettingRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsElementSettingRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsElementSettingRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsElementSettingRepositoryInstanceEnumeration(
  	   const Linux_DnsElementSettingRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsElementSettingRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsElementSettingRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsElementSettingRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsElementSettingRepositoryInstance& elementP);
  };
}
#endif

