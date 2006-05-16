// =======================================================================
// Linux_DnsIPAddressInstanceName.h
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
#ifndef Linux_DnsIPAddressInstanceName_h
#define Linux_DnsIPAddressInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsIPAddressInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsIPAddressInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_IPAddress;
    const char* m_ZoneName;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int IPAddress:1;
      unsigned int ZoneName:1;

    } isSet;
  
    public:
    Linux_DnsIPAddressInstanceName();
  	
    Linux_DnsIPAddressInstanceName(const Linux_DnsIPAddressInstanceName& anInstanceName);
  	   
    Linux_DnsIPAddressInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsIPAddressInstanceName();
       
    Linux_DnsIPAddressInstanceName& operator=(const Linux_DnsIPAddressInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isIPAddressSet() const;
    void setIPAddress(const char* aValue, int aCopyFlag = 1);
    const char* getIPAddress() const;

    unsigned int isZoneNameSet() const;
    void setZoneName(const char* aValue, int aCopyFlag = 1);
    const char* getZoneName() const;


  };
  
  //****************************************************************************
  struct Linux_DnsIPAddressInstanceNameEnumerationElement {
  	Linux_DnsIPAddressInstanceName* m_elementP;
  	Linux_DnsIPAddressInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsIPAddressInstanceNameEnumerationElement();
  	~Linux_DnsIPAddressInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsIPAddressInstanceNameEnumeration {
  
  	private:
    Linux_DnsIPAddressInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsIPAddressInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsIPAddressInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsIPAddressInstanceNameEnumeration();
  	  
    Linux_DnsIPAddressInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsIPAddressInstanceNameEnumeration(const Linux_DnsIPAddressInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsIPAddressInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsIPAddressInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsIPAddressInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsIPAddressInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

