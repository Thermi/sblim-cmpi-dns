 /**
 * CIM_ConcreteJobInstanceName.h
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
  public:
       CIM_ConcreteJobInstanceName();
  	
       CIM_ConcreteJobInstanceName
  	    (const CIM_ConcreteJobInstanceName& original);
  	   
       CIM_ConcreteJobInstanceName
        (const CmpiObjectPath& path);
  	 
       ~CIM_ConcreteJobInstanceName();
       
       CIM_ConcreteJobInstanceName& operator=
  	    (const CIM_ConcreteJobInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isInstanceIDSet() const;
       void setInstanceID(const char* val, int makeCopy = 1);
       const char* getInstanceID() const;
       
  private:
       void init();
       void init(const CIM_ConcreteJobInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_InstanceID;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int InstanceID:1;
       } isSet;
  };
  
  
  struct CIM_ConcreteJobInstanceNameEnumerationElement{
  	CIM_ConcreteJobInstanceName* m_elementP;
  	CIM_ConcreteJobInstanceNameEnumerationElement* m_nextP;
  	
  	CIM_ConcreteJobInstanceNameEnumerationElement();
  	~CIM_ConcreteJobInstanceNameEnumerationElement();  	
  };
  

  class CIM_ConcreteJobInstanceNameEnumeration {
  	private:
  	  CIM_ConcreteJobInstanceNameEnumerationElement* firstElementP;
  	  CIM_ConcreteJobInstanceNameEnumerationElement* currentElementP;
  	  CIM_ConcreteJobInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  CIM_ConcreteJobInstanceNameEnumeration();
  	  
  	  CIM_ConcreteJobInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  CIM_ConcreteJobInstanceNameEnumeration(
  	   const CIM_ConcreteJobInstanceNameEnumeration& original);
  	  
  	  ~CIM_ConcreteJobInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const CIM_ConcreteJobInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const CIM_ConcreteJobInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const CIM_ConcreteJobInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

