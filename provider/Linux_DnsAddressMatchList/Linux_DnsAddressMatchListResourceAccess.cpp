// =======================================================================
// Linux_DnsAddressMatchListResourceAccess.cpp
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
#include "Linux_DnsAddressMatchListResourceAccess.h"
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
      const Linux_DnsAddressMatchListInstanceName& anInstanceName,
      Linux_DnsAddressMatchListManualInstance& aManualInstance) {

    aManualInstance.setInstanceName(anInstanceName);

    DnsArray da = DnsArray( aclValue );
    if (da.size() > 0) {
      aManualInstance.setAddressMatchListElement( da.toArray(), da.size() );

      CMPIUint8* aclType = new CMPIUint8[da.size()];
      DnsArrayConstIterator iter;
      int i = 0;

      for ( iter = da.begin(); iter != da.end(); ++iter) {
         aclType[i++] = getACLType((*iter).c_str());
      }
      aManualInstance.setAddressMatchListElementType (aclType, da.size() );
    }
  }

  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListResourceAccess::Linux_DnsAddressMatchListResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListResourceAccess::~Linux_DnsAddressMatchListResourceAccess() { }
    
  // intrinsic methods
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
     cout << "entering Linux_DnsAddressMatchList::enumInstanceNames" << endl;
