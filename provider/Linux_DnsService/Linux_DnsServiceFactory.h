 /**
 * Linux_DnsServiceFactory.h
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
#ifndef Linux_DnsServiceFactory_h
#define Linux_DnsServiceFactory_h


#include "Linux_DnsServiceInterface.h"

namespace genProvider{
	
class Linux_DnsServiceFactory{
public:

	Linux_DnsServiceFactory(){};
	~Linux_DnsServiceFactory(){};
	
	static Linux_DnsServiceInterface* getImplementation();
};
}
#endif
 
