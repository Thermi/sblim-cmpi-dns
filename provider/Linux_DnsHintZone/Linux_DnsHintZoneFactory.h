// =======================================================================
// Linux_DnsHintZoneFactory.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
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
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsHintZoneFactory_h
#define Linux_DnsHintZoneFactory_h


#include "Linux_DnsHintZoneInterface.h"

namespace genProvider{
	
  class Linux_DnsHintZoneFactory {

    public:
	  Linux_DnsHintZoneFactory() {};
	  ~Linux_DnsHintZoneFactory() {};
	
	  static Linux_DnsHintZoneInterface* getImplementation();

    };
    
}

#endif
