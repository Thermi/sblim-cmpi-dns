 /**
 * Linux_DnsIPAddressInstanceName.cpp
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
#include "Linux_DnsIPAddressInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsIPAddressInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsIPAddressInstanceName::
   Linux_DnsIPAddressInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsIPAddressInstanceName::
   Linux_DnsIPAddressInstanceName
   (const Linux_DnsIPAddressInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsIPAddressInstanceName::
   Linux_DnsIPAddressInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiString IPAddress = path.getKey("IPAddress");
    setIPAddress(IPAddress.charPtr());
    
    CmpiString ZoneName = path.getKey("ZoneName");
    setZoneName(ZoneName.charPtr());
    
  }
  
  
  //destructor
  Linux_DnsIPAddressInstanceName::
   ~Linux_DnsIPAddressInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsIPAddressInstanceName&
   Linux_DnsIPAddressInstanceName::operator=
   (const Linux_DnsIPAddressInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsIPAddressInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("IPAddress",CmpiData(m_IPAddress));

  	objectPath.setKey("ZoneName",CmpiData(m_ZoneName));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsIPAddressInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.IPAddress){
  	  cmpiInstance.setProperty("IPAddress",CmpiData(m_IPAddress));
  	}

  	if(isSet.ZoneName){
  	  cmpiInstance.setProperty("ZoneName",CmpiData(m_ZoneName));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsIPAddressInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsIPAddressInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsIPAddress instanceName");
  	return m_namespace;
  }

  void Linux_DnsIPAddressInstanceName::
   setNamespace(const char* val, int makeCopy){
    if (isSet.m_namespace) {
      delete m_namespace;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_namespace = tmpval;
    } else {
      m_namespace = val;
    }
    isSet.m_namespace=1;
  }
       
  //IPAddress related methods
  unsigned int Linux_DnsIPAddressInstanceName::isIPAddressSet() const{
    return isSet.IPAddress;
  }
  void  Linux_DnsIPAddressInstanceName::
   setIPAddress(const char* val, int makeCopy){
    if (isSet.IPAddress) {
      delete []m_IPAddress;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_IPAddress = tmpval;
    } else {
      m_IPAddress = val;
    }
    isSet.IPAddress=1;
  }       
  const char* Linux_DnsIPAddressInstanceName::
   getIPAddress() const{
    
    if(!isSet.IPAddress)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "IPAddress not set");
   	   	
    return m_IPAddress;
  }
       
  //ZoneName related methods
  unsigned int Linux_DnsIPAddressInstanceName::isZoneNameSet() const{
    return isSet.ZoneName;
  }
  void  Linux_DnsIPAddressInstanceName::
   setZoneName(const char* val, int makeCopy){
    if (isSet.ZoneName) {
      delete []m_ZoneName;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ZoneName = tmpval;
    } else {
      m_ZoneName = val;
    }
    isSet.ZoneName=1;
  }       
  const char* Linux_DnsIPAddressInstanceName::
   getZoneName() const{
    
    if(!isSet.ZoneName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ZoneName not set");
   	   	
    return m_ZoneName;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsIPAddressInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsIPAddress";
  	isSet.m_namespace=0;    	
    isSet.IPAddress=0;   	
    isSet.ZoneName=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsIPAddressInstanceName::init
   (const Linux_DnsIPAddressInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isIPAddressSet()){
      const char* IPAddressOriginal=original.getIPAddress();
      setIPAddress(IPAddressOriginal, 1);
    }   	
    if(original.isZoneNameSet()){
      const char* ZoneNameOriginal=original.getZoneName();
      setZoneName(ZoneNameOriginal, 1);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsIPAddressInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);

  	if (isSet.IPAddress)
  	  delete(m_IPAddress);

  	if (isSet.ZoneName)
  	  delete(m_ZoneName);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsIPAddressInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsIPAddressInstanceNameEnumerationElement::
   Linux_DnsIPAddressInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsIPAddressInstanceNameEnumerationElement::
   ~Linux_DnsIPAddressInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsIPAddressInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsIPAddressInstanceNameEnumeration::
   Linux_DnsIPAddressInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsIPAddressInstanceNameEnumeration::
   Linux_DnsIPAddressInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsIPAddressInstanceName(arr[i]));
    }
  }
  
  Linux_DnsIPAddressInstanceNameEnumeration::
   Linux_DnsIPAddressInstanceNameEnumeration(
   const Linux_DnsIPAddressInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsIPAddressInstanceNameEnumeration::
   ~Linux_DnsIPAddressInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsIPAddressInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsIPAddressInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsIPAddressInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsIPAddressInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsIPAddressInstanceName&  
   Linux_DnsIPAddressInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsIPAddressInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsIPAddressInstanceName&
   Linux_DnsIPAddressInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsIPAddressInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsIPAddressInstanceNameEnumeration::addElement
   (const Linux_DnsIPAddressInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsIPAddressInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsIPAddressInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsIPAddressInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsIPAddressInstanceName(elementP);
  	}
  };
  
  Linux_DnsIPAddressInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
