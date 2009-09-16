// =======================================================================
// CmpiLinux_DnsAllowRecursionForServiceProvider.h
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
#ifndef CmpiLinux_DnsAllowRecursionForServiceProvider_h
#define CmpiLinux_DnsAllowRecursionForServiceProvider_h



#include "CmpiInstanceMI.h"
#include "CmpiMethodMI.h"
#include "Linux_DnsAllowRecursionForServiceFactory.h"
#include "CmpiAssociationMI.h"


namespace genProvider{

  class CmpiLinux_DnsAllowRecursionForServiceProvider : 
    public CmpiInstanceMI,
    public CmpiMethodMI, public CmpiAssociationMI {	
	
	  private:
	  Linux_DnsAllowRecursionForServiceInterface* m_interfaceP;
	  CmpiBroker m_cmpiBroker;
	    
	  private:

    void completeInstance(
      const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceNameP,
      CmpiInstance& aCmpiInstance,
      const CmpiContext& aContext);
	
    void copyShadowData(
      const CmpiInstance* aSourceCmpiInstanceP,
      CmpiInstance* aTargetCmpiInstanceP);
	
    CmpiInstance* getShadowInstance(
      const CmpiInstance& aCmpiInstance,
      const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName);
	
    void removeDanglingShadowInstances (
      const Linux_DnsAllowRecursionForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
	  
	  public:

    CmpiLinux_DnsAllowRecursionForServiceProvider(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);

    ~CmpiLinux_DnsAllowRecursionForServiceProvider();
	
    int isUnloadable() const;
	
    CmpiStatus enumInstanceNames (
      const CmpiContext& aContext,
      CmpiResult& aResult,
      const CmpiObjectPath& aCop);
     
    CmpiStatus enumInstances (
      const CmpiContext& aContext,
      CmpiResult& aResult,
      const CmpiObjectPath& aCop,
      const char** aPropertiesPP);
     
    CmpiStatus getInstance (
     const CmpiContext& aContext,
     CmpiResult& aResult,
     const CmpiObjectPath& aCop,
     const char** aPropertiesPP);
    
    virtual CmpiStatus createInstance (
     const CmpiContext& aContext,
     CmpiResult& aResult,
     const CmpiObjectPath& aCop,
     const CmpiInstance& anInstance);
    
    virtual CmpiStatus setInstance (
     const CmpiContext& aContext,
     CmpiResult& aResult,
     const CmpiObjectPath& aCop,
     const CmpiInstance& anInstance,
     const char** aPropertiesPP);
    
    virtual CmpiStatus deleteInstance (
     const CmpiContext& aContext,
     CmpiResult& aResult,
     const CmpiObjectPath& aCop);
     
    /*
    virtual CmpiStatus execQuery(
     const CmpiContext& aContext,
     CmpiResult& aResult,
     const CmpiObjectPath& aCop,
     const char* aLanguageP,
     const char* aQueryP);
    */  
      
    virtual CmpiStatus invokeMethod(
     const CmpiContext& aContext,
     CmpiResult& aResult,
     const CmpiObjectPath& aCop,
     const char* aMethodNameP,
     const CmpiArgs& anInputArgSet,
     CmpiArgs& anOutputArgSet);

    CmpiStatus associationLogic(
      const CmpiContext& aContext, 
	    CmpiResult& aResult,
	    const CmpiObjectPath& aCop,
	    const int instances,
	    const int references,
      const char** aPropertiesPP=0);
	
	  CmpiStatus associators (
      const CmpiContext& aContext,
      CmpiResult& aResult,
      const CmpiObjectPath& aCop,
	    const char* anAssocClassNameP, 
	    const char* aResultClassNameP,
      const char* aRoleNameP,
      const char* aResultRoleNameP,
      const char** aPropertiesPP);
    
    CmpiStatus associatorNames (
      const CmpiContext & aContext,
      CmpiResult & aResult,
      const CmpiObjectPath& aCop,
      const char* anAssocClassNameP,
      const char* aResultClassNameP,
      const char* aRoleNameP, 
      const char* aResultRoleNameP);
    
    CmpiStatus references (
      const CmpiContext& aContext,
      CmpiResult& aResult,
      const CmpiObjectPath& aCop,
      const char* anAssocClassNameP,
      const char* aRoleNameP,
      const char** aPropertiesPP);
    
    CmpiStatus referenceNames (
      const CmpiContext& aContext,
      CmpiResult& aResult,
      const CmpiObjectPath& aCop,
      const char* anAssocClassNameP,
      const char* aRoleNameP); 
  };

}

#endif
