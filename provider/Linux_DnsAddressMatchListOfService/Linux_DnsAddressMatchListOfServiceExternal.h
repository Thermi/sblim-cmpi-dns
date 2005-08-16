 /**
 * Linux_DnsAddressMatchListOfServiceExternal.h
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
#ifndef Linux_DnsAddressMatchListOfServiceExternal_h
#define Linux_DnsAddressMatchListOfServiceExternal_h

#include "Linux_DnsAddressMatchListOfServiceInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceExternal {
  	
    public:
    Linux_DnsAddressMatchListOfServiceExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsAddressMatchListOfServiceExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsAddressMatchListOfServiceInstanceEnumeration&);
     
    virtual Linux_DnsAddressMatchListOfServiceInstance getInstance(
     const char* *properties,
     const Linux_DnsAddressMatchListOfServiceInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsAddressMatchListOfServiceInstance&);
     
    virtual void createInstance(
     const Linux_DnsAddressMatchListOfServiceInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsAddressMatchListOfServiceInstanceName&);
    
    //association calls
    
    void referencesAntecedent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAddressMatchListOfServiceInstanceEnumeration& instances);

    void referenceNamesAntecedent( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& instanceNames);

    void referencesDependent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListOfServiceInstanceEnumeration& instances);

    void referenceNamesDependent( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& instanceNames);

    void associatorsAntecedent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances);

    void associatorNamesAntecedent( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceNameEnumeration& instanceNames);

    void associatorsDependent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances);

    void associatorNamesDependent( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceNameEnumeration& instanceNames);

     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
