#
# ACL.pm
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

package smt_dns_ra_acl;
use YaST::YCP;
YaST::YCP::Import ("DnsServer");
YaST::YCP::Import ("Service");
YaST::YCP::Import ("Progress");

our $VERSION='1.0.0';
our @CAPABILITIES = ('SLES9');
our %TYPEINFO;

use strict;
use Errno qw(ENOENT);




BEGIN{$TYPEINFO{ReadAcl} = ["function", ["list", ["map", "string", "any"]], ["map", "string", "any"]];}
sub ReadAcl {
    my $self = shift;
    my $config_options = shift;
		
    DnsServer->InitYapiConfigOptions ($config_options);

    Progress::off ();

		my $acl = undef;	
    my $ret = DnsServer->Read ();
		if ($ret)	
		{
			$acl = DnsServer->GetAcl();
		}
		Progress::on();

    DnsServer->CleanYapiConfigOptions ();
		my $aclarray = [];
		foreach $a (@$acl){
  		$_ =  $a;

  		if ( /\"?\'?([^{"' ]+)\"?\'?(.*)/ ){
    		$$aclarray[$#$aclarray +1] =
   			{
      			'key' => $1,
      			'value' => $2,
    		};
  		}
		}
		
		return $aclarray;

}

BEGIN{$TYPEINFO{WriteAcl} = ["function", "boolean", ["map", "string", "any"], ["list", ["map", "string", "any"]]];}
sub WriteAcl {
    my $config_options = shift;
    my $acl= shift;


    DnsServer->InitYapiConfigOptions ($config_options);
    Progress::off ();
    my $ret = DnsServer->Read ();
		$ret = $ret && (DnsServer->SetAcl($acl) || !@$acl);
		DnsServer::SetModified();
		$ret = $ret && DnsServer->Write ();
    Progress::on ();

    DnsServer->CleanYapiConfigOptions ();

    return $ret;

}


1;
