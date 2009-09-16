// =======================================================================
// Linux_DnsMastersInstance.h
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
#ifndef Linux_DnsMastersInstance_h
#define Linux_DnsMastersInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersInstance& anInstance);
    void reset();
       
    Linux_DnsMastersInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    const CMPIUint8* m_MasterElementType;
    unsigned int m_MasterElementTypeSize;
    const char** m_MasterElement;
    unsigned int m_MasterElementSize;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int MasterElementType:1;
      unsigned int MasterElement:1;

    } isSet;
    
    public:
    Linux_DnsMastersInstance();
    Linux_DnsMastersInstance(
      const Linux_DnsMastersInstance& anInstance);
    Linux_DnsMastersInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersInstance();
       
    Linux_DnsMastersInstance& operator=(
      const Linux_DnsMastersInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersInstanceName& anInstanceName);        
    const Linux_DnsMastersInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isMasterElementTypeSet() const;
    void setMasterElementType(const CMPIUint8* aValue, unsigned const int aSize, int aCopyFlag = 1);
    const CMPIUint8* getMasterElementType(unsigned int& aSize) const;

    unsigned int isMasterElementSet() const;
    void setMasterElement(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getMasterElement(unsigned int& aSize) const;


  };
  
  struct Linux_DnsMastersInstanceEnumerationElement {

    Linux_DnsMastersInstance* m_elementP;
    Linux_DnsMastersInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersInstanceEnumerationElement();
    ~Linux_DnsMastersInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersInstanceEnumeration {

    private:
    Linux_DnsMastersInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersInstanceEnumeration();
    Linux_DnsMastersInstanceEnumeration(
      const Linux_DnsMastersInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersInstance& anInstance);

  };

}

#endif
