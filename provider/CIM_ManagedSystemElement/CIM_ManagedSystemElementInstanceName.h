// =======================================================================
// CIM_ManagedSystemElementInstanceName.h
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
#ifndef CIM_ManagedSystemElementInstanceName_h
#define CIM_ManagedSystemElementInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class CIM_ManagedSystemElementInstanceName {
       
    private:
    void init();
    void init(const CIM_ManagedSystemElementInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;

    } isSet;
  
    public:
    CIM_ManagedSystemElementInstanceName();
  	
    CIM_ManagedSystemElementInstanceName(const CIM_ManagedSystemElementInstanceName& anInstanceName);
  	   
    CIM_ManagedSystemElementInstanceName(const CmpiObjectPath& path);
  	 
    ~CIM_ManagedSystemElementInstanceName();
       
    CIM_ManagedSystemElementInstanceName& operator=(const CIM_ManagedSystemElementInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    

  };
  
  //****************************************************************************
  struct CIM_ManagedSystemElementInstanceNameEnumerationElement {
  	CIM_ManagedSystemElementInstanceName* m_elementP;
  	CIM_ManagedSystemElementInstanceNameEnumerationElement* m_nextP;
  	
  	CIM_ManagedSystemElementInstanceNameEnumerationElement();
  	~CIM_ManagedSystemElementInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class CIM_ManagedSystemElementInstanceNameEnumeration {
  
  	private:
    CIM_ManagedSystemElementInstanceNameEnumerationElement* m_firstElementP;
  	CIM_ManagedSystemElementInstanceNameEnumerationElement* m_currentElementP;
  	CIM_ManagedSystemElementInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    CIM_ManagedSystemElementInstanceNameEnumeration();
  	  
    CIM_ManagedSystemElementInstanceNameEnumeration(const CmpiArray& arr);
  	  
    CIM_ManagedSystemElementInstanceNameEnumeration(const CIM_ManagedSystemElementInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~CIM_ManagedSystemElementInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const CIM_ManagedSystemElementInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const CIM_ManagedSystemElementInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const CIM_ManagedSystemElementInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

