 /**
 * Linux_DnsMastersOfSlaveZoneFactory.h
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
#ifndef Linux_DnsMastersOfSlaveZoneFactory_h
#define Linux_DnsMastersOfSlaveZoneFactory_h


#include "Linux_DnsMastersOfSlaveZoneInterface.h"

namespace genProvider{
	
class Linux_DnsMastersOfSlaveZoneFactory{
public:

	Linux_DnsMastersOfSlaveZoneFactory(){};
	~Linux_DnsMastersOfSlaveZoneFactory(){};
	
	static Linux_DnsMastersOfSlaveZoneInterface* getImplementation();
};
}
#endif
 
