include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsZone -I../Linux_DnsAddressMatchList -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsZoneSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsAllowUpdateACLForZoneInstanceName.o \
        Linux_DnsAllowUpdateACLForZoneInstance.o \
        Linux_DnsAllowUpdateACLForZoneExternal.o \
        Linux_DnsAllowUpdateACLForZoneRepositoryInstance.o \
        Linux_DnsAllowUpdateACLForZoneRepositoryExternal.o \
        Linux_DnsAllowUpdateACLForZoneManualInstance.o \
        Linux_DnsAllowUpdateACLForZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsAllowUpdateACLForZoneFakeFactory.o

NORMALFACTORY= Linux_DnsAllowUpdateACLForZoneFactory.o

RESOURCEOBJECT= Linux_DnsAllowUpdateACLForZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsAllowUpdateACLForZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsAllowUpdateACLForZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsAllowUpdateACLForZoneSupport.so \
      libLinux_DnsAllowUpdateACLForZone.so

libLinux_DnsAllowUpdateACLForZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsAllowUpdateACLForZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsAllowUpdateACLForZone.so: LDFLAGS+=-lLinux_DnsAllowUpdateACLForZoneSupport
libLinux_DnsAllowUpdateACLForZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsAllowUpdateACLForZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsAllowUpdateACLForZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsAllowUpdateACLForZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsAllowUpdateACLForZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsAllowUpdateACLForZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsAllowUpdateACLForZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsAllowUpdateACLForZone.so
