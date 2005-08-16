 /**
 * CIM_CollectionOfMSEsExternal.h
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
#ifndef CIM_CollectionOfMSEsExternal_h
#define CIM_CollectionOfMSEsExternal_h

#include "CIM_CollectionOfMSEsInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class CIM_CollectionOfMSEsExternal {
  	
    public:
    CIM_CollectionOfMSEsExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~CIM_CollectionOfMSEsExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     CIM_CollectionOfMSEsInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     CIM_CollectionOfMSEsInstanceEnumeration&);
     
    virtual CIM_CollectionOfMSEsInstance getInstance(
     const char* *properties,
     const CIM_CollectionOfMSEsInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const CIM_CollectionOfMSEsInstance&);
     
    virtual void createInstance(
     const CIM_CollectionOfMSEsInstance&);
     
    virtual void deleteInstance(
     const CIM_CollectionOfMSEsInstanceName&);
     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
