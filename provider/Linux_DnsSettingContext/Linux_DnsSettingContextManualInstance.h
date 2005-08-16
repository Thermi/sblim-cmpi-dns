 /**
 * Linux_DnsSettingContextManualInstance.h
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
#ifndef Linux_DnsSettingContextManualInstance_h
#define Linux_DnsSettingContextManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingContextInstanceName.h"

namespace genProvider {

  class Linux_DnsSettingContextManualInstance {
  public:
       Linux_DnsSettingContextManualInstance();
  	
       Linux_DnsSettingContextManualInstance
  	    (const Linux_DnsSettingContextManualInstance& original);
  	   
       Linux_DnsSettingContextManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsSettingContextManualInstance();
       
       Linux_DnsSettingContextManualInstance& operator=
  	    (const Linux_DnsSettingContextManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsSettingContextInstanceName& val);        
       const Linux_DnsSettingContextInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsSettingContextManualInstance& original);
       void reset();
       
       Linux_DnsSettingContextInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsSettingContextManualInstanceEnumerationElement{
  	Linux_DnsSettingContextManualInstance* m_elementP;
  	Linux_DnsSettingContextManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingContextManualInstanceEnumerationElement();
  	~Linux_DnsSettingContextManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsSettingContextManualInstanceEnumeration {
  	private:
  	  Linux_DnsSettingContextManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsSettingContextManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsSettingContextManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSettingContextManualInstanceEnumeration();
  	  
  	  Linux_DnsSettingContextManualInstanceEnumeration(
  	   const Linux_DnsSettingContextManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsSettingContextManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSettingContextManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSettingContextManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsSettingContextManualInstance& elementP);
  };
}
#endif

