include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_CollectionOfMSEsSupport -lCIM_ManagedSystemElementSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsForwardZoneInstanceName.o \
        Linux_DnsForwardZoneInstance.o \
        Linux_DnsForwardZoneExternal.o \
        Linux_DnsForwardZoneRepositoryInstance.o \
        Linux_DnsForwardZoneRepositoryExternal.o \
        Linux_DnsForwardZoneManualInstance.o \
        Linux_DnsForwardZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsForwardZoneFakeFactory.o

NORMALFACTORY= Linux_DnsForwardZoneFactory.o

RESOURCEOBJECT= Linux_DnsForwardZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsForwardZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsForwardZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsForwardZoneSupport.so \
      libLinux_DnsForwardZone.so

libLinux_DnsForwardZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsForwardZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsForwardZone.so: LDFLAGS+=-lLinux_DnsForwardZoneSupport
libLinux_DnsForwardZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsForwardZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsForwardZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsForwardZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsForwardZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsForwardZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsForwardZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsForwardZone.so
