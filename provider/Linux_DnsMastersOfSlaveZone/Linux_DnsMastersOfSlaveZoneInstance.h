 /**
 * Linux_DnsMastersOfSlaveZoneInstance.h
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
#ifndef Linux_DnsMastersOfSlaveZoneInstance_h
#define Linux_DnsMastersOfSlaveZoneInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneInstance {
  public:
       Linux_DnsMastersOfSlaveZoneInstance();
  	
       Linux_DnsMastersOfSlaveZoneInstance
  	    (const Linux_DnsMastersOfSlaveZoneInstance& original);
  	   
       Linux_DnsMastersOfSlaveZoneInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsMastersOfSlaveZoneInstance();
       
       Linux_DnsMastersOfSlaveZoneInstance& operator=
  	    (const Linux_DnsMastersOfSlaveZoneInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsMastersOfSlaveZoneInstanceName& val);        
       const Linux_DnsMastersOfSlaveZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsMastersOfSlaveZoneInstance& original);
       void reset();
       
       Linux_DnsMastersOfSlaveZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement{
  	Linux_DnsMastersOfSlaveZoneInstance* m_elementP;
  	Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement();
  	~Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement();  	
  };
  

  class Linux_DnsMastersOfSlaveZoneInstanceEnumeration {
  	private:
  	  Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* firstElementP;
  	  Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* currentElementP;
  	  Linux_DnsMastersOfSlaveZoneInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsMastersOfSlaveZoneInstanceEnumeration();
  	  
  	  Linux_DnsMastersOfSlaveZoneInstanceEnumeration(
  	   const Linux_DnsMastersOfSlaveZoneInstanceEnumeration& original);
  	  
  	  ~Linux_DnsMastersOfSlaveZoneInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsMastersOfSlaveZoneInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsMastersOfSlaveZoneInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsMastersOfSlaveZoneInstance& elementP);
  };
}
#endif

