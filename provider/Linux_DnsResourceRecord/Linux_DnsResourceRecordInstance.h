 /**
 * Linux_DnsResourceRecordInstance.h
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
#ifndef Linux_DnsResourceRecordInstance_h
#define Linux_DnsResourceRecordInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInstanceName.h"

namespace genProvider {

  class Linux_DnsResourceRecordInstance {
  public:
       Linux_DnsResourceRecordInstance();
  	
       Linux_DnsResourceRecordInstance
  	    (const Linux_DnsResourceRecordInstance& original);
  	   
       Linux_DnsResourceRecordInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsResourceRecordInstance();
       
       Linux_DnsResourceRecordInstance& operator=
  	    (const Linux_DnsResourceRecordInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsResourceRecordInstanceName& val);        
       const Linux_DnsResourceRecordInstanceName&
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

       unsigned int isFamilySet() const;
       void setFamily(const CMPIUint16 val);
       const CMPIUint16 getFamily() const;

       unsigned int isSettingIDSet() const;
       void setSettingID(const char* val, int makeCopy = 1);
       const char* getSettingID() const;

       unsigned int isTTLSet() const;
       void setTTL(const CMPIUint32 val);
       const CMPIUint32 getTTL() const;
       
  private:
       void init();
       void init(const Linux_DnsResourceRecordInstance& original);
       void reset();
       
       Linux_DnsResourceRecordInstanceName m_instanceName;
       const char* m_Caption;
       const char* m_Description;
       const char* m_ElementName;
       CMPIBoolean m_Enabled;
       CMPIUint16 m_Family;
       const char* m_SettingID;
       CMPIUint32 m_TTL;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Caption:1;
         unsigned int Description:1;
         unsigned int ElementName:1;
         unsigned int Enabled:1;
         unsigned int Family:1;
         unsigned int SettingID:1;
         unsigned int TTL:1;
       } isSet;
  };
  
  
  struct Linux_DnsResourceRecordInstanceEnumerationElement{
  	Linux_DnsResourceRecordInstance* m_elementP;
  	Linux_DnsResourceRecordInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordInstanceEnumerationElement();
  	~Linux_DnsResourceRecordInstanceEnumerationElement();  	
  };
  

  class Linux_DnsResourceRecordInstanceEnumeration {
  	private:
  	  Linux_DnsResourceRecordInstanceEnumerationElement* firstElementP;
  	  Linux_DnsResourceRecordInstanceEnumerationElement* currentElementP;
  	  Linux_DnsResourceRecordInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsResourceRecordInstanceEnumeration();
  	  
  	  Linux_DnsResourceRecordInstanceEnumeration(
  	   const Linux_DnsResourceRecordInstanceEnumeration& original);
  	  
  	  ~Linux_DnsResourceRecordInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsResourceRecordInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsResourceRecordInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsResourceRecordInstance& elementP);
  };
}
#endif

