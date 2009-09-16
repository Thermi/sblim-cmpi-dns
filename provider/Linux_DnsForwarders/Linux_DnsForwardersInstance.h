// =======================================================================
// Linux_DnsForwardersInstance.h
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
#ifndef Linux_DnsForwardersInstance_h
#define Linux_DnsForwardersInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardersInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardersInstance& anInstance);
    void reset();
       
    Linux_DnsForwardersInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    const CMPIUint8* m_ForwardersElementType;
    unsigned int m_ForwardersElementTypeSize;
    const char** m_ForwardersElement;
    unsigned int m_ForwardersElementSize;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int ForwardersElementType:1;
      unsigned int ForwardersElement:1;

    } isSet;
    
    public:
    Linux_DnsForwardersInstance();
    Linux_DnsForwardersInstance(
      const Linux_DnsForwardersInstance& anInstance);
    Linux_DnsForwardersInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardersInstance();
       
    Linux_DnsForwardersInstance& operator=(
      const Linux_DnsForwardersInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardersInstanceName& anInstanceName);        
    const Linux_DnsForwardersInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isForwardersElementTypeSet() const;
    void setForwardersElementType(const CMPIUint8* aValue, unsigned const int aSize, int aCopyFlag = 1);
    const CMPIUint8* getForwardersElementType(unsigned int& aSize) const;

    unsigned int isForwardersElementSet() const;
    void setForwardersElement(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getForwardersElement(unsigned int& aSize) const;


  };
  
  struct Linux_DnsForwardersInstanceEnumerationElement {

    Linux_DnsForwardersInstance* m_elementP;
    Linux_DnsForwardersInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardersInstanceEnumerationElement();
    ~Linux_DnsForwardersInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardersInstanceEnumeration {

    private:
    Linux_DnsForwardersInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardersInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardersInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardersInstanceEnumeration();
    Linux_DnsForwardersInstanceEnumeration(
      const Linux_DnsForwardersInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardersInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardersInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardersInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardersInstance& anInstance);

  };

}

#endif
