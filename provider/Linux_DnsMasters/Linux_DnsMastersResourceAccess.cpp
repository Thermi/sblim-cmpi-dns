// =======================================================================
// Linux_DnsMastersResourceAccess.cpp
//     created on Fri, 27 Oct 2006 using ECUTE 2.2
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
#include "Linux_DnsMastersResourceAccess.h"
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
      const Linux_DnsMastersInstanceName& anInstanceName,
      Linux_DnsMastersManualInstance& aManualInstance) {

    aManualInstance.setInstanceName(anInstanceName);

    DnsArray da = DnsArray( aclValue );
    if (da.size() > 0) {
      aManualInstance.setMasterElement( da.toArray(), da.size() );

      CMPIUint8* mastersType = new CMPIUint8[da.size()];
      DnsArrayConstIterator iter;
      int i = 0;

      for ( iter = da.begin(); iter != da.end(); ++iter) {
         mastersType[i++] = getMastersType((*iter).c_str());
      }
      aManualInstance.setMasterElementType (mastersType, da.size() );
    }
  }

  //----------------------------------------------------------------------------
  //Linux_DnsMastersResourceAccess::Linux_DnsMastersResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsMastersResourceAccess::~Linux_DnsMastersResourceAccess() { }
    
  // intrinsic methods
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsMastersInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
     cout << "entering Linux_DnsMasters::enumInstanceNames" << endl;
