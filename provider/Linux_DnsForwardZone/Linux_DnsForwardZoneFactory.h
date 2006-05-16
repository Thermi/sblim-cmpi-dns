// =======================================================================
// Linux_DnsForwardZoneFactory.h
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsForwardZoneFactory_h
#define Linux_DnsForwardZoneFactory_h


#include "Linux_DnsForwardZoneInterface.h"

namespace genProvider{
	
  class Linux_DnsForwardZoneFactory {

    public:
	  Linux_DnsForwardZoneFactory() {};
	  ~Linux_DnsForwardZoneFactory() {};
	
	  static Linux_DnsForwardZoneInterface* getImplementation();

    };
    
}

#endif
