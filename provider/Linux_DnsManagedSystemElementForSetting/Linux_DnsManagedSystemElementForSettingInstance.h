 /**
 * Linux_DnsManagedSystemElementForSettingInstance.h
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
#ifndef Linux_DnsManagedSystemElementForSettingInstance_h
#define Linux_DnsManagedSystemElementForSettingInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsManagedSystemElementForSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingInstance {
  public:
       Linux_DnsManagedSystemElementForSettingInstance();
  	
       Linux_DnsManagedSystemElementForSettingInstance
  	    (const Linux_DnsManagedSystemElementForSettingInstance& original);
  	   
       Linux_DnsManagedSystemElementForSettingInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsManagedSystemElementForSettingInstance();
       
       Linux_DnsManagedSystemElementForSettingInstance& operator=
  	    (const Linux_DnsManagedSystemElementForSettingInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsManagedSystemElementForSettingInstanceName& val);        
       const Linux_DnsManagedSystemElementForSettingInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsManagedSystemElementForSettingInstance& original);
       void reset();
       
       Linux_DnsManagedSystemElementForSettingInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement{
  	Linux_DnsManagedSystemElementForSettingInstance* m_elementP;
  	Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement();
  	~Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement();  	
  };
  

  class Linux_DnsManagedSystemElementForSettingInstanceEnumeration {
  	private:
  	  Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* firstElementP;
  	  Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* currentElementP;
  	  Linux_DnsManagedSystemElementForSettingInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsManagedSystemElementForSettingInstanceEnumeration();
  	  
  	  Linux_DnsManagedSystemElementForSettingInstanceEnumeration(
  	   const Linux_DnsManagedSystemElementForSettingInstanceEnumeration& original);
  	  
  	  ~Linux_DnsManagedSystemElementForSettingInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsManagedSystemElementForSettingInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsManagedSystemElementForSettingInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsManagedSystemElementForSettingInstance& elementP);
  };
}
#endif

