 /**
 * Linux_DnsSettingInstance.h
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
#ifndef Linux_DnsSettingInstance_h
#define Linux_DnsSettingInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsSettingInstance {
  public:
       Linux_DnsSettingInstance();
  	
       Linux_DnsSettingInstance
  	    (const Linux_DnsSettingInstance& original);
  	   
       Linux_DnsSettingInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsSettingInstance();
       
       Linux_DnsSettingInstance& operator=
  	    (const Linux_DnsSettingInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsSettingInstanceName& val);        
       const Linux_DnsSettingInstanceName&
        getInstanceName() const;

       unsigned int isCaptionSet() const;
       void setCaption(const char* val, int makeCopy = 1);
       const char* getCaption() const;

       unsigned int isConfigurationDirectorySet() const;
       void setConfigurationDirectory(const char* val, int makeCopy = 1);
       const char* getConfigurationDirectory() const;

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

       unsigned int isPortNumberSet() const;
       void setPortNumber(const CMPIUint32 val);
       const CMPIUint32 getPortNumber() const;

       unsigned int isSettingIDSet() const;
       void setSettingID(const char* val, int makeCopy = 1);
       const char* getSettingID() const;

       unsigned int isTSIGSet() const;
       void setTSIG(const CMPIUint16 val);
       const CMPIUint16 getTSIG() const;

       unsigned int isTTLSet() const;
       void setTTL(const CMPIUint32 val);
       const CMPIUint32 getTTL() const;

       unsigned int isXferFormatSet() const;
       void setXferFormat(const CMPIUint16 val);
       const CMPIUint16 getXferFormat() const;
       
  private:
       void init();
       void init(const Linux_DnsSettingInstance& original);
       void reset();
       
       Linux_DnsSettingInstanceName m_instanceName;
       const char* m_Caption;
       const char* m_ConfigurationDirectory;
       const char* m_Description;
       const char* m_ElementName;
       CMPIUint16 m_Forward;
       const char** m_Forwarders;
        unsigned int ForwardersArraySize;
       CMPIUint32 m_PortNumber;
       const char* m_SettingID;
       CMPIUint16 m_TSIG;
       CMPIUint32 m_TTL;
       CMPIUint16 m_XferFormat;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Caption:1;
         unsigned int ConfigurationDirectory:1;
         unsigned int Description:1;
         unsigned int ElementName:1;
         unsigned int Forward:1;
         unsigned int Forwarders:1;
         unsigned int PortNumber:1;
         unsigned int SettingID:1;
         unsigned int TSIG:1;
         unsigned int TTL:1;
         unsigned int XferFormat:1;
       } isSet;
  };
  
  
  struct Linux_DnsSettingInstanceEnumerationElement{
  	Linux_DnsSettingInstance* m_elementP;
  	Linux_DnsSettingInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingInstanceEnumerationElement();
  	~Linux_DnsSettingInstanceEnumerationElement();  	
  };
  

  class Linux_DnsSettingInstanceEnumeration {
  	private:
  	  Linux_DnsSettingInstanceEnumerationElement* firstElementP;
  	  Linux_DnsSettingInstanceEnumerationElement* currentElementP;
  	  Linux_DnsSettingInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSettingInstanceEnumeration();
  	  
  	  Linux_DnsSettingInstanceEnumeration(
  	   const Linux_DnsSettingInstanceEnumeration& original);
  	  
  	  ~Linux_DnsSettingInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSettingInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSettingInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsSettingInstance& elementP);
  };
}
#endif