#endif

    DnsArray list = DnsArray();
    list.add("allow-notify");
    list.add("allow-query");
    list.add("allow-transfer");
    list.add("allow-update");
    list.add("allow-recursion");
    list.add("blackhole");
    DnsArrayConstIterator iter;

    ACL *list_acl = ReadACL();
    ACL *list_aclStart = list_acl;

    if (list_acl) {
      for (; list_acl->key; list_acl++) {
        string aclName = "global::";
        aclName.append(list_acl->key);
        aclName.append("::acl");

        Linux_DnsAddressMatchListInstanceName anInstanceName;

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(aclName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
    }
    if (list_aclStart) freeACL( list_aclStart );
    
    BINDOPTS *options = ReadOptions();
    BINDOPTS* optionsStart = options;
    for ( iter = list.begin(); iter != list.end(); ++iter) {
        char* option = getOption(options,(*iter).c_str());
        if (option) {
          Linux_DnsAddressMatchListInstanceName anInstanceName;
          string aclName = "options::";
          aclName.append((*iter).c_str());

          anInstanceName.setNamespace(aNameSpaceP);
          anInstanceName.setName(aclName.c_str());
          anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
          anInstanceNameEnumeration.addElement(anInstanceName);
        }
    }
    if (optionsStart) freeOptions(optionsStart);    

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;
    while(zones && zones->zoneName) {
      for ( iter = list.begin(); iter != list.end(); ++iter) {
          ZONEOPTS* zopts = findOptsInZone(zones,(*iter).c_str());

          if (zopts) {
            Linux_DnsAddressMatchListInstanceName anInstanceName;
            string aclName = "zone::";
            aclName.append(zones->zoneName);
            aclName.append("::");
            aclName.append((*iter).c_str());

            anInstanceName.setNamespace(aNameSpaceP);
            anInstanceName.setName(aclName.c_str());
            anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
            anInstanceNameEnumeration.addElement(anInstanceName);
          }
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsAddressMatchList::enumInstanceNames" << endl;
#endif

  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsAddressMatchListManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
     cout << "entering Linux_DnsAddressMatchList::enumInstances" << endl;
#endif

    DnsArray list = DnsArray();
    list.add("allow-notify");
    list.add("allow-query");
    list.add("allow-transfer");
    list.add("allow-update");
    list.add("allow-recursion");
    list.add("blackhole");
    DnsArrayConstIterator iter;

    ACL *list_acl = ReadACL();
    ACL *list_aclStart = list_acl;

    if (list_acl) {
      for (; list_acl->key; list_acl++) {
        string aclName = "global::";
        aclName.append(list_acl->key);
        aclName.append("::acl");

        Linux_DnsAddressMatchListInstanceName anInstanceName;
        Linux_DnsAddressMatchListManualInstance aManualInstance;

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(aclName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );

        setInstanceProperties(aclName.c_str(), list_acl->value, anInstanceName ,aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (list_aclStart) freeACL( list_aclStart );

    BINDOPTS *options = ReadOptions();
    BINDOPTS *optionsStart = options;
    for ( iter = list.begin(); iter != list.end(); ++iter) {
        char* option = getOption(options,(*iter).c_str());
        if (option) {
          Linux_DnsAddressMatchListInstanceName anInstanceName;
          Linux_DnsAddressMatchListManualInstance aManualInstance;

          string aclName = "options::";
          aclName.append((*iter).c_str());

          anInstanceName.setNamespace(aNameSpaceP);
          anInstanceName.setName(aclName.c_str());
          anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
          setInstanceProperties(aclName.c_str(), option, anInstanceName , aManualInstance);

          aManualInstanceEnumeration.addElement(aManualInstance);
        }
    }
    if (optionsStart) freeOptions(optionsStart);

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      for ( iter = list.begin(); iter != list.end(); ++iter) {
          ZONEOPTS* zopts = findOptsInZone(zones,(*iter).c_str());

          if (zopts) {
            Linux_DnsAddressMatchListInstanceName anInstanceName;
            Linux_DnsAddressMatchListManualInstance aManualInstance;

            string aclName = "zone::";
            aclName.append(zones->zoneName);
            aclName.append("::");
            aclName.append((*iter).c_str());

            anInstanceName.setNamespace(aNameSpaceP);
            anInstanceName.setName(aclName.c_str());
            anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );

            setInstanceProperties(aclName.c_str(), zopts->value, anInstanceName , aManualInstance);

            aManualInstanceEnumeration.addElement(aManualInstance);
          }
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsAddressMatchList::enumInstances" << endl;
#endif

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstance 
  Linux_DnsAddressMatchListResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsAddressMatchList::getInstance" << endl;
#endif

    Linux_DnsAddressMatchListManualInstance aManualInstance;

    DnsArray list = DnsArray();
    list.add("allow-notify");
    list.add("allow-query");
    list.add("allow-transfer");
    list.add("allow-update");
    list.add("allow-recursion");
    list.add("blackhole");
    DnsArrayConstIterator iter;
    int found = 0;

    string iName = anInstanceName.getName();
    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (strcmp("global", parentName.c_str()) == 0) {
      string aclName = iName.substr(0, iName.find_first_of("::"));
      ACL *list_acl = ReadACL();
      ACL *list_aclStart = list_acl;

      if (list_acl) {
        for (; list_acl->key && found == 0; list_acl++) {
          if (strcmp(list_acl->key, aclName.c_str()) == 0) {
            setInstanceProperties(aclName.c_str(), list_acl->value, anInstanceName , aManualInstance);

            found = 1;
          }
        }
      }
      if (list_aclStart) freeACL( list_aclStart );

    } else { // It is not a 'global' ACL! So it has to be one of the 'allow-' ACLS or the 'blackhole'.
      if (strcmp("options", parentName.c_str()) == 0) {
        string aclName = iName.substr(0,iName.find_first_of("::"));

        if (aclName.empty() || !list.isPresent(aclName.c_str()))
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a supported attribute name!");

        BINDOPTS *options = ReadOptions();
        BINDOPTS *optionsStart = options;
        char* option = getOption(options,aclName.c_str());
        if (option) {
          setInstanceProperties(aclName.c_str(), option, anInstanceName , aManualInstance);
          found = 1;
        } 
        if (optionsStart) freeOptions(optionsStart);
        
      } else if (strcmp("zone", parentName.c_str()) == 0) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;
        string zoneName = iName.substr(0,iName.find_first_of("::"));
        string aclName = iName.substr(iName.find_first_of("::")+2, iName.length());

        if (aclName.empty() || !list.isPresent(aclName.c_str()))
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a supported attribute name!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
            ZONEOPTS* zopts = findOptsInZone(zones,aclName.c_str());

            if (zopts) {
              setInstanceProperties(aclName.c_str(), zopts->value, anInstanceName , aManualInstance);
              found = 1;
            }
          }
          zones++;
        }
        if (zonesStart) freeZones(zonesStart);

      } else 
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported address match list attribute!");
    }
    if (found == 0) 
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");

#ifdef DEBUG
     cout << "exiting Linux_DnsAddressMatchList::getInstance" << endl;
#endif

    return aManualInstance;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsAddressMatchListManualInstance& aManualInstance) { 

#ifdef DEBUG
     cout << "entering Linux_DnsAddressMatchList::setInstance" << endl;
#endif

    DnsArray list = DnsArray();
    list.add("allow-notify");
    list.add("allow-query");
    list.add("allow-transfer");
    list.add("allow-update");
    list.add("allow-recursion");
    list.add("blackhole");
    DnsArray aclValues = DnsArray();
    DnsArrayConstIterator iter;
    int modified = 0;
 
    string iName = aManualInstance.getInstanceName().getName();
    unsigned int addressListSize;
    const char **addressList;

    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (aManualInstance.isAddressMatchListElementSet()) {
      addressList = aManualInstance.getAddressMatchListElement(addressListSize);
      if (addressList) {
        for (unsigned int i = 0; i < addressListSize; i++)
          if (! aclValues.isPresent( string( addressList[i]) ) )
            aclValues.add( addressList[i] );
      }
    }

    if (strcmp("global", parentName.c_str()) == 0) {
      ACL *list_acl = ReadACL();
      ACL *list_aclStart = list_acl;
      string aclName = iName.substr(0,iName.find_first_of("::"));

      if (list_acl) {
        for (; list_acl->key && modified == 0; list_acl++) {
          if (strcmp(list_acl->key, aclName.c_str()) == 0) {
            list_acl->value = strdup(aclValues.toString().c_str());
            WriteACL(list_acl);
            modified = 1;
          }
        }
      }
      if (list_aclStart) freeACL( list_aclStart );

    } else {
      if (strcmp("options", parentName.c_str()) == 0) {
        BINDOPTS *options = ReadOptions();
        BINDOPTS *optionsStart = options;
        string aclName = iName.substr(0,iName.find_first_of("::"));

        if (aclName.empty() || !list.isPresent(aclName.c_str()))
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a supported ACL name!");

        if ( getOption(options,aclName.c_str()) ) {
          setOption(options, aclName.c_str(), strdup(aclValues.toString().c_str()));
          modified = 1;
        }
        if (optionsStart) freeOptions(optionsStart);

      } else if (strcmp("zone", parentName.c_str()) == 0) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;
        string zoneName = iName.substr(0,iName.find_first_of("::"));
        string aclName = iName.substr(iName.find_first_of("::")+2, iName.length());

        if (aclName.empty() || !list.isPresent(aclName.c_str()))
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a supported ACL name!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
            ZONEOPTS* zopts = findOptsInZone(zones,aclName.c_str());

            if (zopts) {
              zopts->value = strdup(aclValues.toString().c_str());
              updateZones(zonesStart);
              modified = 1;
            }
          }
          zones++;
        }
        if (zonesStart) freeZones(zonesStart);

      } else {
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported address match list attribute!");
      }
    }

    if (modified == 0)
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");

#ifdef DEBUG
     cout << "exiting Linux_DnsAddressMatchList::setInstance" << endl;
#endif

    return;
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstanceName
  Linux_DnsAddressMatchListResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListManualInstance& aManualInstance) {

#ifdef DEBUG
     cout << "entering Linux_DnsAddressMatchList::createInstance" << endl;
#endif

    DnsArray list = DnsArray();
    list.add("allow-notify");
    list.add("allow-query");
    list.add("allow-transfer");
    list.add("allow-update");
    list.add("allow-recursion");
    list.add("blackhole");
    DnsArray aclValues = DnsArray();
    DnsArrayConstIterator iter;
    int created = 0;

    string iName = aManualInstance.getInstanceName().getName();
    unsigned int addressListSize;
    const char **addressList;

    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (aManualInstance.isAddressMatchListElementSet()) {
      addressList = aManualInstance.getAddressMatchListElement(addressListSize);
      if (addressList) {
        for (unsigned int i = 0; i < addressListSize; i++)
          if (! aclValues.isPresent( string( addressList[i]) ) )
            aclValues.add( addressList[i] );
      }
    }

    if (strcmp("global", parentName.c_str()) == 0) {
      ACL *list_acl = ReadACL();
      ACL *list_aclStart=list_acl;
      string aclName = iName.substr(0,iName.find_first_of("::"));

      if (list_acl) {
        for (; list_acl->key && created == 0; list_acl++) {
          if (strcmp(list_acl->key, aclName.c_str()) == 0) {
            throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS,"There is an already existend instance present!");
          }
        }
      }
      ACL *newACL = (ACL *) malloc(sizeof(ACL));
      newACL->key = strdup(aclName.c_str());
      newACL->value = strdup(aclValues.toString().c_str());
      addACL(newACL);
      if (list_aclStart) freeACL( list_aclStart );
      created = 1;

    } else {
      if (strcmp("options", parentName.c_str()) == 0) {
        BINDOPTS *options = ReadOptions();
        BINDOPTS *optionsStart = options;
        string aclName = iName.substr(0,iName.find_first_of("::"));

        if (aclName.empty() || !list.isPresent(aclName.c_str()))
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a supported ACL name!");

        if ( getOption(options,aclName.c_str()) ) {
          throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS,"There is an already existend instance present!");
        }
        BINDOPTS* newOption = (BINDOPTS*) malloc (sizeof(BINDOPTS));
        newOption->key = strdup(aclName.c_str());
        newOption->value = strdup(aclValues.toString().c_str());
        addOption(newOption);
        if (optionsStart) freeOptions(optionsStart);
        created = 1;

      } else if (strcmp("zone", parentName.c_str()) == 0 ) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;
        string zoneName = iName.substr(0,iName.find_first_of("::"));
        string aclName = iName.substr(iName.find_first_of("::")+2, iName.length());

        if (aclName.empty() || !list.isPresent(aclName.c_str()))
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a supported ACL name!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
            if (findOptsInZone(zones,aclName.c_str())) {
              throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS,"There is an already existend instance present!");
            }
            addOptsToZone(zones, aclName.c_str(), strdup(aclValues.toString().c_str()));
            updateZones(zonesStart);
            created = 1;
          }
          zones++;
        }
        if (zonesStart)freeZones(zonesStart);

      } else {
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported address match list attribute!");
      }
    }
    if (created == 0) {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a supported ACL name!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsAddressMatchList::createInstance" << endl;
#endif

    return aManualInstance.getInstanceName();
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsAddressMatchList::deleteInstance" << endl;
#endif

    DnsArray list = DnsArray();
    list.add("allow-notify");
    list.add("allow-query");
    list.add("allow-transfer");
    list.add("allow-update");
    list.add("allow-recursion");
    list.add("blackhole");
    DnsArray aclValues = DnsArray();
    DnsArrayConstIterator iter;
    int deleted = 0;

    string iName = anInstanceName.getName();

    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (strcmp("global", parentName.c_str()) == 0) {
      ACL *list_acl = ReadACL();
      ACL *list_aclStart = list_acl;
      string aclName = iName.substr(0,iName.find_first_of("::"));

      if (list_acl) {
        for (; list_acl->key && deleted == 0; list_acl++) {
          if (strcmp(list_acl->key, aclName.c_str()) == 0) {
            deleteACL(aclName.c_str());
            deleted = 1;
          }
        }
      }
      if (list_aclStart) freeACL( list_aclStart );
    } else {
      if (strcmp("options", parentName.c_str()) == 0) {
        BINDOPTS *options = ReadOptions();
        BINDOPTS *optionsStart = options;
        string aclName = iName.substr(0,iName.find_first_of("::"));

        if (aclName.empty() || !list.isPresent(aclName.c_str()))
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a supported ACL name!");

        if (options) {
          for (; options->key && deleted == 0; options++) {
            if (strcmp(options->key, aclName.c_str()) == 0) {
              deleteOption(aclName.c_str());
              deleted = 1;
            }
          }
        }
        if(optionsStart) freeOptions(optionsStart);
      } else if (strcmp("zone", parentName.c_str()) == 0) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;
        string zoneName = iName.substr(0,iName.find_first_of("::"));
        string aclName = iName.substr(iName.find_first_of("::")+2, iName.length());

        if (aclName.empty() || !list.isPresent(aclName.c_str()))
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a supported ACL name!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
            if (findOptsInZone(zones, aclName.c_str())) {
              delOptsFromZone(zones, aclName.c_str());
              deleted = 1;
            }
          }
          zones++;
        }
        if (zonesStart) freeZones(zonesStart);

      } else {
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported address match list attribute!");
      }
    }
    if (deleted == 0) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsAddressMatchList::deleteInstance" << endl;
#endif

  }
	

  
  // extrinsic methods

	
}


