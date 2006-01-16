# $Id: Makefile.am,v 1.2 2006/01/16 17:23:07 taphorn Exp $
# ==================================================================
# (C) Copyright IBM Corp. 2005
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Common Public License from
# http://www.opensource.org/licenses/cpl1.0.php
#
# Author:       Wolfgang Taphorn <taphorn@de.ibm.com>
# Description:  Automake input file for resource access layer.
# ==================================================================


# SBLIM Include Directory
sblimincdir = $(includedir)/sblim

# SBLIM Headers to be installed
sbliminc_HEADERS =


# docdir defines where the documentation goes
docdir = $(datadir)/doc/$(PACKAGE)-$(VERSION)

# Non-Installable Header Files
noinst_HEADERS =

# Configuration files
sysconf_DATA =

# Scripts that are used in the libraries
pkgdata_SCRIPTS =

# System wide libraries
lib_LTLIBRARIES =

# providerdir defines where provider libraries will be installed (@PROVIDERDIR@ is set by the configure script). 
providerdir = @PROVIDERDIR@

# Start from an empty list for files to clean up
CLEANFILES =

# Start from an empty extra distribution file list
EXTRA_DIST =

# Pre Build requirements need to be compiled prior anything else
BUILT_SOURCES = 


######################################################################################
# sed scriptlets for replacing values in .in files
do_substDir    = sed -e 's,[@]SYSCONFDIR[@],$(sysconfdir),g' \
                     -e 's,[@]SCRIPTDIR[@],$(pkgdatadir),g'



######################################################################################
# Automake instructions for 'resource-access' dir

BUILT_SOURCES += \
		$(srcdir)/smt_dns_ra_support.conf 

$(srcdir)/smt_dns_ra_support.conf: $(srcdir)/smt_dns_ra_support.conf.in
	$(do_substDir) < $(srcdir)/smt_dns_ra_support.conf.in > $(srcdir)/smt_dns_ra_support.conf


# Adding new generated files to file list for clean up
CLEANFILES += \
		$(srcdir)/smt_dns_ra_support.conf

# Files for /etc directory
sysconf_DATA += $(srcdir)/smt_dns_ra_support.conf

#  LibRaTools libraries
lib_LTLIBRARIES += libRaToolsDns.la 

# LibRaTools sources
libRaToolsDns_la_SOURCES = \
		$(srcdir)/smt_dns_ra_support.conf.in \
		$(srcdir)/smt_dns_ra_support.h \
		$(srcdir)/smt_dns_ra_support.c \
		$(srcdir)/smt_dns_ra_perlxsi.c \
		$(srcdir)/smt_dns_ra_rrhandle.c \
		$(srcdir)/smt_dns_ra_service.c
libRaToolsDns_la_CPPFLAGS = -fPIC `perl -MExtUtils::Embed -e ccopts` -DUSE_CACHE
libRaToolsDns_la_LDFLAGS = -fPIC `perl -MExtUtils::Embed -e ldopts`

# Scripts that are copied to an executable (at least for the libs) directory.
pkgdata_SCRIPTS += \
		$(srcdir)/scripts/smt_dns_ra_delete.sh \
		$(srcdir)/scripts/smt_dns_ra_deleterr.sh \
		$(srcdir)/scripts/smt_dns_ra_disable.sh \
		$(srcdir)/scripts/smt_dns_ra_disablerr.sh \
		$(srcdir)/scripts/smt_dns_ra_enable.sh \
		$(srcdir)/scripts/smt_dns_ra_enablerr.sh \
		$(srcdir)/scripts/smt_dns_ra_status.sh \
		$(srcdir)/scripts/smt_dns_ra_acl.pm \
		$(srcdir)/scripts/smt_dns_ra_getopts.pl \
		$(srcdir)/scripts/smt_dns_ra_getzones.pl \
		$(srcdir)/scripts/smt_dns_ra_readacl.pl \
 		$(srcdir)/scripts/smt_dns_ra_lines.awk
 
# Installable Header Files
sbliminc_HEADERS += \
		$(srcdir)/smt_dns_ra_scripts.h \
		$(srcdir)/smt_dns_ra_service.h \
		$(srcdir)/smt_dns_ra_rrhandle.h \
		$(srcdir)/smt_dns_ra_perlstr.h \
		$(srcdir)/smt_dns_ra_support.h

# We must explicity add the list of scripts to the 
EXTRA_DIST += $(pkgdata_SCRIPTS)

