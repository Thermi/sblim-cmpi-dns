 /**
 * Linux_DnsConfigurationInstance.h
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
#ifndef Linux_DnsConfigurationInstance_h
#define Linux_DnsConfigurationInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsConfigurationInstanceName.h"

namespace genProvider {

  class Linux_DnsConfigurationInstance {
  public:
       Linux_DnsConfigurationInstance();
  	
       Linux_DnsConfigurationInstance
  	    (const Linux_DnsConfigurationInstance& original);
  	   
       Linux_DnsConfigurationInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsConfigurationInstance();
       
       Linux_DnsConfigurationInstance& operator=
  	    (const Linux_DnsConfigurationInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsConfigurationInstanceName& val);        
       const Linux_DnsConfigurationInstanceName&
        getInstanceName() const;

       unsigned int isCaptionSet() const;
       void setCaption(const char* val, int makeCopy = 1);
       const char* getCaption() const;

       unsigned int isConfigurationFileSet() const;
       void setConfigurationFile(const char* val, int makeCopy = 1);
       const char* getConfigurationFile() const;

       unsigned int isDescriptionSet() const;
       void setDescription(const char* val, int makeCopy = 1);
       const char* getDescription() const;

       unsigned int isElementNameSet() const;
       void setElementName(const char* val, int makeCopy = 1);
       const char* getElementName() const;
       
  private:
       void init();
       void init(const Linux_DnsConfigurationInstance& original);
       void reset();
       
       Linux_DnsConfigurationInstanceName m_instanceName;
       const char* m_Caption;
       const char* m_ConfigurationFile;
       const char* m_Description;
       const char* m_ElementName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Caption:1;
         unsigned int ConfigurationFile:1;
         unsigned int Description:1;
         unsigned int ElementName:1;
       } isSet;
  };
  
  
  struct Linux_DnsConfigurationInstanceEnumerationElement{
  	Linux_DnsConfigurationInstance* m_elementP;
  	Linux_DnsConfigurationInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsConfigurationInstanceEnumerationElement();
  	~Linux_DnsConfigurationInstanceEnumerationElement();  	
  };
  

  class Linux_DnsConfigurationInstanceEnumeration {
  	private:
  	  Linux_DnsConfigurationInstanceEnumerationElement* firstElementP;
  	  Linux_DnsConfigurationInstanceEnumerationElement* currentElementP;
  	  Linux_DnsConfigurationInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsConfigurationInstanceEnumeration();
  	  
  	  Linux_DnsConfigurationInstanceEnumeration(
  	   const Linux_DnsConfigurationInstanceEnumeration& original);
  	  
  	  ~Linux_DnsConfigurationInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsConfigurationInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsConfigurationInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsConfigurationInstance& elementP);
  };
}
#endif

