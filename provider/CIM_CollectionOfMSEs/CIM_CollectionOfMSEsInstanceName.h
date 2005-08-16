 /**
 * CIM_CollectionOfMSEsInstanceName.h
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
  public:
       CIM_CollectionOfMSEsInstanceName();
  	
       CIM_CollectionOfMSEsInstanceName
  	    (const CIM_CollectionOfMSEsInstanceName& original);
  	   
       CIM_CollectionOfMSEsInstanceName
        (const CmpiObjectPath& path);
  	 
       ~CIM_CollectionOfMSEsInstanceName();
       
       CIM_CollectionOfMSEsInstanceName& operator=
  	    (const CIM_CollectionOfMSEsInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;
       
  private:
       void init();
       void init(const CIM_CollectionOfMSEsInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
       } isSet;
  };
  
  
  struct CIM_CollectionOfMSEsInstanceNameEnumerationElement{
  	CIM_CollectionOfMSEsInstanceName* m_elementP;
  	CIM_CollectionOfMSEsInstanceNameEnumerationElement* m_nextP;
  	
  	CIM_CollectionOfMSEsInstanceNameEnumerationElement();
  	~CIM_CollectionOfMSEsInstanceNameEnumerationElement();  	
  };
  

  class CIM_CollectionOfMSEsInstanceNameEnumeration {
  	private:
  	  CIM_CollectionOfMSEsInstanceNameEnumerationElement* firstElementP;
  	  CIM_CollectionOfMSEsInstanceNameEnumerationElement* currentElementP;
  	  CIM_CollectionOfMSEsInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  CIM_CollectionOfMSEsInstanceNameEnumeration();
  	  
  	  CIM_CollectionOfMSEsInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  CIM_CollectionOfMSEsInstanceNameEnumeration(
  	   const CIM_CollectionOfMSEsInstanceNameEnumeration& original);
  	  
  	  ~CIM_CollectionOfMSEsInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const CIM_CollectionOfMSEsInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const CIM_CollectionOfMSEsInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const CIM_CollectionOfMSEsInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

