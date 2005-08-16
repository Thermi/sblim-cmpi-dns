include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_CollectionOfMSEsSupport -lCIM_ManagedSystemElementSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsZoneInstanceName.o \
        Linux_DnsZoneInstance.o \
        Linux_DnsZoneExternal.o \
        Linux_DnsZoneRepositoryInstance.o \
        Linux_DnsZoneRepositoryExternal.o \
        Linux_DnsZoneManualInstance.o \
        Linux_DnsZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsZoneFakeFactory.o

NORMALFACTORY= Linux_DnsZoneFactory.o

RESOURCEOBJECT= Linux_DnsZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsZoneSupport.so \
      libLinux_DnsZone.so

libLinux_DnsZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsZone.so: LDFLAGS+=-lLinux_DnsZoneSupport
libLinux_DnsZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsZone.so
