#
# writezones.pl
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

  my $zones = [
    {
      'options' => [
        {
            'value' => 'master',
            'key' => 'type'
        },
        {
            'value' => '"localhost.zone"',
            'key' => 'file'
        }
      ],
      'zone' => 'localhost',
      'ttl' => '1W',
      'records' => [
        {
            'value' => '127.0.0.1',
            'type' => 'A',
            'key' => 'localhost.'
        },
        {
            'value' => '@',
            'type' => 'NS',
            'key' => 'localhost.'
        }
      ],
      'file' => 'localhost.zone',
      'type' => 'master',
      'soa' => {
        'minimum' => '1W',
        'expiry' => '6W',
        'serial' => 2004012701,
        'zone' => '@',
        'retry' => '4H',
        'refresh' => '2D',
        'mail' => 'root',
        'server' => '@'
      }
    },
    {
      'options' => [
        {
            'value' => 'master',
            'key' => 'type'
        },
        {
            'value' => '"mydomain.zone"',
            'key' => 'file'
        }
      ],
      'zone' => 'glommerdomain',
      'ttl' => '1W',
      'records' => [
        {
            'value' => '10.0.0.1',
            'type' => 'A',
            'key' => 'ns.mydomain.com.'
        },
        {
            'value' => '@',
            'type' => 'NS',
            'key' => 'ns.mydomain.com.'
        }
      ],
      'file' => 'mydomain.zone',
      'type' => 'master',
      'soa' => {
        'minimum' => '1W',
        'expiry' => '6W',
        'serial' => 2004012701,
        'zone' => '@',
        'retry' => '4H',
        'refresh' => '2D',
        'mail' => 'root',
        'server' => '@'
      }
    },
    {
      'options' => [
        {
            'value' => 'master',
            'key' => 'type'
        },
        {
            'value' => '"0.0.10.in-addr.arpa.zone"',
            'key' => 'file'
        }
      ],
      'zone' => '0.0.10.in-addr.arpa',
      'ttl' => '1W',
      'records' => [
        {
            'value' => 'ns.',
            'type' => 'PTR',
            'key' => '1',
        },
        {
            'value' => 'ns.',
            'type' => 'NS',
            'key' => '0.0.10.in-addr.arpa.'
        }
      ],
      'file' => '0.0.10.in-addr.arpa.zone',
      'type' => 'master',
      'soa' => {
        'minimum' => '1W',
        'expiry' => '6W',
        'serial' => 2004012701,
        'zone' => '@',
        'retry' => '4H',
        'refresh' => '2D',
        'mail' => 'root',
        'server' => '@'
      }
    }
  ];

my $x=YaPI::DNSD->WriteZones ({}, $zones);
