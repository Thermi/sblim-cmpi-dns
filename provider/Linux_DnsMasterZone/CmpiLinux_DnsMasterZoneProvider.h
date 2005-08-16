 /**
 * CmpiLinux_DnsMasterZoneProvider.h
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
#ifndef CmpiLinux_DnsMasterZoneProvider_h
#define CmpiLinux_DnsMasterZoneProvider_h

#include "CmpiInstanceMI.h"
#include "CmpiMethodMI.h"
#include "Linux_DnsMasterZoneFactory.h"

 namespace genProvider{

  class CmpiLinux_DnsMasterZoneProvider : public CmpiInstanceMI,
   public CmpiMethodMI{	
	
	private:

	Linux_DnsMasterZoneInterface* interfaceP;
	const static char * shadowNameSpaceP;
	CmpiBroker cppBroker;
	    
    void completeInstance (
     const Linux_DnsMasterZoneInstanceName& intanceNameP,
     CmpiInstance& target, const CmpiContext& ctx);
	
    void copyShadowData (
     const CmpiInstance* source, CmpiInstance* target);
	
    CmpiInstance* getShadowInstance (
     const CmpiInstance& original,
     const Linux_DnsMasterZoneInstanceName& intanceName);
	
    void removeDanglingShadowInstances (
     const Linux_DnsMasterZoneInstanceNameEnumeration& dinInsNames);

	  
	public:

    CmpiLinux_DnsMasterZoneProvider (
     const CmpiBroker &mbp, const CmpiContext& ctx);

    ~CmpiLinux_DnsMasterZoneProvider ();
	
    int isUnloadable() const;
	
    CmpiStatus enumInstanceNames (
     const CmpiContext& ctx, CmpiResult& rslt,
     const CmpiObjectPath& cop);
     
    CmpiStatus enumInstances (
     const CmpiContext& ctx, CmpiResult& rslt,
     const CmpiObjectPath& cop,
     const char* *properties);
     
    CmpiStatus getInstance (
     const CmpiContext& ctx, CmpiResult& rslt,
     const CmpiObjectPath& cop,
     const char* *properties);
    
    virtual CmpiStatus createInstance (
     const CmpiContext& ctx, CmpiResult& rslt,
     const CmpiObjectPath& cop,
     const CmpiInstance& inst);
    
    virtual CmpiStatus setInstance (
     const CmpiContext& ctx, CmpiResult& rslt,
     const CmpiObjectPath& cop,
     const CmpiInstance& inst,
     const char* *properties);
    
    virtual CmpiStatus deleteInstance (
     const CmpiContext& ctx, CmpiResult& rslt,
     const CmpiObjectPath& cop);
     
    /*
    virtual CmpiStatus execQuery (
     const CmpiContext& ctx, CmpiResult& rslt,
     const CmpiObjectPath& cop,
     const char* language,
     const char* query);
    */  
      
    virtual CmpiStatus invokeMethod (
     const CmpiContext& ctx, CmpiResult& rslt,
     const CmpiObjectPath& ref,
     const char* methodName,
     const CmpiArgs& in,
     CmpiArgs& out);
 
  };
}

#endif