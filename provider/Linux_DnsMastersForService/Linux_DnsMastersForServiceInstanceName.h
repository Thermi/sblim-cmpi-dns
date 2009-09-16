// =======================================================================
// Linux_DnsMastersForServiceInstanceName.h
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
#ifndef Linux_DnsMastersForServiceInstanceName_h
#define Linux_DnsMastersForServiceInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsMastersInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersForServiceInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsMastersForServiceInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsServiceInstanceName m_GroupComponent;
    Linux_DnsMastersInstanceName m_PartComponent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int GroupComponent:1;
      unsigned int PartComponent:1;

    } isSet;
  
    public:
    Linux_DnsMastersForServiceInstanceName();
  	
    Linux_DnsMastersForServiceInstanceName(const Linux_DnsMastersForServiceInstanceName& anInstanceName);
  	   
    Linux_DnsMastersForServiceInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsMastersForServiceInstanceName();
       
    Linux_DnsMastersForServiceInstanceName& operator=(const Linux_DnsMastersForServiceInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isGroupComponentSet() const;
    void setGroupComponent(const Linux_DnsServiceInstanceName& aValue);
    const Linux_DnsServiceInstanceName& getGroupComponent() const;

    unsigned int isPartComponentSet() const;
    void setPartComponent(const Linux_DnsMastersInstanceName& aValue);
    const Linux_DnsMastersInstanceName& getPartComponent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsMastersForServiceInstanceNameEnumerationElement {
  	Linux_DnsMastersForServiceInstanceName* m_elementP;
  	Linux_DnsMastersForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsMastersForServiceInstanceNameEnumerationElement();
  	~Linux_DnsMastersForServiceInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsMastersForServiceInstanceNameEnumeration {
  
  	private:
    Linux_DnsMastersForServiceInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsMastersForServiceInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsMastersForServiceInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsMastersForServiceInstanceNameEnumeration();
  	  
    Linux_DnsMastersForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsMastersForServiceInstanceNameEnumeration(const Linux_DnsMastersForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsMastersForServiceInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsMastersForServiceInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsMastersForServiceInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsMastersForServiceInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

