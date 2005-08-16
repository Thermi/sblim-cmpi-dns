 /**
 * Linux_DnsMastersOfSlaveZoneManualInstance.h
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
#ifndef Linux_DnsMastersOfSlaveZoneManualInstance_h
#define Linux_DnsMastersOfSlaveZoneManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneManualInstance {
  public:
       Linux_DnsMastersOfSlaveZoneManualInstance();
  	
       Linux_DnsMastersOfSlaveZoneManualInstance
  	    (const Linux_DnsMastersOfSlaveZoneManualInstance& original);
  	   
       Linux_DnsMastersOfSlaveZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsMastersOfSlaveZoneManualInstance();
       
       Linux_DnsMastersOfSlaveZoneManualInstance& operator=
  	    (const Linux_DnsMastersOfSlaveZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsMastersOfSlaveZoneInstanceName& val);        
       const Linux_DnsMastersOfSlaveZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsMastersOfSlaveZoneManualInstance& original);
       void reset();
       
       Linux_DnsMastersOfSlaveZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement{
  	Linux_DnsMastersOfSlaveZoneManualInstance* m_elementP;
  	Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement();
  	~Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsMastersOfSlaveZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration(
  	   const Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsMastersOfSlaveZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsMastersOfSlaveZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsMastersOfSlaveZoneManualInstance& elementP);
  };
}
#endif

