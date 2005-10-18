#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(SBLIM CMPI Provider for WBEM-SMT DNS task, 0.1.1, sblim-devel@lists.sourceforge.net, sblim-cmpi-dns)
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

AC_ARG_ENABLE(
  debug,
  [AS_HELP_STRING([--enable-debug],[enable debugging messages [default=yes]])],
  [
    if test $enableval = "yes"; then
      AC_MSG_RESULT(debugging ENABLED)
      CFLAGS="$CFLAGS -O0 -g"
      CXXFLAGS="$CXXFLAGS -O0 -g"
      FFLAGS="$FFLAGS -O0 -g"
    else
      AC_MSG_RESULT(debugging DISABLED)
      CFLAGS="$CFLAGS -O2"
      CXXFLAGS="$CXXFLAGS -O2"
      FFLAGS="$FFLAGS -O2"
    fi
  ],
  [
    AC_MSG_RESULT(debugging ENABLED)
    CFLAGS="$CFLAGS -O0 -g"
    CXXFLAGS="$CXXFLAGS -O0 -g"
    FFLAGS="$FFLAGS -O0 -g"
  ]
)

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL

# Check for required CMPI header files (defined in acinclude.m4)
CHECK_CMPI

# Check for required CMPI libraries (defined in acinclude.m4)
CHECK_CMPI_LIB

# Check for required libraries (defined in acinclude.m4)
CHECK_PROVIDERDIR

# Check for CIM Server (defined in acinclude.m4)
CHECK_CIMSERVER

# Check for tools-libra header files
CHECK_SBLIM_LIBRA

# Checks for libraries.
AC_CHECK_LIB(RaTools, main, [], [AC_MSG_ERROR(You have to install libRaTools first)])
AC_CHECK_LIB(cmpiCppImpl, main, [], [AC_MSG_ERROR(You have to install cmpiCppImpl first)])

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_OFF_T
AC_HEADER_TIME

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_SELECT_ARGTYPES
AC_FUNC_STAT
AC_CHECK_FUNCS([memmove select strchr strdup])
AC_CONFIG_FILES(Makefile sblim-cmpi-dns.spec resource-access/Makefile provider/Makefile)

# Display configuration options
echo "-------------------------------------------------------"
echo "Configuration for $PACKAGE complete."
echo ""
echo "The following configuration options have been selected:"
echo "CIMSERVER: " $CIMSERVER
echo "PROVIDERDIR: " $PROVIDERDIR
echo "CPPFLAGS:" $CPPFLAGS
echo "LDFLAGS:" $LDFLAGS
echo "-------------------------------------------------------"

AC_OUTPUT

echo "You may now run make"
