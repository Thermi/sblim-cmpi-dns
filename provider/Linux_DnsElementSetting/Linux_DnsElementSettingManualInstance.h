 /**
 * Linux_DnsElementSettingManualInstance.h
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
#ifndef Linux_DnsElementSettingManualInstance_h
#define Linux_DnsElementSettingManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsElementSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsElementSettingManualInstance {
  public:
       Linux_DnsElementSettingManualInstance();
  	
       Linux_DnsElementSettingManualInstance
  	    (const Linux_DnsElementSettingManualInstance& original);
  	   
       Linux_DnsElementSettingManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsElementSettingManualInstance();
       
       Linux_DnsElementSettingManualInstance& operator=
  	    (const Linux_DnsElementSettingManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsElementSettingInstanceName& val);        
       const Linux_DnsElementSettingInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsElementSettingManualInstance& original);
       void reset();
       
       Linux_DnsElementSettingInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsElementSettingManualInstanceEnumerationElement{
  	Linux_DnsElementSettingManualInstance* m_elementP;
  	Linux_DnsElementSettingManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsElementSettingManualInstanceEnumerationElement();
  	~Linux_DnsElementSettingManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsElementSettingManualInstanceEnumeration {
  	private:
  	  Linux_DnsElementSettingManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsElementSettingManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsElementSettingManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsElementSettingManualInstanceEnumeration();
  	  
  	  Linux_DnsElementSettingManualInstanceEnumeration(
  	   const Linux_DnsElementSettingManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsElementSettingManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsElementSettingManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsElementSettingManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsElementSettingManualInstance& elementP);
  };
}
#endif

