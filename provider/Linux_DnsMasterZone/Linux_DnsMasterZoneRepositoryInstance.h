 /**
 * Linux_DnsMasterZoneRepositoryInstance.h
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
#ifndef Linux_DnsMasterZoneRepositoryInstance_h
#define Linux_DnsMasterZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMasterZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsMasterZoneRepositoryInstance {
  public:
       Linux_DnsMasterZoneRepositoryInstance();
  	
       Linux_DnsMasterZoneRepositoryInstance
  	    (const Linux_DnsMasterZoneRepositoryInstance& original);
  	   
       Linux_DnsMasterZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsMasterZoneRepositoryInstance();
       
       Linux_DnsMasterZoneRepositoryInstance& operator=
  	    (const Linux_DnsMasterZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsMasterZoneInstanceName& val);        
       const Linux_DnsMasterZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsMasterZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsMasterZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsMasterZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsMasterZoneRepositoryInstance* m_elementP;
  	Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsMasterZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsMasterZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsMasterZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsMasterZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsMasterZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsMasterZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsMasterZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsMasterZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsMasterZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsMasterZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsMasterZoneRepositoryInstance& elementP);
  };
}
#endif

