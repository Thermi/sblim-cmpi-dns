 /**
 * Linux_DnsIPAddressRepositoryInstance.h
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
#ifndef Linux_DnsIPAddressRepositoryInstance_h
#define Linux_DnsIPAddressRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsIPAddressInstanceName.h"

namespace genProvider {

  class Linux_DnsIPAddressRepositoryInstance {
  public:
       Linux_DnsIPAddressRepositoryInstance();
  	
       Linux_DnsIPAddressRepositoryInstance
  	    (const Linux_DnsIPAddressRepositoryInstance& original);
  	   
       Linux_DnsIPAddressRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsIPAddressRepositoryInstance();
       
       Linux_DnsIPAddressRepositoryInstance& operator=
  	    (const Linux_DnsIPAddressRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsIPAddressInstanceName& val);        
       const Linux_DnsIPAddressInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsIPAddressRepositoryInstance& original);
       void reset();
       
       Linux_DnsIPAddressInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsIPAddressRepositoryInstanceEnumerationElement{
  	Linux_DnsIPAddressRepositoryInstance* m_elementP;
  	Linux_DnsIPAddressRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsIPAddressRepositoryInstanceEnumerationElement();
  	~Linux_DnsIPAddressRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsIPAddressRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsIPAddressRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsIPAddressRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsIPAddressRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsIPAddressRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsIPAddressRepositoryInstanceEnumeration(
  	   const Linux_DnsIPAddressRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsIPAddressRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsIPAddressRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsIPAddressRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsIPAddressRepositoryInstance& elementP);
  };
}
#endif

