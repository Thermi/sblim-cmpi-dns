include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsZone -I../Linux_DnsAddressMatchList -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsZoneSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsAllowNotifyACLForZoneInstanceName.o \
        Linux_DnsAllowNotifyACLForZoneInstance.o \
        Linux_DnsAllowNotifyACLForZoneExternal.o \
        Linux_DnsAllowNotifyACLForZoneRepositoryInstance.o \
        Linux_DnsAllowNotifyACLForZoneRepositoryExternal.o \
        Linux_DnsAllowNotifyACLForZoneManualInstance.o \
        Linux_DnsAllowNotifyACLForZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsAllowNotifyACLForZoneFakeFactory.o

NORMALFACTORY= Linux_DnsAllowNotifyACLForZoneFactory.o

RESOURCEOBJECT= Linux_DnsAllowNotifyACLForZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsAllowNotifyACLForZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsAllowNotifyACLForZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsAllowNotifyACLForZoneSupport.so \
      libLinux_DnsAllowNotifyACLForZone.so

libLinux_DnsAllowNotifyACLForZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsAllowNotifyACLForZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsAllowNotifyACLForZone.so: LDFLAGS+=-lLinux_DnsAllowNotifyACLForZoneSupport
libLinux_DnsAllowNotifyACLForZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsAllowNotifyACLForZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsAllowNotifyACLForZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsAllowNotifyACLForZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsAllowNotifyACLForZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsAllowNotifyACLForZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsAllowNotifyACLForZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsAllowNotifyACLForZone.so
