include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsZone -I../Linux_DnsAddressMatchList -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsZoneSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsAllowTransferACLForZoneInstanceName.o \
        Linux_DnsAllowTransferACLForZoneInstance.o \
        Linux_DnsAllowTransferACLForZoneExternal.o \
        Linux_DnsAllowTransferACLForZoneRepositoryInstance.o \
        Linux_DnsAllowTransferACLForZoneRepositoryExternal.o \
        Linux_DnsAllowTransferACLForZoneManualInstance.o \
        Linux_DnsAllowTransferACLForZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsAllowTransferACLForZoneFakeFactory.o

NORMALFACTORY= Linux_DnsAllowTransferACLForZoneFactory.o

RESOURCEOBJECT= Linux_DnsAllowTransferACLForZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsAllowTransferACLForZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsAllowTransferACLForZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsAllowTransferACLForZoneSupport.so \
      libLinux_DnsAllowTransferACLForZone.so

libLinux_DnsAllowTransferACLForZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsAllowTransferACLForZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsAllowTransferACLForZone.so: LDFLAGS+=-lLinux_DnsAllowTransferACLForZoneSupport
libLinux_DnsAllowTransferACLForZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsAllowTransferACLForZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsAllowTransferACLForZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsAllowTransferACLForZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsAllowTransferACLForZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsAllowTransferACLForZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsAllowTransferACLForZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsAllowTransferACLForZone.so
