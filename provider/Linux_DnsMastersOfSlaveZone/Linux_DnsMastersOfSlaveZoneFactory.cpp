 /**
 * Linux_DnsMastersOfSlaveZoneFactory.cpp
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
#include "Linux_DnsMastersOfSlaveZoneFactory.h"
#include "Linux_DnsMastersOfSlaveZoneResourceAccess.h"

namespace genProvider{
	
	Linux_DnsMastersOfSlaveZoneInterface* 
	  Linux_DnsMastersOfSlaveZoneFactory::getImplementation(){
	  	
	  	return (new Linux_DnsMastersOfSlaveZoneResourceAccess());
	  };
}
 