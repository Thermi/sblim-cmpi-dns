 /**
 * Linux_DnsElementSettingExternal.h
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
#ifndef Linux_DnsElementSettingExternal_h
#define Linux_DnsElementSettingExternal_h

#include "Linux_DnsElementSettingInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsSettingInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsElementSettingExternal {
  	
    public:
    Linux_DnsElementSettingExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsElementSettingExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsElementSettingInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsElementSettingInstanceEnumeration&);
     
    virtual Linux_DnsElementSettingInstance getInstance(
     const char* *properties,
     const Linux_DnsElementSettingInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsElementSettingInstance&);
     
    virtual void createInstance(
     const Linux_DnsElementSettingInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsElementSettingInstanceName&);
    
    //association calls
    
    void referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsElementSettingInstanceEnumeration& instances);

    void referenceNamesElement( 
     const char *nsp,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsElementSettingInstanceNameEnumeration& instanceNames);

    void referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsElementSettingInstanceEnumeration& instances);

    void referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsElementSettingInstanceNameEnumeration& instanceNames);

    void associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances);

    void associatorNamesElement( 
     const char *nsp,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsServiceInstanceNameEnumeration& instanceNames);

    void associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsSettingInstanceEnumeration& instances);

    void associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsSettingInstanceNameEnumeration& instanceNames);

     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
