// =======================================================================
// CmpiLinux_DnsAllowTransferForZoneProvider.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
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
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef CmpiLinux_DnsAllowTransferForZoneProvider_h
#define CmpiLinux_DnsAllowTransferForZoneProvider_h



#include "CmpiInstanceMI.h"
#include "CmpiMethodMI.h"
#include "Linux_DnsAllowTransferForZoneFactory.h"
#include "CmpiAssociationMI.h"


namespace genProvider{

  class CmpiLinux_DnsAllowTransferForZoneProvider : 
    public CmpiInstanceMI,
    public CmpiMethodMI, public CmpiAssociationMI {	
	
	  private:
	  Linux_DnsAllowTransferForZoneInterface* m_interfaceP;
	  CmpiBroker m_cmpiBroker;
	    
	  private:

    void completeInstance(
      const Linux_DnsAllowTransferForZoneInstanceName& anInstanceNameP,
      CmpiInstance& aCmpiInstance,
      const CmpiContext& aContext);
	
    void copyShadowData(
      const CmpiInstance* aSourceCmpiInstanceP,
      CmpiInstance* aTargetCmpiInstanceP);
	
    CmpiInstance* getShadowInstance(
      const CmpiInstance& aCmpiInstance,
      const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName);
	
    void removeDanglingShadowInstances (
      const Linux_DnsAllowTransferForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
	  
	  public:

    CmpiLinux_DnsAllowTransferForZoneProvider(
      const CmpiBroker& aBroker,
      const CmpiContext& aContext);

    ~CmpiLinux_DnsAllowTransferForZoneProvider();
	
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