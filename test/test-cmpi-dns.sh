#!/bin/bash

# test sblim-cmpi-dns package

SCRIPT_PATH=`dirname ${BASH_SOURCE}`

#*****************************************************************************#

export SBLIM_TESTSUITE_RUN=1;
export DNSCONFDIR=/var/lib/named
export TESTCONFFILE=named.conf
export DNSCONFFILE=$DNSCONFDIR/$TESTCONFFILE
export DNSZONEDIR=/var/lib/named

export TESTZONEFILE1=testnamed.ca
export TESTZONEFILE2=testnamed.broadcast
export TESTZONEFILE3=testnamed.zero
export TESTZONEFILE4=testnamed.ip6.local
export TESTZONEFILE5=testnamed.local
export TESTZONEFILE6=testlocaldomain.zone
export TESTZONEFILE7=testlocalhost.zone

export DNSZONEFILE1=$DNSZONEDIR/$TESTZONEFILE1
export DNSZONEFILE2=$DNSZONEDIR/$TESTZONEFILE2
export DNSZONEFILE3=$DNSZONEDIR/$TESTZONEFILE3
export DNSZONEFILE4=$DNSZONEDIR/$TESTZONEFILE4
export DNSZONEFILE5=$DNSZONEDIR/$TESTZONEFILE5
export DNSZONEFILE6=$DNSZONEDIR/$TESTZONEFILE6
export DNSZONEFILE7=$DNSZONEDIR/$TESTZONEFILE7

#******************************************************************************#

init () {
  # Install an example config file and save the original if one exists
  if [[ -a $DNSCONFFILE ]]; then
    echo "Saving original config file $DNSCONFFILE to $DNSCONFFILE.sblimsave..."
    cp -p $DNSCONFFILE $DNSCONFFILE.sblimsave
  fi 

  if [[ -a $DNSZONEFILE1 ]]; then
    echo "Saving original zone file $DNSZONEFILE1 to $DNSZONEFILE1.sblimsave..."
    cp -p $DNSZONEFILE1 $DNSZONEFILE1.sblimsave
  fi 

  if [[ -a $DNSZONEFILE2 ]]; then
    echo "Saving original zone file $DNSZONEFILE2 to $DNSZONEFILE2.sblimsave..."
    cp -p $DNSZONEFILE2 $DNSZONEFILE2.sblimsave
  fi 

  if [[ -a $DNSZONEFILE3 ]]; then
    echo "Saving original zone file $DNSZONEFILE3 to $DNSZONEFILE3.sblimsave..."
    cp -p $DNSZONEFILE3 $DNSZONEFILE3.sblimsave
  fi 

  if [[ -a $DNSZONEFILE4 ]]; then
    echo "Saving original zone file $DNSZONEFILE4 to $DNSZONEFILE4.sblimsave..."
    cp -p $DNSZONEFILE4 $DNSZONEFILE4.sblimsave
  fi 

  if [[ -a $DNSZONEFILE5 ]]; then
    echo "Saving original zone file $DNSZONEFILE5 to $DNSZONEFILE5.sblimsave..."
    cp -p $DNSZONEFILE5 $DNSZONEFILE5.sblimsave
  fi 

  if [[ -a $DNSZONEFILE6 ]]; then
    echo "Saving original zone file $DNSZONEFILE6 to $DNSZONEFILE6.sblimsave..."
    cp -p $DNSZONEFILE6 $DNSZONEFILE6.sblimsave
  fi 

  if [[ -a $DNSZONEFILE7 ]]; then
    echo "Saving original zone file $DNSZONEFILE7 to $DNSZONEFILE7.sblimsave..."
    cp -p $DNSZONEFILE7 $DNSZONEFILE7.sblimsave
  fi 

  echo "Copying test config file $TESTCONFFILE to $DNSCONFFILE ..."
  cp -p $TESTCONFFILE $DNSCONFFILE

  echo "Copying test zone file $TESTZONEFILE1 to $DNSZONEFILE1 ..."
  cp -p $TESTZONEFILE1 $DNSZONEFILE1

  echo "Copying test zone file $TESTZONEFILE2 to $DNSZONEFILE2 ..."
  cp -p $TESTZONEFILE2 $DNSZONEFILE2

  echo "Copying test zone file $TESTZONEFILE3 to $DNSZONEFILE3 ..."
  cp -p $TESTZONEFILE3 $DNSZONEFILE3

  echo "Copying test zone file $TESTZONEFILE4 to $DNSZONEFILE4 ..."
  cp -p $TESTZONEFILE4 $DNSZONEFILE4

  echo "Copying test zone file $TESTZONEFILE5 to $DNSZONEFILE5 ..."
  cp -p $TESTZONEFILE5 $DNSZONEFILE5

  echo "Copying test zone file $TESTZONEFILE6 to $DNSZONEFILE6 ..."
  cp -p $TESTZONEFILE6 $DNSZONEFILE6

  echo "Copying test zone file $TESTZONEFILE7 to $DNSZONEFILE7 ..."
  cp -p $TESTZONEFILE7 $DNSZONEFILE7

  cimserver -s 
  cimserver 
}


