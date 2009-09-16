// =======================================================================
// Linux_DnsServiceConfigurationResourceAccess.cpp
//     created on Thu, 26 Oct 2006 using ECUTE 2.2
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
#include "Linux_DnsServiceConfigurationResourceAccess.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_defaultvalues.h"
#include "smt_dns_ra_support.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceConfigurationResourceAccess::Linux_DnsServiceConfigurationResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationResourceAccess::~Linux_DnsServiceConfigurationResourceAccess() { }
    
  // intrinsic methods
 //----------------------------------------------------------------------------

  void
  Linux_DnsServiceConfigurationResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfiguration::enumInstanceNames" << endl;
#endif
    Linux_DnsServiceConfigurationInstanceName instanceName;

    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);

    anInstanceNameEnumeration.addElement(instanceName);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfiguration::enumInstanceNames" << endl;
#endif
  } 
//----------------------------------------------------------------------------
  
  void
  Linux_DnsServiceConfigurationResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfiguration::enumInstances" << endl;
#endif

    Linux_DnsServiceConfigurationInstanceName instanceName;
    Linux_DnsServiceConfigurationManualInstance aManualInstance;

    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);

    aManualInstance.setInstanceName(instanceName);
    aManualInstance.setConfigurationFile(get_bindconf());

    aManualInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfiguration::enumInstances" << endl;
#endif
}
  
//----------------------------------------------------------------------------
  
  Linux_DnsServiceConfigurationManualInstance 
  Linux_DnsServiceConfigurationResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfiguration::getInstance" << endl;
#endif

    //Check whether the said instanc exists, else throw exception.
    if (strcasecmp(anInstanceName.getName(),DEFAULT_SERVICE_NAME)!=0) {
        throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Instance does not exist!");
     }

    Linux_DnsServiceConfigurationManualInstance aManualInstance;

    aManualInstance.setInstanceName(anInstanceName);
    aManualInstance.setConfigurationFile(get_bindconf());

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfiguration::getInstance" << endl;
#endif
    return aManualInstance;
}
  //----------------------------------------------------------------------------
 
  void
  Linux_DnsServiceConfigurationResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsServiceConfigurationManualInstance& aManualInstance) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfiguration::setInstance" << endl;
#endif

     if (strcasecmp(aManualInstance.getInstanceName().getName(),DEFAULT_SERVICE_NAME)!=0) {
        throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Instance does not exist!");
     }
  
     if (!aManualInstance.isConfigurationFileSet() || CmpiData(aManualInstance.getConfigurationFile()).isNullValue())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The required parameter ConfigurationFile is not set properly!");     
      

    char* PrsntConfFile = get_bindconf();
    const char* NewConfFile =  aManualInstance.getConfigurationFile();

    //cout<<"Present conf file = "<<PrsntConfFile<<endl;
    //cout<<"New conf file = "<<NewConfFile<<endl;

    if(!strcmp(PrsntConfFile,NewConfFile))
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The absolute path name of the configuration file is same as supplied!");
    
   set_bindconf(NewConfFile);
    
#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfiguration::setInstance" << endl;
#endif
}
  
//----------------------------------------------------------------------------
  /*
  Linux_DnsServiceConfigurationInstanceName
  Linux_DnsServiceConfigurationResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceConfigurationManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsServiceConfigurationResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceConfigurationInstanceName& anInstanceName) { }
	*/
	

  
  // extrinsic methods

	
}


