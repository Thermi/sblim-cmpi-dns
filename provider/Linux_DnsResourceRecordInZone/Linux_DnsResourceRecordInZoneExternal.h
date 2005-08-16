 /**
 * Linux_DnsResourceRecordInZoneExternal.h
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
#ifndef Linux_DnsResourceRecordInZoneExternal_h
#define Linux_DnsResourceRecordInZoneExternal_h

#include "Linux_DnsResourceRecordInZoneInstance.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsResourceRecordInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsResourceRecordInZoneExternal {
  	
    public:
    Linux_DnsResourceRecordInZoneExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsResourceRecordInZoneExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsResourceRecordInZoneInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsResourceRecordInZoneInstanceEnumeration&);
     
    virtual Linux_DnsResourceRecordInZoneInstance getInstance(
     const char* *properties,
     const Linux_DnsResourceRecordInZoneInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsResourceRecordInZoneInstance&);
     
    virtual void createInstance(
     const Linux_DnsResourceRecordInZoneInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsResourceRecordInZoneInstanceName&);
    
    //association calls
    
    void referencesGroupComponent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneInstanceEnumeration& instances);

    void referenceNamesGroupComponent( 
     const char *nsp,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneInstanceNameEnumeration& instanceNames);

    void referencesPartComponent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneInstanceEnumeration& instances);

    void referenceNamesPartComponent( 
     const char *nsp,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneInstanceNameEnumeration& instanceNames);

    void associatorsGroupComponent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances);

    void associatorNamesGroupComponent( 
     const char *nsp,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsZoneInstanceNameEnumeration& instanceNames);

    void associatorsPartComponent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInstanceEnumeration& instances);

    void associatorNamesPartComponent( 
     const char *nsp,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInstanceNameEnumeration& instanceNames);

     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
