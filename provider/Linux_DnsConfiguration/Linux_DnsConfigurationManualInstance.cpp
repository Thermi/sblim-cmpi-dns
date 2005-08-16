 /**
 * Linux_DnsConfigurationManualInstance.cpp
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
#include "Linux_DnsConfigurationManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsConfigurationManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsConfigurationManualInstance::
   Linux_DnsConfigurationManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsConfigurationManualInstance::
   Linux_DnsConfigurationManualInstance
   (const Linux_DnsConfigurationManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsConfigurationManualInstance::
   Linux_DnsConfigurationManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsConfigurationInstanceName(cop));
    
    cmpiData = inst.getProperty("ConfigurationFile");
    if(!cmpiData.isNullValue()){
      CmpiString ConfigurationFile = cmpiData;
      setConfigurationFile(ConfigurationFile.charPtr());
    }
    
  }
  
  
  //Destructor
  Linux_DnsConfigurationManualInstance::
   ~Linux_DnsConfigurationManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsConfigurationManualInstance&
   Linux_DnsConfigurationManualInstance::operator=
   (const Linux_DnsConfigurationManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsConfigurationManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.ConfigurationFile){
  	  cmpiInstance.setProperty("ConfigurationFile",CmpiData(m_ConfigurationFile));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsConfigurationManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsConfigurationInstanceName&
    Linux_DnsConfigurationManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsConfiguration instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsConfigurationManualInstance::setInstanceName(
   const Linux_DnsConfigurationInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //ConfigurationFile related methods
  unsigned int Linux_DnsConfigurationManualInstance::isConfigurationFileSet() const{
    return isSet.ConfigurationFile;
  }
  void  Linux_DnsConfigurationManualInstance::
   setConfigurationFile(const char* val, int makeCopy){
    if (isSet.ConfigurationFile) {
      delete []m_ConfigurationFile;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ConfigurationFile = tmpval;
    } else {
      m_ConfigurationFile = val;
    }
    isSet.ConfigurationFile=1;
  }       
  const char* Linux_DnsConfigurationManualInstance::
   getConfigurationFile() const{
    
    if(!isSet.ConfigurationFile)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ConfigurationFile not set");
   	   	
    return m_ConfigurationFile;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsConfigurationManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.ConfigurationFile=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsConfigurationManualInstance::init
   (const Linux_DnsConfigurationManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isConfigurationFileSet()){
      const char* ConfigurationFileOriginal=original.getConfigurationFile();
      setConfigurationFile(ConfigurationFileOriginal, 1);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsConfigurationManualInstance::reset(){
   	

  	if (isSet.ConfigurationFile)
  	  delete(m_ConfigurationFile);
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsConfigurationManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsConfigurationManualInstanceEnumerationElement::
   Linux_DnsConfigurationManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsConfigurationManualInstanceEnumerationElement::
   ~Linux_DnsConfigurationManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsConfigurationManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsConfigurationManualInstanceEnumeration::
   Linux_DnsConfigurationManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsConfigurationManualInstanceEnumeration::
   Linux_DnsConfigurationManualInstanceEnumeration(
   const Linux_DnsConfigurationManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsConfigurationManualInstanceEnumeration::
   ~Linux_DnsConfigurationManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsConfigurationManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsConfigurationManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsConfigurationManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsConfigurationManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsConfigurationManualInstance&  
   Linux_DnsConfigurationManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsConfigurationManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsConfigurationManualInstance&
   Linux_DnsConfigurationManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsConfigurationManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsConfigurationManualInstanceEnumeration::addElement
   (const Linux_DnsConfigurationManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsConfigurationManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsConfigurationManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsConfigurationManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsConfigurationManualInstance(elementP);
  	}
  };  
}
 
