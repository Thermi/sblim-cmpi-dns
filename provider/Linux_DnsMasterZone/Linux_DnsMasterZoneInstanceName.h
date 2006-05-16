// =======================================================================
// Linux_DnsMasterZoneInstanceName.h
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsMasterZoneInstanceName_h
#define Linux_DnsMasterZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsMasterZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsMasterZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_Name;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Name:1;

    } isSet;
  
    public:
    Linux_DnsMasterZoneInstanceName();
  	
    Linux_DnsMasterZoneInstanceName(const Linux_DnsMasterZoneInstanceName& anInstanceName);
  	   
    Linux_DnsMasterZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsMasterZoneInstanceName();
       
    Linux_DnsMasterZoneInstanceName& operator=(const Linux_DnsMasterZoneInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isNameSet() const;
    void setName(const char* aValue, int aCopyFlag = 1);
    const char* getName() const;


  };
  
  //****************************************************************************
  struct Linux_DnsMasterZoneInstanceNameEnumerationElement {
  	Linux_DnsMasterZoneInstanceName* m_elementP;
  	Linux_DnsMasterZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsMasterZoneInstanceNameEnumerationElement();
  	~Linux_DnsMasterZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsMasterZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsMasterZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsMasterZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsMasterZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsMasterZoneInstanceNameEnumeration();
  	  
    Linux_DnsMasterZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsMasterZoneInstanceNameEnumeration(const Linux_DnsMasterZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsMasterZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsMasterZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsMasterZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsMasterZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

