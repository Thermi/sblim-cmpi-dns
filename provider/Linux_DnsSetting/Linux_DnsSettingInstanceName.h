// =======================================================================
// Linux_DnsSettingInstanceName.h
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
#ifndef Linux_DnsSettingInstanceName_h
#define Linux_DnsSettingInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsSettingInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsSettingInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_Name;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int Name:1;

    } isSet;
  
    public:
    Linux_DnsSettingInstanceName();
  	
    Linux_DnsSettingInstanceName(const Linux_DnsSettingInstanceName& anInstanceName);
  	   
    Linux_DnsSettingInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsSettingInstanceName();
       
    Linux_DnsSettingInstanceName& operator=(const Linux_DnsSettingInstanceName& anInstanceName);
       
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
  struct Linux_DnsSettingInstanceNameEnumerationElement {
  	Linux_DnsSettingInstanceName* m_elementP;
  	Linux_DnsSettingInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingInstanceNameEnumerationElement();
  	~Linux_DnsSettingInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsSettingInstanceNameEnumeration {
  
  	private:
    Linux_DnsSettingInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsSettingInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsSettingInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsSettingInstanceNameEnumeration();
  	  
    Linux_DnsSettingInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsSettingInstanceNameEnumeration(const Linux_DnsSettingInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsSettingInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsSettingInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsSettingInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsSettingInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

