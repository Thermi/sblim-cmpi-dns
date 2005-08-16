 /**
 * Linux_DnsHintZoneInstance.h
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
#ifndef Linux_DnsHintZoneInstance_h
#define Linux_DnsHintZoneInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsHintZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsHintZoneInstance {
  public:
       Linux_DnsHintZoneInstance();
  	
       Linux_DnsHintZoneInstance
  	    (const Linux_DnsHintZoneInstance& original);
  	   
       Linux_DnsHintZoneInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsHintZoneInstance();
       
       Linux_DnsHintZoneInstance& operator=
  	    (const Linux_DnsHintZoneInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsHintZoneInstanceName& val);        
       const Linux_DnsHintZoneInstanceName&
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

       unsigned int isEnabledSet() const;
       void setEnabled(const CMPIBoolean val);
       const CMPIBoolean getEnabled() const;

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
       void init(const Linux_DnsHintZoneInstance& original);
       void reset();
       
       Linux_DnsHintZoneInstanceName m_instanceName;
       const char* m_Caption;
       const char* m_Description;
       const char* m_ElementName;
       CMPIBoolean m_Enabled;
       const char* m_ResourceRecordFile;
       const char* m_SettingID;
       CMPIUint16 m_Type;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Caption:1;
         unsigned int Description:1;
         unsigned int ElementName:1;
	 unsigned int Enabled:1;
	 unsigned int ResourceRecordFile:1;
         unsigned int SettingID:1;
         unsigned int Type:1;
       } isSet;
  };
  
  
  struct Linux_DnsHintZoneInstanceEnumerationElement{
  	Linux_DnsHintZoneInstance* m_elementP;
  	Linux_DnsHintZoneInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsHintZoneInstanceEnumerationElement();
  	~Linux_DnsHintZoneInstanceEnumerationElement();  	
  };
  

  class Linux_DnsHintZoneInstanceEnumeration {
  	private:
  	  Linux_DnsHintZoneInstanceEnumerationElement* firstElementP;
  	  Linux_DnsHintZoneInstanceEnumerationElement* currentElementP;
  	  Linux_DnsHintZoneInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsHintZoneInstanceEnumeration();
  	  
  	  Linux_DnsHintZoneInstanceEnumeration(
  	   const Linux_DnsHintZoneInstanceEnumeration& original);
  	  
  	  ~Linux_DnsHintZoneInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsHintZoneInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsHintZoneInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsHintZoneInstance& elementP);
  };
}
#endif

