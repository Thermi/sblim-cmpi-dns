 /**
 * Linux_DnsAllowTransferACLForZoneFactory.h
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
#ifndef Linux_DnsAllowTransferACLForZoneFactory_h
#define Linux_DnsAllowTransferACLForZoneFactory_h


#include "Linux_DnsAllowTransferACLForZoneInterface.h"

namespace genProvider{
	
class Linux_DnsAllowTransferACLForZoneFactory{
public:

	Linux_DnsAllowTransferACLForZoneFactory(){};
	~Linux_DnsAllowTransferACLForZoneFactory(){};
	
	static Linux_DnsAllowTransferACLForZoneInterface* getImplementation();
};
}
#endif
 
