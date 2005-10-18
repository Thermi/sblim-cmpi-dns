#!/usr/bin/perl

#
# readacl.pl
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

if ($#ARGV < 1){
	exit 1;
}

my $file = $ARGV[0];
my $pipefd = $ARGV[1]; 

open (FILE, $file) or die (2); 

$acl = [];
while (<FILE>){
	if (/^\s*acl\s+["']?(\w+)["']?\s+({.*})/){
		$$acl[$#$acl +1] = {'key'=> $1,'value' => $2};
	}
}
close (FILE);

open (PIPE,">&$pipefd") or die (2);
## : Number of acls 
#K : Key	 
#V : Value 

$nacl = $#$acl +1;
if ($acl > 0){
	print PIPE "#:$nacl\n";
	foreach $thisacl (@$acl){
		print PIPE "K:$$thisacl{'key'}\n";
		print PIPE "V:$$thisacl{'value'}\n";
	}
}
print PIPE "ENDACL\n";
close(PIPE);

