 /**
 * Linux_DnsManagedSystemElementForSettingRepositoryInstance.h
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
#ifndef Linux_DnsManagedSystemElementForSettingRepositoryInstance_h
#define Linux_DnsManagedSystemElementForSettingRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsManagedSystemElementForSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingRepositoryInstance {
  public:
       Linux_DnsManagedSystemElementForSettingRepositoryInstance();
  	
       Linux_DnsManagedSystemElementForSettingRepositoryInstance
  	    (const Linux_DnsManagedSystemElementForSettingRepositoryInstance& original);
  	   
       Linux_DnsManagedSystemElementForSettingRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsManagedSystemElementForSettingRepositoryInstance();
       
       Linux_DnsManagedSystemElementForSettingRepositoryInstance& operator=
  	    (const Linux_DnsManagedSystemElementForSettingRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsManagedSystemElementForSettingInstanceName& val);        
       const Linux_DnsManagedSystemElementForSettingInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsManagedSystemElementForSettingRepositoryInstance& original);
       void reset();
       
       Linux_DnsManagedSystemElementForSettingInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement{
  	Linux_DnsManagedSystemElementForSettingRepositoryInstance* m_elementP;
  	Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement();
  	~Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration(
  	   const Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsManagedSystemElementForSettingRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsManagedSystemElementForSettingRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsManagedSystemElementForSettingRepositoryInstance& elementP);
  };
}
#endif

