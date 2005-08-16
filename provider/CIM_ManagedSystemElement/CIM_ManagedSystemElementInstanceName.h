 /**
 * CIM_ManagedSystemElementInstanceName.h
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
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
  public:
       CIM_ManagedSystemElementInstanceName();
  	
       CIM_ManagedSystemElementInstanceName
  	    (const CIM_ManagedSystemElementInstanceName& original);
  	   
       CIM_ManagedSystemElementInstanceName
        (const CmpiObjectPath& path);
  	 
       ~CIM_ManagedSystemElementInstanceName();
       
       CIM_ManagedSystemElementInstanceName& operator=
  	    (const CIM_ManagedSystemElementInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;
       
  private:
       void init();
       void init(const CIM_ManagedSystemElementInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
       } isSet;
  };
  
  
  struct CIM_ManagedSystemElementInstanceNameEnumerationElement{
  	CIM_ManagedSystemElementInstanceName* m_elementP;
  	CIM_ManagedSystemElementInstanceNameEnumerationElement* m_nextP;
  	
  	CIM_ManagedSystemElementInstanceNameEnumerationElement();
  	~CIM_ManagedSystemElementInstanceNameEnumerationElement();  	
  };
  

  class CIM_ManagedSystemElementInstanceNameEnumeration {
  	private:
  	  CIM_ManagedSystemElementInstanceNameEnumerationElement* firstElementP;
  	  CIM_ManagedSystemElementInstanceNameEnumerationElement* currentElementP;
  	  CIM_ManagedSystemElementInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  CIM_ManagedSystemElementInstanceNameEnumeration();
  	  
  	  CIM_ManagedSystemElementInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  CIM_ManagedSystemElementInstanceNameEnumeration(
  	   const CIM_ManagedSystemElementInstanceNameEnumeration& original);
  	  
  	  ~CIM_ManagedSystemElementInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const CIM_ManagedSystemElementInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const CIM_ManagedSystemElementInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const CIM_ManagedSystemElementInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

