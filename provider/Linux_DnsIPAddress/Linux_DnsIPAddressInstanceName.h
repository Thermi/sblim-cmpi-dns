 /**
 * Linux_DnsIPAddressInstanceName.h
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
#ifndef Linux_DnsIPAddressInstanceName_h
#define Linux_DnsIPAddressInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"

namespace genProvider {

  class Linux_DnsIPAddressInstanceName {
  public:
       Linux_DnsIPAddressInstanceName();
  	
       Linux_DnsIPAddressInstanceName
  	    (const Linux_DnsIPAddressInstanceName& original);
  	   
       Linux_DnsIPAddressInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsIPAddressInstanceName();
       
       Linux_DnsIPAddressInstanceName& operator=
  	    (const Linux_DnsIPAddressInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isIPAddressSet() const;
       void setIPAddress(const char* val, int makeCopy = 1);
       const char* getIPAddress() const;

       unsigned int isZoneNameSet() const;
       void setZoneName(const char* val, int makeCopy = 1);
       const char* getZoneName() const;
       
  private:
       void init();
       void init(const Linux_DnsIPAddressInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_IPAddress;
       const char* m_ZoneName;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int IPAddress:1;
         unsigned int ZoneName:1;
       } isSet;
  };
  
  
  struct Linux_DnsIPAddressInstanceNameEnumerationElement{
  	Linux_DnsIPAddressInstanceName* m_elementP;
  	Linux_DnsIPAddressInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsIPAddressInstanceNameEnumerationElement();
  	~Linux_DnsIPAddressInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsIPAddressInstanceNameEnumeration {
  	private:
  	  Linux_DnsIPAddressInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsIPAddressInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsIPAddressInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsIPAddressInstanceNameEnumeration();
  	  
  	  Linux_DnsIPAddressInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsIPAddressInstanceNameEnumeration(
  	   const Linux_DnsIPAddressInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsIPAddressInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsIPAddressInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsIPAddressInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsIPAddressInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

