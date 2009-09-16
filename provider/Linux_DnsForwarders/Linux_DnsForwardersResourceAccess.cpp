// =======================================================================
// Linux_DnsForwardersResourceAccess.cpp
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
#include "Linux_DnsForwardersResourceAccess.h"
#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  static void setInstanceProperties(
      const char* aclName,
      const char* aclValue,
      const Linux_DnsForwardersInstanceName& anInstanceName,
      Linux_DnsForwardersManualInstance& aManualInstance) {

    aManualInstance.setInstanceName(anInstanceName);

    DnsArray da = DnsArray( aclValue );
    if (da.size() > 0) {
      aManualInstance.setForwardersElement( da.toArray(), da.size() );

      CMPIUint8* aclType = new CMPIUint8[da.size()];
      DnsArrayConstIterator iter;
      int i = 0;

      for ( iter = da.begin(); iter != da.end(); ++iter) {
         aclType[i++] = getForwardersType((*iter).c_str());
      }
      aManualInstance.setForwardersElementType (aclType, da.size() );
    }
  }

  //----------------------------------------------------------------------------
  //Linux_DnsForwardersResourceAccess::Linux_DnsForwardersResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsForwardersResourceAccess::~Linux_DnsForwardersResourceAccess() { }
    
  // intrinsic methods
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsForwardersInstanceNameEnumeration& anInstanceNameEnumeration) {
      
     
#ifdef DEBUG
     cout << "entering Linux_DnsForwarders::enumInstanceNames" << endl;
#endif

    BINDOPTS *options = ReadOptions();
    BINDOPTS *optionsStart = options;
    char* option = getOption(options,"forwarders");

    if (option) {
      Linux_DnsForwardersInstanceName anInstanceName;
      string aclName = "options::forwarders";

      anInstanceName.setNamespace(aNameSpaceP);
      anInstanceName.setName(aclName.c_str());
      anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
      anInstanceNameEnumeration.addElement(anInstanceName);
    }
    if (optionsStart) freeOptions(optionsStart);

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;
    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"forwarders");

      if (zopts) {
        Linux_DnsForwardersInstanceName anInstanceName;
        string aclName = "zone::";
        aclName.append(zones->zoneName);
        aclName.append("::forwarders");

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(aclName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsForwarders::enumInstanceNames" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsForwardersManualInstanceEnumeration& aManualInstanceEnumeration) {
#ifdef DEBUG
     cout << "entering Linux_DnsForwarders::enumInstances" << endl;
#endif

    BINDOPTS *options = ReadOptions();
    BINDOPTS *optionsStart = options;

    char* option = getOption(options, "forwarders");
    if (option) {
      Linux_DnsForwardersInstanceName anInstanceName;
      Linux_DnsForwardersManualInstance aManualInstance;

      string aclName = "options::forwarders";

      anInstanceName.setNamespace(aNameSpaceP);
      anInstanceName.setName(aclName.c_str());
      anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
      
      setInstanceProperties(aclName.c_str(), option, anInstanceName ,aManualInstance);

      aManualInstanceEnumeration.addElement(aManualInstance);
    }
    if (optionsStart) freeOptions(optionsStart);

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"forwarders");

      if (zopts) {
        Linux_DnsForwardersInstanceName anInstanceName;
        Linux_DnsForwardersManualInstance aManualInstance;

        string aclName = "zone::";
        aclName.append(zones->zoneName);
        aclName.append("::forwarders");

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(aclName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
        
        setInstanceProperties(aclName.c_str(), zopts->value, anInstanceName ,aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsForwarders::enumInstances" << endl;
#endif
}
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstance 
  Linux_DnsForwardersResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsForwardersInstanceName& anInstanceName) {

    Linux_DnsForwardersManualInstance manualInstance;

  
#ifdef DEBUG
     cout << "entering Linux_DnsForwarders::getInstance" << endl;
#endif

    Linux_DnsForwardersManualInstance aManualInstance;

    int found = 0;

    string iName = anInstanceName.getName();
    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (strcmp("options", parentName.c_str()) == 0) {
      string optionName = iName.substr(0,iName.find_first_of("::"));

      BINDOPTS *options = ReadOptions();
      BINDOPTS *optionsStart = options;
      char* option = getOption(options,optionName.c_str());
      if (option) {
        setInstanceProperties(optionName.c_str(), option, anInstanceName ,aManualInstance);
        found = 1;
      }
      if (optionsStart) freeOptions(optionsStart);

    } else if (strcmp("zone", parentName.c_str()) == 0) {
      DNSZONE *zones = getZones();
      DNSZONE *zonesStart = zones;
      string zoneName = iName.substr(0,iName.find_first_of("::"));
      string optionName = iName.substr(iName.find_first_of("::")+2, iName.length());

      if (strcmp(optionName.c_str(), "forwarders") != 0)
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a forwarders instance!");

      while(zones && zones->zoneName) {
        if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
          ZONEOPTS* zopts = findOptsInZone(zones,optionName.c_str());

          if (zopts) {
            setInstanceProperties(optionName.c_str(), zopts->value, anInstanceName ,aManualInstance);
            found = 1;
          }
        }
        zones++;
      }
      if (zonesStart) freeZones(zonesStart);

    } else
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported forwarders attribute!");

    if (found == 0)
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");

#ifdef DEBUG
     cout << "exiting Linux_DnsForwarders::getInstance" << endl;
#endif

    return aManualInstance;
  }
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsForwardersManualInstance& aManualInstance) { 

#ifdef DEBUG
     cout << "entering Linux_DnsForwarders::setInstance" << endl;
#endif

    DnsArray optionValues = DnsArray();
    int modified = 0;

    string iName = aManualInstance.getInstanceName().getName();
    unsigned int forwardersListSize;
    const char **forwardersList;

    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (aManualInstance.isForwardersElementSet()) {
      forwardersList = aManualInstance.getForwardersElement(forwardersListSize);
      if (forwardersList) {
        for (unsigned int i = 0; i < forwardersListSize; i++)
          if (! optionValues.isPresent( string( forwardersList[i]) ) )
            optionValues.add( forwardersList[i] );
      }
    }

    if (strcmp("options", parentName.c_str()) == 0) {
      BINDOPTS *options = ReadOptions();
      BINDOPTS *optionsStart = options;
      string optionName = iName.substr(0,iName.find_first_of("::"));

      if ( getOption(options,optionName.c_str()) ) {
        setOption(options, optionName.c_str(), strdup(optionValues.toString().c_str()));
        modified = 1;
      }
      if (optionsStart) freeOptions(optionsStart);

    } else if (strcmp("zone", parentName.c_str()) == 0) {
      DNSZONE *zones = getZones();
      DNSZONE *zonesStart = zones;
      string zoneName = iName.substr(0,iName.find_first_of("::"));
      string optionName = iName.substr(iName.find_first_of("::")+2, iName.length());

      if (strcmp(optionName.c_str(), "forwarders") != 0)
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a forwarders instance!");

      while(zones && zones->zoneName) {
        if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
          ZONEOPTS* zopts = findOptsInZone(zones,optionName.c_str());

          if (zopts) {
            zopts->value = strdup(optionValues.toString().c_str());
            updateZones(zonesStart);
            modified = 1;
          }
        }
        zones++;
      }
      if (zonesStart) freeZones(zonesStart);

    } else {
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported forwarders attribute!");
    }

    if (modified == 0)
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");

