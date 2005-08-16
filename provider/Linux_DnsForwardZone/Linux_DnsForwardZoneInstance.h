 /**
 * Linux_DnsForwardZoneInstance.h
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
#ifndef Linux_DnsForwardZoneInstance_h
#define Linux_DnsForwardZoneInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsForwardZoneInstance {
  public:
       Linux_DnsForwardZoneInstance();
  	
       Linux_DnsForwardZoneInstance
  	    (const Linux_DnsForwardZoneInstance& original);
  	   
       Linux_DnsForwardZoneInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsForwardZoneInstance();
       
       Linux_DnsForwardZoneInstance& operator=
  	    (const Linux_DnsForwardZoneInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsForwardZoneInstanceName& val);        
       const Linux_DnsForwardZoneInstanceName&
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

       unsigned int isForwardSet() const;
       void setForward(const CMPIUint16 val);
       const CMPIUint16 getForward() const;

       unsigned int isForwardersSet() const;
       void setForwarders(const char** val, unsigned const int size, int makeCopy = 1);
       const char** getForwarders(unsigned int& size) const;

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
       void init(const Linux_DnsForwardZoneInstance& original);
       void reset();
       
       Linux_DnsForwardZoneInstanceName m_instanceName;
       const char* m_Caption;
       const char* m_Description;
       const char* m_ElementName;
       CMPIUint16 m_Forward;
       const char** m_Forwarders;
        unsigned int ForwardersArraySize;
       const char* m_ResourceRecordFile;
       const char* m_SettingID;
       CMPIUint16 m_Type;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Caption:1;
         unsigned int Description:1;
         unsigned int ElementName:1;
         unsigned int Forward:1;
         unsigned int Forwarders:1;
         unsigned int ResourceRecordFile:1;
         unsigned int SettingID:1;
         unsigned int Type:1;
       } isSet;
  };
  
  
  struct Linux_DnsForwardZoneInstanceEnumerationElement{
  	Linux_DnsForwardZoneInstance* m_elementP;
  	Linux_DnsForwardZoneInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsForwardZoneInstanceEnumerationElement();
  	~Linux_DnsForwardZoneInstanceEnumerationElement();  	
  };
  

  class Linux_DnsForwardZoneInstanceEnumeration {
  	private:
  	  Linux_DnsForwardZoneInstanceEnumerationElement* firstElementP;
  	  Linux_DnsForwardZoneInstanceEnumerationElement* currentElementP;
  	  Linux_DnsForwardZoneInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsForwardZoneInstanceEnumeration();
  	  
  	  Linux_DnsForwardZoneInstanceEnumeration(
  	   const Linux_DnsForwardZoneInstanceEnumeration& original);
  	  
  	  ~Linux_DnsForwardZoneInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsForwardZoneInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsForwardZoneInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsForwardZoneInstance& elementP);
  };
}
#endif

