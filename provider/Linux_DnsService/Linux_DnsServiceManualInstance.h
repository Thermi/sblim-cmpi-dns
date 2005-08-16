 /**
 * Linux_DnsServiceManualInstance.h
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
#ifndef Linux_DnsServiceManualInstance_h
#define Linux_DnsServiceManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsServiceManualInstance {
  public:
       Linux_DnsServiceManualInstance();
  	
       Linux_DnsServiceManualInstance
  	    (const Linux_DnsServiceManualInstance& original);
  	   
       Linux_DnsServiceManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsServiceManualInstance();
       
       Linux_DnsServiceManualInstance& operator=
  	    (const Linux_DnsServiceManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsServiceInstanceName& val);        
       const Linux_DnsServiceInstanceName&
        getInstanceName() const;

       unsigned int isRunAsRootSet() const;
       void setRunAsRoot(const CMPIBoolean val);
       const CMPIBoolean getRunAsRoot() const;

       unsigned int isStartedSet() const;
       void setStarted(const CMPIBoolean val);
       const CMPIBoolean getStarted() const;
       
  private:
       void init();
       void init(const Linux_DnsServiceManualInstance& original);
       void reset();
       
       Linux_DnsServiceInstanceName m_instanceName;
       CMPIBoolean m_RunAsRoot;
       CMPIBoolean m_Started;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int RunAsRoot:1;
         unsigned int Started:1;
       } isSet;
  };
  
  
  struct Linux_DnsServiceManualInstanceEnumerationElement{
  	Linux_DnsServiceManualInstance* m_elementP;
  	Linux_DnsServiceManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceManualInstanceEnumerationElement();
  	~Linux_DnsServiceManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsServiceManualInstanceEnumeration {
  	private:
  	  Linux_DnsServiceManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsServiceManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsServiceManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsServiceManualInstanceEnumeration();
  	  
  	  Linux_DnsServiceManualInstanceEnumeration(
  	   const Linux_DnsServiceManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsServiceManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsServiceManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsServiceManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsServiceManualInstance& elementP);
  };
}
#endif

