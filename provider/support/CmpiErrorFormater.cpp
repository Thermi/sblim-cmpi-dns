// =======================================================================
// CmpiErrorFormater.cpp
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#include "CmpiErrorFormater.h"

namespace genProvider {

  CmpiStatus
  CmpiErrorFormater::getErrorException(
    const int anErrorCode,
    const char* aParm1P,
    const char* aParm2P,
    const char* aParm3P) {
      
    CMPIrc cmpiRc = CMPI_RC_ERR_FAILED;

    /*
    CmpiErrorFormater.cpp:24: error: duplicate case value
    CmpiErrorFormater.cpp:19: error: previously used here    
    */
    
    if (anErrorCode == NOT_SET) {
        cmpiRc = CMPI_RC_ERR_FAILED;
    } else if (anErrorCode == NOT_IMPLEMENTED) {
        cmpiRc = CMPI_RC_ERR_NOT_SUPPORTED;
    } else if (anErrorCode == METHOD_NOT_FOUND) {
        cmpiRc = CMPI_RC_ERR_METHOD_NOT_FOUND;
    } else {
        cmpiRc = CMPI_RC_ERR_FAILED;
    }

    std::string parm1(aParm1P ? aParm1P : "");
    std::string parm2(aParm2P ? aParm2P : "");
    std::string parm3(aParm3P ? aParm3P : "");
    std::string errString = parm1 + parm2 + parm3;
    return CmpiStatus(cmpiRc,errString.c_str());

  }

}
