// =======================================================================
// CIM_ConcreteJobExternal.h
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
#ifndef CIM_ConcreteJobExternal_h
#define CIM_ConcreteJobExternal_h


#include "CIM_ConcreteJobInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class CIM_ConcreteJobExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    CIM_ConcreteJobExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~CIM_ConcreteJobExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      CIM_ConcreteJobInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      CIM_ConcreteJobInstanceEnumeration& anInstanceEnumeration);
     
    virtual CIM_ConcreteJobInstance getInstance(
      const char** aPropertiesPP,
      const CIM_ConcreteJobInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const CIM_ConcreteJobInstance& anInstance);
     
    virtual CIM_ConcreteJobInstanceName createInstance(
      const CIM_ConcreteJobInstance& anInstance);
     
    virtual void deleteInstance(
      const CIM_ConcreteJobInstanceName& anInstanceName);

 
  
  };

}

#endif
