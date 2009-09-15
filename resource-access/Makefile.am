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
# Description:  Automake input file for resource access layer.
# ==================================================================

AM_CFLAGS = -Wall

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

# Start from an empty list of programs not to install
noinst_PROGRAMS =


######################################################################################
# Automake instructions for 'resource-access' dir

smt_dns_ra_support.conf: smt_dns_ra_support.conf.pre
	sed -e 's,[@]SCRIPTDIR[@],$(pkgdatadir),g' -e s?$$\{prefix\}?$(prefix)?g -e s?$$\{exec_prefix\}?$(prefix)?g $< > $@

# Adding new generated files to file list for clean up
CLEANFILES += \
	smt_dns_ra_support.conf \
	conf.parser.tab.c \
	conf.parser.tab.h \
	lex.conf.c \
	zone.parser.tab.c \
	zone.parser.tab.h \
	lex.zone.c

# Files for /etc directory
sysconf_DATA += smt_dns_ra_support.conf

# Parser binaries for testing
noinst_PROGRAMS += confParseTest zoneParseTest confLexTest zoneLexTest #apiTest

nodist_confParseTest_SOURCES = \
	parser_support.c \
	conf.parser.tab.c \
	lex.conf.c

confParseTest_CPPFLAGS = \
	-D_GNU_SOURCE \
	-DDEBUG_YACC

nodist_confLexTest_SOURCES = \
	parser_support.c \
	conf.parser.tab.c \
	lex.conf.c

confLexTest_CPPFLAGS = \
	-D_GNU_SOURCE \
	-DDEBUG_LEX

nodist_zoneLexTest_SOURCES = \
	parser_support.c \
	zone.parser.tab.c \
	lex.zone.c

zoneLexTest_CPPFLAGS = \
	-D_GNU_SOURCE \
	-DDEBUG_LEX

nodist_zoneParseTest_SOURCES = \
	parser_support.c \
	zone.parser.tab.c \
	lex.zone.c

zoneParseTest_CPPFLAGS = \
	-D_GNU_SOURCE \
	-DDEBUG_YACC

#  LibRaTools libraries
lib_LTLIBRARIES += libRaToolsDns.la 

# LibRaTools sources
libRaToolsDns_la_SOURCES = \
    parser_support.c \
    smt_dns_ra_support.c \
    smt_dns_ra_rrhandle.c \
    smt_dns_ra_service.c

nodist_libRaToolsDns_la_SOURCES = \
    conf.parser.tab.h \
    zone.parser.tab.h \
    conf.parser.tab.c \
    zone.parser.tab.c \
    lex.conf.c \
    lex.zone.c
 
libRaToolsDns_la_CPPFLAGS = \
    -fPIC \
    -DUSE_CACHE \
    -DCONFFILE=\"$(sysconfdir)/smt_dns_ra_support.conf\" \
    -D_GNU_SOURCE

libRaToolsDns_la_LDFLAGS = \
    -fPIC 

# Scripts that are copied to an executable (at least for the libs) directory.
pkgdata_SCRIPTS += \
    scripts/smt_dns_ra_status.sh \
    scripts/smt_dns_ra_delete.sh \
    scripts/smt_dns_ra_disable.sh \
    scripts/smt_dns_ra_enable.sh \
    scripts/smt_dns_ra_deleterr.sh \
    scripts/smt_dns_ra_disablerr.sh \
    scripts/smt_dns_ra_enablerr.sh \
    scripts/smt_dns_ra_cleanuprr.sh \
    scripts/smt_dns_ra_lines.awk
 
# Installable Header Files
noinst_HEADERS += \
    parser_support.h \
    smt_dns_ra_cache.h \
    smt_dns_ra_scripts.h \
    smt_dns_ra_service.h \
    smt_dns_ra_rrhandle.h \
    smt_dns_ra_support.h


# We must explicity add the list of scripts to the 
EXTRA_DIST += $(pkgdata_SCRIPTS) conf.lexer.l conf.parser.y zone.lexer.l zone.parser.y

lex.conf.c: conf.lexer.l
	$(LEX) $<

conf.parser.tab.c: conf.parser.y
	$(YACC) $<

lex.zone.c: zone.lexer.l
	$(LEX) $<

zone.parser.tab.c: zone.parser.y
	$(YACC) $<

