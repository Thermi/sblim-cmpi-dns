include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_CollectionOfMSEsSupport -lCIM_ManagedSystemElementSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsHintZoneInstanceName.o \
        Linux_DnsHintZoneInstance.o \
        Linux_DnsHintZoneExternal.o \
        Linux_DnsHintZoneRepositoryInstance.o \
        Linux_DnsHintZoneRepositoryExternal.o \
        Linux_DnsHintZoneManualInstance.o \
        Linux_DnsHintZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsHintZoneFakeFactory.o

NORMALFACTORY= Linux_DnsHintZoneFactory.o

RESOURCEOBJECT= Linux_DnsHintZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsHintZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsHintZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsHintZoneSupport.so \
      libLinux_DnsHintZone.so

libLinux_DnsHintZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsHintZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsHintZone.so: LDFLAGS+=-lLinux_DnsHintZoneSupport
libLinux_DnsHintZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsHintZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsHintZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsHintZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsHintZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsHintZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsHintZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsHintZone.so
