// =======================================================================
// CIM_ManagedSystemElementExternal.h
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
#ifndef CIM_ManagedSystemElementExternal_h
#define CIM_ManagedSystemElementExternal_h


#include "CIM_ManagedSystemElementInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class CIM_ManagedSystemElementExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    CIM_ManagedSystemElementExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~CIM_ManagedSystemElementExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      CIM_ManagedSystemElementInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      CIM_ManagedSystemElementInstanceEnumeration& anInstanceEnumeration);
     
    virtual CIM_ManagedSystemElementInstance getInstance(
      const char** aPropertiesPP,
      const CIM_ManagedSystemElementInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const CIM_ManagedSystemElementInstance& anInstance);
     
    virtual CIM_ManagedSystemElementInstanceName createInstance(
      const CIM_ManagedSystemElementInstance& anInstance);
     
    virtual void deleteInstance(
      const CIM_ManagedSystemElementInstanceName& anInstanceName);

 
  
  };

}

#endif
