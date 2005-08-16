 /**
 * Linux_DnsSettingManualInstance.h
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
#ifndef Linux_DnsSettingManualInstance_h
#define Linux_DnsSettingManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsSettingManualInstance {
  public:
       Linux_DnsSettingManualInstance();
  	
       Linux_DnsSettingManualInstance
  	    (const Linux_DnsSettingManualInstance& original);
  	   
       Linux_DnsSettingManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsSettingManualInstance();
       
       Linux_DnsSettingManualInstance& operator=
  	    (const Linux_DnsSettingManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsSettingInstanceName& val);        
       const Linux_DnsSettingInstanceName&
        getInstanceName() const;

       unsigned int isConfigurationDirectorySet() const;
       void setConfigurationDirectory(const char* val, int makeCopy = 1);
       const char* getConfigurationDirectory() const;

       unsigned int isForwardSet() const;
       void setForward(const CMPIUint16 val);
       const CMPIUint16 getForward() const;

       unsigned int isForwardersSet() const;
       void setForwarders(const char** val, unsigned const int size, int makeCopy = 1);
       const char** getForwarders(unsigned int& size) const;

       unsigned int isPortNumberSet() const;
       void setPortNumber(const CMPIUint32 val);
       const CMPIUint32 getPortNumber() const;

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
       void init(const Linux_DnsSettingManualInstance& original);
       void reset();
       
       Linux_DnsSettingInstanceName m_instanceName;
       const char* m_ConfigurationDirectory;
       CMPIUint16 m_Forward;
       const char** m_Forwarders;
        unsigned int ForwardersArraySize;
       CMPIUint32 m_PortNumber;
       CMPIUint16 m_TSIG;
       CMPIUint32 m_TTL;
       CMPIUint16 m_XferFormat;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int ConfigurationDirectory:1;
         unsigned int Forward:1;
         unsigned int Forwarders:1;
         unsigned int PortNumber:1;
         unsigned int TSIG:1;
         unsigned int TTL:1;
         unsigned int XferFormat:1;
       } isSet;
  };
  
  
  struct Linux_DnsSettingManualInstanceEnumerationElement{
  	Linux_DnsSettingManualInstance* m_elementP;
  	Linux_DnsSettingManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingManualInstanceEnumerationElement();
  	~Linux_DnsSettingManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsSettingManualInstanceEnumeration {
  	private:
  	  Linux_DnsSettingManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsSettingManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsSettingManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSettingManualInstanceEnumeration();
  	  
  	  Linux_DnsSettingManualInstanceEnumeration(
  	   const Linux_DnsSettingManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsSettingManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSettingManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSettingManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsSettingManualInstance& elementP);
  };
}
#endif

