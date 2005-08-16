/*
 * readzones.pl
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

use lib '/usr/share/YaST2/modules';
use YaPI::DNSD;

my $zones = YaPI::DNSD->ReadZones ();
if (! defined ($zones))
{
    print ("Could not read zones");
}
else
{
    my $count = @{$zones};
    print "Maintaining $count zones\n";
}
