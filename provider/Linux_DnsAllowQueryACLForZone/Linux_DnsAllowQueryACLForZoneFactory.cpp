 /**
 * Linux_DnsAllowQueryACLForZoneFactory.cpp
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
#include "Linux_DnsAllowQueryACLForZoneFactory.h"
#include "Linux_DnsAllowQueryACLForZoneResourceAccess.h"

namespace genProvider{
	
	Linux_DnsAllowQueryACLForZoneInterface* 
	  Linux_DnsAllowQueryACLForZoneFactory::getImplementation(){
	  	
	  	return (new Linux_DnsAllowQueryACLForZoneResourceAccess());
	  };
}
 
