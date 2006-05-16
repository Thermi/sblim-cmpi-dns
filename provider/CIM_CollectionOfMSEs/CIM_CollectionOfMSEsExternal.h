// =======================================================================
// CIM_CollectionOfMSEsExternal.h
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
#ifndef CIM_CollectionOfMSEsExternal_h
#define CIM_CollectionOfMSEsExternal_h


#include "CIM_CollectionOfMSEsInstance.h"

#include "CmpiBroker.h"

namespace genProvider {

  class CIM_CollectionOfMSEsExternal {
    
    private:
    CmpiBroker m_broker;
    CmpiContext m_context;
  	
    public:
    CIM_CollectionOfMSEsExternal(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);
    virtual ~CIM_CollectionOfMSEsExternal();
    
    virtual void enumInstanceNames(
      const char *aNameSpaceP,
      CIM_CollectionOfMSEsInstanceNameEnumeration& anInstanceNameEnumeration);
     
    virtual void enumInstances(
      const char *anNameSpaceP,
      const char** aPropertiesPP,
      CIM_CollectionOfMSEsInstanceEnumeration& anInstanceEnumeration);
     
    virtual CIM_CollectionOfMSEsInstance getInstance(
      const char** aPropertiesPP,
      const CIM_CollectionOfMSEsInstanceName& anInstanceName);
     
    virtual void setInstance(
      const char** aPropertiesPP,
      const CIM_CollectionOfMSEsInstance& anInstance);
     
    virtual CIM_CollectionOfMSEsInstanceName createInstance(
      const CIM_CollectionOfMSEsInstance& anInstance);
     
    virtual void deleteInstance(
      const CIM_CollectionOfMSEsInstanceName& anInstanceName);

 
  
  };

}

#endif
