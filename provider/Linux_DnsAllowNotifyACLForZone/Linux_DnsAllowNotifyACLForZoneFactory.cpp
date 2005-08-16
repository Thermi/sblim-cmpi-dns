 /**
 * Linux_DnsAllowNotifyACLForZoneFactory.cpp
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
#include "Linux_DnsAllowNotifyACLForZoneFactory.h"
#include "Linux_DnsAllowNotifyACLForZoneResourceAccess.h"

namespace genProvider{
	
	Linux_DnsAllowNotifyACLForZoneInterface* 
	  Linux_DnsAllowNotifyACLForZoneFactory::getImplementation(){
	  	
	  	return (new Linux_DnsAllowNotifyACLForZoneResourceAccess());
	  };
}
 
