// =======================================================================
// Linux_DnsMastersResourceAccess.h
//     created on Fri, 27 Oct 2006 using ECUTE 2.2
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
#ifndef Linux_DnsMastersResourceAccess_h
#define Linux_DnsMastersResourceAccess_h

#include "Linux_DnsMastersInstanceName.h"
#include "Linux_DnsMastersManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsMastersDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsMastersResourceAccess:
   public Linux_DnsMastersDefaultImplementation {
  	
    public:
    /*
    Linux_DnsMastersResourceAccess();
    */    
    virtual ~Linux_DnsMastersResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsMastersInstanceNameEnumeration& anInstanceNameEnumeration);
  	
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsMastersManualInstanceEnumeration& aManualInstanceEnumeration);
  	
    virtual Linux_DnsMastersManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsMastersInstanceName& anInstanceName);
  	
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsMastersManualInstance& aManualInstance);
  	
    virtual Linux_DnsMastersInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMastersManualInstance& aManualInstance);
  	
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMastersInstanceName& anInstanceName);
	
    
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
