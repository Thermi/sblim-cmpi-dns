 /**
 * Linux_DnsAddressMatchListOfServiceResourceAccess.cpp
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
#include "Linux_DnsAddressMatchListOfServiceResourceAccess.h"

namespace genProvider {
  
    //Linux_DnsAddressMatchListOfServiceResourceAccess::Linux_DnsAddressMatchListOfServiceResourceAccess();
    Linux_DnsAddressMatchListOfServiceResourceAccess::~Linux_DnsAddressMatchListOfServiceResourceAccess() { };
    
    /* intrinsic methods */
    /*
    void Linux_DnsAddressMatchListOfServiceResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& instnames){
      
      int numInstanceNames=1;
      for(int i=0;i<numInstanceNames;i++){
      
        //place here the code retrieving your instanceName
      
        Linux_DnsAddressMatchListOfServiceInstanceName instanceName;
        
      }      
    }
    */
  	/*
    void Linux_DnsAddressMatchListOfServiceResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& instances){};
  	*/
  	/*
    Linux_DnsAddressMatchListOfServiceManualInstance 
     Linux_DnsAddressMatchListOfServiceResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAddressMatchListOfServiceInstanceName&){
      Linux_DnsAddressMatchListOfServiceManualInstance instance;
      
    }
  	*/
  	/*
    void Linux_DnsAddressMatchListOfServiceResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAddressMatchListOfServiceManualInstance&){};
  	*/
  	/*
    void Linux_DnsAddressMatchListOfServiceResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListOfServiceManualInstance&){};
  	*/
  	/*
    void Linux_DnsAddressMatchListOfServiceResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListOfServiceInstanceName&){};
	*/
    
    /* Association Interface */
    void Linux_DnsAddressMatchListOfServiceResourceAccess::referencesAntecedent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& instEnum) {
     
        ACL *list_acl = ReadACL();
	ACL *all_acls = list_acl;

        if (list_acl)
        {
            for (; list_acl->key; list_acl++)
            {
	    	if ( strcmp( list_acl->key, sourceInst.getName() ) != 0 )
			continue;
	    
                Linux_DnsAddressMatchListInstanceName aclInstanceName;
		
                aclInstanceName.setNamespace( nsp );
                aclInstanceName.setName( list_acl->key );
		aclInstanceName.setServiceName( DEFAULT_SERVICE_NAME );

		Linux_DnsServiceInstanceName serviceInstanceName;

		serviceInstanceName.setNamespace( nsp );
		serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
		serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
		serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
		serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
			
		Linux_DnsAddressMatchListOfServiceManualInstance aManualInstance;
		Linux_DnsAddressMatchListOfServiceInstanceName anInstanceName;
	
		anInstanceName.setNamespace( nsp );	
		anInstanceName.setAntecedent( serviceInstanceName );
		anInstanceName.setDependent( aclInstanceName );
		
		aManualInstance.setInstanceName( anInstanceName );
		
                instEnum.addElement( aManualInstance );
            }
        }
	freeACL( all_acls );
     };
    
    void Linux_DnsAddressMatchListOfServiceResourceAccess::referencesDependent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& instEnum) {

        ACL *list_acl = ReadACL();
	ACL *all_acls = list_acl;

        if (list_acl)
        {
            for (; list_acl->key; list_acl++)
            {	    
                Linux_DnsAddressMatchListInstanceName aclInstanceName;
		
                aclInstanceName.setNamespace( nsp );
                aclInstanceName.setName( list_acl->key );
		aclInstanceName.setServiceName( DEFAULT_SERVICE_NAME );

		Linux_DnsServiceInstanceName serviceInstanceName;

		serviceInstanceName.setNamespace( nsp );
		serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
		serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
		serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
		serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
			
		Linux_DnsAddressMatchListOfServiceManualInstance aManualInstance;
		Linux_DnsAddressMatchListOfServiceInstanceName anInstanceName;
		
		anInstanceName.setNamespace( nsp );
		anInstanceName.setAntecedent( serviceInstanceName );
		anInstanceName.setDependent( aclInstanceName );
		
		aManualInstance.setInstanceName( anInstanceName );
		
                instEnum.addElement( aManualInstance );
            }
        }
        freeACL( all_acls );
     };
    
    
    void Linux_DnsAddressMatchListOfServiceResourceAccess::associatorsAntecedent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instEnum) {

        ACL *list_acl = ReadACL();
	ACL *all_acls = list_acl;

        if (list_acl)
        {
            for (; list_acl->key; list_acl++)
            {	    
	    	if ( strcmp( list_acl->key, sourceInst.getName() ) != 0 )
			continue;
	    	    
                Linux_DnsAddressMatchListInstanceName aclInstanceName;
		
                aclInstanceName.setNamespace( nsp );
                aclInstanceName.setName( list_acl->key );
		aclInstanceName.setServiceName( DEFAULT_SERVICE_NAME );

		Linux_DnsServiceInstanceName instanceName;

		instanceName.setNamespace(nsp);
		instanceName.setName(DEFAULT_SERVICE_NAME);
		instanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
		instanceName.setSystemName(DEFAULT_SYSTEM_NAME);
		instanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
		
		Linux_DnsServiceInstance inst;
		inst.setInstanceName( instanceName );
		
		instEnum.addElement( inst );
	    }
     	}
	freeACL( all_acls );
     };
    
    
    void Linux_DnsAddressMatchListOfServiceResourceAccess::associatorsDependent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instEnum) {

        ACL *list_acl = ReadACL();
	ACL *all_acls = list_acl;

        if (list_acl)
        {
            for (; list_acl->key; list_acl++)
            {	    
                Linux_DnsAddressMatchListInstanceName aclInstanceName;
		
                aclInstanceName.setNamespace( nsp );
                aclInstanceName.setName( list_acl->key );
		aclInstanceName.setServiceName( DEFAULT_SERVICE_NAME );

		Linux_DnsAddressMatchListInstance inst;
		inst.setInstanceName( aclInstanceName );
		
                instEnum.addElement( inst );
            }
        }
	freeACL( all_acls );
          
     };
    
   
    /* extrinsic methods */
	
}


