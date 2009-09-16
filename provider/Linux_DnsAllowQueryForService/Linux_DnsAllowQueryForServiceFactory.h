// =======================================================================
// Linux_DnsAllowQueryForServiceFactory.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
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
#ifndef Linux_DnsAllowQueryForServiceFactory_h
#define Linux_DnsAllowQueryForServiceFactory_h


#include "Linux_DnsAllowQueryForServiceInterface.h"

namespace genProvider{
	
  class Linux_DnsAllowQueryForServiceFactory {

    public:
	  Linux_DnsAllowQueryForServiceFactory() {};
	  ~Linux_DnsAllowQueryForServiceFactory() {};
	
	  static Linux_DnsAllowQueryForServiceInterface* getImplementation();

    };
    
}

#endif
