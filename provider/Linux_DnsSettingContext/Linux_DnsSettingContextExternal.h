 /**
 * Linux_DnsSettingContextExternal.h
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
#ifndef Linux_DnsSettingContextExternal_h
#define Linux_DnsSettingContextExternal_h

#include "Linux_DnsSettingContextInstance.h"
#include "Linux_DnsConfigurationInstance.h"
#include "Linux_DnsSettingInstance.h"
#include "CmpiBroker.h"

namespace genProvider {

  class Linux_DnsSettingContextExternal {
  	
    public:
    Linux_DnsSettingContextExternal(
     const CmpiBroker& brkr, const CmpiContext& ctx);
    virtual ~Linux_DnsSettingContextExternal();
    
    virtual void enumInstanceNames(
     const char *nsp,
     Linux_DnsSettingContextInstanceNameEnumeration&);
     
    virtual void enumInstances(
     const char *nsp,
     const char* *properties,
     Linux_DnsSettingContextInstanceEnumeration&);
     
    virtual Linux_DnsSettingContextInstance getInstance(
     const char* *properties,
     const Linux_DnsSettingContextInstanceName&);
     
    virtual void setInstance(
     const char* *properties,
     const Linux_DnsSettingContextInstance&);
     
    virtual void createInstance(
     const Linux_DnsSettingContextInstance&);
     
    virtual void deleteInstance(
     const Linux_DnsSettingContextInstanceName&);
    
    //association calls
    
    void referencesContext( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsSettingContextInstanceEnumeration& instances);

    void referenceNamesContext( 
     const char *nsp,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsSettingContextInstanceNameEnumeration& instanceNames);

    void referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingContextInstanceEnumeration& instances);

    void referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingContextInstanceNameEnumeration& instanceNames);

    void associatorsContext( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceEnumeration& instances);

    void associatorNamesContext( 
     const char *nsp,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceNameEnumeration& instanceNames);

    void associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingInstanceEnumeration& instances);

    void associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingInstanceNameEnumeration& instanceNames);

     
    private:
    CmpiBroker  broker;
    CmpiContext context;
  };
}
#endif
