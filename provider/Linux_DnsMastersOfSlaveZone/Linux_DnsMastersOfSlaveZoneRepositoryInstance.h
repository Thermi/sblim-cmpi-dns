 /**
 * Linux_DnsMastersOfSlaveZoneRepositoryInstance.h
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
#ifndef Linux_DnsMastersOfSlaveZoneRepositoryInstance_h
#define Linux_DnsMastersOfSlaveZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneRepositoryInstance {
  public:
       Linux_DnsMastersOfSlaveZoneRepositoryInstance();
  	
       Linux_DnsMastersOfSlaveZoneRepositoryInstance
  	    (const Linux_DnsMastersOfSlaveZoneRepositoryInstance& original);
  	   
       Linux_DnsMastersOfSlaveZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsMastersOfSlaveZoneRepositoryInstance();
       
       Linux_DnsMastersOfSlaveZoneRepositoryInstance& operator=
  	    (const Linux_DnsMastersOfSlaveZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsMastersOfSlaveZoneInstanceName& val);        
       const Linux_DnsMastersOfSlaveZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsMastersOfSlaveZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsMastersOfSlaveZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsMastersOfSlaveZoneRepositoryInstance* m_elementP;
  	Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsMastersOfSlaveZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsMastersOfSlaveZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsMastersOfSlaveZoneRepositoryInstance& elementP);
  };
}
#endif

