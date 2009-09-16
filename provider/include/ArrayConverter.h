// =======================================================================
// ArrayConverter.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 

#ifndef _ArrayConverter_h_
#define _ArrayConverter_h_

#include "cmpidt.h"
#include "CmpiData.h"
#include "CmpiDateTime.h"
#include "CmpiArray.h"

namespace genProvider {
class ArrayConverter {
 public:
   // Generate Cmpi Array from native data
   static CmpiArray makeCmpiArray(const unsigned char* arr, CMPICount num, int isBoolean);
   static CmpiArray makeCmpiArray(const unsigned short* arr, CMPICount num, int isChar16);
   static CmpiArray makeCmpiArray(const CMPIUint32* arr, CMPICount num);
   static CmpiArray makeCmpiArray(const CMPIUint64* arr, CMPICount num);
   static CmpiArray makeCmpiArray(const CMPISint8* arr, CMPICount num);
   static CmpiArray makeCmpiArray(const CMPISint16* arr, CMPICount num);
   static CmpiArray makeCmpiArray(const CMPISint32* arr, CMPICount num);
   static CmpiArray makeCmpiArray(const CMPISint64* arr, CMPICount num);
   static CmpiArray makeCmpiArray(const CMPIReal32* arr, CMPICount num);
   static CmpiArray makeCmpiArray(const CMPIReal64* arr, CMPICount num);
   static CmpiArray makeCmpiArray(const char** arr, CMPICount num);
   static CmpiArray makeCmpiArray(const CmpiDateTime* arr, CMPICount num);
   // Allocate new C++ array from CmpiArray 
   static void makeArray(const CmpiArray &cmpiarr, unsigned char** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, unsigned short** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, CMPIUint32** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, CMPIUint64** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, CMPISint8** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, CMPISint16** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, CMPISint32** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, CMPISint64** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, CMPIReal32** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, CMPIReal64** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, char*** arr, CMPICount& num);
   static void makeArray(const CmpiArray &cmpiarr, CmpiDateTime** arr, CMPICount& num);
   // Destruct a native data array
   static void destructArray(unsigned char* arr);
   static void destructArray(unsigned short* arr);
   static void destructArray(CMPIUint32* arr);
   static void destructArray(CMPIUint64* arr);
   static void destructArray(CMPISint8* arr);
   static void destructArray(CMPISint16* arr);
   static void destructArray(CMPISint32* arr);
   static void destructArray(CMPISint64* arr);
   static void destructArray(CMPIReal32* arr);
   static void destructArray(CMPIReal64* arr);
   static void destructArray(char** arr, CMPICount num);
   static void destructArray(CmpiDateTime* arr);
   
};
}
#endif



