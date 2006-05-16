// =======================================================================
// CIM_CollectionOfMSEsInstanceName.h
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
#ifndef CIM_CollectionOfMSEsInstanceName_h
#define CIM_CollectionOfMSEsInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class CIM_CollectionOfMSEsInstanceName {
       
    private:
    void init();
    void init(const CIM_CollectionOfMSEsInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;

    } isSet;
  
    public:
    CIM_CollectionOfMSEsInstanceName();
  	
    CIM_CollectionOfMSEsInstanceName(const CIM_CollectionOfMSEsInstanceName& anInstanceName);
  	   
    CIM_CollectionOfMSEsInstanceName(const CmpiObjectPath& path);
  	 
    ~CIM_CollectionOfMSEsInstanceName();
       
    CIM_CollectionOfMSEsInstanceName& operator=(const CIM_CollectionOfMSEsInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    

  };
  
  //****************************************************************************
  struct CIM_CollectionOfMSEsInstanceNameEnumerationElement {
  	CIM_CollectionOfMSEsInstanceName* m_elementP;
  	CIM_CollectionOfMSEsInstanceNameEnumerationElement* m_nextP;
  	
  	CIM_CollectionOfMSEsInstanceNameEnumerationElement();
  	~CIM_CollectionOfMSEsInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class CIM_CollectionOfMSEsInstanceNameEnumeration {
  
  	private:
    CIM_CollectionOfMSEsInstanceNameEnumerationElement* m_firstElementP;
  	CIM_CollectionOfMSEsInstanceNameEnumerationElement* m_currentElementP;
  	CIM_CollectionOfMSEsInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    CIM_CollectionOfMSEsInstanceNameEnumeration();
  	  
    CIM_CollectionOfMSEsInstanceNameEnumeration(const CmpiArray& arr);
  	  
    CIM_CollectionOfMSEsInstanceNameEnumeration(const CIM_CollectionOfMSEsInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~CIM_CollectionOfMSEsInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const CIM_CollectionOfMSEsInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const CIM_CollectionOfMSEsInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const CIM_CollectionOfMSEsInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

