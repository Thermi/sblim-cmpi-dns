 /**
 * CmpiErrorFormater.cpp
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
#include "CmpiErrorFormater.h"

namespace genProvider {

  CmpiStatus CmpiErrorFormater::
   getErrorException(const int errorCode, const char* description){
    if (errorCode==NOT_SET)
      return CmpiStatus(CMPI_RC_ERR_FAILED,description);
      
    else if (errorCode==NOT_IMPLEMENTED)  
      return CmpiStatus(CMPI_RC_ERR_NOT_SUPPORTED);
      
    else if (errorCode==METHOD_NOT_FOUND)
      return CmpiStatus(CMPI_RC_ERR_METHOD_NOT_FOUND,description);
      
    else
      return CmpiStatus(CMPI_RC_ERR_FAILED,description);
  }
}


