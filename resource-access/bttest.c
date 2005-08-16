/*
 * bttest.c
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
 * Author:  Glauber de Oliveira Costa <gocosta@br.ibm.com>
 *
 * Contributors:
 *
 */
#include <stdio.h>

static int uint64_to_BindTime(unsigned long long ull, char * time)
{
  unsigned long long divresult=ull;
  unsigned long long modresult=0;
  char suffix=' ';
  if (time) {
    /* minutes */
    modresult = ull % 60;
    if (modresult==0 && (divresult/60)) {
      divresult /= 60;
      suffix = 'M';
      if (divresult >= 60) {
	/* hours */
	modresult = divresult % 60;
	if (modresult==0) {
	  divresult /= 60;
	  suffix = 'H'; 
	  if (divresult >= 24) {
	    /* days */
	    modresult = divresult % 24;
	    if (modresult==0) {
	      divresult /= 24;
	      suffix = 'D'; 
	      if (divresult >= 7) {
		/* weeks */
		modresult = divresult % 7;
		if (modresult == 0) {
		  divresult /= 7;
		  suffix = 'W';
		}
	      }
	    }
	  }
	}
      }
    }

    sprintf(time,"%lld%c",divresult,suffix);

    return 0;
  } else {
    return -1;
  }
}

main()
{
  char buf[20];
  uint64_to_BindTime(30ULL,buf);
  printf ("%lld: %s\n",30ULL,buf);
  uint64_to_BindTime(59ULL,buf);
  printf ("%lld: %s\n",59ULL,buf);
  uint64_to_BindTime(60ULL,buf);
  printf ("%lld: %s\n",60ULL,buf);
  uint64_to_BindTime(70ULL,buf);
  printf ("%lld: %s\n",70ULL,buf);
  uint64_to_BindTime(119ULL,buf);
  printf ("%lld: %s\n",119ULL,buf);
  uint64_to_BindTime(120ULL,buf);
  printf ("%lld: %s\n",120ULL,buf);
  uint64_to_BindTime(3540ULL,buf);
  printf ("%lld: %s\n",3540ULL,buf);
  uint64_to_BindTime(3599ULL,buf);
  printf ("%lld: %s\n",3599ULL,buf);
  uint64_to_BindTime(3600ULL,buf);
  printf ("%lld: %s\n",3600ULL,buf);
  uint64_to_BindTime(3*3600ULL,buf);
  printf ("%lld: %s\n",3*3600ULL,buf);
  uint64_to_BindTime(24*3600ULL-60,buf);
  printf ("%lld: %s\n",24*3600ULL-60,buf);
  uint64_to_BindTime(24*3600ULL-3600,buf);
  printf ("%lld: %s\n",24*3600ULL-3600,buf);
  uint64_to_BindTime(24*3600ULL-1,buf);
  printf ("%lld: %s\n",24*3600ULL-1,buf);
  uint64_to_BindTime(24*3600ULL,buf);
  printf ("%lld: %s\n",24*3600ULL,buf);
  uint64_to_BindTime(24*3600ULL+1,buf);
  printf ("%lld: %s\n",24*3600ULL+1,buf);
  uint64_to_BindTime(7*24*3600ULL-1,buf);
  printf ("%lld: %s\n",7*24*3600ULL-1,buf);
  uint64_to_BindTime(7*24*3600ULL,buf);
  printf ("%lld: %s\n",7*24*3600ULL,buf);
  uint64_to_BindTime(7*24*3600ULL+1,buf);
  printf ("%lld: %s\n",7*24*3600ULL+1,buf);
  uint64_to_BindTime(7*24*3600ULL+60,buf);
  printf ("%lld: %s\n",7*24*3600ULL+60,buf);
  uint64_to_BindTime(7*24*3600ULL+3600,buf);
  printf ("%lld: %s\n",7*24*3600ULL+3600,buf);
  uint64_to_BindTime(7*24*3600ULL+3600*24,buf);
  printf ("%lld: %s\n",7*24*3600ULL+3600*24,buf);
  return 0;
}
