// =======================================================================
// ArrayConverter.cpp
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
#include "ArrayConverter.h"

namespace genProvider {

CmpiArray ArrayConverter::makeCmpiArray(const unsigned char* arr, CMPICount max, int isBoolean ) {
  CmpiArray cmpiarr(max,isBoolean?CMPI_boolean:CMPI_uint8);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const unsigned short* arr, CMPICount max, int isChar16 ) {
  CmpiArray cmpiarr(max,isChar16?CMPI_char16:CMPI_uint16);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const CMPIUint32* arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_uint32);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const CMPIUint64* arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_uint64);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const CMPISint8* arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_sint8);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const CMPISint16* arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_sint16);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const CMPISint32* arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_sint32);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const CMPISint64* arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_sint64);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const CMPIReal32* arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_real32);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const CMPIReal64* arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_real64);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const char** arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_chars);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

CmpiArray ArrayConverter::makeCmpiArray(const CmpiDateTime* arr, CMPICount max) {
  CmpiArray cmpiarr(max,CMPI_dateTime);
  for (CMPICount i=0; i < max; i++) {
    cmpiarr[i]=arr[i];
  }
  return cmpiarr;
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, unsigned char** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new unsigned char[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, unsigned short** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new unsigned short[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, CMPIUint32** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new CMPIUint32[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, CMPIUint64** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new CMPIUint64[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, CMPISint8** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new CMPISint8[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, CMPISint16** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new CMPISint16[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, CMPISint32** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new CMPISint32[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, CMPISint64** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new CMPISint64[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, CMPIReal32** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new CMPIReal32[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, CMPIReal64** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new CMPIReal64[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, char*** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new char*[num];
  for (CMPICount i=0; i < num; i++) {
    CmpiString dummy = cmpiarr[i];
    const char *str = dummy.charPtr();
    if (str) {
      (*arr)[i]=new char[strlen(str)+1];
      strcpy((*arr)[i],str);
    } else {
      (*arr)[i]=0;
    }
  }
}

void ArrayConverter::makeArray(const CmpiArray &cmpiarr, CmpiDateTime** arr, CMPICount& num) {
  num = cmpiarr.size();
  *arr = new CmpiDateTime[num];
  for (CMPICount i=0; i < num; i++) {
    (*arr)[i] = cmpiarr[i];
  }
}

void ArrayConverter::destructArray(unsigned char* arr) {
  delete arr;
}

void ArrayConverter::destructArray(unsigned short* arr) {
  delete arr;
}

void ArrayConverter::destructArray(CMPIUint32* arr) {
  delete arr;
}

void ArrayConverter::destructArray(CMPIUint64* arr) {
  delete arr;
}

void ArrayConverter::destructArray(CMPISint8* arr) {
  delete arr;
}

void ArrayConverter::destructArray(CMPISint16* arr) {
  delete arr;
}

void ArrayConverter::destructArray(CMPISint32* arr) {
  delete arr;
}

void ArrayConverter::destructArray(CMPISint64* arr) {
  delete arr;
}

void ArrayConverter::destructArray(CMPIReal32* arr) {
  delete arr;
}

void ArrayConverter::destructArray(CMPIReal64* arr) {
  delete arr;
}

void ArrayConverter::destructArray(char** arr, CMPICount num) {
  for (CMPICount i=0; i < num; i++) {
    delete (arr[i]);
  }
  delete(arr);
}

void ArrayConverter::destructArray(CmpiDateTime* arr) {
  delete arr;
}
}
