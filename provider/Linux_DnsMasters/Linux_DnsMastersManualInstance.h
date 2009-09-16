// =======================================================================
// Linux_DnsMastersManualInstance.h
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
#ifndef Linux_DnsMastersManualInstance_h
#define Linux_DnsMastersManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsMastersInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsMastersManualInstance& anInstance);
    void reset();
       
    Linux_DnsMastersInstanceName m_instanceName;
    const CMPIUint8* m_MasterElementType;
    unsigned int m_MasterElementTypeSize;
    const char** m_MasterElement;
    unsigned int m_MasterElementSize;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int MasterElementType:1;
      unsigned int MasterElement:1;

    } isSet;
    
    public:
    Linux_DnsMastersManualInstance();
    Linux_DnsMastersManualInstance(
      const Linux_DnsMastersManualInstance& anInstance);
    Linux_DnsMastersManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsMastersManualInstance();
       
    Linux_DnsMastersManualInstance& operator=(
      const Linux_DnsMastersManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsMastersInstanceName& anInstanceName);        
    const Linux_DnsMastersInstanceName& getInstanceName() const;

    unsigned int isMasterElementTypeSet() const;
    void setMasterElementType(const CMPIUint8* aValue, unsigned const int aSize, int aCopyFlag = 1);
    const CMPIUint8* getMasterElementType(unsigned int& aSize) const;

    unsigned int isMasterElementSet() const;
    void setMasterElement(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getMasterElement(unsigned int& aSize) const;


  };
  
  struct Linux_DnsMastersManualInstanceEnumerationElement {

    Linux_DnsMastersManualInstance* m_elementP;
    Linux_DnsMastersManualInstanceEnumerationElement* m_nextP;

    Linux_DnsMastersManualInstanceEnumerationElement();
    ~Linux_DnsMastersManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsMastersManualInstanceEnumeration {

    private:
    Linux_DnsMastersManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsMastersManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsMastersManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsMastersManualInstanceEnumeration();
    Linux_DnsMastersManualInstanceEnumeration(
      const Linux_DnsMastersManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsMastersManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsMastersManualInstance& getNext();
    int getSize() const;
    const Linux_DnsMastersManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsMastersManualInstance& anInstance);

  };

}

#endif
