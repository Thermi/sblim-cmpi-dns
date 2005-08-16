 /**
 * CIM_CollectionOfMSEsInstance.h
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
#ifndef CIM_CollectionOfMSEsInstance_h
#define CIM_CollectionOfMSEsInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "CIM_CollectionOfMSEsInstanceName.h"

namespace genProvider {

  class CIM_CollectionOfMSEsInstance {
  public:
       CIM_CollectionOfMSEsInstance();
  	
       CIM_CollectionOfMSEsInstance
  	    (const CIM_CollectionOfMSEsInstance& original);
  	   
       CIM_CollectionOfMSEsInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~CIM_CollectionOfMSEsInstance();
       
       CIM_CollectionOfMSEsInstance& operator=
  	    (const CIM_CollectionOfMSEsInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const CIM_CollectionOfMSEsInstanceName& val);        
       const CIM_CollectionOfMSEsInstanceName&
        getInstanceName() const;

       unsigned int isCaptionSet() const;
       void setCaption(const char* val, int makeCopy = 1);
       const char* getCaption() const;

       unsigned int isCollectionIDSet() const;
       void setCollectionID(const char* val, int makeCopy = 1);
       const char* getCollectionID() const;

       unsigned int isDescriptionSet() const;
       void setDescription(const char* val, int makeCopy = 1);
       const char* getDescription() const;

       unsigned int isElementNameSet() const;
       void setElementName(const char* val, int makeCopy = 1);
       const char* getElementName() const;
       
  private:
       void init();
       void init(const CIM_CollectionOfMSEsInstance& original);
       void reset();
       
       CIM_CollectionOfMSEsInstanceName m_instanceName;
       const char* m_Caption;
       const char* m_CollectionID;
       const char* m_Description;
       const char* m_ElementName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Caption:1;
         unsigned int CollectionID:1;
         unsigned int Description:1;
         unsigned int ElementName:1;
       } isSet;
  };
  
  
  struct CIM_CollectionOfMSEsInstanceEnumerationElement{
  	CIM_CollectionOfMSEsInstance* m_elementP;
  	CIM_CollectionOfMSEsInstanceEnumerationElement* m_nextP;
  	
  	CIM_CollectionOfMSEsInstanceEnumerationElement();
  	~CIM_CollectionOfMSEsInstanceEnumerationElement();  	
  };
  

  class CIM_CollectionOfMSEsInstanceEnumeration {
  	private:
  	  CIM_CollectionOfMSEsInstanceEnumerationElement* firstElementP;
  	  CIM_CollectionOfMSEsInstanceEnumerationElement* currentElementP;
  	  CIM_CollectionOfMSEsInstanceEnumerationElement* endElementP;
  	
  	public:
  	  CIM_CollectionOfMSEsInstanceEnumeration();
  	  
  	  CIM_CollectionOfMSEsInstanceEnumeration(
  	   const CIM_CollectionOfMSEsInstanceEnumeration& original);
  	  
  	  ~CIM_CollectionOfMSEsInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const CIM_CollectionOfMSEsInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const CIM_CollectionOfMSEsInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const CIM_CollectionOfMSEsInstance& elementP);
  };
}
#endif

