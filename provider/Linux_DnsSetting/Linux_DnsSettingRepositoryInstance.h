 /**
 * Linux_DnsSettingRepositoryInstance.h
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
#ifndef Linux_DnsSettingRepositoryInstance_h
#define Linux_DnsSettingRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsSettingRepositoryInstance {
  public:
       Linux_DnsSettingRepositoryInstance();
  	
       Linux_DnsSettingRepositoryInstance
  	    (const Linux_DnsSettingRepositoryInstance& original);
  	   
       Linux_DnsSettingRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsSettingRepositoryInstance();
       
       Linux_DnsSettingRepositoryInstance& operator=
  	    (const Linux_DnsSettingRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsSettingInstanceName& val);        
       const Linux_DnsSettingInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsSettingRepositoryInstance& original);
       void reset();
       
       Linux_DnsSettingInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsSettingRepositoryInstanceEnumerationElement{
  	Linux_DnsSettingRepositoryInstance* m_elementP;
  	Linux_DnsSettingRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingRepositoryInstanceEnumerationElement();
  	~Linux_DnsSettingRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsSettingRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsSettingRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsSettingRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsSettingRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSettingRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsSettingRepositoryInstanceEnumeration(
  	   const Linux_DnsSettingRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsSettingRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSettingRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSettingRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsSettingRepositoryInstance& elementP);
  };
}
#endif

