// =======================================================================
// CIM_ConcreteJobExternal.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
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
