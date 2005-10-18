#!/usr/bin/perl

#
# getzones.pl
#
# (C) Copyright IBM Corp. 2005
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Common Public License from
# http://www.opensource.org/licenses/cpl1.0.php
#
# Author:  Glauber de Oliveira Costa <gocosta@br.ibm.com>
#
# Contributors:
#
#

use lib '/usr/share/YaST2/modules';
use YaPI::DNSD; 


if ($#ARGV < 0){
	exit 1;
}
my $zones = YaPI::DNSD->ReadZones({});

my $pipefd = $ARGV[0]; 
#For Zones:
#
## : Number of zones
#N : zoneName
#T : zoneType
#F : zoneFileName
#C : soaContact
#S : soaServer
#U : soaSerialNumber
#R : soaRefresh
#Y : soaRetry
#E : soaExpire
#L : soaNegativeCachingTTL
#
#For Options:
#
#K : Key
#V : Value
#
#For Records:
#
#N : recordName
#Z : recordZoneName
#T : recordNegativeCachingTTL
#V : recordValue

open (PIPE,">&$pipefd");

$nzones = $#$zones +1;
if ($nzones >0){
	print PIPE "#:$nzones\n";

	foreach $zone (@$zones){
		print PIPE "N:$$zone{'zone'}\n";
		print PIPE "T:$$zone{'type'}\n"; 
		print PIPE "F:$$zone{'file'}\n";
  	$soa = $$zone{'soa'};
		if ($soa){
			print PIPE "C:$$soa{'mail'}\n";
			print PIPE "S:$$soa{'server'}\n";
			print PIPE "U:$$soa{'serial'}\n";
			print PIPE "R:$$soa{'refresh'}\n";
			print PIPE "Y:$$soa{'retry'}\n";
			print PIPE "E:$$soa{'expiry'}\n";
		}
		print PIPE "OPTS\n";
		$opts = $$zone{'options'};
		$nopts = $#$opts +1;
		if ($nopts > 0 ){
			print PIPE "#:$nopts\n";
			foreach $opt (@$opts){
				print PIPE "K:$$opt{'key'}\n";
				print PIPE "V:$$opt{'value'}\n";
			}
		}
		print PIPE "ENDOPTS\n";
	
		print PIPE "RRS\n";
		$rrs = $$zone{'records'};
		$nrrs = $#$rrs +1;
		if ($nrrs > 0 ){
			print PIPE "#:$nrrs\n";
			foreach $rr (@$rrs){
				print PIPE "N:$$rr{'key'}\n";
				print PIPE "Z:$$zone{'zone'}\n";
				print PIPE "T:$$rr{'type'}\n"; 
				print PIPE "V:$$rr{'value'}\n";
			}
		}
		print PIPE "ENDRRS\n";

	}
	print PIPE "ENDZONES\n";
}
close(PIPE);
