# ==================================================================
# (C) Copyright IBM Corp. 2005
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Eclipse Public License from
# http://www.opensource.org/licenses/eclipse-1.0.php
#
# Author:       Wolfgang Taphorn <taphorn@de.ibm.com>
# Description:  Automake input file for cmpi provider and resource
#               access layer.
# ==================================================================

#Include local M4 macros
ACLOCAL_AMFLAGS = -I m4

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

# Subdirectories to recognize during build process
if SBLIM_TESTSUITE
  TESTCASE_DIR = test
endif
SUBDIRS = $(TESTCASE_DIR) man resource-access provider

# Automake instructions for documentation
doc_DATA = README AUTHORS COPYING NEWS ChangeLog TroubleShooting
EXTRA_DIST += $(doc_DATA)

######################################################################################
# We must explicitly add the RPM spec file to the distribution package
EXTRA_DIST += $(PACKAGE).spec


######################################################################################
# Automake instructions for ./model subdir
SCHEMAS = $(srcdir)/model/Linux_Dns_Profile.mof \
	$(srcdir)/model/Linux_Dns.mof

REGISTRATIONS = $(srcdir)/model/Linux_Dns.registration

######################################################################################
INTEROP_SCHEMAS = $(srcdir)/model/Linux_Dns_Profile.mof

######################################################################################
INTEROP_REGISTRATIONS = $(srcdir)/model/Linux_Dns_Profile.registration

######################################################################################

# We must explicitly add all the schema files to the distribution package
pkgdata_DATA = $(SCHEMAS) $(REGISTRATIONS) $(INTEROP_SCHEMAS) $(INTEROP_REGISTRATIONS)

pkgdata_SCRIPTS += $(srcdir)/provider-register.sh

EXTRA_DIST += $(pkgdata_SCRIPTS) $(pkgdata_DATA)

# Register the provider(s) and class definition(s) to the current CIM server/CIMOM
postinstall:
	sh provider-register.sh -t @CIMSERVER@ -r $(REGISTRATIONS) -m $(SCHEMAS)
	sh provider-register.sh -t @CIMSERVER@ -n "root/PG_InterOp" -r $(INTEROP_REGISTRATIONS) -m $(INTEROP_SCHEMAS)

preuninstall:
	sh provider-register.sh -d -t @CIMSERVER@ -r $(REGISTRATIONS) -m $(SCHEMAS)
	sh provider-register.sh -d -t @CIMSERVER@ -n "root/PG_InterOp" -r $(INTEROP_REGISTRATIONS) -m $(INTEROP_SCHEMAS)

dist-hook:
	test -d "$(distdir)" &&	rm -rf `find $(distdir) -type d -name CVS`

