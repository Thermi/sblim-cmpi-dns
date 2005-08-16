 /**
 * CmpiErrorFormater.h
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
#ifndef CmpiErrorFormater_h
#define CmpiErrorFormater_h

#include "CmpiStatus.h"

namespace genProvider {

  class CmpiErrorFormater{
  public:
    const static int NOT_IMPLEMENTED=0;
    const static int NOT_SET=1;
    const static int METHOD_NOT_FOUND=1;
    
    static CmpiStatus getErrorException(const int errorCode, const char* description);
  };
}

#endif


