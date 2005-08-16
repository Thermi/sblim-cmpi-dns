 /**
 * Linux_DnsIPAddressInstance.h
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
#ifndef Linux_DnsIPAddressInstance_h
#define Linux_DnsIPAddressInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsIPAddressInstanceName.h"

namespace genProvider {

  class Linux_DnsIPAddressInstance {
  public:
       Linux_DnsIPAddressInstance();
  	
       Linux_DnsIPAddressInstance
  	    (const Linux_DnsIPAddressInstance& original);
  	   
       Linux_DnsIPAddressInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsIPAddressInstance();
       
       Linux_DnsIPAddressInstance& operator=
  	    (const Linux_DnsIPAddressInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsIPAddressInstanceName& val);        
       const Linux_DnsIPAddressInstanceName&
        getInstanceName() const;

       unsigned int isCaptionSet() const;
       void setCaption(const char* val, int makeCopy = 1);
       const char* getCaption() const;

       unsigned int isDescriptionSet() const;
       void setDescription(const char* val, int makeCopy = 1);
       const char* getDescription() const;

       unsigned int isElementNameSet() const;
       void setElementName(const char* val, int makeCopy = 1);
       const char* getElementName() const;

       unsigned int isPortSet() const;
       void setPort(const CMPIUint32 val);
       const CMPIUint32 getPort() const;

       unsigned int isSecurityKeySet() const;
       void setSecurityKey(const char* val, int makeCopy = 1);
       const char* getSecurityKey() const;

       unsigned int isSettingIDSet() const;
       void setSettingID(const char* val, int makeCopy = 1);
       const char* getSettingID() const;
       
  private:
       void init();
       void init(const Linux_DnsIPAddressInstance& original);
       void reset();
       
       Linux_DnsIPAddressInstanceName m_instanceName;
       const char* m_Caption;
       const char* m_Description;
       const char* m_ElementName;
       CMPIUint32 m_Port;
       const char* m_SecurityKey;
       const char* m_SettingID;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Caption:1;
         unsigned int Description:1;
         unsigned int ElementName:1;
         unsigned int Port:1;
         unsigned int SecurityKey:1;
         unsigned int SettingID:1;
       } isSet;
  };
  
  
  struct Linux_DnsIPAddressInstanceEnumerationElement{
  	Linux_DnsIPAddressInstance* m_elementP;
  	Linux_DnsIPAddressInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsIPAddressInstanceEnumerationElement();
  	~Linux_DnsIPAddressInstanceEnumerationElement();  	
  };
  

  class Linux_DnsIPAddressInstanceEnumeration {
  	private:
  	  Linux_DnsIPAddressInstanceEnumerationElement* firstElementP;
  	  Linux_DnsIPAddressInstanceEnumerationElement* currentElementP;
  	  Linux_DnsIPAddressInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsIPAddressInstanceEnumeration();
  	  
  	  Linux_DnsIPAddressInstanceEnumeration(
  	   const Linux_DnsIPAddressInstanceEnumeration& original);
  	  
  	  ~Linux_DnsIPAddressInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsIPAddressInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsIPAddressInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsIPAddressInstance& elementP);
  };
}
#endif