#endif

    MASTERS *list_masters = ReadMasters();
    MASTERS *list_mastersStart = list_masters;

    if (list_masters) {
      for (; list_masters->key; list_masters++) {
        string mastersName = "global::";
        mastersName.append(list_masters->key);
        mastersName.append("::masters");

        Linux_DnsMastersInstanceName anInstanceName;

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(mastersName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
    }
    if (list_mastersStart) freeMasters( list_mastersStart );

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"masters");

      if (zopts) {
        Linux_DnsMastersInstanceName anInstanceName;
        string mastersName = "zone::";
        mastersName.append(zones->zoneName);
        mastersName.append("::masters");

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(mastersName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsMasters::enumInstanceNames" << endl;
#endif

  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsMastersManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
     cout << "entering Linux_DnsMasters::enumInstances" << endl;
#endif

    MASTERS *list_masters = ReadMasters();
    MASTERS *list_mastersStart = list_masters;

    if (list_masters) {
      for (; list_masters->key; list_masters++) {
        string mastersName = "global::";
        mastersName.append(list_masters->key);
        mastersName.append("::masters");

        Linux_DnsMastersInstanceName anInstanceName;
        Linux_DnsMastersManualInstance aManualInstance;

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(mastersName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );

        setInstanceProperties(mastersName.c_str(), list_masters->value, anInstanceName ,aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if(list_mastersStart) freeMasters( list_mastersStart );

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"masters");

      if (zopts) {
        Linux_DnsMastersInstanceName anInstanceName;
        Linux_DnsMastersManualInstance aManualInstance;

        string mastersName = "zone::";
        mastersName.append(zones->zoneName);
        mastersName.append("::masters");

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(mastersName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );

        setInstanceProperties(mastersName.c_str(), zopts->value, anInstanceName ,aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsMasters::enumInstances" << endl;
#endif

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstance 
  Linux_DnsMastersResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsMastersInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsMasters::getInstance" << endl;
#endif

    Linux_DnsMastersManualInstance aManualInstance;
    int found = 0;
    string iName = anInstanceName.getName();
    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (strcmp("global", parentName.c_str()) == 0) {
      MASTERS *list_masters = ReadMasters();
      MASTERS *list_mastersStart = list_masters;

      string mastersName = iName.substr(0,iName.find_first_of("::"));
      if (list_masters) {
        for (; list_masters->key && found == 0; list_masters++) {
          if (strcmp(list_masters->key, mastersName.c_str()) == 0) {
            setInstanceProperties(mastersName.c_str(), list_masters->value, anInstanceName ,aManualInstance);
            found = 1;
          }
        }
      }
      if (list_mastersStart) freeMasters( list_mastersStart );

    } else if (strcmp("zone", parentName.c_str()) == 0) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;

        string zoneName = iName.substr(0,iName.find_first_of("::"));
        string mastersName = iName.substr(iName.find_first_of("::")+2, iName.length());

       if (strcmp(mastersName.c_str(), "masters") != 0)
         throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a masters instance!");
       
       while(zones && zones->zoneName) {
         if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
           ZONEOPTS* zopts = findOptsInZone(zones,mastersName.c_str());

           if (zopts) {
             setInstanceProperties(mastersName.c_str(), zopts->value, anInstanceName ,aManualInstance);
             found = 1;
           }
         }
         zones++;
       }

       if (zonesStart) freeZones(zonesStart);
    } else {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported masters attribute!");
    }

    if (found == 0)
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");

#ifdef DEBUG
     cout << "exiting Linux_DnsMasters::getInstance" << endl;
#endif

    return aManualInstance;
  }
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsMastersManualInstance& aManualInstance) { 
    DnsArray mastersValues = DnsArray();
    DnsArrayConstIterator iter;
    int modified = 0;

#ifdef DEBUG
     cout << "entering Linux_DnsMasters::setInstance" << endl;
#endif

    string iName = aManualInstance.getInstanceName().getName();
    unsigned int addressListSize;
    const char **addressList;

    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (aManualInstance.isMasterElementSet()) {
      addressList = aManualInstance.getMasterElement(addressListSize);
      if (addressList) {
        for (unsigned int i = 0; i < addressListSize; i++)
          if (! mastersValues.isPresent( string( addressList[i]) ) )
            mastersValues.add( addressList[i] );
      }
    }

    if (strcmp("global", parentName.c_str()) == 0) {
      MASTERS *list_masters = ReadMasters();
      MASTERS *list_mastersStart = list_masters;
      string mastersName = iName.substr(0, iName.find_first_of("::"));

      if (list_masters) {
        for (; list_masters->key && modified == 0; list_masters++) {
          if (strcmp(list_masters->key, mastersName.c_str()) == 0) {
            list_masters->value = strdup(mastersValues.toString().c_str());
            WriteMasters(list_masters);
            modified = 1;
          }
        }
      }
      if (list_mastersStart) freeMasters( list_mastersStart );

    } else if (strcmp("zone", parentName.c_str()) == 0) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;
        string zoneName = iName.substr(0, iName.find_first_of("::"));
        string mastersName = iName.substr(iName.find_first_of("::")+2, iName.length());

       if (strcmp(mastersName.c_str(), "masters") != 0)
         throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a masters instance!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
            ZONEOPTS* zopts = findOptsInZone(zones,mastersName.c_str());

            if (zopts) {
              zopts->value = strdup(mastersValues.toString().c_str());
              updateZones(zonesStart);
              modified = 1;
            }
          }
          zones++;
        }
        if(zonesStart) freeZones(zonesStart);

    } else {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported masters attribute!");
    }

    if (modified == 0)
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");

#ifdef DEBUG
     cout << "exiting Linux_DnsMasters::setInstance" << endl;
#endif

    return;
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersInstanceName
  Linux_DnsMastersResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMastersManualInstance& aManualInstance) {

#ifdef DEBUG
     cout << "entering Linux_DnsMasters::createInstance" << endl;
#endif

    DnsArray mastersValues = DnsArray();
    int created = 0;

    string iName = aManualInstance.getInstanceName().getName();
    unsigned int addressListSize;
    const char **addressList;

    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (aManualInstance.isMasterElementSet()) {
      addressList = aManualInstance.getMasterElement(addressListSize);
      if (addressList) {
        for (unsigned int i = 0; i < addressListSize; i++)
          if (! mastersValues.isPresent( string( addressList[i]) ) )
            mastersValues.add( addressList[i] );
      }
    }

    if (strcmp("global", parentName.c_str()) == 0) {
      MASTERS *list_masters = ReadMasters();
      MASTERS *list_mastersStart = list_masters;
      string mastersName = iName.substr(0,iName.find_first_of("::"));

      if (list_masters) {
        for (; list_masters->key && created == 0; list_masters++) {
          if (strcmp(list_masters->key, "masters") == 0) {
            throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS,"There is an already existend instance present!");
          }
        }
      }
      MASTERS *newMasters = (MASTERS *) malloc(sizeof(MASTERS));
      newMasters->key = strdup(mastersName.c_str());
      newMasters->value = strdup(mastersValues.toString().c_str());
      newMasters->port = 0; // not supported yet
      addMasters(newMasters);
      if (list_mastersStart) freeMasters( list_mastersStart );
      created = 1;

    } else if (strcmp("zone", parentName.c_str()) == 0) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;
        string zoneName = iName.substr(0,iName.find_first_of("::"));
        string mastersName = iName.substr(iName.find_first_of("::")+2, iName.length());

       if (strcmp(mastersName.c_str(), "masters") != 0)
         throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a masters instance!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
            if (findOptsInZone(zones,mastersName.c_str())) {
              throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS,"There is an already existend instance present!");
            }
            addOptsToZone(zones, mastersName.c_str(), strdup(mastersValues.toString().c_str()));
            updateZones(zonesStart);
            created = 1;
          }
          zones++;
        }
        if (zonesStart) freeZones(zonesStart);

    } else {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported masters attribute!");
    }

    if (created == 0) {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does doe not contain a known parent entry!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsMasters::createInstance" << endl;
#endif

    return aManualInstance.getInstanceName();
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMastersInstanceName& anInstanceName) { 

#ifdef DEBUG
     cout << "entering Linux_DnsMasters::deleteInstance" << endl;
#endif

    DnsArray mastersValues = DnsArray();
    DnsArrayConstIterator iter;
    int deleted = 0;

    string iName = anInstanceName.getName();

    if (!iName.c_str())
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance name is not valid!");

    string parentName = iName.substr(0, iName.find_first_of("::"));
    iName.erase(0,iName.find_first_of("::")+2);

    if (strcmp("global", parentName.c_str()) == 0) {
      MASTERS *list_masters = ReadMasters();
      MASTERS *list_mastersStart = list_masters;
      string mastersName = iName.substr(0, iName.find_first_of("::"));

      if (list_masters) {
        for (; list_masters->key && deleted == 0; list_masters++) {
          if (strcmp(list_masters->key, mastersName.c_str()) == 0) {
            deleteMasters(mastersName.c_str());
            deleted = 1;
          }
        }
      }
      if (list_mastersStart) freeMasters( list_mastersStart );
    } else if (strcmp("zone", parentName.c_str()) == 0) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;
        string zoneName = iName.substr(0, iName.find_first_of("::"));
        string mastersName = iName.substr(iName.find_first_of("::")+2, iName.length());

       if (strcmp(mastersName.c_str(), "masters") != 0)
         throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a masters instance!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, zoneName.c_str()) == 0) {
            if (findOptsInZone(zones, mastersName.c_str())) {
              delOptsFromZone(zones, mastersName.c_str());
              deleted = 1;
            }
          }
          zones++;
        }
        if(zonesStart)freeZones(zonesStart);

    } else {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported masters attribute!");
    }

    if (deleted == 0) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsMasters::deleteInstance" << endl;
#endif

  }
	

  
  // extrinsic methods

	
}


