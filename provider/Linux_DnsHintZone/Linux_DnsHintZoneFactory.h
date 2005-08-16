 /**
 * Linux_DnsHintZoneFactory.h
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
#ifndef Linux_DnsHintZoneFactory_h
#define Linux_DnsHintZoneFactory_h


#include "Linux_DnsHintZoneInterface.h"

namespace genProvider{
	
class Linux_DnsHintZoneFactory{
public:

	Linux_DnsHintZoneFactory(){};
	~Linux_DnsHintZoneFactory(){};
	
	static Linux_DnsHintZoneInterface* getImplementation();
};
}
#endif
 
