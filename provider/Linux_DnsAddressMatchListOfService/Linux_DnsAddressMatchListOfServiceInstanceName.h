 /**
 * Linux_DnsAddressMatchListOfServiceInstanceName.h
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
#ifndef Linux_DnsAddressMatchListOfServiceInstanceName_h
#define Linux_DnsAddressMatchListOfServiceInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsAddressMatchListInstanceName.h"

namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceInstanceName {
  public:
       Linux_DnsAddressMatchListOfServiceInstanceName();
  	
       Linux_DnsAddressMatchListOfServiceInstanceName
  	    (const Linux_DnsAddressMatchListOfServiceInstanceName& original);
  	   
       Linux_DnsAddressMatchListOfServiceInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsAddressMatchListOfServiceInstanceName();
       
       Linux_DnsAddressMatchListOfServiceInstanceName& operator=
  	    (const Linux_DnsAddressMatchListOfServiceInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isAntecedentSet() const;
       void setAntecedent(const Linux_DnsServiceInstanceName& val);
       const Linux_DnsServiceInstanceName& getAntecedent() const;

       unsigned int isDependentSet() const;
       void setDependent(const Linux_DnsAddressMatchListInstanceName& val);
       const Linux_DnsAddressMatchListInstanceName& getDependent() const;
       
  private:
       void init();
       void init(const Linux_DnsAddressMatchListOfServiceInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       Linux_DnsServiceInstanceName m_Antecedent;
       Linux_DnsAddressMatchListInstanceName m_Dependent;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Antecedent:1;
         unsigned int Dependent:1;
       } isSet;
  };
  
  
  struct Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement{
  	Linux_DnsAddressMatchListOfServiceInstanceName* m_elementP;
  	Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement();
  	~Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration {
  	private:
  	  Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration();
  	  
  	  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(
  	   const Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAddressMatchListOfServiceInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAddressMatchListOfServiceInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsAddressMatchListOfServiceInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

