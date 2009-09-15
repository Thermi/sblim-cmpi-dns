#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(SBLIM CMPI Provider for WBEM-SMT DNS task, 1.0, sblim-devel@lists.sourceforge.net, sblim-cmpi-dns)
AC_CONFIG_SRCDIR([.])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([tar-ustar])

AC_CANONICAL_HOST
case $host_cpu in
     i*86) HW=INTEL;; 
     s390*) HW=S390;; 
     ppc*) HW=PPC;; 
     x86_64) HW=X86_64;; 
     ia64) HW=IA64;; 
     **) HW=GENERIC;;
esac

AC_ARG_VAR([PROVIDERDIR],[the directory where the CMPI providers will be installed.])
AC_ARG_VAR([CIMSERVER],[the target CIM server (pegasus|sfcb|openwbem|sniacimom).])
AC_ARG_VAR([TESTSUITEDIR],[the directory where the SBLIM TestSuite is installed.])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL

AC_CHECK_PROG(LEX,flex,[flex])
if test -z "${LEX}"
then
	AC_MSG_ERROR([GNU flex is required to build the cmpi-dns package.])
fi
AC_CHECK_PROG(YACC,bison,[bison])
if test -z "${YACC}"
then
	AC_MSG_ERROR([GNU bison is required to build the cmpi-dns package.])
fi

# Check for installed CIM Server (defined in local m4 macro)
CHECK_CIMSERVER

# Check for required CIM Server provider directory (defined in local m4 macro)
CHECK_CIMSERVER_PROVIDERDIR

# Check for required CMPI header files (defined in local m4 macro)
CHECK_CMPI_HEADER

# Check for SBLIM TestSuite support (defined in local m4 macro)
CHECK_SBLIM_TESTSUITE

# Check for required WBEM-SMT Resource Access header files (defined in local m4 macro)
CHECK_SBLIM_LIBRA_HEADER

# Checks for libraries.
AC_CHECK_LIB(RaTools, main, [], [AC_MSG_ERROR(You have to install libRaTools first)])
AC_CHECK_LIB(cmpiCppImpl, main, [], [AC_MSG_ERROR(You have to install cmpiCppImpl first)])

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_HEADER_STDBOOL
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h strings.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_OFF_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_SELECT_ARGTYPES
AC_FUNC_STAT
AC_CHECK_FUNCS([memmove select strchr strdup memset mkdir strcasecmp strndup strstr])

AC_CONFIG_FILES(Makefile sblim-cmpi-dns.spec)
AC_CONFIG_FILES(resource-access/Makefile resource-access/smt_dns_ra_support.conf.pre)
AC_CONFIG_FILES(man/Makefile man/smt_dns_ra_support.conf.5.pre)
AC_CONFIG_FILES(provider/Makefile)
AC_CONFIG_FILES(provider/CIM_ConcreteJob/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAddressMatchList/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAddressMatchListsForService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAllowNotifyForZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAllowQueryForZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAllowTransferForZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAllowUpdateForZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAllowNotifyForService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAllowQueryForService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAllowRecursionForService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsAllowTransferForService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsBlackholeForService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsForwarders/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsForwardersForService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsForwardersForZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsForwardZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsHintZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsMasters/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsMasterZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsMastersForZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsMastersForService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsRegisteredProfile/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsResourceRecord/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsResourceRecordsForZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsServiceConfiguration/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsServiceConfigurationForService/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsServiceSettingData/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsServiceSettingDataForServiceConfiguration/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsSlaveZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsStubZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsZone/Makefile)
AC_CONFIG_FILES(provider/Linux_DnsElementConformsToProfile/Makefile)
AC_CONFIG_FILES(test/Makefile)

echo
AC_OUTPUT
echo

# Display configuration options
echo "-------------------------------------------------------"
echo "Configuration for $PACKAGE complete."
echo ""
echo "The following configuration options have been selected:"
echo "CIMSERVER: " $CIMSERVER
echo "PROVIDERDIR: " $PROVIDERDIR
echo "CPPFLAGS:" $CPPFLAGS
echo "LDFLAGS:" $LDFLAGS
echo 
if test $TESTSUITEDIR; then
  echo "Test Suite Support: enabled"
  echo "TESTSUITEDIR = $TESTSUITEDIR"
else
  echo "Test Suite Support: disabled"
fi
echo "-------------------------------------------------------"
echo
echo "You may now run make"
echo