#*****************************************************************************#
cleanup() {
  if [[ -a $DNSCONFFILE.sblimsave ]]; then
    echo "Moving back the original config file ..."
    mv $DNSCONFFILE.sblimsave $DNSCONFFILE
  fi

  if [[ -a $DNSZONEFILE1.sblimsave ]]; then
    echo "Moving back the original zone file ..."
    mv $DNSZONEFILE1.sblimsave $DNSZONEFILE1
  fi

  if [[ -a $DNSZONEFILE2.sblimsave ]]; then
    echo "Moving back the original zone file ..."
    mv $DNSZONEFILE2.sblimsave $DNSZONEFILE2
  fi

  if [[ -a $DNSZONEFILE2.sblimsave ]]; then
    echo "Moving back the original zone file ..."
    mv $DNSZONEFILE2.sblimsave $DNSZONEFILE2
  fi

  if [[ -a $DNSZONEFILE3.sblimsave ]]; then
    echo "Moving back the original zone file ..."
    mv $DNSZONEFILE3.sblimsave $DNSZONEFILE3
  fi

  if [[ -a $DNSZONEFILE4.sblimsave ]]; then
    echo "Moving back the original zone file ..."
    mv $DNSZONEFILE4.sblimsave $DNSZONEFILE4
  fi

  if [[ -a $DNSZONEFILE5.sblimsave ]]; then
    echo "Moving back the original zone file ..."
    mv $DNSZONEFILE5.sblimsave $DNSZONEFILE5
  fi

  if [[ -a $DNSZONEFILE6.sblimsave ]]; then
    echo "Moving back the original zone file ..."
    mv $DNSZONEFILE6.sblimsave $DNSZONEFILE6
  fi

  if [[ -a $DNSZONEFILE7.sblimsave ]]; then
    echo "Moving back the original zone file ..."
    mv $DNSZONEFILE7.sblimsave $DNSZONEFILE7
  fi

  exit 1
}


#*****************************************************************************#
trap cleanup 2 3 4 6 9 15


#*****************************************************************************#

declare -a CLASSNAMES[];
CLASSNAMES=(

[0]=Linux_DnsMasterZone
[1]=Linux_DnsForwardZone
[2]=Linux_DnsHintZone
[3]=Linux_DnsSlaveZone
[4]=Linux_DnsStubZone
[5]=Linux_DnsResourceRecord
[6]=Linux_DnsService
[7]=Linux_DnsServiceConfiguration
[8]=Linux_DnsServiceSettingData
[9]=Linux_DnsMasters
[10]=Linux_DnsForwarders
[11]=Linux_DnsAddressMatchList
[12]=Linux_DnsAddressMatchListsForService
[13]=Linux_DnsAllowNotifyForZone
[14]=Linux_DnsAllowQueryForZone
[15]=Linux_DnsAllowTransferForZone
[15]=Linux_DnsAllowUpdateForZone
[17]=Linux_DnsAllowNotifyForService
[18]=Linux_DnsAllowQueryForService
[19]=Linux_DnsAllowRecursionForService
[20]=Linux_DnsAllowTransferForService
[21]=Linux_DnsBlackholeForService
[22]=Linux_DnsForwardersForService
[23]=Linux_DnsForwardersForZone
[24]=Linux_DnsMastersForService
[25]=Linux_DnsMastersForZone
[26]=Linux_DnsResourceRecordsForZone
[27]=Linux_DnsServiceConfigurationForService
[28]=Linux_DnsServiceSettingDataForServiceConfiguration
)

#*****************************************************************************#

init

declare -i max=28;
declare -i i=0;

cd $SCRIPT_PATH
while(($i<=$max))
do
  . ${SCRIPT_PATH}/run.sh ${CLASSNAMES[$i]} || exit 1;
  i=$i+1;
done

. ${SCRIPT_PATH}/run.sh Linux_DHCPRegisteredProfile -n /root/PG_InterOp  || exit 1;
. ${SCRIPT_PATH}/run.sh Linux_DHCPElementConformsToProfile -n /root/PG_InterOp || exit 1;
cleanup

#*****************************************************************************#

