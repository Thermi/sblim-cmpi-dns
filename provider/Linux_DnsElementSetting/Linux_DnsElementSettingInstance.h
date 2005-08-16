 /**
 * Linux_DnsElementSettingInstance.h
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
#ifndef Linux_DnsElementSettingInstance_h
#define Linux_DnsElementSettingInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsElementSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsElementSettingInstance {
  public:
       Linux_DnsElementSettingInstance();
  	
       Linux_DnsElementSettingInstance
  	    (const Linux_DnsElementSettingInstance& original);
  	   
       Linux_DnsElementSettingInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsElementSettingInstance();
       
       Linux_DnsElementSettingInstance& operator=
  	    (const Linux_DnsElementSettingInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsElementSettingInstanceName& val);        
       const Linux_DnsElementSettingInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsElementSettingInstance& original);
       void reset();
       
       Linux_DnsElementSettingInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsElementSettingInstanceEnumerationElement{
  	Linux_DnsElementSettingInstance* m_elementP;
  	Linux_DnsElementSettingInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsElementSettingInstanceEnumerationElement();
  	~Linux_DnsElementSettingInstanceEnumerationElement();  	
  };
  

  class Linux_DnsElementSettingInstanceEnumeration {
  	private:
  	  Linux_DnsElementSettingInstanceEnumerationElement* firstElementP;
  	  Linux_DnsElementSettingInstanceEnumerationElement* currentElementP;
  	  Linux_DnsElementSettingInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsElementSettingInstanceEnumeration();
  	  
  	  Linux_DnsElementSettingInstanceEnumeration(
  	   const Linux_DnsElementSettingInstanceEnumeration& original);
  	  
  	  ~Linux_DnsElementSettingInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsElementSettingInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsElementSettingInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsElementSettingInstance& elementP);
  };
}
#endif

