 /**
 * Linux_DnsAddressMatchListManualInstance.cpp
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
#include "Linux_DnsAddressMatchListManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsAddressMatchListManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsAddressMatchListManualInstance::
   Linux_DnsAddressMatchListManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsAddressMatchListManualInstance::
   Linux_DnsAddressMatchListManualInstance
   (const Linux_DnsAddressMatchListManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsAddressMatchListManualInstance::
   Linux_DnsAddressMatchListManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsAddressMatchListInstanceName(cop));
    
    cmpiData = inst.getProperty("AddressListType");
    if(!cmpiData.isNullValue()){
      CMPIUint16 AddressListType = cmpiData;
      setAddressListType(AddressListType);
    }
    
    cmpiData = inst.getProperty("AddressList");
    if(!cmpiData.isNullValue()){
      CmpiArray AddressList = cmpiData;
      unsigned int AddressListSize;
      const char** AddressListArray;
      ArrayConverter::makeArray(AddressList, (char***)&AddressListArray, AddressListSize);
      setAddressList(AddressListArray, AddressListSize, 0);
    }
    
  }
  
  
  //Destructor
  Linux_DnsAddressMatchListManualInstance::
   ~Linux_DnsAddressMatchListManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAddressMatchListManualInstance&
   Linux_DnsAddressMatchListManualInstance::operator=
   (const Linux_DnsAddressMatchListManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsAddressMatchListManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.AddressListType){
  	  cmpiInstance.setProperty("AddressListType",CmpiData(m_AddressListType));
  	}

  	if(isSet.AddressList){
  	  unsigned int AddressListSize;
      const char** arrayAddressList=getAddressList(AddressListSize);
      CmpiArray arrayCmpiAddressList=CmpiArray(AddressListSize,CMPI_chars);
      for(unsigned int i=0;i<AddressListSize;i++)
        arrayCmpiAddressList[i]=CmpiData(arrayAddressList[i]);
  	cmpiInstance.setProperty("AddressList",CmpiData(arrayCmpiAddressList));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsAddressMatchListManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsAddressMatchListInstanceName&
    Linux_DnsAddressMatchListManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsAddressMatchList instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsAddressMatchListManualInstance::setInstanceName(
   const Linux_DnsAddressMatchListInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //AddressListType related methods
  unsigned int Linux_DnsAddressMatchListManualInstance::isAddressListTypeSet() const{
    return isSet.AddressListType;
  }
  void Linux_DnsAddressMatchListManualInstance::
   setAddressListType(const CMPIUint16 val){
    m_AddressListType = val;
    isSet.AddressListType=1;
  }       
  const CMPIUint16 Linux_DnsAddressMatchListManualInstance::
   getAddressListType() const{
    
    if(!isSet.AddressListType)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "AddressListType not set");
   	   	
    return m_AddressListType;
  }
       
  //AddressList related methods
  unsigned int Linux_DnsAddressMatchListManualInstance::isAddressListSet() const{
    return isSet.AddressList;
  }
  void  Linux_DnsAddressMatchListManualInstance::
   setAddressList(const char** val, const unsigned int size, int makeCopy){
    AddressListArraySize=size;
    if (isSet.AddressList) {
      delete m_AddressList;
    }
    if (makeCopy&&val) {
      m_AddressList = new const char*[size];
      for(unsigned int i=0;i<size;i++){
        char* aString = new char[strlen(val[i])+1];
        strcpy(aString,val[i]);
        m_AddressList[i]=aString;
      }      
    } else {
      m_AddressList = val;
    }
    isSet.AddressList=1;
  }       
  const char** Linux_DnsAddressMatchListManualInstance::
   getAddressList(unsigned int& size) const{
    
    if(!isSet.AddressList)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "AddressList not set");
   	   	
    size=AddressListArraySize;
    return m_AddressList;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsAddressMatchListManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.AddressListType=0;   	
    isSet.AddressList=0;   	
    AddressListArraySize=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsAddressMatchListManualInstance::init
   (const Linux_DnsAddressMatchListManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isAddressListTypeSet()){
      const CMPIUint16 AddressListTypeOriginal=original.getAddressListType();
      setAddressListType(AddressListTypeOriginal);
    }   	
    if(original.isAddressListSet()){
      unsigned int sizeAddressList;
    const char** AddressListOriginal=original.getAddressList(sizeAddressList);
      setAddressList(AddressListOriginal, sizeAddressList, 1);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsAddressMatchListManualInstance::reset(){
   	

  	if (isSet.AddressList){
  	  ArrayConverter::destructArray((char**)(char**)m_AddressList,AddressListArraySize);
  	}
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsAddressMatchListManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsAddressMatchListManualInstanceEnumerationElement::
   Linux_DnsAddressMatchListManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAddressMatchListManualInstanceEnumerationElement::
   ~Linux_DnsAddressMatchListManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAddressMatchListManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsAddressMatchListManualInstanceEnumeration::
   Linux_DnsAddressMatchListManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAddressMatchListManualInstanceEnumeration::
   Linux_DnsAddressMatchListManualInstanceEnumeration(
   const Linux_DnsAddressMatchListManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAddressMatchListManualInstanceEnumeration::
   ~Linux_DnsAddressMatchListManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAddressMatchListManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAddressMatchListManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAddressMatchListManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsAddressMatchListManualInstance&  
   Linux_DnsAddressMatchListManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAddressMatchListManualInstance&
   Linux_DnsAddressMatchListManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsAddressMatchListManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAddressMatchListManualInstanceEnumeration::addElement
   (const Linux_DnsAddressMatchListManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAddressMatchListManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAddressMatchListManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAddressMatchListManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAddressMatchListManualInstance(elementP);
  	}
  };  
}
 
