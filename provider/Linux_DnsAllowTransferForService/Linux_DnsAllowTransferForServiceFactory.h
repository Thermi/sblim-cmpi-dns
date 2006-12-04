// =======================================================================
// Linux_DnsAllowTransferForServiceFactory.h
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
#ifndef Linux_DnsAllowTransferForServiceFactory_h
#define Linux_DnsAllowTransferForServiceFactory_h


#include "Linux_DnsAllowTransferForServiceInterface.h"

namespace genProvider{
	
  class Linux_DnsAllowTransferForServiceFactory {

    public:
	  Linux_DnsAllowTransferForServiceFactory() {};
	  ~Linux_DnsAllowTransferForServiceFactory() {};
	
	  static Linux_DnsAllowTransferForServiceInterface* getImplementation();

    };
    
}

#endif
