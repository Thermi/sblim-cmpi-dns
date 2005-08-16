 /**
 * Linux_DnsMastersOfSlaveZoneExternal.h
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
#ifndef Linux_DnsMastersOfSlaveZoneExternal_h
#define Linux_DnsMastersOfSlaveZoneExternal_h

#include "Linux_DnsMastersOfSlaveZoneInstance.h"
#include "Linux_DnsSlaveZoneInstance.h"
#include "Linux_DnsIPAddressInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneExternal {
  	
    public:
    Linux_DnsMastersOfSlaveZoneExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsMastersOfSlaveZoneExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsMastersOfSlaveZoneInstanceEnumeration&);
     
    virtual Linux_DnsMastersOfSlaveZoneInstance getInstance(
     const char* *properties,
     const Linux_DnsMastersOfSlaveZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsMastersOfSlaveZoneInstance&);
     
    virtual void createInstance(
     const Linux_DnsMastersOfSlaveZoneInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsMastersOfSlaveZoneInstanceName&);
    
    //association calls
    
    void referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneInstanceEnumeration& instances);

    void referenceNamesElement( 
     const char *nsp,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& instanceNames);

    void referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneInstanceEnumeration& instances);

    void referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& instanceNames);

    void associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsSlaveZoneInstanceEnumeration& instances);

    void associatorNamesElement( 
     const char *nsp,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsSlaveZoneInstanceNameEnumeration& instanceNames);

    void associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsIPAddressInstanceEnumeration& instances);

    void associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsIPAddressInstanceNameEnumeration& instanceNames);

     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
