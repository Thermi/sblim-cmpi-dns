include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsSlaveZone -I../Linux_DnsIPAddress -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsSlaveZoneSupport -lLinux_DnsIPAddressSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsMastersOfSlaveZoneInstanceName.o \
        Linux_DnsMastersOfSlaveZoneInstance.o \
        Linux_DnsMastersOfSlaveZoneExternal.o \
        Linux_DnsMastersOfSlaveZoneRepositoryInstance.o \
        Linux_DnsMastersOfSlaveZoneRepositoryExternal.o \
        Linux_DnsMastersOfSlaveZoneManualInstance.o \
        Linux_DnsMastersOfSlaveZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsMastersOfSlaveZoneFakeFactory.o

NORMALFACTORY= Linux_DnsMastersOfSlaveZoneFactory.o

RESOURCEOBJECT= Linux_DnsMastersOfSlaveZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsMastersOfSlaveZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsMastersOfSlaveZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsMastersOfSlaveZoneSupport.so \
      libLinux_DnsMastersOfSlaveZone.so

libLinux_DnsMastersOfSlaveZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsMastersOfSlaveZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsMastersOfSlaveZone.so: LDFLAGS+=-lLinux_DnsMastersOfSlaveZoneSupport
libLinux_DnsMastersOfSlaveZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsMastersOfSlaveZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsMastersOfSlaveZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsMastersOfSlaveZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsMastersOfSlaveZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsMastersOfSlaveZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsMastersOfSlaveZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsMastersOfSlaveZone.so
