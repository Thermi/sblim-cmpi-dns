 /**
 * Linux_DnsMasterZoneInstanceName.h
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
  public:
       Linux_DnsMasterZoneInstanceName();
  	
       Linux_DnsMasterZoneInstanceName
  	    (const Linux_DnsMasterZoneInstanceName& original);
  	   
       Linux_DnsMasterZoneInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsMasterZoneInstanceName();
       
       Linux_DnsMasterZoneInstanceName& operator=
  	    (const Linux_DnsMasterZoneInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isNameSet() const;
       void setName(const char* val, int makeCopy = 1);
       const char* getName() const;
       
  private:
       void init();
       void init(const Linux_DnsMasterZoneInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_Name;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Name:1;
       } isSet;
  };
  
  
  struct Linux_DnsMasterZoneInstanceNameEnumerationElement{
  	Linux_DnsMasterZoneInstanceName* m_elementP;
  	Linux_DnsMasterZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsMasterZoneInstanceNameEnumerationElement();
  	~Linux_DnsMasterZoneInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsMasterZoneInstanceNameEnumeration {
  	private:
  	  Linux_DnsMasterZoneInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsMasterZoneInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsMasterZoneInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsMasterZoneInstanceNameEnumeration();
  	  
  	  Linux_DnsMasterZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsMasterZoneInstanceNameEnumeration(
  	   const Linux_DnsMasterZoneInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsMasterZoneInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsMasterZoneInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsMasterZoneInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsMasterZoneInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

