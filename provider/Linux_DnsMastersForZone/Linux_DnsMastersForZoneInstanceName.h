// =======================================================================
// Linux_DnsMastersForZoneInstanceName.h
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
#ifndef Linux_DnsMastersForZoneInstanceName_h
#define Linux_DnsMastersForZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsZoneInstanceName.h"
#include "Linux_DnsMastersInstanceName.h"


namespace genProvider {

  class Linux_DnsMastersForZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsMastersForZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    Linux_DnsZoneInstanceName m_GroupComponent;
    Linux_DnsMastersInstanceName m_PartComponent;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int GroupComponent:1;
      unsigned int PartComponent:1;

    } isSet;
  
    public:
    Linux_DnsMastersForZoneInstanceName();
  	
    Linux_DnsMastersForZoneInstanceName(const Linux_DnsMastersForZoneInstanceName& anInstanceName);
  	   
    Linux_DnsMastersForZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsMastersForZoneInstanceName();
       
    Linux_DnsMastersForZoneInstanceName& operator=(const Linux_DnsMastersForZoneInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isGroupComponentSet() const;
    void setGroupComponent(const Linux_DnsZoneInstanceName& aValue);
    const Linux_DnsZoneInstanceName& getGroupComponent() const;

    unsigned int isPartComponentSet() const;
    void setPartComponent(const Linux_DnsMastersInstanceName& aValue);
    const Linux_DnsMastersInstanceName& getPartComponent() const;


  };
  
  //****************************************************************************
  struct Linux_DnsMastersForZoneInstanceNameEnumerationElement {
  	Linux_DnsMastersForZoneInstanceName* m_elementP;
  	Linux_DnsMastersForZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsMastersForZoneInstanceNameEnumerationElement();
  	~Linux_DnsMastersForZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsMastersForZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsMastersForZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsMastersForZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsMastersForZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsMastersForZoneInstanceNameEnumeration();
  	  
    Linux_DnsMastersForZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsMastersForZoneInstanceNameEnumeration(const Linux_DnsMastersForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsMastersForZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsMastersForZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsMastersForZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsMastersForZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

