include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_CollectionOfMSEsSupport -lCIM_ManagedSystemElementSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsSlaveZoneInstanceName.o \
        Linux_DnsSlaveZoneInstance.o \
        Linux_DnsSlaveZoneExternal.o \
        Linux_DnsSlaveZoneRepositoryInstance.o \
        Linux_DnsSlaveZoneRepositoryExternal.o \
        Linux_DnsSlaveZoneManualInstance.o \
        Linux_DnsSlaveZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsSlaveZoneFakeFactory.o

NORMALFACTORY= Linux_DnsSlaveZoneFactory.o

RESOURCEOBJECT= Linux_DnsSlaveZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsSlaveZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsSlaveZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsSlaveZoneSupport.so \
      libLinux_DnsSlaveZone.so

libLinux_DnsSlaveZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsSlaveZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsSlaveZone.so: LDFLAGS+=-lLinux_DnsSlaveZoneSupport
libLinux_DnsSlaveZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsSlaveZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsSlaveZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsSlaveZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsSlaveZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsSlaveZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsSlaveZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsSlaveZone.so
