 /**
 * Linux_DnsAddressMatchListOfServiceInstanceName.cpp
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
#include "Linux_DnsAddressMatchListOfServiceInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //*********************************************************
  //Linux_DnsAddressMatchListOfServiceInstanceName
  //*********************************************************
  
  //empty constructor
  Linux_DnsAddressMatchListOfServiceInstanceName::
   Linux_DnsAddressMatchListOfServiceInstanceName(){
   	init();  	
  };
  
  
  //copy constructor	
  Linux_DnsAddressMatchListOfServiceInstanceName::
   Linux_DnsAddressMatchListOfServiceInstanceName
   (const Linux_DnsAddressMatchListOfServiceInstanceName& original){
   	init(original);  	
  };
  
  
  //contructor using CmpiObjectPath
  Linux_DnsAddressMatchListOfServiceInstanceName::
   Linux_DnsAddressMatchListOfServiceInstanceName (const CmpiObjectPath& path){
    
    init();
    
    m_CIMClassNameP=path.getClassName().charPtr();
    
    CmpiString namespaceOP;
    namespaceOP=path.getNameSpace();
    setNamespace(namespaceOP.charPtr(),1);
    
    CmpiObjectPath Antecedent = path.getKey("Antecedent");
    setAntecedent(Linux_DnsServiceInstanceName(Antecedent));
    
    CmpiObjectPath Dependent = path.getKey("Dependent");
    setDependent(Linux_DnsAddressMatchListInstanceName(Dependent));
    
  }
  
  
  //destructor
  Linux_DnsAddressMatchListOfServiceInstanceName::
   ~Linux_DnsAddressMatchListOfServiceInstanceName(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsAddressMatchListOfServiceInstanceName&
   Linux_DnsAddressMatchListOfServiceInstanceName::operator=
   (const Linux_DnsAddressMatchListOfServiceInstanceName& original){    
    init(original);
   	return *this;    
  }
  
  
  //returns the related CmpiObjectPath
  CmpiObjectPath Linux_DnsAddressMatchListOfServiceInstanceName::
   getObjectPath() const{
   	
   	CmpiObjectPath objectPath(m_namespace, m_CIMClassNameP);

  	objectPath.setKey("Antecedent",CmpiData(m_Antecedent.getObjectPath()));

  	objectPath.setKey("Dependent",CmpiData(m_Dependent.getObjectPath()));
  	
  	return objectPath;
  	
  }
  
  
  //adds the related CmpiObjectPath to an existing cmpiInstance
  void Linux_DnsAddressMatchListOfServiceInstanceName::fillKeys(CmpiInstance& cmpiInstance) const{
  	

  	if(isSet.Antecedent){
  	  cmpiInstance.setProperty("Antecedent",CmpiData(m_Antecedent.getObjectPath()));
  	}

  	if(isSet.Dependent){
  	  cmpiInstance.setProperty("Dependent",CmpiData(m_Dependent.getObjectPath()));
  	}
  }
  
  
  //NameSpace related methods
  unsigned int Linux_DnsAddressMatchListOfServiceInstanceName::
   isNameSpaceSet() const{
  	return isSet.m_namespace;
  }
  
  const char * Linux_DnsAddressMatchListOfServiceInstanceName::
   getNamespace() const {
    if(!isSet.m_namespace)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace not set in Linux_DnsAddressMatchListOfService instanceName");
  	return m_namespace;
  }

  void Linux_DnsAddressMatchListOfServiceInstanceName::
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
       
  //Antecedent related methods
  unsigned int Linux_DnsAddressMatchListOfServiceInstanceName::isAntecedentSet() const{
    return isSet.Antecedent;
  }
  void Linux_DnsAddressMatchListOfServiceInstanceName::
   setAntecedent(const Linux_DnsServiceInstanceName& val){
    m_Antecedent = val;
    isSet.Antecedent=1;
  }       
  const Linux_DnsServiceInstanceName& Linux_DnsAddressMatchListOfServiceInstanceName::
   getAntecedent() const{
    
    if(!isSet.Antecedent)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Antecedent not set");
   	   	
    return m_Antecedent;
  }
       
  //Dependent related methods
  unsigned int Linux_DnsAddressMatchListOfServiceInstanceName::isDependentSet() const{
    return isSet.Dependent;
  }
  void Linux_DnsAddressMatchListOfServiceInstanceName::
   setDependent(const Linux_DnsAddressMatchListInstanceName& val){
    m_Dependent = val;
    isSet.Dependent=1;
  }       
  const Linux_DnsAddressMatchListInstanceName& Linux_DnsAddressMatchListOfServiceInstanceName::
   getDependent() const{
    
    if(!isSet.Dependent)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Dependent not set");
   	   	
    return m_Dependent;
  }

  
  //set isSet variables to FALSE
  void Linux_DnsAddressMatchListOfServiceInstanceName::init(){
  	
  	m_CIMClassNameP="Linux_DnsAddressMatchListOfService";
  	isSet.m_namespace=0;    	
    isSet.Antecedent=0;   	
    isSet.Dependent=0;
  }
  
  
  //copies another instance properties in this
  void Linux_DnsAddressMatchListOfServiceInstanceName::init
   (const Linux_DnsAddressMatchListOfServiceInstanceName& original){
   	init();
   	   	
    m_CIMClassNameP=original.m_CIMClassNameP;
    if(original.isNameSpaceSet()){
      setNamespace(original.getNamespace(),1);
    }   	
    if(original.isAntecedentSet()){
      const Linux_DnsServiceInstanceName& AntecedentOriginal=original.getAntecedent();
      setAntecedent(AntecedentOriginal);
    }   	
    if(original.isDependentSet()){
      const Linux_DnsAddressMatchListInstanceName& DependentOriginal=original.getDependent();
      setDependent(DependentOriginal);
    }    
  }
  
  //reset the instanceName data
  void Linux_DnsAddressMatchListOfServiceInstanceName::reset(){   	
  	if (isSet.m_namespace)
  	  delete(m_namespace);  	  
  };
  
  
  
  
  //*********************************************************
  //Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement	
  //*********************************************************
  
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement::
   Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement::
   ~Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration
  //*********************************************************
  
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::
   Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::
   Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(const CmpiArray& arr){
  	
  	firstElementP=0;
    currentElementP=0;
    endElementP=0;
    
    int size = arr.size();
    for (int i=0; i < size; i++) {
     addElement(Linux_DnsAddressMatchListOfServiceInstanceName(arr[i]));
    }
  }
  
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::
   Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(
   const Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::
   ~Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
  };
  
  const Linux_DnsAddressMatchListOfServiceInstanceName&  
   Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::getElement(int pos) const{
   
    Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsAddressMatchListOfServiceInstanceName&
   Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::addElement
   (const Linux_DnsAddressMatchListOfServiceInstanceName& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsAddressMatchListOfServiceInstanceName(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsAddressMatchListOfServiceInstanceName(elementP);
  	}
  };
  
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::operator CmpiArray() const{
  	int size=getSize();
   	CmpiArray arr=CmpiArray(size,CMPI_instance);
   	for(int i=0;i<size;i++){
   	  arr[i]=getElement(i).getObjectPath();
   	}
   	return arr;
  };  
}
 
