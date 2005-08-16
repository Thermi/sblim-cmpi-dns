 /**
 * CIM_ManagedSystemElementExternal.h
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
#ifndef CIM_ManagedSystemElementExternal_h
#define CIM_ManagedSystemElementExternal_h

#include "CIM_ManagedSystemElementInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class CIM_ManagedSystemElementExternal {
  	
    public:
    CIM_ManagedSystemElementExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~CIM_ManagedSystemElementExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     CIM_ManagedSystemElementInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     CIM_ManagedSystemElementInstanceEnumeration&);
     
    virtual CIM_ManagedSystemElementInstance getInstance(
     const char* *properties,
     const CIM_ManagedSystemElementInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const CIM_ManagedSystemElementInstance&);
     
    virtual void createInstance(
     const CIM_ManagedSystemElementInstance&);
     
    virtual void deleteInstance(
     const CIM_ManagedSystemElementInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
