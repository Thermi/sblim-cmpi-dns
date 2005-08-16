 /**
 * Linux_DnsZoneInstance.h
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
#ifndef Linux_DnsZoneInstance_h
#define Linux_DnsZoneInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsZoneInstance {
  public:
       Linux_DnsZoneInstance();
  	
       Linux_DnsZoneInstance
  	    (const Linux_DnsZoneInstance& original);
  	   
       Linux_DnsZoneInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsZoneInstance();
       
       Linux_DnsZoneInstance& operator=
  	    (const Linux_DnsZoneInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsZoneInstanceName& val);        
       const Linux_DnsZoneInstanceName&
        getInstanceName() const;

       unsigned int isCaptionSet() const;
       void setCaption(const char* val, int makeCopy = 1);
       const char* getCaption() const;

       unsigned int isContactSet() const;
       void setContact(const char* val, int makeCopy = 1);
       const char* getContact() const;

       unsigned int isDescriptionSet() const;
       void setDescription(const char* val, int makeCopy = 1);
       const char* getDescription() const;

       unsigned int isElementNameSet() const;
       void setElementName(const char* val, int makeCopy = 1);
       const char* getElementName() const;

       unsigned int isResourceRecordFileSet() const;
       void setResourceRecordFile(const char* val, int makeCopy = 1);
       const char* getResourceRecordFile() const;

       unsigned int isSettingIDSet() const;
       void setSettingID(const char* val, int makeCopy = 1);
       const char* getSettingID() const;

       unsigned int isTypeSet() const;
       void setType(const CMPIUint16 val);
       const CMPIUint16 getType() const;
       
  private:
       void init();
       void init(const Linux_DnsZoneInstance& original);
       void reset();
       
       Linux_DnsZoneInstanceName m_instanceName;
       const char* m_Caption;
       const char* m_Contact;
       const char* m_Description;
       const char* m_ElementName;
       const char* m_ResourceRecordFile;
       const char* m_SettingID;
       CMPIUint16 m_Type;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Caption:1;
         unsigned int Contact:1;
         unsigned int Description:1;
         unsigned int ElementName:1;
         unsigned int ResourceRecordFile:1;
         unsigned int SettingID:1;
         unsigned int Type:1;
       } isSet;
  };
  
  
  struct Linux_DnsZoneInstanceEnumerationElement{
  	Linux_DnsZoneInstance* m_elementP;
  	Linux_DnsZoneInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsZoneInstanceEnumerationElement();
  	~Linux_DnsZoneInstanceEnumerationElement();  	
  };
  

  class Linux_DnsZoneInstanceEnumeration {
  	private:
  	  Linux_DnsZoneInstanceEnumerationElement* firstElementP;
  	  Linux_DnsZoneInstanceEnumerationElement* currentElementP;
  	  Linux_DnsZoneInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsZoneInstanceEnumeration();
  	  
  	  Linux_DnsZoneInstanceEnumeration(
  	   const Linux_DnsZoneInstanceEnumeration& original);
  	  
  	  ~Linux_DnsZoneInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsZoneInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsZoneInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsZoneInstance& elementP);
  };
}
#endif

