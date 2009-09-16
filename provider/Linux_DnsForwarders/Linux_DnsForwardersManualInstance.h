// =======================================================================
// Linux_DnsForwardersManualInstance.h
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
#ifndef Linux_DnsForwardersManualInstance_h
#define Linux_DnsForwardersManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardersInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardersManualInstance& anInstance);
    void reset();
       
    Linux_DnsForwardersInstanceName m_instanceName;
    const CMPIUint8* m_ForwardersElementType;
    unsigned int m_ForwardersElementTypeSize;
    const char** m_ForwardersElement;
    unsigned int m_ForwardersElementSize;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int ForwardersElementType:1;
      unsigned int ForwardersElement:1;

    } isSet;
    
    public:
    Linux_DnsForwardersManualInstance();
    Linux_DnsForwardersManualInstance(
      const Linux_DnsForwardersManualInstance& anInstance);
    Linux_DnsForwardersManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardersManualInstance();
       
    Linux_DnsForwardersManualInstance& operator=(
      const Linux_DnsForwardersManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardersInstanceName& anInstanceName);        
    const Linux_DnsForwardersInstanceName& getInstanceName() const;

    unsigned int isForwardersElementTypeSet() const;
    void setForwardersElementType(const CMPIUint8* aValue, unsigned const int aSize, int aCopyFlag = 1);
    const CMPIUint8* getForwardersElementType(unsigned int& aSize) const;

    unsigned int isForwardersElementSet() const;
    void setForwardersElement(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getForwardersElement(unsigned int& aSize) const;


  };
  
  struct Linux_DnsForwardersManualInstanceEnumerationElement {

    Linux_DnsForwardersManualInstance* m_elementP;
    Linux_DnsForwardersManualInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardersManualInstanceEnumerationElement();
    ~Linux_DnsForwardersManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardersManualInstanceEnumeration {

    private:
    Linux_DnsForwardersManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardersManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardersManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardersManualInstanceEnumeration();
    Linux_DnsForwardersManualInstanceEnumeration(
      const Linux_DnsForwardersManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardersManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardersManualInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardersManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardersManualInstance& anInstance);

  };

}

#endif
