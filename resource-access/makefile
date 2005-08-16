# Makefile Skeleton for CMPI Instrumentation 
include setting.cmpi
VERSION=1

COMMONINC=../../tools-libra
DYNALOADER=`./dynaloader.sh`
PERL_CFLAGS=`perl -MExtUtils::Embed -e ccopts`
PERL_LDFLAGS=`perl -MExtUtils::Embed -e ldopts`

CFLAGS=-Wall -g -I$(COMMONINC) -I. -fPIC $(PERL_CFLAGS) -DUSE_CACHE 
LDFLAGS=-L. -L$(COMMONLIB_OUT) -lc  
LDSOFLAGS=-shared $(PERL_LDFLAGS) $(LDFLAGS) -lratools -Wl,-soname=$@.$(VERSION)

all: 	dynaloader libdnssupport.so dnstest

dynaloader:
	chmod +x dynaloader.sh

libdnssupport.so: dnssupport.o perlxsi.o rrhandle.o service.o 

dnstest: LDFLAGS+=-ldnssupport
dnstest: dnstest.o

perlxsi.c:
	perl -MExtUtils::Embed -e xsinit -- -o perlxsi.c -std

lib%.so: %.o 
	$(LINK.c) $(LDSOFLAGS) $^ -o $@ $(DYNALOADER) 

install: all
	install libdnssupport.so $(COMMONLIB_OUT)
	/sbin/ldconfig -N -n $(COMMONLIB_OUT)
	install -d $(COMMONLIB_OUT)/dns/scripts
	install -m 755 `find scripts -maxdepth 1 -type f` $(COMMONLIB_OUT)/dns/scripts
	sed  s:PEGASUS:$(COMMONLIB_OUT):g dnssupport.conf  > /etc/dnssupport.conf
	 
clean:
	$(RM)	*.so* *.o *~ dnstest

.PHONY: dynaloader clean all
