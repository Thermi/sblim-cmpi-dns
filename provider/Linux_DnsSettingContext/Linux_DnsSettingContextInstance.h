 /**
 * Linux_DnsSettingContextInstance.h
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
#ifndef Linux_DnsSettingContextInstance_h
#define Linux_DnsSettingContextInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingContextInstanceName.h"

namespace genProvider {

  class Linux_DnsSettingContextInstance {
  public:
       Linux_DnsSettingContextInstance();
  	
       Linux_DnsSettingContextInstance
  	    (const Linux_DnsSettingContextInstance& original);
  	   
       Linux_DnsSettingContextInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsSettingContextInstance();
       
       Linux_DnsSettingContextInstance& operator=
  	    (const Linux_DnsSettingContextInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsSettingContextInstanceName& val);        
       const Linux_DnsSettingContextInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsSettingContextInstance& original);
       void reset();
       
       Linux_DnsSettingContextInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsSettingContextInstanceEnumerationElement{
  	Linux_DnsSettingContextInstance* m_elementP;
  	Linux_DnsSettingContextInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingContextInstanceEnumerationElement();
  	~Linux_DnsSettingContextInstanceEnumerationElement();  	
  };
  

  class Linux_DnsSettingContextInstanceEnumeration {
  	private:
  	  Linux_DnsSettingContextInstanceEnumerationElement* firstElementP;
  	  Linux_DnsSettingContextInstanceEnumerationElement* currentElementP;
  	  Linux_DnsSettingContextInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSettingContextInstanceEnumeration();
  	  
  	  Linux_DnsSettingContextInstanceEnumeration(
  	   const Linux_DnsSettingContextInstanceEnumeration& original);
  	  
  	  ~Linux_DnsSettingContextInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSettingContextInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSettingContextInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsSettingContextInstance& elementP);
  };
}
#endif