#ifdef DEBUG
     cout << "exiting Linux_DnsForwarders::setInstance" << endl;
#endif


    return;
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardersInstanceName
  Linux_DnsForwardersResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardersManualInstance& aManualInstance) { 

#ifdef DEBUG
     cout << "entering Linux_DnsForwarders::createInstance" << endl;
#endif

    DnsArray optionValues = DnsArray();
    int created = 0;

    string iName = aManualInstance.getInstanceName().getName();
    unsigned int forwardersListSize;
    const char **forwardersList;

    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (aManualInstance.isForwardersElementSet()) {
      forwardersList = aManualInstance.getForwardersElement(forwardersListSize);
      if (forwardersList) {
        for (unsigned int i = 0; i < forwardersListSize; i++)
          if (! optionValues.isPresent( string( forwardersList[i]) ) )
            optionValues.add( forwardersList[i] );
      }
    }

    if (strcmp("options", parentName.c_str()) == 0) {
      BINDOPTS *options = ReadOptions();
      BINDOPTS *optionsStart = options;
      string optionName = iName.substr(0,iName.find_first_of("::"));

      if ( getOption(options,optionName.c_str()) ) {
        throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS,"There is an already existend instance present!");
      }
      BINDOPTS* newOption = (BINDOPTS*) malloc (sizeof(BINDOPTS));
      newOption->key = strdup(optionName.c_str());
      newOption->value = strdup(optionValues.toString().c_str());
      addOption(newOption);
      if (optionsStart) freeOptions(optionsStart);
      created = 1;

    } else if (strcmp("zone", parentName.c_str()) == 0 ) {
      DNSZONE *zones = getZones();
      DNSZONE *zonesStart = zones;
      string zoneName = iName.substr(0,iName.find_first_of("::"));
      string optionName = iName.substr(iName.find_first_of("::")+2, iName.length());
 
      if (strcmp(optionName.c_str(), "forwarders") != 0)
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a forwarders instance!");

      while(zones && zones->zoneName) {
        if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
          if (findOptsInZone(zones,optionName.c_str())) {
            throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS,"There is an already existend instance present!");
          }
          addOptsToZone(zones, optionName.c_str(), strdup(optionValues.toString().c_str()));
          updateZones(zonesStart);
          created = 1;
        }
        zones++;
      }
      if (zonesStart)freeZones(zonesStart);

    } else {
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported forwarders attribute!");
    }

    if (created == 0) {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not contain a known parent entry!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsForwarders::createInstance" << endl;
#endif

    return aManualInstance.getInstanceName();
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardersInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsForwarders::deleteInstance" << endl;
#endif

    DnsArray optionValues = DnsArray();
    int deleted = 0;

    string iName = anInstanceName.getName();

    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (strcmp("options", parentName.c_str()) == 0) {
      BINDOPTS *options = ReadOptions();
      BINDOPTS *optionsStart = options;
      string optionName = iName.substr(0,iName.find_first_of("::"));

      if (options) {
        for (; options->key && deleted == 0; options++) {
          if (strcmp(options->key, optionName.c_str()) == 0) {
            deleteOption(optionName.c_str());
            deleted = 1;
          }
        }
      }
      if(optionsStart) freeOptions(optionsStart);
    } else if (strcmp("zone", parentName.c_str()) == 0) {
      DNSZONE *zones = getZones();
      DNSZONE *zonesStart = zones;
      string zoneName = iName.substr(0,iName.find_first_of("::"));
      string optionName = iName.substr(iName.find_first_of("::")+2, iName.length());

      if (strcmp(optionName.c_str(), "forwarders") != 0)
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a forwarders instance!");

      while(zones && zones->zoneName) {
        if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
          if (findOptsInZone(zones, optionName.c_str())) {
            delOptsFromZone(zones, optionName.c_str());
            deleted = 1;
          }
        }
        zones++;
      }
      if (zonesStart) freeZones(zonesStart);

    } else {
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported forwarders attribute!");
    }
    if (deleted == 0) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsForwarders::deleteInstance" << endl;
#endif
  }
	

  
  // extrinsic methods

	
}


