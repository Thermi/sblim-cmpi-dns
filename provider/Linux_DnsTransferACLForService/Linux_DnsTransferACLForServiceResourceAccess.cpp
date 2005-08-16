 /**
 * Linux_DnsTransferACLForServiceResourceAccess.cpp
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
#include "Linux_DnsTransferACLForServiceResourceAccess.h"

#define DNS_ATTR_STR	"allow-transfer"

namespace genProvider {
  
    //Linux_DnsTransferACLForServiceResourceAccess::Linux_DnsTransferACLForServiceResourceAccess();
    Linux_DnsTransferACLForServiceResourceAccess::~Linux_DnsTransferACLForServiceResourceAccess() { };
    
 /* intrinsic methods */

    void Linux_DnsTransferACLForServiceResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsTransferACLForServiceInstanceNameEnumeration& instnames){
      BINDOPTS *sopts = ReadOptions(); 
	char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
	
	if ( ! myoptvalue )
		return;
	
	DnsArray list = DnsArray(myoptvalue);
	DnsArrayConstIterator iter;

	for ( iter = list.begin(); iter != list.end(); ++iter)
	{
		Linux_DnsTransferACLForServiceInstanceName Inst;
		Linux_DnsAddressMatchListInstanceName addrList;
		Linux_DnsServiceInstanceName serviceInstanceName;

		Inst.setNamespace( nsp );
		addrList.setNamespace( nsp );
		
		serviceInstanceName.setNamespace( nsp );
       		serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
        	serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
        	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
        	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
		
		addrList.setName( (*iter).c_str() );
		addrList.setServiceName( DEFAULT_SERVICE_NAME );
		Inst.setSetting( addrList );
		Inst.setElement( serviceInstanceName );
		instnames.addElement(Inst); 
	}
	freeOptions( sopts );
    }


    void Linux_DnsTransferACLForServiceResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsTransferACLForServiceManualInstanceEnumeration& instances){
	 
	BINDOPTS *sopts = ReadOptions(); 
	char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
	
	if ( ! myoptvalue )
		return;
	
	DnsArray list = DnsArray( myoptvalue );
	DnsArrayConstIterator iter;

	for ( iter = list.begin(); iter != list.end(); ++iter)
	{
		Linux_DnsTransferACLForServiceInstanceName Inst;
		Linux_DnsAddressMatchListInstanceName addrList;
		Linux_DnsServiceInstanceName serviceInstanceName;

		Inst.setNamespace( nsp );
		addrList.setNamespace( nsp );
		
		serviceInstanceName.setNamespace( nsp );
       		serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
        	serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
        	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
        	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
	
		addrList.setName( (*iter).c_str() );
		addrList.setServiceName( DEFAULT_SERVICE_NAME, 1 );
		Inst.setSetting( addrList );
		Inst.setElement( serviceInstanceName );
		
		Linux_DnsTransferACLForServiceManualInstance manualInst;
		manualInst.setInstanceName( Inst );
		
		instances.addElement(manualInst); 
	}
	freeOptions( sopts );
    };


    Linux_DnsTransferACLForServiceManualInstance 
     Linux_DnsTransferACLForServiceResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsTransferACLForServiceInstanceName& instanceName){
      Linux_DnsTransferACLForServiceManualInstance instance;
      
        Linux_DnsTransferACLForServiceManualInstance manualInst;
	manualInst.setInstanceName( instanceName );
		
	return manualInst;
   }


    /* void Linux_DnsTransferACLForServiceResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsTransferACLForServiceManualInstance&){}; */


    void Linux_DnsTransferACLForServiceResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsTransferACLForServiceManualInstance& anInstance){
     	BINDOPTS* sopts = ReadOptions();
	char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
	
	DnsArray list;

	if (myoptvalue)
		list.populate(myoptvalue);
	
	list.add( string(anInstance.getInstanceName().getSetting().getName()) );
	setOption(sopts, DNS_ATTR_STR,  list.toString().c_str());
	freeOptions( sopts );
     };


    void Linux_DnsTransferACLForServiceResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsTransferACLForServiceInstanceName& anInstanceName){
     	BINDOPTS* sopts = ReadOptions();
	char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
	
	DnsArray list;

	if (myoptvalue)
		list.populate(myoptvalue);
	
	list.remove( string(anInstanceName.getSetting().getName()) );
	setOption(sopts, DNS_ATTR_STR,  list.toString().c_str());
	freeOptions( sopts );
     };

    
   /* Association Interface */

    void Linux_DnsTransferACLForServiceResourceAccess::referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsTransferACLForServiceManualInstanceEnumeration& instEnum) {
     	Linux_DnsServiceInstanceName serviceInstanceName;

        BINDOPTS *sopts = ReadOptions();
        char *myoptvalue = getOption(sopts,DNS_ATTR_STR);

        if ( ! myoptvalue )
                return;

        DnsArray list = DnsArray(myoptvalue);
        DnsArrayConstIterator iter;

        for ( iter = list.begin(); iter != list.end(); ++iter)
        {
                if ( strcmp( (*iter).c_str(), sourceInst.getName() ) )
                        continue;	

	       	serviceInstanceName.setNamespace( nsp );
       		serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
       		serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
        	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
        	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
		
		Linux_DnsTransferACLForServiceManualInstance inst;
		Linux_DnsTransferACLForServiceInstanceName instName;
		instName.setNamespace( nsp );
		instName.setElement( serviceInstanceName );
		instName.setSetting( sourceInst );
		inst.setInstanceName( instName );
		instEnum.addElement(inst); 
	}
     };


    void Linux_DnsTransferACLForServiceResourceAccess::referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsTransferACLForServiceManualInstanceEnumeration& instEnum) {
        BINDOPTS *sopts = ReadOptions(); 
	char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
	
	if ( ! myoptvalue )
		return;
	
	DnsArray list = DnsArray(myoptvalue);
	DnsArrayConstIterator iter;

	for ( iter = list.begin(); iter != list.end(); ++iter)
	{
		Linux_DnsTransferACLForServiceInstanceName Inst;
		Linux_DnsAddressMatchListInstanceName addrList;
		Linux_DnsServiceInstanceName serviceInstanceName;

		Inst.setNamespace( nsp );
		addrList.setNamespace( nsp );
		
		serviceInstanceName.setNamespace( nsp );
       		serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
        	serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
        	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
        	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
		
		addrList.setName( (*iter).c_str() );
		addrList.setServiceName( DEFAULT_SERVICE_NAME );
		Inst.setNamespace( nsp );
		Inst.setSetting( addrList );
		Inst.setElement( serviceInstanceName );
		
		Linux_DnsTransferACLForServiceManualInstance manualInst;
		manualInst.setInstanceName( Inst );
		
		instEnum.addElement(manualInst); 
	} 
	freeOptions( sopts );
     };


    void Linux_DnsTransferACLForServiceResourceAccess::associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instEnum) {
        Linux_DnsServiceInstance inst;
	Linux_DnsServiceInstanceName instanceName;

        BINDOPTS *sopts = ReadOptions();
        char *myoptvalue = getOption(sopts,DNS_ATTR_STR);

        if ( ! myoptvalue )
                return;

        DnsArray list = DnsArray(myoptvalue);
        DnsArrayConstIterator iter;

        for ( iter = list.begin(); iter != list.end(); ++iter)
        {
                if ( strcmp( (*iter).c_str(), sourceInst.getName() ) )
                        continue;	
	       	instanceName.setNamespace( nsp );
	       	instanceName.setName( DEFAULT_SERVICE_NAME );
	        instanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
	        instanceName.setSystemName( DEFAULT_SYSTEM_NAME );
	        instanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
	
		inst.setInstanceName(instanceName);
	
		instEnum.addElement(inst);
	}
     };


    void Linux_DnsTransferACLForServiceResourceAccess::associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instEnum) {
     	
	ACL *list_acl = ReadACL();
    
	if (! list_acl )
		return;
 
	BINDOPTS *sopts = ReadOptions(); 
	char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
	
	if ( ! myoptvalue )
		return;
	
	DnsArray list = DnsArray(myoptvalue);
	DnsArrayConstIterator iter;

	for ( iter = list.begin(); iter != list.end(); ++iter)
	{
		Linux_DnsAddressMatchListInstance addrInst;
		Linux_DnsAddressMatchListInstanceName addrInstName;
		

		addrInstName.setNamespace( nsp );
		addrInstName.setName( (*iter).c_str() );
		addrInstName.setServiceName( DEFAULT_SERVICE_NAME );
		
		addrInst.setInstanceName( addrInstName );
		char *aclValue = getACL(list_acl, (*iter).c_str());
		if ( ! aclValue )
			continue;
				
		DnsArray aclArray = DnsArray( aclValue );
		addrInst.setAddressList( aclArray.toArray(), aclArray.size() );	
		addrInst.setAddressListType( DNS_AMLTYPE_AML );			
		instEnum.addElement(addrInst); 
	}
	freeOptions( sopts );
	freeACL( list_acl ); 
     };

   
 /* extrinsic methods */
	
}


