 /**
 * CIM_ConcreteJobExternal.h
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
#ifndef CIM_ConcreteJobExternal_h
#define CIM_ConcreteJobExternal_h

#include "CIM_ConcreteJobInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class CIM_ConcreteJobExternal {
  	
    public:
    CIM_ConcreteJobExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~CIM_ConcreteJobExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     CIM_ConcreteJobInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     CIM_ConcreteJobInstanceEnumeration&);
     
    virtual CIM_ConcreteJobInstance getInstance(
     const char* *properties,
     const CIM_ConcreteJobInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const CIM_ConcreteJobInstance&);
     
    virtual void createInstance(
     const CIM_ConcreteJobInstance&);
     
    virtual void deleteInstance(
     const CIM_ConcreteJobInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
