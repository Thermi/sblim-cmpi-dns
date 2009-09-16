// =======================================================================
// Linux_DnsServiceConfigurationInstance.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsServiceConfigurationInstance_h
#define Linux_DnsServiceConfigurationInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceConfigurationInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceConfigurationInstance& anInstance);
    void reset();
       
    Linux_DnsServiceConfigurationInstanceName m_instanceName;
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
    
    public:
    Linux_DnsServiceConfigurationInstance();
    Linux_DnsServiceConfigurationInstance(
      const Linux_DnsServiceConfigurationInstance& anInstance);
    Linux_DnsServiceConfigurationInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceConfigurationInstance();
       
    Linux_DnsServiceConfigurationInstance& operator=(
      const Linux_DnsServiceConfigurationInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceConfigurationInstanceName& anInstanceName);        
    const Linux_DnsServiceConfigurationInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isConfigurationFileSet() const;
    void setConfigurationFile(const char* aValue, int aCopyFlag = 1);
    const char* getConfigurationFile() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;


  };
  
  struct Linux_DnsServiceConfigurationInstanceEnumerationElement {

    Linux_DnsServiceConfigurationInstance* m_elementP;
    Linux_DnsServiceConfigurationInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceConfigurationInstanceEnumerationElement();
    ~Linux_DnsServiceConfigurationInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceConfigurationInstanceEnumeration {

    private:
    Linux_DnsServiceConfigurationInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceConfigurationInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceConfigurationInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceConfigurationInstanceEnumeration();
    Linux_DnsServiceConfigurationInstanceEnumeration(
      const Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceConfigurationInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceConfigurationInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceConfigurationInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceConfigurationInstance& anInstance);

  };

}

#endif
