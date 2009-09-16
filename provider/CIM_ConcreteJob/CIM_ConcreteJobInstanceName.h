// =======================================================================
// CIM_ConcreteJobInstanceName.h
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
#ifndef CIM_ConcreteJobInstanceName_h
#define CIM_ConcreteJobInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class CIM_ConcreteJobInstanceName {
       
    private:
    void init();
    void init(const CIM_ConcreteJobInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_InstanceID;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int InstanceID:1;

    } isSet;
  
    public:
    CIM_ConcreteJobInstanceName();
  	
    CIM_ConcreteJobInstanceName(const CIM_ConcreteJobInstanceName& anInstanceName);
  	   
    CIM_ConcreteJobInstanceName(const CmpiObjectPath& path);
  	 
    ~CIM_ConcreteJobInstanceName();
       
    CIM_ConcreteJobInstanceName& operator=(const CIM_ConcreteJobInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isInstanceIDSet() const;
    void setInstanceID(const char* aValue, int aCopyFlag = 1);
    const char* getInstanceID() const;


  };
  
  //****************************************************************************
  struct CIM_ConcreteJobInstanceNameEnumerationElement {
  	CIM_ConcreteJobInstanceName* m_elementP;
  	CIM_ConcreteJobInstanceNameEnumerationElement* m_nextP;
  	
  	CIM_ConcreteJobInstanceNameEnumerationElement();
  	~CIM_ConcreteJobInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class CIM_ConcreteJobInstanceNameEnumeration {
  
  	private:
    CIM_ConcreteJobInstanceNameEnumerationElement* m_firstElementP;
  	CIM_ConcreteJobInstanceNameEnumerationElement* m_currentElementP;
  	CIM_ConcreteJobInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    CIM_ConcreteJobInstanceNameEnumeration();
  	  
    CIM_ConcreteJobInstanceNameEnumeration(const CmpiArray& arr);
  	  
    CIM_ConcreteJobInstanceNameEnumeration(const CIM_ConcreteJobInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~CIM_ConcreteJobInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const CIM_ConcreteJobInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const CIM_ConcreteJobInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const CIM_ConcreteJobInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

