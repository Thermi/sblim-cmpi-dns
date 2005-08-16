include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsZone -I../CIM_ManagedSystemElement -I../Linux_DnsResourceRecord -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsZoneSupport -lLinux_DnsResourceRecordSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsResourceRecordInZoneInstanceName.o \
        Linux_DnsResourceRecordInZoneInstance.o \
        Linux_DnsResourceRecordInZoneExternal.o \
        Linux_DnsResourceRecordInZoneRepositoryInstance.o \
        Linux_DnsResourceRecordInZoneRepositoryExternal.o \
        Linux_DnsResourceRecordInZoneManualInstance.o \
        Linux_DnsResourceRecordInZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsResourceRecordInZoneFakeFactory.o

NORMALFACTORY= Linux_DnsResourceRecordInZoneFactory.o

RESOURCEOBJECT= Linux_DnsResourceRecordInZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsResourceRecordInZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsResourceRecordInZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsResourceRecordInZoneSupport.so \
      libLinux_DnsResourceRecordInZone.so

libLinux_DnsResourceRecordInZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsResourceRecordInZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsResourceRecordInZone.so: LDFLAGS+=-lLinux_DnsResourceRecordInZoneSupport
libLinux_DnsResourceRecordInZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsResourceRecordInZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsResourceRecordInZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsResourceRecordInZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsResourceRecordInZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsResourceRecordInZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsResourceRecordInZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsResourceRecordInZone.so
