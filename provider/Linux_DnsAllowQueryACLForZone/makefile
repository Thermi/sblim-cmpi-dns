include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsZone -I../Linux_DnsAddressMatchList -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsZoneSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsAllowQueryACLForZoneInstanceName.o \
        Linux_DnsAllowQueryACLForZoneInstance.o \
        Linux_DnsAllowQueryACLForZoneExternal.o \
        Linux_DnsAllowQueryACLForZoneRepositoryInstance.o \
        Linux_DnsAllowQueryACLForZoneRepositoryExternal.o \
        Linux_DnsAllowQueryACLForZoneManualInstance.o \
        Linux_DnsAllowQueryACLForZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsAllowQueryACLForZoneFakeFactory.o

NORMALFACTORY= Linux_DnsAllowQueryACLForZoneFactory.o

RESOURCEOBJECT= Linux_DnsAllowQueryACLForZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsAllowQueryACLForZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsAllowQueryACLForZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsAllowQueryACLForZoneSupport.so \
      libLinux_DnsAllowQueryACLForZone.so

libLinux_DnsAllowQueryACLForZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsAllowQueryACLForZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsAllowQueryACLForZone.so: LDFLAGS+=-lLinux_DnsAllowQueryACLForZoneSupport
libLinux_DnsAllowQueryACLForZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsAllowQueryACLForZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsAllowQueryACLForZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsAllowQueryACLForZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsAllowQueryACLForZone*.h $(COMMONINC)
	$(MAKE) -C mof -f $(MOFMAKEFILE) install

#------------------------------------------------------------------------------#

testfiles:	
	@[ -d $(CIMOMLIB) ] || ( echo directory $(CIMOMLIB) does not exist && false)
	@[ -d $(CIMOMINC) ] || ( echo directory $(CIMOMINC) does not exist - please create manually && false)
	@[ -d $(CIMOMMOF) ] || ( echo directory $(CIMOMMOF) does not exist - please create manually && false)
	@[ -d $(COMMONINC) ] || ( echo directory $(COMMONINC) does not exist - please create manually && false)
	@[ -d $(COMMONLIB) ] || ( echo directory $(COMMONLIB) does not exist - please create manually && false)

#------------------------------------------------------------------------------#

clean:
	$(RM) *.so *.o *~

#------------------------------------------------------------------------------#

uninstall: 
	$(MAKE) -C mof -f $(MOFMAKEFILE) uninstall;
#	$(RM) $(COMMONINC)/Linux_DnsAllowQueryACLForZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsAllowQueryACLForZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsAllowQueryACLForZone.so
