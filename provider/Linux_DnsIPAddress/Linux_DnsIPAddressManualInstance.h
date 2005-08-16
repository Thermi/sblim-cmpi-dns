 /**
 * Linux_DnsIPAddressManualInstance.h
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
#ifndef Linux_DnsIPAddressManualInstance_h
#define Linux_DnsIPAddressManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsIPAddressInstanceName.h"

namespace genProvider {

  class Linux_DnsIPAddressManualInstance {
  public:
       Linux_DnsIPAddressManualInstance();
  	
       Linux_DnsIPAddressManualInstance
  	    (const Linux_DnsIPAddressManualInstance& original);
  	   
       Linux_DnsIPAddressManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsIPAddressManualInstance();
       
       Linux_DnsIPAddressManualInstance& operator=
  	    (const Linux_DnsIPAddressManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsIPAddressInstanceName& val);        
       const Linux_DnsIPAddressInstanceName&
        getInstanceName() const;

       unsigned int isPortSet() const;
       void setPort(const CMPIUint32 val);
       const CMPIUint32 getPort() const;

       unsigned int isSecurityKeySet() const;
       void setSecurityKey(const char* val, int makeCopy = 1);
       const char* getSecurityKey() const;
       
  private:
       void init();
       void init(const Linux_DnsIPAddressManualInstance& original);
       void reset();
       
       Linux_DnsIPAddressInstanceName m_instanceName;
       CMPIUint32 m_Port;
       const char* m_SecurityKey;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Port:1;
         unsigned int SecurityKey:1;
       } isSet;
  };
  
  
  struct Linux_DnsIPAddressManualInstanceEnumerationElement{
  	Linux_DnsIPAddressManualInstance* m_elementP;
  	Linux_DnsIPAddressManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsIPAddressManualInstanceEnumerationElement();
  	~Linux_DnsIPAddressManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsIPAddressManualInstanceEnumeration {
  	private:
  	  Linux_DnsIPAddressManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsIPAddressManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsIPAddressManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsIPAddressManualInstanceEnumeration();
  	  
  	  Linux_DnsIPAddressManualInstanceEnumeration(
  	   const Linux_DnsIPAddressManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsIPAddressManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsIPAddressManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsIPAddressManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsIPAddressManualInstance& elementP);
  };
}
#endif

