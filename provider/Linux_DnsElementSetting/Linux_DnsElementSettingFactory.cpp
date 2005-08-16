 /**
 * Linux_DnsElementSettingFactory.cpp
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
#include "Linux_DnsElementSettingFactory.h"
#include "Linux_DnsElementSettingResourceAccess.h"

namespace genProvider{
	
	Linux_DnsElementSettingInterface* 
	  Linux_DnsElementSettingFactory::getImplementation(){
	  	
	  	return (new Linux_DnsElementSettingResourceAccess());
	  };
}
 
