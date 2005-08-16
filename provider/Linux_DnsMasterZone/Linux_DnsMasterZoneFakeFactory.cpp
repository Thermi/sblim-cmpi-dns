 /**
 * Linux_DnsMasterZoneFakeFactory.cpp
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
#include <iostream>
#include <strings.h>

#include "Linux_DnsMasterZoneFactory.h"

using namespace std;

namespace genProvider{
	
	Linux_DnsMasterZoneInterface* 
	  Linux_DnsMasterZoneFactory::getImplementation(){
	  	
	  	cout<<"ERROR: incomplete support library is being used"<<endl;
	  	cout<<"       in provider from class Linux_DnsMasterZone"<<endl;
	  	cout<<"       Use the link-install options for the makefile"<<endl;
	  	return 0;
	  };
}
