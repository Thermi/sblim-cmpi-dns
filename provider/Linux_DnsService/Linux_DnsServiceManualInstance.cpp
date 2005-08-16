 /**
 * Linux_DnsServiceManualInstance.cpp
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
#include "Linux_DnsServiceManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //Linux_DnsServiceManualInstance
  //*********************************************************

  //empty constructor
  Linux_DnsServiceManualInstance::
   Linux_DnsServiceManualInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  Linux_DnsServiceManualInstance::
   Linux_DnsServiceManualInstance
   (const Linux_DnsServiceManualInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  Linux_DnsServiceManualInstance::
   Linux_DnsServiceManualInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(Linux_DnsServiceInstanceName(cop));
    
    cmpiData = inst.getProperty("RunAsRoot");
    if(!cmpiData.isNullValue()){
      CMPIBoolean RunAsRoot = cmpiData;
      setRunAsRoot(RunAsRoot);
    }
    
    cmpiData = inst.getProperty("Started");
    if(!cmpiData.isNullValue()){
      CMPIBoolean Started = cmpiData;
      setStarted(Started);
    }
    
  }
  
  
  //Destructor
  Linux_DnsServiceManualInstance::
   ~Linux_DnsServiceManualInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  Linux_DnsServiceManualInstance&
   Linux_DnsServiceManualInstance::operator=
   (const Linux_DnsServiceManualInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance Linux_DnsServiceManualInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.RunAsRoot){
  	  cmpiInstance.setProperty("RunAsRoot",CmpiBooleanData(m_RunAsRoot));
  	}

  	if(isSet.Started){
  	  cmpiInstance.setProperty("Started",CmpiBooleanData(m_Started));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int Linux_DnsServiceManualInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const Linux_DnsServiceInstanceName&
    Linux_DnsServiceManualInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in Linux_DnsService instance");
  		
   	return m_instanceName;
  }

  void Linux_DnsServiceManualInstance::setInstanceName(
   const Linux_DnsServiceInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //RunAsRoot related methods
  unsigned int Linux_DnsServiceManualInstance::isRunAsRootSet() const{
    return isSet.RunAsRoot;
  }
  void Linux_DnsServiceManualInstance::
   setRunAsRoot(const CMPIBoolean val){
    m_RunAsRoot = val;
    isSet.RunAsRoot=1;
  }       
  const CMPIBoolean Linux_DnsServiceManualInstance::
   getRunAsRoot() const{
    
    if(!isSet.RunAsRoot)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "RunAsRoot not set");
   	   	
    return m_RunAsRoot;
  }
       
  //Started related methods
  unsigned int Linux_DnsServiceManualInstance::isStartedSet() const{
    return isSet.Started;
  }
  void Linux_DnsServiceManualInstance::
   setStarted(const CMPIBoolean val){
    m_Started = val;
    isSet.Started=1;
  }       
  const CMPIBoolean Linux_DnsServiceManualInstance::
   getStarted() const{
    
    if(!isSet.Started)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Started not set");
   	   	
    return m_Started;
  }


  
  //set isSet attributes to FALSE
  void Linux_DnsServiceManualInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.RunAsRoot=0;   	
    isSet.Started=0;  	
  };
  
  
  //copies another instance properties in this
  void Linux_DnsServiceManualInstance::init
   (const Linux_DnsServiceManualInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isRunAsRootSet()){
      const CMPIBoolean RunAsRootOriginal=original.getRunAsRoot();
      setRunAsRoot(RunAsRootOriginal);
    }   	
    if(original.isStartedSet()){
      const CMPIBoolean StartedOriginal=original.getStarted();
      setStarted(StartedOriginal);
    }    
   }
  
  
  //reset the instance data
  void Linux_DnsServiceManualInstance::reset(){
   	
  	  
  };
  
  
  //*********************************************************
  //Linux_DnsServiceManualInstanceEnumerationElement	
  //*********************************************************
  
  Linux_DnsServiceManualInstanceEnumerationElement::
   Linux_DnsServiceManualInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  Linux_DnsServiceManualInstanceEnumerationElement::
   ~Linux_DnsServiceManualInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //Linux_DnsServiceManualInstanceNameEnumeration
  //*********************************************************

  Linux_DnsServiceManualInstanceEnumeration::
   Linux_DnsServiceManualInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  Linux_DnsServiceManualInstanceEnumeration::
   Linux_DnsServiceManualInstanceEnumeration(
   const Linux_DnsServiceManualInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  Linux_DnsServiceManualInstanceEnumeration::
   ~Linux_DnsServiceManualInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void Linux_DnsServiceManualInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool Linux_DnsServiceManualInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int Linux_DnsServiceManualInstanceEnumeration::getSize() const{
  	
    int size=0;
    Linux_DnsServiceManualInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const Linux_DnsServiceManualInstance&  
   Linux_DnsServiceManualInstanceEnumeration::getElement(int pos) const{
   
    Linux_DnsServiceManualInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const Linux_DnsServiceManualInstance&
   Linux_DnsServiceManualInstanceEnumeration::getNext() {
   	
  	 Linux_DnsServiceManualInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void Linux_DnsServiceManualInstanceEnumeration::addElement
   (const Linux_DnsServiceManualInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new Linux_DnsServiceManualInstanceEnumerationElement();
  	  firstElementP->m_elementP=new Linux_DnsServiceManualInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new Linux_DnsServiceManualInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new Linux_DnsServiceManualInstance(elementP);
  	}
  };  
}
 
