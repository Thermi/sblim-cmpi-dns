 /**
 * Linux_DnsSettingContextRepositoryInstance.h
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
#ifndef Linux_DnsSettingContextRepositoryInstance_h
#define Linux_DnsSettingContextRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingContextInstanceName.h"

namespace genProvider {

  class Linux_DnsSettingContextRepositoryInstance {
  public:
       Linux_DnsSettingContextRepositoryInstance();
  	
       Linux_DnsSettingContextRepositoryInstance
  	    (const Linux_DnsSettingContextRepositoryInstance& original);
  	   
       Linux_DnsSettingContextRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsSettingContextRepositoryInstance();
       
       Linux_DnsSettingContextRepositoryInstance& operator=
  	    (const Linux_DnsSettingContextRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsSettingContextInstanceName& val);        
       const Linux_DnsSettingContextInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsSettingContextRepositoryInstance& original);
       void reset();
       
       Linux_DnsSettingContextInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsSettingContextRepositoryInstanceEnumerationElement{
  	Linux_DnsSettingContextRepositoryInstance* m_elementP;
  	Linux_DnsSettingContextRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingContextRepositoryInstanceEnumerationElement();
  	~Linux_DnsSettingContextRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsSettingContextRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsSettingContextRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsSettingContextRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsSettingContextRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSettingContextRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsSettingContextRepositoryInstanceEnumeration(
  	   const Linux_DnsSettingContextRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsSettingContextRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSettingContextRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSettingContextRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsSettingContextRepositoryInstance& elementP);
  };
}
#endif

