#!/usr/bin/perl

#
# getopts.pl
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


if ($#ARGV < 1){
	exit 1;
}

my $opts = YaPI::DNSD->ReadGlobalOptions({});

my $filename = $ARGV[0]; # bogus for now
my $pipefd = $ARGV[1]; 

open (PIPE,">&$pipefd");

$nopts = $#$opts +1;
if ($nopts >0){
	print PIPE "#:$nopts\n";

	foreach $opt (@$opts){
		print PIPE "K:$$opt{'key'}\n";
		print PIPE "V:$$opt{'value'}\n"; 
	}
	print PIPE "ENDOPTS\n";
}
close(PIPE);
