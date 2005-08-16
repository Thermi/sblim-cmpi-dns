 /**
 * Linux_DnsManagedSystemElementForSettingManualInstance.h
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
#ifndef Linux_DnsManagedSystemElementForSettingManualInstance_h
#define Linux_DnsManagedSystemElementForSettingManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsManagedSystemElementForSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingManualInstance {
  public:
       Linux_DnsManagedSystemElementForSettingManualInstance();
  	
       Linux_DnsManagedSystemElementForSettingManualInstance
  	    (const Linux_DnsManagedSystemElementForSettingManualInstance& original);
  	   
       Linux_DnsManagedSystemElementForSettingManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsManagedSystemElementForSettingManualInstance();
       
       Linux_DnsManagedSystemElementForSettingManualInstance& operator=
  	    (const Linux_DnsManagedSystemElementForSettingManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsManagedSystemElementForSettingInstanceName& val);        
       const Linux_DnsManagedSystemElementForSettingInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsManagedSystemElementForSettingManualInstance& original);
       void reset();
       
       Linux_DnsManagedSystemElementForSettingInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement{
  	Linux_DnsManagedSystemElementForSettingManualInstance* m_elementP;
  	Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement();
  	~Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration {
  	private:
  	  Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsManagedSystemElementForSettingManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration();
  	  
  	  Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration(
  	   const Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsManagedSystemElementForSettingManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsManagedSystemElementForSettingManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsManagedSystemElementForSettingManualInstance& elementP);
  };
}
#endif

